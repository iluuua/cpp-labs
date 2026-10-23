// Лаба 2, задание 1: ввод с клавиатуры, if и switch.

#include <iostream>
#include "console.h"

int main() {
    setupConsole();

    double first = 0;
    double second = 0;
    std::cout << "Введите первое число: ";
    std::cin >> first;
    std::cout << "Введите второе число: ";
    std::cin >> second;
    if (!std::cin) {
        std::cout << "Нужно было ввести числа\n";
        return 1;
    }

    std::cout << "Среднее арифметическое: " << (first + second) / 2 << "\n";

    char operation = ' ';
    std::cout << "Введите знак операции (+, -, * или /): ";
    std::cin >> operation;

    /*
    Первая версия, на if. По заданию её нужно закомментировать
    и переписать через switch, что и сделано ниже.

    if (operation == '+') {
        std::cout << first << " + " << second << " = " << first + second << "\n";
    } else if (operation == '-') {
        std::cout << first << " - " << second << " = " << first - second << "\n";
    } else if (operation == '*') {
        std::cout << first << " * " << second << " = " << first * second << "\n";
    } else if (operation == '/') {
        if (second == 0) {
            std::cout << "На ноль делить нельзя\n";
        } else {
            std::cout << first << " / " << second << " = " << first / second << "\n";
        }
    } else {
        std::cout << "Не знаю операцию " << operation << "\n";
    }
    */

    switch (operation) {
    case '+':
        std::cout << first << " + " << second << " = " << first + second << "\n";
        break;
    case '-':
        std::cout << first << " - " << second << " = " << first - second << "\n";
        break;
    case '*':
        std::cout << first << " * " << second << " = " << first * second << "\n";
        break;
    case '/':
        if (second == 0) {
            std::cout << "На ноль делить нельзя\n";
        } else {
            std::cout << first << " / " << second << " = " << first / second << "\n";
        }
        break;
    default:
        std::cout << "Не знаю операцию " << operation << "\n";
    }

    return 0;
}
