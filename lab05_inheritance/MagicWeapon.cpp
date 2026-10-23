#include "MagicWeapon.h"

#include <iostream>

MagicWeapon::MagicWeapon(const std::string& name, float damage, float weight,
                         WeaponType type, float extraDamage)
    : Weapon(name, damage, weight, type), extraDamage(extraDamage) {}

MagicWeapon::MagicWeapon()
    : MagicWeapon("Волшебная палочка", 5, 0.3f, WeaponType::ONEHANDED, 10) {}

float MagicWeapon::getExtraDamage() const {
    return extraDamage;
}

float MagicWeapon::getDamage() const {
    return Weapon::getDamage() + extraDamage;
}

void MagicWeapon::attack() {
    std::cout << "Атакуем магическим оружием\n";
}
