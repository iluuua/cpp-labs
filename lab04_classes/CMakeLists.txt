add_task(lab04_classes
    main.cpp
    Weapon.h Weapon.cpp
    Characteristic.h Characteristic.cpp
    MyMath.h MyMath.cpp)

add_io_test(lab04_classes lab04_classes "" "Вызовов методов MyMath: 4")
