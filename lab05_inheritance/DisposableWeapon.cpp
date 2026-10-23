#include "DisposableWeapon.h"

#include <iostream>

DisposableWeapon::DisposableWeapon(const std::string& name, float damage, float weight,
                                   WeaponType type)
    : Weapon(name, damage, weight, type) {}

bool DisposableWeapon::isUsed() const {
    return used;
}

void DisposableWeapon::attack() {
    if (used) {
        std::cout << "Оружие уже было использовано\n";
        return;
    }
    std::cout << "Атакуем одноразовым оружием\n";
    used = true;
}
