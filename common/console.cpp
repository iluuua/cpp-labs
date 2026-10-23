#include "console.h"

#ifdef _WIN32

// Без этих двух define windows.h тянет лишнее и объявляет макросы min и max,
// которые ломают std::min и std::max.
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

void setupConsole() {
    SetConsoleCP(CP_UTF8);        // ввод
    SetConsoleOutputCP(CP_UTF8);  // вывод
}

#else

void setupConsole() {}

#endif
