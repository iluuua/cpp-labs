// Лаба 6, задание 1: число словами и исключение на неправильный ввод.

#include <iostream>
#include <stdexcept>
#include "console.h"

int main() {
    setupConsole();

    std::cout << "Введите число 1, 2 или 3: ";
    int number = 0;
    std::cin >> number;  // если ввести не число, number останется 0

    try {
        switch (number) {
        case 1:
            std::cout << "Один\n";
            break;
        case 2:
            std::cout << "Два\n";
            break;
        case 3:
            std::cout << "Три\n";
            break;
        default:
            throw std::invalid_argument("ожидалось 1, 2 или 3");
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Некорректное значение\n";
    }

    return 0;
}
