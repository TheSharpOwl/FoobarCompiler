#include<string>
#include<memory>
#include<vector>

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
    struct Type : Node
    {

		Type(std::shared_ptr <Node> node)
		{
			name = node->name;
			start = node->start;
			end = node->end;
		}
		Type() = default;
		Type(Type&&) = default;
		Type(Type&) = default;
		Type& operator= (const Type& other) = default;
		Type& operator= (Type&&) = default;
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
		Variable(Variable&& ) = default;
		Variable(Variable&) = default;
		Variable& operator= (const Variable&) = default;
		Variable& operator= (Variable&& ) = default;
	};
}