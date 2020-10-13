foobar: Scanner.cpp parser.ypp
	bison -d parser.ypp
	g++ -std=c++17 -o foobar parser.tab.cpp Scanner.cpp Reader.cpp Foobar.cpp AST.cpp
