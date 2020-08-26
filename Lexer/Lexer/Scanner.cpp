#include "Scanner.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::map <std::string, std::string> Scanner::dic = std::map <std::string, std::string>();
std::map <std::string, unsigned int> Scanner::tokenOrder = std::map<std::string, unsigned int>();
std::vector<std::string> Scanner::tokens = std::vector<std::string>();

Scanner::Scanner(const char* tokensFilePath)
{
	std::string symbol, name;
	std::ifstream fstream(tokensFilePath);
	unsigned int n = 1;
	if (!fstream)
	{
		std::cout << "Error reading the tokens file\n";
		exit(-1);
	}
	while (fstream >> symbol >> name)
	{
		dic[symbol] = name;
		tokenOrder[name] = n++;
	}
}
Scanner::~Scanner()
{

}
void Scanner::readSource(const char* sourceFilePath)
{
	std::string line, word;
	std::ifstream fstream(sourceFilePath);
	if (!fstream)
	{
		std::cout << "ERROR READING THE FILE!\n";
		exit(-1);
	}

	while (std::getline(fstream, line))
	{
		std::istringstream sstream(line);
		while (sstream >> word)
		{
			// if it is a keyword
			if (dic.find(word) != dic.end())
			{
				tokens.push_back(dic[word]);
				tokens.push_back("SPACE");
				continue;
			}
			else
			{
				std::string temp = word;
				// now we have to know if it's a number or something else
				processToken(std::move(temp));
				tokens.push_back("SPACE");
			}
		}
		// delete the last space because it shouldn't be there
		tokens.pop_back();
		tokens.push_back("NEWLINE");
	}
}

void Scanner::processToken(const std::string&& token)
{
	if (token.empty())
		return;
	int i = 0;
	// IDENTIFER
	if (isletter(token[0]))
	{
		while (isletter(token[i]) || isdigit(token[i]))
			i++;
		tokens.push_back("IDENTIFIER");
	}
	else if (isdigit(token[0]))
	{
		while (isdigit(token[i]))
			i++;
		tokens.push_back("NUMBER");
	}
	else
	{
		while (!isdigit(token[i]) && !isletter(token[i]))
			i++;
		std::string temp = token.substr(0, i);
		if (dic.find(temp) != dic.end())
			tokens.push_back(dic[temp]);
		else
			tokens.push_back("UNKNOWN");
	}
	processToken(token.substr(i, token.size() - i));
}
bool Scanner::isletter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}