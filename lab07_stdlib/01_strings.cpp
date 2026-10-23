// Лаба 7, задание 1: подстрока и поиск в строке.

#include <iostream>
#include <string>
#include "console.h"
#include "utf8.h"

int main() {
    setupConsole();

    std::cout << "Введите строку: ";
    std::string line;
    std::getline(std::cin, line);

    // Работаем с wstring, чтобы позиции считались в буквах, а не в байтах.
    std::wstring text = fromUtf8(line);

    // Второй символ имеет индекс 1, с него берём три символа: 2-й, 3-й и 4-й.
    if (text.size() >= 4) {
        std::cout << "Символы со 2-го по 4-й: " << toUtf8(text.substr(1, 3)) << "\n";
    } else {
        std::cout << "Строка короче четырёх символов, подстроку взять нельзя\n";
    }

    // Ищем латинскую a. Русская «а» выглядит так же, но это другой символ.
    size_t position = text.find(L"a");
    if (position != std::wstring::npos) {
        std::cout << "Первая буква a стоит на позиции " << position << " (счёт с нуля)\n";
    } else {
        std::cout << "Символа a не найдено\n";
    }

    return 0;
}
