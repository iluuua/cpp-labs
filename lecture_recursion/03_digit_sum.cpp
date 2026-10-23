// Рекурсия, задача 3: сумма цифр числа. Без строк, массивов и циклов.

#include <iostream>
#include "console.h"

// Последняя цифра плюс сумма цифр числа без неё.
long long digitSum(long long n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + digitSum(n / 10);
}

int main() {
    setupConsole();

    std::cout << "Введите натуральное N: ";
    long long n = 0;
    std::cin >> n;

    std::cout << "Сумма цифр: " << digitSum(n) << "\n";
    return 0;
}
