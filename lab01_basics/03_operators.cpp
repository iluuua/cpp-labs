// Лаба 1, задание 3: арифметика, побитовые и логические операции.

#include <iostream>
#include "console.h"

int main() {
    setupConsole();

    int a = 17;
    int b = 5;
    int c = 3;
    std::cout << "a + b + c = " << a + b + c << "\n";
    std::cout << "a - b - c = " << a - b - c << "\n";
    std::cout << "a * b * c = " << a * b * c << "\n";
    // Целые числа делятся нацело: 17 / 5 = 3, затем 3 / 3 = 1.
    // Чтобы получить дробь, одно из чисел нужно сделать вещественным.
    std::cout << "a / b / c = " << a / b / c << "\n";
    std::cout << "a / b / c (вещественное) = " << static_cast<double>(a) / b / c << "\n";
    std::cout << "a % b = " << a % b << "\n";

    // Посчитал заранее: 100 / 20 = 5, 145 - 5 = 140, 140 / 20 = 7, 7 * 50 = 350, 350 + 45 = 395.
    int expression = (((145 - 100 / 20) / 20) * 50) + 45;
    std::cout << "expression = " << expression << "\n";

    // 3 = 011, 7 = 111 в двоичной записи.
    int x = 3;
    int y = 7;
    int andResult = x & y;      // 011 = 3
    int orResult = x | y;       // 111 = 7
    int xorResult = x ^ y;      // 100 = 4
    int notX = ~x;              // все биты наоборот, получается -4
    int xShiftRight = x >> 1;   // 001 = 1, то же что деление на 2
    int xShiftLeft = x << 1;    // 110 = 6, то же что умножение на 2
    std::cout << "andResult = " << andResult << "\n";
    std::cout << "orResult = " << orResult << "\n";
    std::cout << "xorResult = " << xorResult << "\n";
    std::cout << "notX = " << notX << "\n";
    std::cout << "xShiftRight = " << xShiftRight << "\n";
    std::cout << "xShiftLeft = " << xShiftLeft << "\n";

    bool yes = true;
    bool no = false;
    // Изнутри наружу: (yes && yes) || no = true; yes != no = true, поэтому
    // no || true = true. Дальше одни && с true, итог true, то есть 1.
    // != выполняется раньше ||, так что скобки вокруг него не нужны.
    bool combined = yes && (yes && ((yes && yes) || no) && (no || yes != no));
    std::cout << "combined = " << combined << "\n";

    // 23 > 18 уже истина, поэтому всё после || можно не считать.
    // 25 < 48 тоже истина, итог 1.
    bool guess = 25 < 48 && (23 > (3 + 15) || (2 < 8 && (5 >= 2 && 15 < 15)));
    std::cout << "guess = " << guess << "\n";

    return 0;
}
