#pragma once

#include <string>

// В std::string русская буква в UTF-8 занимает два байта, поэтому substr,
// find и регулярки вроде [А-Я] работают с ней неправильно. Для таких задач
// переводим строку в std::wstring, где одна буква это один элемент,
// а для вывода переводим обратно.
std::wstring fromUtf8(const std::string& text);
std::string toUtf8(const std::wstring& text);
