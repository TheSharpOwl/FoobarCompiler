cmake_minimum_required(VERSION 3.17)
project(FoobarCompiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(FoobarCompiler main.cpp Scanner.cpp Scanner.h Reader.cpp Reader.h)