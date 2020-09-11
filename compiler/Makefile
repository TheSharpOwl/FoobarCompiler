# part of the makefile
foobar: Scanner.cpp parser.ypp
	bison -d parser.ypp
	g++ -o foobar parser.tab.cpp Scanner.cpp Reader.cpp
