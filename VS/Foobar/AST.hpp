#pragma once

#include<memory>
#include <vector>
#include <string>
#include<variant>

// TODO read about Visitor Pattern and try to apply it here

// forward declerations 
namespace ast
{
	struct Node;
	struct Block;
	struct Routine;
	struct Variable;
	struct Statement;
	struct ReturnStatement;
	struct WhileLoop;
	struct IfStatement;
	struct ForLoop;
	struct Decleration;
	struct Assignment;
	struct Expression;
	struct Type;
	struct Ident;
}

namespace ast
{

	using namespace std;

	template <typename T> using sp = shared_ptr<T>;
	template <typename T> using vsp = vector<shared_ptr<T>>;

	struct Node
	{
		string name;
		int start, end;

		Node() = default;
	};
	struct Program : Node
	{
		vsp<Variable> variables;
		vsp<Statement> statemets;
		vsp<Routine> routines;
	};
	struct Block : Node
	{
		vsp<Variable> variables;
		vsp<Statement> statemets;
	};
	struct Routine : Node
	{
		sp<Block> body; // variables and other things go inside the body
		vsp <Variable> parameters;
		sp<Type> returnType;
		vsp<ReturnStatement> returnStatements;

		//TODO function to store the returnStatements inside the vector
		//TODO function to check valid return statements
	};
	struct Variable : Node
	{
		sp<Type> type;

		Variable(const string& Name, int Start, int End, sp<Type> type2)
		{
			name = Name;
			start = Start;
			end = End;
			this->type = make_shared<Type>(type2);
		}
		Variable() = default;
		Variable(Variable&&) = default;
		Variable(Variable&) = default;
		Variable& operator= (const Variable&) = default;
		Variable& operator= (Variable&&) = default;
	};

	struct Statement : Node
	{

	};
	struct ReturnStatement : Statement
	{
		sp<Expression> returned;
	};
	struct WhileLoop : Statement
	{
		sp<Expression> condition;
		sp<Block> body;

	};
	struct IfStatement : Statement
	{
		sp<Expression> condition;
		sp<Block> body;
		sp<Block> elseBody;
	};
	struct ForLoop : Statement
	{
		sp<Block> body;
		sp<Expression> rangeStart;
		sp<Expression> rangeEnd;
		sp<Variable> loopVar;
		bool reversed = false; // by default
	};

	struct Decleration : Statement
	{
		sp<Type> type;
		// TODO function to create a variable
	};

	struct Assignment : Statement
	{
		sp<Expression> lValue;
		sp<Ident> rValue;
		// TODO function to check if lValue is a valid Ident
		// TODO function to check if the rValue is valid (use the expression type determiner function)
	};
	struct Ident : Node
	{

	};
	struct Expression : Node
	{
		// if l = r = nullptr this means we can't go deeper in the tree

		// TODO might change to enum for symbols
		variant<string, Ident, long long int, double, bool> symbol, ident, iValue, rValue, bValue;
		sp<Expression> l;
		sp<Expression> r;
		// TODO impelement function which returns Type of the expression
		// TODO store the expression from bison (need to solve the union bison issue)
		// TODO figure out other things to impelement as funcitons here
	};

	struct Type : Node
	{
		Type(shared_ptr <Node> node)
		{
			name = node->name;
			start = node->start;
			end = node->end;
		}
		Type(string otherName)
		{
			start = end = 0; //TODO change after adding the char count system
			name = otherName;
		}
		Type() = default;
		Type(Type&&) = default;
		Type(Type&) = default;
		Type& operator= (const Type & other) = default;
		Type& operator= (Type&&) = default;

	};
	struct BuiltinType : Type
	{
		variant<long long int, double, bool> iValue, rValue, bValue;
		BuiltinType(string otherName)
		{
			start = end = 0; //TODO change after adding the char count system
			name = otherName;
		}
	};
	struct Record : Type
	{
		vsp<Type> fields;
	};

	struct Alias : Type
	{
		sp<Type> type; // the original one and "name" is already inherited
	};

	struct Array : Type
	{
		int size = 0;
		sp<Type> type;
		// TODO figure out how to store the values
	};
}

// TODO : make sure type aliases can only be defined in the outside program and handle it.