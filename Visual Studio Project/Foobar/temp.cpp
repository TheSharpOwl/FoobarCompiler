#include "temp.hpp"
#include <iostream>

int main()
{
    std::shared_ptr<ast::Type> myType = std::make_shared<ast::Type>();
    myType->name = "test_type";
    myType->start = 0;
    myType-> end = 100;
    ast::Variable* var = new ast::Variable("test_variable", 0, 1, myType);
    std::cout<<var->name << " " << var->type->name << '\n';
    return 0;
}