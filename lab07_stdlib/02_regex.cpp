// Лаба 7, задание 2: регулярные выражения.

#include <iostream>
#include <regex>
#include <string>
#include "console.h"
#include "utf8.h"

// Имя: первая буква заглавная, потом от 1 до 31 любой буквы, всего от 2 до 32.
// Ё указана отдельно, потому что в Unicode она не входит в диапазон А-Я.
bool isValidName(const std::string& name) {
    static const std::wregex pattern(L"[A-ZА-ЯЁ][A-Za-zА-Яа-яЁё]{1,31}");
    return std::regex_match(fromUtf8(name), pattern);
}

int main() {
    setupConsole();

    std::cout << "Как вас зовут? ";
    std::string name;
    std::getline(std::cin, name);

    if (isValidName(name)) {
        std::cout << "Имя «" << name << "» подходит\n";
    } else {
        std::cout << "Имя «" << name << "» не подходит: нужно от 2 до 32 букв, первая заглавная\n";
    }

    const std::string text =
        "По вопросам заказа пишите на support@example.com, счета присылайте "
        "на billing.team@shop-example.ru. Старый адрес info@old-site.org больше "
        "не работает, а ivan_petrov+news@mail.ru подписан на рассылку.";

    // Адреса латинские, поэтому здесь хватает обычного std::regex.
    const std::regex emailPattern(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");

    std::cout << "\nАдреса из текста:\n";
    auto begin = std::sregex_iterator(text.begin(), text.end(), emailPattern);
    auto end = std::sregex_iterator();
    for (auto match = begin; match != end; ++match) {
        std::cout << match->str() << "\n";
    }

    return 0;
}
