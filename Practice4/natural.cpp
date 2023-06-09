#include "natural.hpp"

int NaturalNumber::checkInt(std::string str_num) {
    for (size_t i = 0; i < str_num.length(); i++) {
        if (!isdigit(str_num[i])) {
            return 0;
        }
    }
    return 1;
}

int NaturalNumber::parseStr(std::string str_num) {
    int result = 0;
    for (int i = 0; i < (int)str_num.length(); i++) {
        result += toDigit(str_num[i]) * std::pow(10, str_num.length() - (i + 1));
    }
    return result;
}

int NaturalNumber::getInput() {
    std::string str_num;
    long num = 0;
    int input = 1;
    while (std::cin && input) {
        std::cout << "Натуральное число: ";
        std::cin >> str_num;
        if (!checkInt(str_num) || (num = parseStr(str_num)) < 1) {
            std::cout << "Ошибка: " << str_num << " - не натуральное число" << std::endl;
        } else {
            input = 0;
            setNum(num);
        }
    }
    return input;
}