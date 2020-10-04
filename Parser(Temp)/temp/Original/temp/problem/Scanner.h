#pragma once
#include "parser.tab.hpp"
#include<set>
#include<map>
#include<string>
#include "Reader.h"

class parser;

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
                    {":", parser::token::COL },
                    {"integer", parser::token::ITYPE },
                    {"var", parser::token::VAR }
            };

public:
    void set_file(std::string filename);
    int get_next_token(parser::semantic_type* yylval);
};