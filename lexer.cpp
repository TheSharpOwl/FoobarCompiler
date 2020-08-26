#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define MAX_FILE_CHARS 10000

class Reader {
public:
    char file[MAX_FILE_CHARS]{};
    int size = 0;
    int ptr = -1;


    void set_file (const char * filename) {
        ifstream in(filename);
        string contents((istreambuf_iterator<char>(in)),
                             istreambuf_iterator<char>());
        strcpy(file, contents.c_str());
        size = contents.size();
    };

    char next_character() {
        ptr++;
        if (ptr == size)
            return EOF;
        else
            return file[ptr];
    }

    void move_back_ptr() {
        ptr--;
    }

    char current_character() {
        return file[ptr];
    }


};

class Lexer {
    Reader reader;
    char buffer[256]{};
    int buffer_ptr = 0;
    char c{};

    map<char, const char *> single_chars_to_token = {

    };

    map< string, const char *> string_to_token = {
            { ">", "GRT " },
            { ">=", "GRTE " },
            { "<", "LES " },
            { "<=", "LESE " },
            { "=", "EQ " },
            { "/=", "NEQ " },
            {"/", "DIV "},
            { "[", "LAR " },
            { "]", "RAR " },
            { "(", "LBR " },
            { ")", "RBR " },
            { "+", "ADD " },
            { "-", "SUB " },
            { "*", "MUL " },
            { "%", "MOD " },
            { ",", "COM " },
            {":", "SEMIC "},
            {":=", "ASN "},
            {"and", "AND" },
            {"or", "OR "},
            {"xor", "XOR "},
            {"if", "IF "},
            {"then", "THEN "},
            {"else", "ELSE "},
            {"true", "TRU "},
            {"false", "FLS "},
            {"var", "VAR "},
            {"type", "TKEY "},
            {"routine", "RUT "},
            {"return", "RTN "},
            {"is", "IS "},
            {"in", "IN "},
            {"reverse", "REV "},
            {"for", "FOR "},
            {"while", "WHL "},
            {"loop", "LOP "},
            {"end", "END "},
            {"record", "RCRD "},
            {"array", "ARR "},
            {"integer", "ITYPE "},
            {"real", "RTYPE "},
            {"boolean", "BTYPE "}
    };

    set<char> spaces = {' ', '\t'};
    set<char> single_chars = {'[', ']', '(', ')', '=', '+', '-', '*', '%', ','};
    set<char> possible_double_chars = {'>', '<', '/', ':'};  /* we can add = to the end */



public:
    void set_file(const char * filename) {
        reader.set_file(filename);
    }

    const char * get_next_token () {
        /* skip leading spaces */
        c = reader.next_character();
        while ((spaces.find(c) != spaces.end())) {
            c = reader.next_character();
        }
        if (c == '\n') {
            return "\n";
        }
        if (c == EOF) {
            return "EOF";
        }

        /* check if special character can be uniquely identified */
        bool is_in = single_chars.find(c) != single_chars.end();
        if (is_in) {
            string s(1, c);
            const char * return_val = string_to_token.find(s)->second;
            return return_val;
        }

        /* check for other special characters  */
        is_in = possible_double_chars.find(c) != possible_double_chars.end();
        if (is_in) {
            char next_c = reader.next_character();
            if (next_c == '=') {
                char arr[] = {c, next_c, '\0'};
                string str(arr);
                return string_to_token.find(str)->second;
            } else {
                reader.move_back_ptr();
                string s(1, c);
                return string_to_token.find(s)->second;
            }
        }

        /* check if number */
        if (c == '-' || (c >= '0' && c <= '9')) {
            /* fill digits in the buffer and then convert to number */
            bool is_real = false;
            do {
                buffer[buffer_ptr++] = c;
                c = reader.next_character();
                if (c == '.') {
                    if (is_real) { /* second dot in number like 21.32. */
                        return "ERR ";
                    }
                    char next_c = reader.next_character();
                    reader.move_back_ptr();
                    if (next_c == '.') { /* we found range .. like 12..50 case  */
                        break;
                    } else {
                        is_real = true;
                    }
                }
            } while (c == '.' || (c >= '0' && c <= '9'));
            reader.move_back_ptr();

            buffer[buffer_ptr] = '\0';
            if (is_real) {
                double number;
                sscanf(buffer, "%lf", &number);
                buffer_ptr = 0;
                return "REAL ";
            } else {
                int number;
                sscanf(buffer, "%d", &number);
                buffer_ptr = 0;
                return "INTEGER ";
            }
        }

        /* If first character is the start of the identifier */
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
            do {
                buffer[buffer_ptr++] = c;
                c = reader.next_character();
            } while ((c >= 'a' && c <= 'z') || (c >= 'A' &&c <= 'Z') || (c >= '0' && c <= '9') || c == '_');
            reader.move_back_ptr();
            buffer[buffer_ptr] = '\0';

            string str(buffer);
            buffer_ptr = 0;
            auto token_struct = string_to_token.find(str);
            if (token_struct != string_to_token.end()) {
                return token_struct->second;
            } else {
                return "IDENTIFIER ";
            }
        }

        if (c == '.') {
            char next_c = reader.next_character();
            if (next_c == '.') {
                return "RNG ";
            } else {
                reader.move_back_ptr();
                return "DOTN ";
            }
        }

        printf("%d", c);
        return "UNKNOWN";
    };
};


int main() {
    Lexer lexer;
    lexer.set_file("2.txt");
    const char *TOKEN = lexer.get_next_token();
    while (strcmp(TOKEN, "EOF") != 0) {
        printf("%s", TOKEN);
        TOKEN = lexer.get_next_token();
    }

    return 0;
}
