// Лаба 3, задание 1: указатели, обход массива указателем, константный указатель.

#include <iostream>
#include "console.h"

int main() {
    setupConsole();

    int score = 42;
    int* pointer = &score;
    std::cout << "Адрес: " << pointer << ", значение по адресу: " << *pointer << "\n";

    // Пишем через указатель. Он смотрит на ту же ячейку памяти,
    // что и score, поэтому score тоже станет 100.
    *pointer = 100;
    std::cout << "score после *pointer = 100: " << score << "\n";

    double prices[] = {99.9, 149.5, 20.75, 5.25};
    const int COUNT = sizeof(prices) / sizeof(prices[0]);
    std::cout << "Массив через указатель:";
    for (double* p = prices; p < prices + COUNT; p++) {
        std::cout << " " << *p;
    }
    std::cout << "\n";

    int five = 5;
    // const после звёздочки: адрес в указателе поменять нельзя,
    // а значение по этому адресу можно.
    int* const fixed = &five;
    // fixed = &score;  // ошибка компиляции: fixed объявлен как int* const
    *fixed = 55;
    std::cout << "five после *fixed = 55: " << five << "\n";

    return 0;
}
