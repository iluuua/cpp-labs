// Лаба 7, задание 4: vector и map.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "console.h"

// Вектор передаём по константной ссылке, чтобы не копировать его целиком.
void printVector(const std::vector<float>& values) {
    for (float value : values) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

// Настройки в виде пар «ключ = значение». После последнего пункта задания
// и поле, и методы статические: объект не нужен, map одна на всю программу.
class Settings {
public:
    static void add(const std::string& key, const std::string& value) {
        values[key] = value;
    }

    // Если ключа нет, возвращаем пустую строку.
    static std::string get(const std::string& key) {
        auto found = values.find(key);
        return found != values.end() ? found->second : "";
    }

    static void print() {
        for (const auto& [key, value] : values) {
            std::cout << key << " = " << value << "\n";
        }
    }

private:
    // inline позволяет определить статическое поле прямо в классе (C++17),
    // без отдельной строки в .cpp.
    inline static std::map<std::string, std::string> values;
};

int main() {
    setupConsole();

    std::vector<float> numbers;
    numbers.push_back(1.5f);
    numbers.push_back(2.5f);
    numbers.push_back(3.5f);
    numbers.push_back(4.5f);
    numbers.push_back(5.5f);
    printVector(numbers);

    // begin() + 3 указывает на элемент с индексом 3, новый встанет перед ним,
    // то есть между элементами с индексами 2 и 3.
    numbers.insert(numbers.begin() + 3, 99.0f);
    printVector(numbers);

    numbers.pop_back();
    printVector(numbers);

    // Проверка первой версии, где поле и методы Settings были обычными:
    // Settings settings;
    // settings.add("language", "ru");
    // settings.add("volume", "80");
    // std::cout << settings.get("language") << "\n";
    // settings.print();

    std::cout << "\n";
    Settings::add("language", "ru");
    Settings::add("volume", "80");
    Settings::add("theme", "dark");
    std::cout << "volume: " << Settings::get("volume") << "\n";
    std::cout << "Все настройки:\n";
    Settings::print();

    return 0;
}
