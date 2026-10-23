#include "Weapon.h"

Weapon::Weapon(const std::string& name, float damage, float weight, WeaponType type)
    : name(name), damage(damage), weight(weight), type(type) {}

Weapon::Weapon() : Weapon("Палка", 5, 1, WeaponType::ONEHANDED) {}

std::string Weapon::getName() const {
    return name;
}

float Weapon::getDamage() const {
    return damage;
}

float Weapon::getWeight() const {
    return weight;
}

WeaponType Weapon::getType() const {
    return type;
}

void Weapon::setDamage(float newDamage) {
    damage = newDamage < 0 ? 0 : newDamage;
}

bool Weapon::isTooHeavy(float maxWeight) const {
    return maxWeight < weight;
}

float Weapon::totalWeight(const Weapon& other) const {
    return totalWeight(other.weight);
}

float Weapon::totalWeight(float otherWeight) const {
    return weight + otherWeight;
}

bool Weapon::operator>(const Weapon& other) const {
    return getDamage() > other.getDamage();
}

bool Weapon::operator<(const Weapon& other) const {
    return getDamage() < other.getDamage();
}
