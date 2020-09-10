#include <iostream>

#include "Scanner.h"
#include<cstring>

int main()
{
	Scanner lexer;
	std::string filename;
	std::cin >> filename;
	lexer.set_file(filename);
	const char* TOKEN = lexer.get_next_token();
	while (strcmp(TOKEN, "EOF") != 0)
	{
		printf("%s", TOKEN);
		TOKEN = lexer.get_next_token();
	}
    return 0;
}
