#include "divisible.hpp"

int main() {
    int error = 0;
    std::cout
        << "Данная программа демонстрирует применение признаков делимости натуральных чисел. Для примера "
           "введенное число будет поочередно проверено на кратность первым 15 простым числам (от 2 до 47)\n"
        << std::endl;
    DivisibleNumber Divisible;
    std::cout << "Введите число, которое будет проверено на делимость" << std::endl;
    if (Divisible.getInput()) {
        error = 1;
    }
    if (!error) {
        Divisible.setCount(15);
        SimpleDivider Div;
        Div.setFunc();
        Divisible.checkDivisibility(Div.getDividers());
        SimpleDivider &div_ref = Div;
        if (!Divisible.callSigns(div_ref)) {
            std::cout << "Число " << Divisible.getNum()
                      << " не кратно ни одному из простых чисел в заданном диапазоне" << std::endl;
        }
    }
    return error;
}