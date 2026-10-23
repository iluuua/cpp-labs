#include "Weapon.h"

#include <iostream>

Weapon::Weapon(const std::string& name, float damage, float weight)
    : name(name), damage(damage), weight(weight) {}

Weapon::Weapon() : Weapon("Палка", 5, 1) {}

Weapon::~Weapon() {
    std::cout << "Оружие «" << name << "» (урон " << damage << ", вес " << weight
              << ") удаляется\n";
}

std::string Weapon::getName() const {
    return name;
}

float Weapon::getDamage() const {
    return damage;
}

float Weapon::getWeight() const {
    return weight;
}

void Weapon::setDamage(float newDamage) {
    damage = newDamage < 0 ? 0 : newDamage;
}

bool Weapon::isTooHeavy(float maxWeight) const {
    return maxWeight < weight;
}

float Weapon::totalWeight(const Weapon& other) const {
    // Не дублируем сложение, а зовём перегрузку с числом.
    return totalWeight(other.weight);
}

float Weapon::totalWeight(float otherWeight) const {
    return weight + otherWeight;
}
