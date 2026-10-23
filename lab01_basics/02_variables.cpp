// Лаба 1, задание 2: переменные, типы данных и константы.

#include <iostream>
#include <string>
#include "console.h"

int main() {
    setupConsole();

    int wholeNumber = 150;
    float fraction = 15.933f;  // без f литерал был бы double и неявно ужимался бы до float

    // 250 помещается в unsigned char (от 0 до 255), а это всего один байт.
    unsigned char smallNumber = 250;

    std::cout << "wholeNumber = " << wholeNumber << "\n";
    std::cout << "fraction = " << fraction << "\n";
    // char cout печатает как символ, поэтому приводим к int, чтобы увидеть число.
    std::cout << "smallNumber = " << static_cast<int>(smallNumber) << "\n";

    // День помещается в один байт, год в два, месяц храним словом.
    unsigned char birthDay = 14;
    std::string birthMonth = "марта";
    unsigned short birthYear = 2006;
    std::cout << "Моя дата рождения: " << static_cast<int>(birthDay) << " "
              << birthMonth << " " << birthYear << " года\n";

    const float NUMBER = 2.3f;
    const std::string SYSTEM_NAME = "WINDOWS";
    std::cout << NUMBER << " " << SYSTEM_NAME << "\n";

    return 0;
}
