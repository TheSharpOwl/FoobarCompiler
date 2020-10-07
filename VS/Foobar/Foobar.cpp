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
    
	// sp<ast::Type> myType = std::make_shared<ast::Type>();

	// myType->name = "test_type";
	// myType->start = 0;
	// myType->end = 100;

	// auto var = std::make_shared<ast::Variable> ("test_variable", 0, 1, myType);
	//std::cout << var->name << " " << var->type->name << '\n';

    return 0;
}
namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}