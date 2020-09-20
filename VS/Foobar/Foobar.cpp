// Foobar.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Scanner.h"
class Reader;

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
