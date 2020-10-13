#include "AST.hpp"

std::unordered_map<std::string, std::shared_ptr<ast::Type> > ast::Type::TypeTable = {};

int ast::line = 0;