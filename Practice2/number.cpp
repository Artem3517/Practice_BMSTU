#include "number.hpp"

#include <iostream>
#include <cstring>
#include <cmath>

using std::string;

void Number::str_to_int() {
    int digit = 0;
    int n = numstr.length();
    num = 0;
    for (int i = 0; i < n; i++) {
        if (numstr[i] >= '0' || numstr[i] <= '9')
            digit = numstr[i] - '0';
        switch (numstr[i]) {
            case 'A': digit = 10; break;
            case 'B': digit = 11; break;
            case 'C': digit = 12; break;
            case 'D': digit = 13; break;
            case 'E': digit = 14; break;
            case 'F': digit = 15; break;
            default: break;
        }
        num += digit * std::pow(pow, n-i-1);
    }
}

void Number::int_to_str() {
    int n = 0;
    unsigned int temp = num;
    while(temp > 0) {
        temp /= pow;
        n++;
    }
    int* digits = new int[n];
    temp = num;
    for(int i = 0; i < n; i++) {
        digits[i] = temp % pow;
        temp /= pow;
    }
    char c = 0;
    numstr.clear();
    for (int i = 0; i < n; i++) {
        if (digits[n-i-1] >= 0 && digits[n-i-1] <= 9) {
            c = '0' + digits[n-i-1];
        }
        switch (digits[n-i-1]) {
            case 10: c = 'A'; break;
            case 11: c = 'B'; break;
            case 12: c = 'C'; break;
            case 13: c = 'D'; break;
            case 14: c = 'E'; break;
            case 15: c = 'F'; break;
            default: break;
        }
        numstr.append(1, c);
    }
    delete[] digits;
}

string Number::reverse() {
    int len = numstr.length();
    string rstr;
    for (int i = len-1; i >= 0; i--) {
        rstr.append(1, numstr[i]);
    }
    int count = 0;
    while (rstr[count] == '0') {
        count++;
    }
    if (count) {
        rstr.erase(0, count);
    }
    return rstr;
}

void set_start(Number& Num, char* str) {
    int len = strlen(str);
    int n = 0;
    switch (Num.pow) {
        case 16: 
            n = len - 2;
            break;
        case 8: 
            n = len - 1; 
            break;
        default: 
            n = len; 
            break;
    }
    for(int i = len - n; i < len; i++) {
        Num.numstr.append(1, str[i]);
    }
}

int num_sys(char* num) {
    int n = strlen(num);
    if (n > 2 && num[0] == '0' && (num[1] == 'x' || num[1] == 'X')) {
        for (int i = 2; i < n; i++) {
            if (num[i] < '0' || num[i] > '9' && num[i] < 'A' || num[i] > 'F') {
                return -1;
            }
        }
        return 16;
    }
    if (n > 1 && num[0] == '0') {
        for (int i = 0; i < n; i++) {
            if (num[i] < '0' || num[i] > '7') {
                return -1;
            }
        }
        return 8;
    }
    for (int i = 0; i < n; i++) {
        if (num[i] < '0' || num[i] > '9') {
                return -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != '0' && num[i] != '1') {
            return 10;
        }
    }
    return 2;
}