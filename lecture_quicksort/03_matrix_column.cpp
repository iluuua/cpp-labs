// Быстрая сортировка, задача 3: отсортировать по возрастанию первый столбец
// двумерного массива из случайных чисел от 5 до 61.
// Сортируется только первый столбец, остальные элементы остаются на местах.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "console.h"
#include "quick_sort.h"
#include "random_int.h"

const int ROWS = 8;
const int COLS = 5;

void printMatrix(const int matrix[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            std::cout << std::setw(4) << matrix[row][col];
        }
        std::cout << "\n";
    }
}

int main() {
    setupConsole();

    int matrix[ROWS][COLS];
    for (auto& row : matrix) {
        for (int& value : row) {
            value = randomInt(5, 61);
        }
    }

    std::cout << "До:\n";
    printMatrix(matrix);

    // Элементы столбца в памяти лежат не подряд, поэтому копируем столбец
    // во временный массив, сортируем его и записываем обратно.
    int column[ROWS];
    for (int row = 0; row < ROWS; row++) {
        column[row] = matrix[row][0];
    }
    quickSort(column, 0, ROWS - 1);
    for (int row = 0; row < ROWS; row++) {
        matrix[row][0] = column[row];
    }

    std::cout << "\nПосле:\n";
    printMatrix(matrix);

    bool sorted = std::is_sorted(column, column + ROWS);
    std::cout << "Первый столбец отсортирован: " << (sorted ? "да" : "нет") << "\n";
    return 0;
}
