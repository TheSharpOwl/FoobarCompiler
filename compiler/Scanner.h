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
                    { ">", GRT },
                    { ">=", GRTE },
                    { "<", LES },
                    { "<=", LESE },
                    { "=", EQ },
                    { "/=", NEQ },
                    {"/", DIV },
                    { "[", LAR },
                    { "]", RAR },
                    { "(", LBR },
                    { ")", RBR },
                    { "+", ADD },
                    { "-", SUB },
                    { "*", MUL },
                    { "%", MOD },
                    { ",", COM },
                    {":", COL },
                    {":=", ASN },
                    {"and", AND},
                    {"or", OR },
                    {"xor", XOR },
                    {"if", IF },
                    {"then", THEN },
                    {"else", ELSE },
                    {"true", TRU },
                    {"false", FLS },
                    {"var", VAR },
                    {"type", TKEY },
                    {"routine", RUT },
                    {"return", RTN },
                    {"is", IS },
                    {"in", IN },
                    {"reverse", REV },
                    {"for", FOR },
                    {"while", WHL },
                    {"loop", LOP },
                    {"end", END },
                    {"record", RCRD },
                    {"array", ARY },
                    {"integer", ITYPE },
                    {"real", RTYPE },
                    {"boolean", BTYPE }
            };

public:
    void set_file(std::string filename);
    int get_next_token(YYSTYPE *lvalp);
};