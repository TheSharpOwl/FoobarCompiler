# FoobarCompiler
Innopolis University Fall20 Complier Construction course project

* ## Parsing Tree Structure :
Can be found [here](https://1drv.ms/u/s!Ah_ytVWf2LPJgelgGSWaCaRmKQ_3HA?e=g5RGcH)
except that Variable class inherits from Type (changed it while doing semantics)

* ## Requirements

    1. Visual Studio
    2. Bison 3.2 or newer
    3. C++17

* ## How to run:<br>

    1. Open VS folder

    2. To generate parser.tab.cpp and parser.tab.hpp, run the   command :
    ```
    bison -d parser.ypp
    ```
    3. Open VS, build and run the solution.

    4. Parsed example will be printed to stdout.
