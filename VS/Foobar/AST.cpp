#include "AST.hpp"

std::unordered_map<std::string, std::shared_ptr<ast::Type> > ast::Type::TypeTable = {};

int ast::line = 0;
extern std::shared_ptr<ast::Program> ourProgram;

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
		sort(ourProgram->variables.begin(), ourProgram->variables.end(),
			[](shared_ptr<ast::Variable> a, shared_ptr<ast::Variable> b) -> bool
			{
				return a->name < b->name;
			});
		std::cout << "ourProgram contains:\nvariables:\n";
		for (auto v : ourProgram->variables)
		{
			std::cout << v->name << "\n";
			if (v->value == nullptr)
				continue;
			std::cout << "has value\n";

		}
		std::cout << "Routines:\n";
		for (auto r : ourProgram->routines)
		{
			std::cout << r->name << " with variables :\n";
			for (auto v : r->body->variables)
				std::cout << v->name << "\n";
		}
	}
}
