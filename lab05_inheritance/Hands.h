#pragma once

// Что персонаж держит в левой и правой руке. Типы задаются снаружи:
// это может быть оружие, а может быть просто id оружия из базы.
// Шаблон целиком живёт в заголовке: компилятор должен видеть код,
// чтобы собрать его под конкретные типы.
template <typename Left, typename Right>
class Hands {
public:
    Hands(const Left& left, const Right& right) : left(left), right(right) {}

    const Left& getLeft() const {
        return left;
    }

    const Right& getRight() const {
        return right;
    }

    void setLeft(const Left& value) {
        left = value;
    }

    void setRight(const Right& value) {
        right = value;
    }

private:
    Left left;
    Right right;
};
