// Быстрая сортировка, задача 4: список группы по алфавиту через qsort.

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "console.h"

// qsort передаёт в функцию сравнения указатели на элементы массива.
// Элемент у нас const char*, значит приходит указатель на const char*.
int compareNames(const void* left, const void* right) {
    const char* a = *static_cast<const char* const*>(left);
    const char* b = *static_cast<const char* const*>(right);
    return std::strcmp(a, b);
}

int main() {
    setupConsole();

    // strcmp сравнивает байты. Для русских букв в UTF-8 порядок байтов
    // совпадает с алфавитом, кроме ё, поэтому в списке её нет.
    const char* students[] = {
        "Смирнова Анна",
        "Иванов Павел",
        "Кузнецов Дмитрий",
        "Александрова Мария",
        "Попов Игорь",
        "Васильева Ольга",
        "Морозов Никита",
        "Новикова Елена",
        "Иванова Дарья",
        "Захаров Кирилл",
    };
    const int COUNT = sizeof(students) / sizeof(students[0]);

    std::qsort(students, COUNT, sizeof(students[0]), compareNames);

    for (int i = 0; i < COUNT; i++) {
        std::cout << i + 1 << ". " << students[i] << "\n";
    }
    return 0;
}
