#include <iostream>
#include "Scanner.h"

int main()
{
    // // TODO define the scanner
    Scanner scanner("inp.txt");
    std::cout << "let's go\n";
    // this should work after setting up the scanner
    yy::parser p;
    p.set_debug_level(1);
	p.parse();
    std::cout << p.parse() << "\n";
    return 0;
}