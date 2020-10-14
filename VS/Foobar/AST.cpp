#include "AST.hpp"

std::unordered_map<std::string, std::shared_ptr<ast::Type> > ast::Type::TypeTable = {};

int ast::line = 0;


namespace ast
{
	void Block::addVariable(sp<Variable> v)
	{
		variables.push_back(v);
		end = max(v->end, end);
	}
	void Block::addStatement(sp<Statement> s)
	{
		statemets.push_back(s);
		end = max(s->end, end);
	}

	void dfs()
	{

	}
}
