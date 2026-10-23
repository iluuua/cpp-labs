#include "utf8.h"

std::wstring fromUtf8(const std::string& text) {
    std::wstring result;
    size_t i = 0;
    while (i < text.size()) {
        unsigned char lead = static_cast<unsigned char>(text[i]);

        // По первому байту понятно, сколько байт ещё относится к этому символу.
        char32_t code = 0;
        int extra = 0;
        if (lead < 0x80) {
            code = lead;
        } else if ((lead >> 5) == 0x6) {
            code = lead & 0x1F;
            extra = 1;
        } else if ((lead >> 4) == 0xE) {
            code = lead & 0x0F;
            extra = 2;
        } else if ((lead >> 3) == 0x1E) {
            code = lead & 0x07;
            extra = 3;
        } else {
            result += L'?';  // битый байт
            i++;
            continue;
        }

        if (i + extra >= text.size()) {
            result += L'?';  // строка оборвалась посреди символа
            break;
        }
        for (int k = 1; k <= extra; k++) {
            code = (code << 6) | (static_cast<unsigned char>(text[i + k]) & 0x3F);
        }

        // В Windows wchar_t двухбайтовый, и эмодзи в него не влезают.
        // Для этих заданий они не нужны, поэтому просто заменяем.
        if (sizeof(wchar_t) == 2 && code > 0xFFFF) {
            code = U'?';
        }
        result += static_cast<wchar_t>(code);
        i += extra + 1;
    }
    return result;
}

std::string toUtf8(const std::wstring& text) {
    std::string result;
    for (wchar_t symbol : text) {
        char32_t code = static_cast<char32_t>(symbol);
        if (code < 0x80) {
            result += static_cast<char>(code);
        } else if (code < 0x800) {
            result += static_cast<char>(0xC0 | (code >> 6));
            result += static_cast<char>(0x80 | (code & 0x3F));
        } else if (code < 0x10000) {
            result += static_cast<char>(0xE0 | (code >> 12));
            result += static_cast<char>(0x80 | ((code >> 6) & 0x3F));
            result += static_cast<char>(0x80 | (code & 0x3F));
        } else {
            result += static_cast<char>(0xF0 | (code >> 18));
            result += static_cast<char>(0x80 | ((code >> 12) & 0x3F));
            result += static_cast<char>(0x80 | ((code >> 6) & 0x3F));
            result += static_cast<char>(0x80 | (code & 0x3F));
        }
    }
    return result;
}
