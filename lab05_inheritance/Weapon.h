#pragma once

#include <string>
#include "WeaponType.h"

// Базовый класс оружия. Он абстрактный: у attack() нет реализации,
// поэтому создать можно только наследника.
class Weapon {
public:
    Weapon(const std::string& name, float damage, float weight, WeaponType type);
    Weapon();
    virtual ~Weapon() = default;

    std::string getName() const;
    // Виртуальный, потому что у магического оружия урон считается иначе.
    virtual float getDamage() const;
    float getWeight() const;
    WeaponType getType() const;

    void setDamage(float newDamage);

    bool isTooHeavy(float maxWeight) const;
    float totalWeight(const Weapon& other) const;
    float totalWeight(float otherWeight) const;

    virtual void attack() = 0;

    // Сравниваем по урону. Берём его только через getDamage(), чтобы у
    // магического оружия учитывался и дополнительный урон.
    bool operator>(const Weapon& other) const;
    bool operator<(const Weapon& other) const;

private:
    std::string name;
    float damage;
    float weight;
    WeaponType type;
};
