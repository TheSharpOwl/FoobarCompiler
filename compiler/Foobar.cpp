#include <iostream>
#include "Scanner.hpp"

Scanner scanner;

int main()
{   
    scanner.set_file("inp.txt");
    yy::parser p;
	p.parse();
    return 0;
}
namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}