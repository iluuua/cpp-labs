// Лаба 5: перечисление, структура, наследование, виртуальные методы,
// перегрузка операторов, абстрактный класс и шаблон класса.

#include <iostream>
#include <type_traits>
#include "DisposableWeapon.h"
#include "Hands.h"
#include "MagicWeapon.h"
#include "Player.h"
#include "console.h"

// У Weapon есть чисто виртуальный attack(), поэтому так написать нельзя:
//     Weapon weapon;  // ошибка: нельзя создать объект абстрактного класса
// Та же проверка, но на этапе компиляции и без закомментированного кода:
static_assert(std::is_abstract_v<Weapon>, "Weapon должен быть абстрактным");

void printWeaponType(const Weapon& weapon) {
    WeaponType type = weapon.getType();
    if (type == WeaponType::ONEHANDED) {
        std::cout << "Одноручное оружие\n";
    } else if (type == WeaponType::TWOHANDED) {
        std::cout << "Двуручное оружие\n";
    } else if (type == WeaponType::BOW) {
        std::cout << "Лук\n";
    } else if (type == WeaponType::CROSSBOW) {
        std::cout << "Арбалет\n";
    }
}

int main() {
    setupConsole();
    std::cout << std::boolalpha;

    MagicWeapon staff("Посох огня", 20, 2.5f, WeaponType::TWOHANDED, 15);
    MagicWeapon wand;
    DisposableWeapon grenade("Граната", 30, 0.5f, WeaponType::ONEHANDED);

    std::cout << "== Тип оружия ==\n";
    std::cout << staff.getName() << ": ";
    printWeaponType(staff);
    std::cout << grenade.getName() << ": ";
    printWeaponType(grenade);

    std::cout << "\n== Структура игрока ==\n";
    Player player;
    player.id = 1;
    player.login = "dragon_slayer";
    player.password = "qwerty123";
    player.print();

    std::cout << "\n== Магическое оружие ==\n";
    std::cout << staff.getName() << ": базовый урон " << staff.Weapon::getDamage()
              << ", дополнительный " << staff.getExtraDamage()
              << ", итого " << staff.getDamage() << "\n";
    std::cout << wand.getName() << " (конструктор без параметров): итого "
              << wand.getDamage() << "\n";
    // Эти методы пришли из Weapon.
    std::cout << "Посох слишком тяжёлый для 2 кг? " << staff.isTooHeavy(2) << "\n";
    std::cout << "Посох и палочка весят " << staff.totalWeight(wand) << " кг\n";

    std::cout << "\n== Сравнение по урону ==\n";
    // Посох: 20 + 15 = 35, граната: 30, палочка: 5 + 10 = 15.
    std::cout << "Посох > граната: " << (staff > grenade) << "\n";
    std::cout << "Посох < граната: " << (staff < grenade) << "\n";
    std::cout << "Палочка < граната: " << (wand < grenade) << "\n";

    std::cout << "\n== Атака ==\n";
    staff.attack();
    grenade.attack();
    grenade.attack();

    std::cout << "\n== Шаблон Hands ==\n";
    Hands<MagicWeapon, DisposableWeapon> hands(staff, grenade);
    std::cout << "В левой руке " << hands.getLeft().getName()
              << ", в правой " << hands.getRight().getName() << "\n";
    hands.setLeft(wand);
    std::cout << "Теперь в левой руке " << hands.getLeft().getName() << "\n";

    Hands<int, int> weaponIds(101, 205);
    std::cout << "id в руках: " << weaponIds.getLeft() << " и " << weaponIds.getRight() << "\n";
    weaponIds.setRight(307);
    std::cout << "Сменили правую руку: " << weaponIds.getRight() << "\n";

    return 0;
}
