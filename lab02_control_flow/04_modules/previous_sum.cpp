#include "previous_sum.h"

#include <iostream>

using std::cout;
using std::endl;

namespace sums {

void printWithPrevious(int number) {
    // static инициализируется один раз, при первом вызове,
    // и сохраняет значение между вызовами функции.
    static int previous = 0;
    cout << number << " + " << previous << " = " << number + previous << endl;
    previous = number;
}

}
