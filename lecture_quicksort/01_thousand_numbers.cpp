// Быстрая сортировка, задача 1: упорядочить по возрастанию 1000 целых чисел.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "console.h"
#include "quick_sort.h"
#include "random_int.h"

int main() {
    setupConsole();

    const int SIZE = 1000;
    int numbers[SIZE];
    for (int& number : numbers) {
        number = randomInt(-10000, 10000);
    }

    quickSort(numbers, 0, SIZE - 1);

    // По 20 чисел в строке, чтобы вывод не растянулся на тысячу строк.
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::setw(7) << numbers[i];
        if (i % 20 == 19) {
            std::cout << "\n";
        }
    }

    bool sorted = std::is_sorted(numbers, numbers + SIZE);
    std::cout << "Отсортировано: " << (sorted ? "да" : "нет") << "\n";
    return 0;
}
