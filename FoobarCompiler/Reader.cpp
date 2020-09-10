//
// Created by ziadx on 10/09/2020.
//

#include "Reader.h"

void Reader::set_file(std::string filename)
{
    std::ifstream f(filename); //taking file as inputstream
    if (f) {
        std::ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();
    }
    size = file.size();
}

char Reader::next_character()
{
    ptr++;
    if (ptr == size)
        return EOF;
    else
        return file[ptr];
}
