#pragma once

#include<map>
#include<string>
#include<vector>

class Scanner
{
public:
	Scanner(const char* tokensFilePath = "tokens.txt");
	~Scanner();
	void readSource(const char* sourceFilePath);
	bool isletter(char c);
private:
	void processToken(const std::string&& token);
	static std::map <std::string, std::string> dic;
	static std::map <std::string, unsigned int> tokenOrder;
	static std::vector<std::string> tokens;

};

