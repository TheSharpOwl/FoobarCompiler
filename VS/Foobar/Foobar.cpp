#include <iostream>
#include "Scanner.hpp"
#include "AST.hpp"

Scanner scanner;

template<typename T> using sp = std::shared_ptr<T>;

int main()
{   
    scanner.set_file("inp.txt");
    yy::parser p;
	p.parse();
    ast::dfs();
    return 0;
}
namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}