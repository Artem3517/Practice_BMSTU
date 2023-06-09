#include <iostream>

#include "number.hpp"

using std::cout;

int main(int argc, char** argv) {
    if (argc == 1) {
        fprintf(stderr, "Error: the first term is not set\n");
        return 1;
    }
    int pow = num_sys(argv[1]);
    if (pow == -1) {
        fprintf(stderr, "Error: incorrect assignment of the first term\n");
        return -1;
    }
    Number Num1(pow), Num2(pow);
    set_start(Num1, argv[1]);
    Num1.str_to_int();
    Num2.set_numstr(Num1.reverse());
    Num2.str_to_int();
    unsigned int summ = 0;
    int count = 1;
    cout << "First term = " << Num1.get_numstr() << "\tNumber system = " << pow << "\n\n";
    while (Num1.get_num() != Num2.get_num()) {
        cout << count << ") " << Num1.get_numstr() << " + " << Num2.get_numstr() << " = ";
        summ = Num1.get_num() + Num2.get_num();
        Num1.set_num(summ);
        Num1.int_to_str();
        cout << Num1.get_numstr() << '\n';
        Num2.set_numstr(Num1.reverse());
        Num2.str_to_int();
        count++;
    }
    cout << "\nReceived palindrome = " << Num1.get_numstr() << '\n';
    return 0;
}