// Лаба 6, задание 3: то же самое, но со своим классом исключения
// и перечислением кодов ошибок.

#include <ctime>
#include <exception>
#include <iostream>
#include "console.h"

enum class BirthYearError {
    Negative,
    TooOld,
    NotBornYet
};

class BirthYearException : public std::exception {
public:
    explicit BirthYearException(BirthYearError code) : code(code) {}

    BirthYearError getCode() const {
        return code;
    }

    // noexcept на месте старого throw() из лекции: внутри what()
    // новое исключение бросать нельзя.
    const char* what() const noexcept override {
        switch (code) {
        case BirthYearError::Negative:
            return "Вы ввели отрицательное число!";
        case BirthYearError::TooOld:
            return "Что-то не верится...";
        case BirthYearError::NotBornYet:
            return "Вы ещё не родились";
        }
        return "Неизвестная ошибка";
    }

private:
    BirthYearError code;
};

int currentYear() {
    std::time_t now = std::time(nullptr);
    return std::localtime(&now)->tm_year + 1900;
}

void checkBirthYear(int year) {
    if (year < 0) {
        throw BirthYearException(BirthYearError::Negative);
    }
    if (year < 1850) {
        throw BirthYearException(BirthYearError::TooOld);
    }
    if (year > currentYear()) {
        throw BirthYearException(BirthYearError::NotBornYet);
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
    } catch (const BirthYearException& error) {
        std::cout << error.what() << "\n";
    }

    return 0;
}
