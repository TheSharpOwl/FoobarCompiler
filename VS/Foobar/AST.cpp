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
			printVariable(v);
		}
		std::cout << "Routines:\n";
		for (auto r : ourProgram->routines)
		{
			std::cout << r->name;
			std::cout << " with parameters: \n";
			for (auto p : r->parameters)
				std::cout << p->name << " of type " << p->type->name <<"\n";
			std::cout << std::endl;
			std::cout  << "with variables :\n";
			for (auto v : r->body->variables)
				printVariable(v);
		}
	}
	void printVariable(std::shared_ptr<Variable> v)
	{
		std::string x = v->name + "has value";
		std::cout << v->name << " ";
		if (v->value == nullptr)
			std::cout << "(no value yet)";
		else
			std::cout << "of type " << Expression::getType(v->value);
		std::cout <<  " at line " << v->start << std::endl;
	}
}
