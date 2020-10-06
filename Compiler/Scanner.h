#pragma once
#include<set>
#include<map>
#include<string>

#include "Reader.h"
#include "parser.tab.hpp"

class Scanner
{

public:

    void set_file(const std::string& filename);
    yy::parser::symbol_type get_next_token();
    Scanner(){};
    ~Scanner(){};
    Scanner(const std::string &filename);
    void parse();
private:

    Reader reader;
    std::string buffer;
    char c;
    std::set<char> spaces = { ' ', '\t' };
    std::set<char> single_chars = { '[', ']', '(', ')', '=', '+', '-', '*', '%', ',' };
    std::set<char> possible_double_chars = { '>', '<', '/', ':' };  /* we can add = to the end */


    std::map< std::string, yy::parser::symbol_type> string_to_token =
            {
                    { ">", yy::parser::make_GRT() },
                    { ">=", yy::parser::make_GRTE() },
                    { "<", yy::parser::make_LES() },
                    { "<=", yy::parser::make_LESE() },
                    { "=", yy::parser::make_EQ() },
                    { "/=", yy::parser::make_NEQ() },
                    {"/", yy::parser::make_DIV() },
                    { "[", yy::parser::make_LAR() },
                    { "]", yy::parser::make_RAR() },
                    { "(", yy::parser::make_LBR() },
                    { ")", yy::parser::make_RBR() },
                    { "+", yy::parser::make_ADD() },
                    { "-", yy::parser::make_SUB() },
                    { "*", yy::parser::make_MUL() },
                    { "%", yy::parser::make_MOD() },
                    { ",", yy::parser::make_COM() },
                    {":", yy::parser::make_COL() },
                    {":=", yy::parser::make_ASN() },
                    {"and", yy::parser::make_AND() },
                    {"or", yy::parser::make_OR()  },
                    {"xor", yy::parser::make_XOR()  },
                    {"if", yy::parser::make_IF()  },
                    {"then", yy::parser::make_THEN()  },
                    {"else", yy::parser::make_ELSE()  },
                    {"true", yy::parser::make_TRU()  },
                    {"false", yy::parser::make_FLS()  },
                    {"var", yy::parser::make_VAR()  },
                    {"type", yy::parser::make_TKEY()  },
                    {"routine", yy::parser::make_RUT()  },
                    {"return", yy::parser::make_RTN()  },
                    {"is", yy::parser::make_IS()  },
                    {"in", yy::parser::make_IN()  },
                    {"reverse", yy::parser::make_REV()  },
                    {"for", yy::parser::make_FOR()  },
                    {"while", yy::parser::make_WHL()  },
                    {"loop", yy::parser::make_LOP()  },
                    {"end", yy::parser::make_END()  },
                    {"record", yy::parser::make_RCRD()  },
                    {"array", yy::parser::make_ARY()  },
                    {"integer", yy::parser::make_ITYPE()  },
                    {"real", yy::parser::make_RTYPE()  },
                    {"boolean", yy::parser::make_BTYPE()  }
            };
};