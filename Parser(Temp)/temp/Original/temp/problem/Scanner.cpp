#include "Scanner.h"
#include <string>
#include <cstring>

void Scanner::set_file(std::string filename)
{
    reader.set_file(filename);
}

int Scanner::get_next_token(parser::semantic_type* yylval)
{
    /* skip leading spaces */
    c = reader.next_character();
    while ((spaces.find(c) != spaces.end())) {
        c = reader.next_character();
    }
    if (c == '\n') {
        return parser::EOL;
    }
    if (c == EOF) {
        return parser::YYEOF;
    }

    /* check if special character can be uniquely identified */
    bool is_in = single_chars.find(c) != single_chars.end();
    if (is_in) {
        std::string s(1, c);
        return string_to_token.find(s)->second;
    }

    /* check for other special characters  */
    is_in = possible_double_chars.find(c) != possible_double_chars.end();
    if (is_in) {
        char next_c = reader.next_character();
        if (next_c == '=') {
            char arr[] = { c, next_c, '\0' };
            std::string str(arr);
            return string_to_token.find(str)->second;
        }
        else {
            reader.move_back_ptr();
            std::string s(1, c);
            return string_to_token.find(s)->second;
        }
    }

    /* check if number */
    if (c == '-' || (c >= '0' && c <= '9')) {
        /* fill digits in the buffer and then convert to number */
        bool is_real = false;
        do {
            buffer += c;
            c = reader.next_character();
            if (c == '.') {
                if (is_real) { /* second dot in number like 21.32. */
                    return parser::YYUNDEF;
                }
                char next_c = reader.next_character();
                reader.move_back_ptr();
                if (next_c == '.') { /* we found range .. like 12..50 case  */
                    break;
                }
                else {
                    is_real = true;
                }
            }
        } while (c == '.' || (c >= '0' && c <= '9'));
        reader.move_back_ptr();

        if (is_real) {
            //edited to int instead of double
            int number = std::stod( buffer );
            yylval->emplace<int>() = number;
            buffer.clear();
            return parser::token::INTEGER;///REAL
        }
        else {
            int number = std::stoi( buffer );
            yylval->emplace<int>() = number;
            buffer.clear();
            return parser::token::INTEGER;
        }
    }

    /* If first character is the start of the identifier */
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        do {
            buffer += c;
            c = reader.next_character();
        } while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_');
        reader.move_back_ptr();

        auto token_struct = string_to_token.find(buffer);
        if (token_struct != string_to_token.end()) {
            buffer.clear();
            return token_struct->second;
        }
        else {
            yylval->emplace<std::string>() = buffer;
            buffer.clear();
            return parser::token::IDENTIFIER;
        }
    }

    if (c == '.') {
        char next_c = reader.next_character();
        if (next_c == '.') {
            return parser::token::INTEGER;//RNG
        }
        else {
            reader.move_back_ptr();
            return parser::token::INTEGER;//DOTIN
        }
    }

    return parser::token::YYUNDEF;
}