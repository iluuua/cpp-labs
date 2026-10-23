// Лаба 7, задание 3: длина окружности и заметки в текстовом файле.

// Без этого define в Visual Studio не будет константы M_PI.
// Он должен стоять до всех #include.
#define _USE_MATH_DEFINES

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "console.h"

int main() {
    setupConsole();

    std::cout << "Введите радиус окружности: ";
    double radius = 0;
    if (!(std::cin >> radius)) {
        std::cout << "Это не число\n";
        return 1;
    }
    // После >> в потоке остался перевод строки. Убираем его,
    // иначе первый getline ниже сразу прочитает пустую строку.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    double length = 2 * M_PI * radius;
    std::cout << "Длина окружности: " << length << "\n";

    double rounded = std::round(length * 1000) / 1000;
    std::cout << "Округлено до трёх знаков: " << std::fixed << std::setprecision(3)
              << rounded << "\n";

    const std::string fileName = "notes.txt";
    std::cout << "\nКаждая строка дописывается в " << fileName
              << ". Команды: read (показать файл), erase (очистить), exit (выйти).\n";

    while (true) {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line) || line == "exit") {
            break;
        }

        if (line == "read") {
            std::ifstream file(fileName);
            std::string fileLine;
            bool empty = true;
            while (std::getline(file, fileLine)) {
                std::cout << fileLine << "\n";
                empty = false;
            }
            if (empty) {
                std::cout << "(файл пуст)\n";
            }
        } else if (line == "erase") {
            std::ofstream file(fileName, std::ios::trunc);  // trunc стирает старое содержимое
            std::cout << "Файл очищен\n";
        } else {
            std::ofstream file(fileName, std::ios::app);  // app дописывает в конец
            file << line << "\n";
        }
    }

    return 0;
}
