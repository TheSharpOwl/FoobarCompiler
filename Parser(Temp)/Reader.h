#pragma once

#include<string>

class Reader {
public:
    std::string file;
    int size = 0;
    int ptr = -1;

    void set_file(std::string filename);

    char next_character();

    void move_back_ptr(){ ptr--; }

    char current_character() { return file[ptr];}
};