#pragma once

#include<memory>
#include <vector>
#include <string>
#include<utility>
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
	struct RoutineCall;
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
		Node(const string& s) : 
			name(s) {}

		virtual ~Node() = default;

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

		Block() = default;
		~Block() = default;

		void addVariable(sp<Variable> v)
		{
			variables.push_back(v);
		}
		void addStatement(sp<Statement> s)
		{
			statemets.push_back(s);
		}

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
		sp<Ident> ident;
		sp<Expression> value = nullptr;

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
		virtual ~Statement() = default;
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
		Ident(const string& s) :
			Node(s) {}
	};
	struct Expression : Node
	{
		using spe = sp<Expression>;
		// if l = r = nullptr this means we can't go deeper in the tree
		bool braces = false;
		// TODO might change to enum for symbols
		variant<string, sp<Ident>, long long int, double, bool> value;
		spe l = nullptr;
		spe r = nullptr;
		// TODO implement function which returns Type of the expression
		Expression(const string& name) : 
			Node(name) {}
		Expression(const string& newSymbol, spe first, spe second, bool braces = false) : Node("Operation")
		{
			value = newSymbol;
			l = first;
			r = second;
		}
		Expression(int val) : Node("INTEGER"), value(val){}
		Expression(bool val) :   Node("BOOLEAN"), value(val){}
		Expression(double val) : Node("REAL"), value(val){}
		Expression(sp<Ident> otherIdent) :
			Node("IDENT") 
		{
			value = otherIdent;
		}
		virtual ~Expression() = default;
		void print() 
		{
			switch (value.index())
			{
			case 0: std::cout << get<0>(value) << std::endl; break;
			case 1: std::cout << (get<1>(value))->name << std::endl; break;
			case 2: std::cout << get<2>(value) << std::endl; break;
			case 3: std::cout << get<3>(value) << std::endl; break;
			case 4: std::cout << get<4>(value) << std::endl; break;
			}
		}
	};
	struct RoutineCall : Expression
	{
		vsp<Expression> args;

	};
	struct Type : Node
	{
		Type(sp<Node> node)
		{
			name = node->name;
			start = node->start;
			end = node->end;
		}
		Type(const std::string& otherName, int st = 0, int en = 0)
		{
			start = end = 0; //TODO change after adding the char count system
			name = otherName;
		}
		Type() = default;
		Type(Type&&) = default;
		Type(Type&) = default;
		Type& operator= (const Type & other) = default;
		Type& operator= (Type&&) = default;

		virtual ~Type() = default;

	};
	struct BuiltinType : Type
	{
		variant<long long int, double, bool> iValue, rValue, bValue;
		// TODO add a way to change the value
		BuiltinType(const string& otherName, int st = 0, int en = 0) : Type(otherName, st, en)
		{
			start = end = 0; //TODO change after adding the char count system
			name = otherName;
		}
	};
	struct Record : Type
	{
		vsp<Type> fields;
		Record(const string& name, vsp<Type> Fields, int st = 0, int en = 0) :
			Type(name, st, en) {}
		//TODO remove
		Record(string name, int st = 0, int en = 0) :
			Type(name, st, en) {}
	};

	struct Alias : Type
	{
		sp<Type> type; // the original one. "name" is already inherited
	};

	struct Array : Type
	{
		int size = 0;
		sp<Type> type;
		Array(const std::string& name, int st = 0, int ed = 0) :
			Type(name, st, ed){}
		// TODO figure out how to store the values (I think I did already)
	};
}

// TODO : make sure type aliases can only be defined in the outside program and handle it.