#pragma once

#include "divider.hpp"
#include "natural.hpp"

class DivisibleNumber : public NaturalNumber {
    int count;
    int *div_mask;

   public:
    void setCount(const int cnt);
    void checkDivisibility(int *dividers);
    int callSigns(SimpleDivider &div);
    ~DivisibleNumber();
};