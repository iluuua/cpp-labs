// Лаба 4: класс оружия. Конструкторы, деструктор, перегрузка методов,
// закрытые поля с геттерами, дружественный класс и статические методы.

#include <iostream>
#include "Characteristic.h"
#include "MyMath.h"
#include "Weapon.h"
#include "console.h"

void printWeapon(const Weapon& weapon) {
    std::cout << weapon.getName() << ": урон " << weapon.getDamage()
              << ", вес " << weapon.getWeight() << "\n";
}

int main() {
    setupConsole();
    std::cout << std::boolalpha;

    std::cout << "== Конструкторы ==\n";
    Weapon sword("Меч", 25, 3.5f);
    Weapon stick;
    printWeapon(sword);
    printWeapon(stick);

    std::cout << "\n== Динамический объект ==\n";
    Weapon* axe = new Weapon("Топор", 40, 6);
    printWeapon(*axe);
    delete axe;  // деструктор топора сработает прямо здесь

    std::cout << "\n== Методы ==\n";
    std::cout << "Меч слишком тяжёлый, если можно поднять 3 кг? " << sword.isTooHeavy(3) << "\n";
    std::cout << "Меч слишком тяжёлый, если можно поднять 10 кг? " << sword.isTooHeavy(10) << "\n";
    std::cout << "Меч и палка вместе весят " << sword.totalWeight(stick) << " кг\n";
    std::cout << "Меч и ещё 2 кг: " << sword.totalWeight(2) << " кг\n";

    std::cout << "\n== Сеттер урона ==\n";
    sword.setDamage(30);
    printWeapon(sword);
    sword.setDamage(-10);  // отрицательный урон превратится в 0
    printWeapon(sword);
    sword.setDamage(30);

    std::cout << "\n== Дружественный класс ==\n";
    Characteristic strength(12);
    std::cout << "Сила 12 и меч с уроном 30 дают " << strength.getDamage(sword) << "\n";

    std::cout << "\n== Статические методы MyMath ==\n";
    std::cout << "7 + 3 = " << MyMath::add(7, 3) << "\n";
    std::cout << "7 - 3 = " << MyMath::sub(7, 3) << "\n";
    std::cout << "7 * 3 = " << MyMath::mult(7, 3) << "\n";
    std::cout << "7 / 2 = " << MyMath::div(7, 2) << "\n";
    std::cout << "Вызовов методов MyMath: " << MyMath::getCallCount() << "\n";

    std::cout << "\nmain закончился, дальше деструкторы локальных объектов:\n";
    return 0;
}
