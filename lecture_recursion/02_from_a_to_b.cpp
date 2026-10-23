// Рекурсия, задача 2: вывести числа от A до B включительно.
// Если A < B, по возрастанию, иначе по убыванию.

#include <iostream>
#include "console.h"

void printRange(int from, int to) {
    std::cout << from << ' ';
    if (from == to) {
        return;
    }
    printRange(from < to ? from + 1 : from - 1, to);
}

int main() {
    setupConsole();

    int a = 0;
    int b = 0;
    std::cin >> a >> b;

    printRange(a, b);
    std::cout << "\n";
    return 0;
}
