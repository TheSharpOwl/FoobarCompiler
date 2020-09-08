# part of the makefile
all: lexer.cpp parser.y
    	bison -d parser.y
	   	cc -o $@ fb1-5.tab.c lex.yy.c -lfl

#.DEFAULT_GOAL := generate
#.PHONY: all say_hello generate clean
#all : say_hello generate
#
#say_hello:
#		@echo "Hello World"
#
#generate:
#		@echo "Creating empty text files..."
#		touch file-{1..10}.txt
#
#clean:
#	@echo "Cleaning up..."
#	rm *.txt 
