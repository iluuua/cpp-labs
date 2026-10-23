#pragma once

#include <string>

class Weapon {
public:
    Weapon(const std::string& name, float damage, float weight);
    Weapon();  // оружие по умолчанию, вызывает конструктор выше
    ~Weapon();

    std::string getName() const;
    float getDamage() const;
    float getWeight() const;

    // Отрицательный урон не принимаем, вместо него ставим 0.
    void setDamage(float newDamage);

    // По условию: true, если допустимый вес меньше веса оружия,
    // то есть поднять его не получится.
    bool isTooHeavy(float maxWeight) const;

    float totalWeight(const Weapon& other) const;
    float totalWeight(float otherWeight) const;

private:
    std::string name;
    float damage;
    float weight;

    // Characteristic может читать закрытые поля оружия напрямую.
    friend class Characteristic;
};
