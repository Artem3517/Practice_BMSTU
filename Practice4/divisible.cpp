#include "divisible.hpp"

void DivisibleNumber::setCount(const int cnt) {
    count = cnt;
    div_mask = new int[count];
    for (int i = 0; i < count; i++) {
        div_mask[i] = 0;
    }
}

void DivisibleNumber::checkDivisibility(int *dividers) {
    for (int i = 0; i < count; i++) {
        if (number % dividers[i] == 0) {
            div_mask[i] = 1;
        }
    }
}

int DivisibleNumber::callSigns(SimpleDivider &div) {
    int cnt = 0;
    for (int i = 0; i < count; i++) {
        if (div_mask[i]) {
            cnt++;
            putchar('\n');
            div.callDivision(i, number);
        }
    }
    return cnt;
}

DivisibleNumber::~DivisibleNumber() { delete[] div_mask; }