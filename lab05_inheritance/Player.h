#pragma once

#include <string>

struct Player {
    int id = 0;
    std::string login;
    std::string password;

    void print() const;
};
