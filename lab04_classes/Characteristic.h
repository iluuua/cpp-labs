#pragma once

#include "Weapon.h"

// Характеристика персонажа. Пока в ней только сила.
class Characteristic {
public:
    explicit Characteristic(float strength);

    // Урон с учётом силы: сила плюс урон оружия.
    float getDamage(const Weapon& weapon) const;

private:
    float strength;
};
