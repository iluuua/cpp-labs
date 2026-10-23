#include "Characteristic.h"

Characteristic::Characteristic(float strength) : strength(strength) {}

float Characteristic::getDamage(const Weapon& weapon) const {
    // weapon.damage закрытое поле, но Characteristic объявлен другом Weapon.
    return strength + weapon.damage;
}
