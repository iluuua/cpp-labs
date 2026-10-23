#pragma once

#include "Weapon.h"

// Одноразовое оружие: срабатывает только при первой атаке.
class DisposableWeapon : public Weapon {
public:
    DisposableWeapon(const std::string& name, float damage, float weight, WeaponType type);

    bool isUsed() const;
    void attack() override;

private:
    bool used = false;
};
