#pragma once

#include <iostream>

class SimpleDivider;

typedef long (SimpleDivider::*DivFunc)(long num);

class SimpleDivider {
    int dividers[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    DivFunc division_func[15];
    long div2(long num);
    long div3(long num);
    long div5(long num);
    long div7(long num);
    long div11(long num);
    long div13(long num);
    long div17(long num);
    long div19(long num);
    long div23(long num);
    long div29(long num);
    long div31(long num);
    long div37(long num);
    long div41(long num);
    long div43(long num);
    long div47(long num);

   public:
    void setFunc();
    long callDivision(int i, long num);
    friend int digitSum(long num);
    int *getDividers() { return dividers; };
};