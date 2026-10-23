// Лаба 6, задание 2: проверка года рождения через стандартные исключения.

#include <ctime>
#include <iostream>
#include <stdexcept>
#include "console.h"

int currentYear() {
    std::time_t now = std::time(nullptr);
    return std::localtime(&now)->tm_year + 1900;  // tm_year считается от 1900
}

void checkBirthYear(int year) {
    // Отрицательные проверяем первыми: они тоже меньше 1850,
    // и иначе пользователь увидел бы не то сообщение.
    if (year < 0) {
        throw std::invalid_argument("Вы ввели отрицательное число!");
    }
    if (year < 1850) {
        throw std::out_of_range("Что-то не верится...");
    }
    if (year > currentYear()) {
        throw std::out_of_range("Вы ещё не родились");
    }
}

int main() {
    setupConsole();

    std::cout << "Введите год своего рождения: ";
    int year = 0;
    if (!(std::cin >> year)) {
        std::cout << "Это не число\n";
        return 1;
    }

    try {
        checkBirthYear(year);
        std::cout << "Спасибо!\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }

    return 0;
}
