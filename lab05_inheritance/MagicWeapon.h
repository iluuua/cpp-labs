#pragma once

#include "Weapon.h"

// Магическое оружие бьёт сильнее за счёт дополнительного урона.
class MagicWeapon : public Weapon {
public:
    MagicWeapon(const std::string& name, float damage, float weight, WeaponType type,
                float extraDamage);
    MagicWeapon();

    float getExtraDamage() const;

    // Полный урон: базовый из Weapon плюс дополнительный.
    float getDamage() const override;
    void attack() override;

private:
    float extraDamage;
};
