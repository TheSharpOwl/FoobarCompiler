#pragma once

#include<memory>
#include <vector>
#include <string>
#include<variant>

template <typename T> using sp = std::shared_ptr<T>;

// forward declerations 

namespace AST
{
	using namespace std;

	struct Node
	{
		string name;
	};

	struct Type : Node{};

	template<typename T>
	struct Record : Type 
	{
		// the types and the name of each corresponding field;
		vector<sp<Type>> fields;
		vector<string> names;
	};
	/*
	* Notes :
	* 1. value can be anything here, vector of primitive types for example in case of a record and so on
	* 2. Type t also can be a record since record inherits from Type
	* 
	*/
	struct Variable : Node
	{
		Type t;
		std::string name;
		Variable(const std::string s) : name(s) {};
		// TODO store the value somehow
	};

	template<typename T>
	struct Array : Node
	{
		Type t;
		std::string name;
		// TODO store the values somehow
	};

	struct Statement : Node{};

	struct Block : Node 
	{
		int start, end; // number of start and end line
		vector<sp<Variable>> variables;
		vector<sp<Statement>> Statements;
		vector<sp<Block>> blocks;
	};

	enum class NodeType
	{
		BOOLEAN = 'B',
		INTEGER = 'I',
		REAL = 'R',
		PLUS = '+',
		MINUS = '-',
		MULT = '*',
		DIV = '/',
		MOD = '%',
		EQUAL = '=',
		NEQUAL = '!',
		GRT,
		GRTE,
		LES,
		LESE,
		EQ,
		NEQ,
		AND,
		OR,
		XOR
	};

	class Expression
	{
	public:
		NodeType nodeType;

		// TODO find a solution for nodes which have - 
		//https://en.cppreference.com/w/cpp/utility/variant (C++ 's alternative to union)
		variant<bool, double, long long int> bValue, rValue, iValue;

		sp<Expression> left, right;
		Expression() = delete;
		Expression(bool value)
		{
			bValue = value;
			left = right = nullptr;
		}
		Expression(long long int value)
		{
			iValue = value;
			left = right = nullptr;
		}
		Expression(double value)
		{
			rValue = value;
			left = right = nullptr;
		}
		Expression(sp<Expression> l, sp<Expression> r, NodeType t) : left(l), right(l), nodeType(t) {};
		// TODO solve the return type in bison and delete these
		Expression(int l, int r, NodeType t) {};
		Expression(int l, int r, char t) {};
		Expression(bool l, bool r, NodeType t) {};
		Expression(bool l, bool r, string t) {};
		Expression(double l, double r, string s) {};
		Expression(bool l, bool r, char t) {};
		Expression(double l, double r, NodeType t) {};
		Expression(double l, double r, char* t) {};
		Expression(double l, double r, char t) {};

		Expression(string t, string s) {};
		// TODO end
		~Expression() {};
	};

	struct IfStatement : Statement
	{
		sp<Expression> condition;
		sp<Block> ifBody;
		sp<Block> elseBody;
	};

	struct WhileLoop : Statement
	{
		sp<Expression> condition;
		sp<Block> body;
		WhileLoop(sp<Expression> cond, sp<Block> b) : condition(cond), body(b) {};
		WhileLoop() {};// TODO delete later
	};

	struct ForLoop : Statement
	{
		sp<Variable> iterVar;
		sp<Expression> rangeStart;
		sp<Expression> rangeEnd;
		bool reversed = false; // by default it is not unless the coder says so
		sp<Block> body;
	};
	struct Parameter : Node
	{
		string name;
		Type type;
	};
	struct Routine : Node
	{
		sp<Block> body;
		vector<sp<Parameter>> parameters;
		sp<Type> returnType;
	};

	struct Program : Node
	{
		vector<sp<Routine>> routines;
		vector<sp<Variable>> variables;
		vector<sp<Type>> types;
	};

	
	
}
