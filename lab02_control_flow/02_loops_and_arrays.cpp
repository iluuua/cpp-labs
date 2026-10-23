// Лаба 2, задание 2: циклы и одномерные массивы.

#include <iostream>
#include <limits>
#include "console.h"

int main() {
    setupConsole();

    // Спрашиваем, пока не введут положительное число.
    int n = 0;
    while (true) {
        std::cout << "Введите целое положительное число: ";
        if (std::cin >> n && n > 0) {
            break;
        }
        if (std::cin.eof()) {
            std::cout << "\nВвод закончился, а числа так и не было\n";
            return 1;
        }
        if (!std::cin) {
            // Ввели не число. Сбрасываем ошибку потока и выкидываем остаток
            // строки, иначе cin так и будет спотыкаться о те же символы.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Печатаем как в примере из задания: 1 + 2 + 3 + 4 = 10
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        std::cout << i << (i < n ? " + " : " = ");
    }
    std::cout << sum << "\n";

    const int SIZE = 10;
    int numbers[SIZE] = {12, 7, 3, 25, 8, 14, 1, 30, 6, 19};

    for (int i = 0; i < SIZE; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    std::cout << "На чётных позициях: ";
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            std::cout << numbers[i] << " ";
        }
    }
    std::cout << "\n";

    int oddSum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 != 0) {
            oddSum += numbers[i];
        }
    }
    std::cout << "Сумма на нечётных позициях: " << oddSum << "\n";

    return 0;
}
