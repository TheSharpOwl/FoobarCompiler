# FoobarCompiler
Innopolis University Fall20 Complier Construction course project

## How to run? 

1. Put examples you want to test in examples folder.
```
docker build . -t lexer

docker run --rm lexer
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

