#pragma once

#include <utility>

// Быстрая сортировка участка data[left..right] по возрастанию.
// Берём опорный элемент из середины, двигаем индексы навстречу друг другу
// и меняем местами пары, стоящие не на своей стороне. Слева от точки встречи
// остаются элементы не больше опорного, справа не меньше. Потом то же самое
// делаем для каждой половины.
inline void quickSort(int* data, int left, int right) {
    int i = left;
    int j = right;
    const int pivot = data[left + (right - left) / 2];

    while (i <= j) {
        while (data[i] < pivot) {
            i++;
        }
        while (data[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(data[i], data[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(data, left, j);
    }
    if (i < right) {
        quickSort(data, i, right);
    }
}
