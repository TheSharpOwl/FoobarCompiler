#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstring>
#include <sstream>

class Reader {
public:
	std::string file;
	int size = 0;
	int ptr = -1;


	void set_file(std::string filename) {
		std::ifstream f(filename); //taking file as inputstream
		if (f) {
			std::ostringstream ss;
			ss << f.rdbuf(); // reading data
			file = ss.str();
		}
		size = file.size();
	};

	char next_character() {
		ptr++;
		if (ptr == size)
			return EOF;
		else
			return file[ptr];
	}

	void move_back_ptr() {
		ptr--;
	}

	char current_character() {
		return file[ptr];
	}


};

class Lexer {
	Reader reader;
	std::string buffer;
	char c;

	std::map< std::string, const char*> string_to_token = {
			{ ">", "GRT " },
			{ ">=", "GRTE " },
			{ "<", "LES " },
			{ "<=", "LESE " },
			{ "=", "EQ " },
			{ "/=", "NEQ " },
			{"/", "DIV "},
			{ "[", "LAR " },
			{ "]", "RAR " },
			{ "(", "LBR " },
			{ ")", "RBR " },
			{ "+", "ADD " },
			{ "-", "SUB " },
			{ "*", "MUL " },
			{ "%", "MOD " },
			{ ",", "COM " },
			{":", "SEMIC "},
			{":=", "ASN "},
			{"and", "AND" },
			{"or", "OR "},
			{"xor", "XOR "},
			{"if", "IF "},
			{"then", "THEN "},
			{"else", "ELSE "},
			{"true", "TRU "},
			{"false", "FLS "},
			{"var", "VAR "},
			{"type", "TKEY "},
			{"routine", "RUT "},
			{"return", "RTN "},
			{"is", "IS "},
			{"in", "IN "},
			{"reverse", "REV "},
			{"for", "FOR "},
			{"while", "WHL "},
			{"loop", "LOP "},
			{"end", "END "},
			{"record", "RCRD "},
			{"array", "ARR "},
			{"integer", "ITYPE "},
			{"real", "RTYPE "},
			{"boolean", "BTYPE "}
	};

	std::set<char> spaces = { ' ', '\t' };
	std::set<char> single_chars = { '[', ']', '(', ')', '=', '+', '-', '*', '%', ',' };
	std::set<char> possible_double_chars = { '>', '<', '/', ':' };  /* we can add = to the end */



public:
	void set_file(std::string filename) {
		reader.set_file(filename);
	}

	const char* get_next_token() {
		/* skip leading spaces */
		c = reader.next_character();
		while ((spaces.find(c) != spaces.end())) {
			c = reader.next_character();
		}
		if (c == '\n') {
			return "\n";
		}
		if (c == EOF) {
			return "EOF";
		}

		/* check if special character can be uniquely identified */
		bool is_in = single_chars.find(c) != single_chars.end();
		if (is_in) {
			std::string s(1, c);
			const char* return_val = string_to_token.find(s)->second;
			return return_val;
		}

		/* check for other special characters  */
		is_in = possible_double_chars.find(c) != possible_double_chars.end();
		if (is_in) {
			char next_c = reader.next_character();
			if (next_c == '=') {
				char arr[] = { c, next_c, '\0' };
				std::string str(arr);
				return string_to_token.find(str)->second;
			}
			else {
				reader.move_back_ptr();
				std::string s(1, c);
				return string_to_token.find(s)->second;
			}
		}

		/* check if number */
		if (c == '-' || (c >= '0' && c <= '9')) {
			/* fill digits in the buffer and then convert to number */
			bool is_real = false;
			do {
				buffer += c;
				c = reader.next_character();
				if (c == '.') {
					if (is_real) { /* second dot in number like 21.32. */
						return "ERR ";
					}
					char next_c = reader.next_character();
					reader.move_back_ptr();
					if (next_c == '.') { /* we found range .. like 12..50 case  */
						break;
					}
					else {
						is_real = true;
					}
				}
			} while (c == '.' || (c >= '0' && c <= '9'));
			reader.move_back_ptr();

			if (is_real) {
				// double number;
				// number = std::stod( buffer );
				buffer.clear();
				return "REAL ";
			}
			else {
				// int number;
				// number = std::stoi( buffer );
				buffer.clear();
				return "INTEGER ";
			}
		}

		/* If first character is the start of the identifier */
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
			do {
				buffer += c;
				c = reader.next_character();
			} while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_');
			reader.move_back_ptr();

			auto token_struct = string_to_token.find(buffer);
			buffer.clear();
			if (token_struct != string_to_token.end()) {
				return token_struct->second;
			}
			else {
				return "IDENTIFIER ";
			}
		}

		if (c == '.') {
			char next_c = reader.next_character();
			if (next_c == '.') {
				return "RNG ";
			}
			else {
				reader.move_back_ptr();
				return "DOTN ";
			}
		}

		printf("%d", c);
		return "UNKNOWN";
	};
};


int main() {
	Lexer lexer;
	std::string filename;
	std::cin >> filename;
	lexer.set_file(filename);
	const char* TOKEN = lexer.get_next_token();
	while (strcmp(TOKEN, "EOF") != 0) {
		printf("%s", TOKEN);
		TOKEN = lexer.get_next_token();
	}

	return 0;
}
