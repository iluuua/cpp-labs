add_task(lab05_inheritance
    main.cpp
    WeaponType.h
    Weapon.h Weapon.cpp
    MagicWeapon.h MagicWeapon.cpp
    DisposableWeapon.h DisposableWeapon.cpp
    Player.h Player.cpp
    Hands.h)

add_io_test(lab05_disposable lab05_inheritance "" "Оружие уже было использовано")
add_io_test(lab05_magic lab05_inheritance "" "Атакуем магическим оружием")
