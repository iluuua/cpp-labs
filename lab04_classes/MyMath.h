#pragma once

// Арифметика через статические методы: объект создавать не нужно.
// Заодно класс считает, сколько раз его методы вызывали.
class MyMath {
public:
    static double add(double a, double b);
    static double sub(double a, double b);
    static double mult(double a, double b);
    static double div(double a, double b);

    static int getCallCount();

private:
    static int callCount;
};
