#include "MyMath.h"

// Статическое поле одно на весь класс, его нужно определить в одном .cpp.
int MyMath::callCount = 0;

double MyMath::add(double a, double b) {
    callCount++;
    return a + b;
}

double MyMath::sub(double a, double b) {
    callCount++;
    return a - b;
}

double MyMath::mult(double a, double b) {
    callCount++;
    return a * b;
}

double MyMath::div(double a, double b) {
    callCount++;
    return a / b;
}

int MyMath::getCallCount() {
    return callCount;
}
