#include <iostream>
#include "Scanner.h"

Scanner scanner;

int main()
{   
    scanner.set_file("inp.txt");
    std::cout << "let's go\n";
    // this should work after setting up the scanner
    yy::parser p;
	int x = p.parse();
    return 0;
}
namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}