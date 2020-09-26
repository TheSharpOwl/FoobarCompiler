#pragma once
#include<set>
#include<map>
#include<string>

#include "Reader.h"
#include "parser.tab.hpp"

class Scanner
{
    Reader reader;
    std::string buffer;
    char c;
    std::set<char> spaces = { ' ', '\t' };
    std::set<char> single_chars = { '[', ']', '(', ')', '=', '+', '-', '*', '%', ',' };
    std::set<char> possible_double_chars = { '>', '<', '/', ':' };  /* we can add = to the end */


    std::map< std::string, int> string_to_token =
            {
                    {":", COL },
                    {"integer", ITYPE },
                    {"var", VAR }
            };

public:
    void set_file(std::string filename);
    int get_next_token(YYSTYPE *lvalp);
};