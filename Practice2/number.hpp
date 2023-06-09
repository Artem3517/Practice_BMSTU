#pragma once

#include <string>

class Number {
    int pow;
    unsigned int num = 0;
    std::string numstr;
public:
    Number(int p) : pow(p) {};
    void str_to_int();
    void int_to_str();
    std::string reverse();
    void set_numstr(std::string str) { numstr = str; };
    std::string get_numstr() const { return numstr; };
    void set_num(unsigned int n) { num = n; };
    unsigned int get_num() const { return num; };
    friend void set_start(Number& Num, char* str);
};

int num_sys(char* num);