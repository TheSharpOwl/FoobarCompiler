FROM gcc:9
COPY lexer.cpp /usr/src/lexer/
COPY examples /usr/src/lexer/examples/
COPY test_script.sh /usr/src/lexer/.
COPY examples/correct_tokens/ /usr/src/lexer/examples/.
WORKDIR /usr/src/lexer/
RUN g++ -std=c++17 lexer.cpp
CMD ["./test_script.sh"]
