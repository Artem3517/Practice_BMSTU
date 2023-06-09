#pragma once

#include <cmath>
#include <iostream>

#define toDigit(c) (c - '0')

class NaturalNumber {
   protected:
    long number;

   public:
    int getInput(int flag);
    int checkInt(std::string str_num);
    int parseStr(std::string str_num);
    void setNum(const long num) { number = num; };
    long getNum() { return number; };
};