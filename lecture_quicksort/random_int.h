#pragma once

#include <random>

// Случайное целое из отрезка [min, max], обе границы включены.
inline int randomInt(int min, int max) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
