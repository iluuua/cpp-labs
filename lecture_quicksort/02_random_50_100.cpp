// Быстрая сортировка, задача 2: массив случайных чисел от 50 до 100.

#include <algorithm>
#include <iostream>
#include "console.h"
#include "quick_sort.h"
#include "random_int.h"

void printArray(const int* data, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    setupConsole();

    const int SIZE = 20;
    int numbers[SIZE];
    for (int& number : numbers) {
        number = randomInt(50, 100);
    }

    std::cout << "До:    ";
    printArray(numbers, SIZE);

    quickSort(numbers, 0, SIZE - 1);

    std::cout << "После: ";
    printArray(numbers, SIZE);

    bool sorted = std::is_sorted(numbers, numbers + SIZE);
    std::cout << "Отсортировано: " << (sorted ? "да" : "нет") << "\n";
    return 0;
}
