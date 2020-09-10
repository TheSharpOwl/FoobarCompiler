#pragma once
#include<set>
#include<map>
#include<string>

// forward decleration
class Reader;

class Scanner
{
    Reader reader;
    std::string buffer;
    char c;
    std::set<char> spaces = { ' ', '\t' };
    std::set<char> single_chars = { '[', ']', '(', ')', '=', '+', '-', '*', '%', ',' };
    std::set<char> possible_double_chars = { '>', '<', '/', ':' };  /* we can add = to the end */


    std::map< std::string, const char*> string_to_token =
            {
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

public:
    void set_file(std::string filename);
    const char* get_next_token();
};


