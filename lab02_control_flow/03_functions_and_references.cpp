// Лаба 2, задание 3: двумерные массивы, ссылки, функции, область видимости.

#include <iostream>
#include <string>
#include "console.h"

// Сумма чисел от 1 до n. Для нуля и отрицательных чисел возвращает 0.
// Если вызвать без аргумента, n будет равно 1 и функция вернёт 1.
int sumUpTo(int n = 1) {
    if (n <= 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Первые два параметра передаются копией, последние два по ссылке:
// в них функция и записывает результат.
void sumAndProduct(int a, int b, int& sum, int& product) {
    sum = a + b;
    product = a * b;
}

int main() {
    setupConsole();

    const int ROWS = 2;
    const int COLS = 3;
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};

    int total = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            total += matrix[row][col];
        }
    }
    std::cout << "Сумма всех элементов: " << total << "\n";

    int columnSums[COLS] = {};  // пустые скобки заполняют массив нулями
    for (int col = 0; col < COLS; col++) {
        for (int row = 0; row < ROWS; row++) {
            columnSums[col] += matrix[row][col];
        }
    }
    std::cout << "Суммы по столбцам: ";
    for (int value : columnSums) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    // Обе ссылки это просто другие имена той же переменной.
    float price = 20.84f;
    float& firstRef = price;
    float& secondRef = price;
    firstRef = 99.5f;
    std::cout << "price = " << price << ", secondRef = " << secondRef << "\n";

    std::cout << "sumUpTo(5) = " << sumUpTo(5) << "\n";
    std::cout << "sumUpTo(-3) = " << sumUpTo(-3) << "\n";
    std::cout << "sumUpTo() = " << sumUpTo() << "\n";

    int sum = 0;
    int product = 0;
    sumAndProduct(4, 6, sum, product);
    std::cout << "После sumAndProduct(4, 6): sum = " << sum << ", product = " << product << "\n";

    std::string greeting = "Привет";
    std::cout << greeting << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << greeting << "\n";
        int insideLoop = 42;
        std::cout << insideLoop << "\n";
    }
    // std::cout << insideLoop;  // ошибка компиляции: insideLoop существует только внутри цикла

    return 0;
}
