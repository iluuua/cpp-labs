// Рекурсия, задача 4: простые делители числа n > 1 по возрастанию за O(√n).
// Повторяющиеся делители печатаются столько раз, сколько входят в число:
// для 12 получится 2 2 3.

#include <iostream>
#include "console.h"

// Пробуем делители по порядку. Если divisor * divisor > n, значит у n не
// осталось делителей до корня, и оно либо 1, либо само простое. Поэтому
// перебор идёт только до √n. После двойки проверяем одни нечётные числа.
void printPrimeFactors(long long n, long long divisor) {
    if (divisor * divisor > n) {
        if (n > 1) {
            std::cout << n << ' ';
        }
        return;
    }
    if (n % divisor == 0) {
        std::cout << divisor << ' ';
        printPrimeFactors(n / divisor, divisor);
    } else {
        printPrimeFactors(n, divisor == 2 ? 3 : divisor + 2);
    }
}

int main() {
    setupConsole();

    std::cout << "Введите натуральное n > 1: ";
    long long n = 0;
    std::cin >> n;
    if (n < 2) {
        std::cout << "Нужно число больше 1\n";
        return 1;
    }

    printPrimeFactors(n, 2);
    std::cout << "\n";
    return 0;
}
