#pragma once

#include<memory>
#include <vector>
#include <string>
#include<utility>
#include<variant>
#include<tuple>
#include<unordered_map>
#include<iostream>
#include<algorithm>
// TODO read about Visitor Pattern and try to apply it here

// forward declerations 
namespace ast
{
	struct Node;
	struct Block;
	struct Routine;
	struct Statement;
	struct ReturnStatement;
	struct WhileLoop;
	struct IfStatement;
	struct ForLoop;
	struct Decleration;
	struct Assignment;
	struct Expression;
	struct RoutineCall;
	struct Ident;
	struct Type;
}

namespace ast
{

	using namespace std;

	template <typename T> using sp = shared_ptr<T>;
	template <typename T> using vsp = vector<shared_ptr<T>>;

	extern int line;

	struct Node
	{
		string name;
		int start, end;

		Node() = default;
		Node(const string& s) : 
			name(s), start(ast::line) {}

		virtual ~Node() = default;

	};
	struct Type : Node
	{
		Type(sp<Node> node)
		{
			name = node->name;
			start = node->start;
			end = node->end;
		}
		Type(const std::string& otherName) :
		 Node(otherName) {}
		Type() = default;
		Type(Type&&) = default;
		Type(Type&) = default;
		Type& operator= (const Type& other) = default;
		Type& operator= (Type&&) = default;

		virtual ~Type() = default;

		static unordered_map<string, sp<Type> > TypeTable;
	};
	struct Variable : Type
	{
		sp<Type> type;
		sp<Ident> ident;
		sp<Expression> value = nullptr;

		Variable(const string& Name, sp<Type> type2) :
		 Type(Name)
		{
			this->type = type2;
		}
		Variable(const string& Name, sp<Expression> exp, sp<Type> type2) :
			Type(Name)
		{
			value = exp;
			
			type = type2;
			//type = Expression::getType(exp);
		}
		Variable() = default;
	};
	struct Program : Node
	{
		vsp<Variable> variables;
		vsp<Statement> statemets;
		vsp<Routine> routines;

		Program() {start = ast::line;}
	};
	struct Block : Node
	{
		vsp<Variable> variables;
		vsp<Statement> statemets;

		Block() { start = end = ast::line; }
		~Block() = default;

		void addVariable(sp<Variable> v);
		void addStatement(sp<Statement> s);

	};
	struct Routine : Node
	{
		sp<Block> body; // variables and other things go inside the body
		vsp <Variable> parameters;
		sp<Type> returnType;
		vsp<ReturnStatement> returnStatements;
		Routine() = default;
		Routine(const string& name, vsp<Variable> params, sp<Block> oBody, sp<Type> rtType) :
			Node(name)
		{
			parameters = (params);
			body = oBody;
			returnType = rtType;
			end = oBody->end;
		}
		void print() 
		{
			cout << "Routine " << name << " with type : ";
			if (returnType != nullptr)
				cout << returnType->name;
			else
				cout << "void";
			cout << endl;
			cout << "vector size : ";
			cout << parameters.size() << endl;
			for (auto a : parameters)
				cout << a->name << " " << a->type->name << endl;

		}
	};


	struct Statement : Node
	{
		virtual ~Statement() = default;
	};
	struct ReturnStatement : Statement
	{
		sp<Expression> returned = nullptr;
		ReturnStatement(sp<Expression> exp)
		{returned = exp; start = end = ast::line;}
		ReturnStatement() = default;
	};
	struct WhileLoop : Statement
	{
		sp<Expression> condition;
		sp<Block> body;
		WhileLoop(sp<Expression> Cond, sp<Block> Body)
		{
			start = ast::line;
			condition = Cond;
			body = Body;
		}
	};
	struct IfStatement : Statement
	{
		sp<Expression> condition;
		sp<Block> body;
		sp<Block> elseBody;

		IfStatement(sp<Expression> exp, sp<Block> block, sp<Block> elseBlock) :
			condition(exp), body(block), elseBody(elseBlock) {start = ast::line;}
	};
	struct ForLoop : Statement
	{
		sp<Block> body;
		sp<Expression> rangeStart;
		sp<Expression> rangeEnd;
		sp<Variable> loopVar;
		bool reversed = false; // by default
		ForLoop(const string& LoopVar, tuple<sp<ast::Expression>, sp<ast::Expression>, bool> Range, sp<Block> Body) :
			 rangeStart(get<0>(Range)), rangeEnd(get<1>(Range)), reversed(get<2>(Range)), body(Body)
		{
			loopVar = make_shared<Variable>(LoopVar, nullptr); 
			start = ast::line;
		}
		ForLoop() = default;
	};

	struct Decleration : Statement
	{
		sp<Type> type;
	};

	struct Assignment : Statement
	{
		sp<Expression> rValue;
		sp<Ident> lValue;
		Assignment(const string& identName, sp<Expression> exp) :
			rValue(exp) 
		{
			start = ast::line;
			lValue = make_shared<Ident>(identName);
		}
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
		// TODO might change to enum for symbols
		variant<string, long long int, double, bool> value;
		spe l = nullptr;
		spe r = nullptr;
		static std::string getType(shared_ptr<Expression> exp);
		Expression(const string& newSymbol, spe first, spe second = nullptr, bool braces = false) : Node("Operation")
		{
			value = newSymbol;
			l = first;
			r = second;
		}
		Expression(long long int val, bool temp) : Node("INTEGER"), value(val) {}
		Expression(bool val) :   Node("BOOLEAN"), value(val){}
		Expression(double val) : Node("REAL"), value(val){}
		Expression(const string& identName) :
			Node("IDENT") 
		{
			value = identName;
		}
		virtual ~Expression() = default;
		void print() 
		{
			switch (value.index())
			{
				case 0: std::cout << get<0>(value) << std::endl; break;
				case 1: std::cout << get<1>(value) << std::endl; break;
				case 2: std::cout << get<2>(value) << std::endl; break;
				case 3: std::cout << get<3>(value) << std::endl; break;
			}
		}
	};
	struct RoutineCall : Statement
	{
		vsp<Expression> args;
		RoutineCall(const string& ident)
		{
			name = ident;
		}
	};
	struct BuiltinType : Type
	{
		variant<long long int, double, bool> iValue, rValue, bValue;
		BuiltinType(const string& otherName) : Type(otherName)
		{
			name = otherName;
		}
	};
	struct Record : Type
	{
		vsp<Variable> fields;

		Record(const string& Name, vsp<Variable>& Fields) : Type(Name)
		{
			fields = move(Fields);
		}
	};

	struct Alias : Type
	{
		sp<Type> type; // the original one. "name" is already inherited
	};

	struct Array : Type
	{
		int size = 0;
		sp<Type> type;
		Array(const std::string& name) :
			Type(name){}
	};

	void dfs();
	void printVariable(sp<Variable> var);
}

