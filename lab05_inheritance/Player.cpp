#include "Player.h"

#include <iostream>

void Player::print() const {
    std::cout << "Игрок #" << id << ", логин: " << login << ", пароль: " << password << "\n";
}
