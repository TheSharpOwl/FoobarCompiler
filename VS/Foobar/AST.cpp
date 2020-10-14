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
	std::string Expression::getType(shared_ptr<Expression> exp)
	{
		if (exp == nullptr)
			return "";
		if (exp->l == nullptr && exp->l == nullptr) // this means it is a number or an identifer
		{
			std::string temp;
			switch (exp->value.index())
			{
			case 0: temp = "ident"; break;
			case 1: temp = "int"; break;
			case 2: temp = "double"; break;
			case 3: temp = "bool"; break;
			}
			if (temp == "ident")
				return Type::TypeTable[std::get<0>(exp->value)]->name;
			else
				return temp;
		}
		else if (exp->l == nullptr)
			return getType(exp->l);
		else if(exp->r == nullptr)
			return getType(exp->r);
		std::string left = getType(exp->l);
		std::string right = getType(exp->r);
		if (left == "double" || right == "double")
			return "double";
		else if (left == "int" || right == "int")
			return "int";
		else
			return "bool";

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
			std::string x = v->name + "has value"; // TODO important
			std::cout << v->name << " ";
			if (v->value == nullptr)
				std::cout << "(no value yet)\n";
			else
				std::cout << "has value of type " << Expression::getType(v->value) << "\n";
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
