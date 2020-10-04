#include <iostream>
#include "Scanner.h"

Scanner scanner;

int main()
{
    // // TODO define the scanner
    
    scanner.set_file("inp.txt");
    std::cout << "let's go\n";
    // this should work after setting up the scanner
    yy::parser p;
    //p.set_debug_level(1);
	p.parse();
    std::cout << p.parse() << "\n";
    return 0;
}
namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}