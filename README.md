# FoobarCompiler
Innopolis University Fall20 Complier Construction course project

## How to run? 
*Make sure that your bison version is 3.2 and higher*
1. Put example you want to check in compiler folder
2. ```cd compiler
make
./foobar
```

parsed examples will be printed to stdout

## How to test?

1. Put examples you want to test in examples folder.
2. Put correct answers in examples/correct_tokens/ with .correct extension
```
docker build . -t lexer

docker run --rm lexer
```

result of each test will be printed to console

