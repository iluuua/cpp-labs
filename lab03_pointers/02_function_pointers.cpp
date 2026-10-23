// Лаба 3, задание 2: массив в функцию через пару указателей,
// функция, которая возвращает указатель на функцию, и new/delete.

#include <iostream>
#include <iterator>
#include "console.h"

// end указывает на место сразу за последним элементом, как std::end.
int sum(const int* begin, const int* end) {
    int total = 0;
    for (const int* p = begin; p != end; p++) {
        total += *p;
    }
    return total;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// Тип «указатель на функцию, которая принимает два int и возвращает int».
// Без этого псевдонима объявление ниже выглядело бы так:
//     int (*chooseOperation(char sign))(int, int)
using Operation = int (*)(int, int);

// Для '+' и '-' возвращает нужную функцию, для остальных символов nullptr.
Operation chooseOperation(char sign) {
    if (sign == '+') {
        return add;
    }
    if (sign == '-') {
        return subtract;
    }
    return nullptr;
}

int main() {
    setupConsole();

    int numbers[] = {4, 8, 15, 16, 23, 42};
    std::cout << "Сумма массива: " << sum(std::begin(numbers), std::end(numbers)) << "\n";

    Operation plus = chooseOperation('+');
    std::cout << "10 + 3 = " << plus(10, 3) << "\n";

    Operation minus = chooseOperation('-');
    std::cout << "10 - 3 = " << minus(10, 3) << "\n";

    if (chooseOperation('*') == nullptr) {
        std::cout << "Для '*' функции нет\n";
    }

    float* temperature = new float(36.6f);
    std::cout << "Адрес: " << temperature << ", значение: " << *temperature << "\n";
    delete temperature;  // память из new сама не освободится

    return 0;
}
