#include "divider.hpp"

void SimpleDivider::setFunc() {
    division_func[0] = &SimpleDivider::div2;
    division_func[1] = &SimpleDivider::div3;
    division_func[2] = &SimpleDivider::div5;
    division_func[3] = &SimpleDivider::div7;
    division_func[4] = &SimpleDivider::div11;
    division_func[5] = &SimpleDivider::div13;
    division_func[6] = &SimpleDivider::div17;
    division_func[7] = &SimpleDivider::div19;
    division_func[8] = &SimpleDivider::div23;
    division_func[9] = &SimpleDivider::div29;
    division_func[10] = &SimpleDivider::div31;
    division_func[11] = &SimpleDivider::div37;
    division_func[12] = &SimpleDivider::div41;
    division_func[13] = &SimpleDivider::div43;
    division_func[14] = &SimpleDivider::div47;
}

long SimpleDivider::callDivision(int i, long num) { return (this->*division_func[i])(num); }

int digitSum(long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

long SimpleDivider::div2(long num) {
    std::cout << "Число кратно 2, так как последняя цифра " << num % 10 << " - четная" << std::endl;
    std::cout << num << " / 2 = " << num / 2 << std::endl;
    return num / 2;
}

long SimpleDivider::div3(long num) {
    std::cout << "Число кратно 3, так как сумма цифр кратна 3" << std::endl;
    std::cout << digitSum(num) << " / 3 = " << digitSum(num) / 3 << std::endl;
    std::cout << num << " / 3 = " << num / 3 << std::endl;
    return num / 3;
}

long SimpleDivider::div5(long num) {
    std::cout << "Число кратно 5, так как последняя цифра " << num % 10 << std::endl;
    std::cout << num << " / 5 = " << num / 5 << std::endl;
    return num / 5;
}

long SimpleDivider::div7(long num) {
    std::cout << "Число кратно 7, так как сумма утроенного числа десятков и единиц кратна 7" << std::endl;
    std::cout << "(3 * " << num / 10 << " + " << num % 10 << ") / 7 = " << (3 * num / 10 + num % 10) / 7
              << std::endl;
    std::cout << num << " / 7 = " << num / 7 << std::endl;
    return num / 7;
}

long SimpleDivider::div11(long num) {
    std::cout << "Число кратно 11, так как модуль разности сумм четных и нечетных разрядов кратен 11"
              << std::endl;
    int sum1 = 0;
    int sum2 = 0;
    long tmp = num;
    int i = 0;
    while (tmp > 0) {
        if (i % 2 == 0) {
            sum1 += tmp % 10;
        } else {
            sum2 += tmp % 10;
        }
        tmp /= 10;
        i++;
    }
    std::cout << '|' << sum1 << " - " << sum2 << "| / 11 = " << std::abs(sum1 - sum2) / 11 << std::endl;
    std::cout << num << " / 11 = " << num / 11 << std::endl;
    return num / 11;
}

long SimpleDivider::div13(long num) {
    std::cout << "Число кратно 13, так как сумма числа десятков и учетверенного числа единиц кратна 13"
              << std::endl;
    std::cout << '(' << num / 10 << " + 4 * " << num % 10 << ") / 13 = " << (num / 10 + 4 * num % 10) / 13
              << std::endl;
    std::cout << num << " / 13 = " << num / 13 << std::endl;
    return num / 13;
}

long SimpleDivider::div17(long num) {
    std::cout
        << "Число кратно 17, так как модуль разности числа десятков и пятикратного числа единиц кратен 17"
        << std::endl;
    std::cout << '|' << num / 10 << " - 5 * " << num % 10
              << "| / 17 = " << std::abs(num / 10 - 5 * num % 10) / 17 << std::endl;
    std::cout << num << " / 17 = " << num / 17 << std::endl;
    return num / 17;
}

long SimpleDivider::div19(long num) {
    std::cout << "Число кратно 19, так как сумма числа десятков и удвоенного числа единиц кратна 19"
              << std::endl;
    std::cout << '(' << num / 10 << " + 2 * " << num % 10 << ") / 19 = " << (num / 10 + 2 * num % 10) / 19
              << std::endl;
    std::cout << num << " / 19 = " << num / 19 << std::endl;
    return num / 19;
}

long SimpleDivider::div23(long num) {
    std::cout << "Число кратно 23, так как сумма числа сотен и удвоенного числа, образованного последними 2 "
                 "цифрами, кратна 23"
              << std::endl;
    long tmp = num / 10;
    std::cout << '(' << num / 100 << " + 2 * " << num % 10 + tmp % 10 * 10
              << ") / 23 = " << (num / 100 + 2 * num % 10 + tmp % 10 * 10) / 23 << std::endl;
    std::cout << num << " / 23 = " << num / 23 << std::endl;
    return num / 23;
}

long SimpleDivider::div29(long num) {
    std::cout << "Число кратно 29, так как сумма числа десятков и утроенного числа единиц кратна 29"
              << std::endl;
    std::cout << '(' << num / 10 << " + 3 * " << num % 10 << ") / 29 = " << (num / 10 + 3 * num % 10) / 29
              << std::endl;
    std::cout << num << " / 29 = " << num / 29 << std::endl;
    return num / 29;
}

long SimpleDivider::div31(long num) {
    std::cout << "Число кратно 31, так как модуль разности числа десятков и утроенного числа единиц кратен 31"
              << std::endl;
    std::cout << '|' << num / 10 << " - 3 * " << num % 10
              << "| / 31 = " << std::abs(num / 10 - 3 * num % 10) / 31 << std::endl;
    std::cout << num << " / 31 = " << num / 31 << std::endl;
    return num / 31;
}

long SimpleDivider::div37(long num) {
    std::cout
        << "Число кратно 37, так как при разбиении числа на группы по 3 цифры сумма этих групп кратна 37"
        << std::endl;
    int triple[10] = {};
    long tmp = num;
    int i = 1;
    triple[0] = tmp % 1000;
    tmp /= 1000;
    int sum = triple[0];
    std::cout << triple[0];
    while (tmp > 0) {
        triple[i] = tmp % 1000;
        std::cout << " + " << triple[i];
        tmp /= 1000;
        sum += triple[i];
        i++;
    }
    std::cout << " = " << sum << '\t' << sum << " / 37 = " << sum / 37 << std::endl;
    std::cout << num << " / 37 = " << num / 37 << std::endl;
    return num / 37;
}

long SimpleDivider::div41(long num) {
    std::cout
        << "Число кратно 41, так как модуль разности числа десятков и четырехкратного числа единиц кратен 41"
        << std::endl;
    std::cout << '|' << num / 10 << " - 4 * " << num % 10
              << "| / 41 = " << std::abs(num / 10 - 4 * num % 10) / 41 << std::endl;
    std::cout << num << " / 41 = " << num / 41 << std::endl;
    return num / 41;
}

long SimpleDivider::div43(long num) {
    std::cout << "Число кратно 41, так как сумма числа десятков и числа единиц, умноженного на 13, кратен 43"
              << std::endl;
    std::cout << '(' << num / 10 << " + 13 * " << num % 10 << ") / 43 = " << (num / 10 + 13 * num % 10) / 43
              << std::endl;
    std::cout << num << " / 43 = " << num / 43 << std::endl;
    return num / 43;
}

long SimpleDivider::div47(long num) {
    std::cout << "Число кратно 47, как как модуль разности числа десятков и числа единиц, умноженного на 14, "
                 "кратен 47"
              << std::endl;
    std::cout << '|' << num / 10 << " - 14 * " << num % 10
              << "| / 47 = " << std::abs(num / 10 - 14 * num % 10) / 47 << std::endl;
    std::cout << num << " / 47 = " << num / 47 << std::endl;
    return num / 47;
}