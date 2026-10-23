// Рекурсия, задача 1: вывести числа от 1 до n. Без циклов и массивов.

#include <iostream>
#include "console.h"

// Сначала спускаемся до нуля, а печатаем на обратном пути,
// поэтому числа выходят по возрастанию.
void printUpTo(int n) {
    if (n < 1) {
        return;
    }
    printUpTo(n - 1);
    std::cout << n << ' ';
}

int main() {
    setupConsole();

    std::cout << "Введите натуральное n: ";
    int n = 0;
    std::cin >> n;

    printUpTo(n);
    std::cout << "\n";
    return 0;
}
