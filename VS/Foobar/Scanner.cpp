#include "Scanner.h"
#include <string>
#include <cstring>

Scanner::Scanner(const std::string& filename)
{
    set_file(filename);
}
void Scanner::set_file(const std::string& filename)
{
    reader.set_file(filename);
}

yy::parser::symbol_type Scanner::get_next_token()
{
    /* skip leading spaces */
    c = reader.next_character();
    while ((spaces.find(c) != spaces.end())) {
        c = reader.next_character();
    }
    if (c == '\n') {
        return yy::parser::make_EOL ();
    }
    if (c == EOF) {
        return yy::parser::make_YYEOF();
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
                    return yy::parser::make_YYUNDEF();
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
            double number = std::stod( buffer );
            buffer.clear();
            return yy::parser::make_REAL(number);
        }
        else {
            int number = std::stoi( buffer );
            buffer.clear();
            return yy::parser::make_INTEGER(number);
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
            std::string temp = "";
            // faster than moving/copying to temp then clearing the buffer
            std::swap(buffer,temp);
            return yy::parser::make_IDENTIFIER(temp);
        }
    }

    if (c == '.') {
        char next_c = reader.next_character();
        if (next_c == '.') {
            return yy::parser::make_RNG();
        }
        else {
            reader.move_back_ptr();
            return yy::parser::make_DOTN();
        }
    }
    return yy::parser::make_YYUNDEF();
}

