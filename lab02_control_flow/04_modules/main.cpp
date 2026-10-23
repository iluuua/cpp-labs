// Лаба 2, задание 4: статическая переменная, пространства имён, макрос,
// функция в отдельных .h и .cpp. Релизная сборка описана в README.

#include <iostream>
#include "console.h"
#include "previous_sum.h"

using std::cout;
using std::endl;

// Макрос подставляется как текст, поэтому скобки нужны и вокруг параметров,
// и вокруг всего выражения. Без них SUM(2, 3) * 4 превратилось бы в 2 + 3 * 4.
#define SUM(a, b) ((a) + (b))

int main() {
    setupConsole();

    sums::printWithPrevious(5);   // 5 + 0 = 5
    sums::printWithPrevious(10);  // 10 + 5 = 15
    sums::printWithPrevious(3);   // 3 + 10 = 13
    sums::printWithPrevious(-1);  // -1 + 3 = 2

    cout << "SUM(2, 3) = " << SUM(2, 3) << endl;
    cout << "SUM(2, 3) * 4 = " << SUM(2, 3) * 4 << endl;

    return 0;
}
