#pragma once

#include "arraysorter.h"

template <typename T>

class ArrayQuickSorter : public ArraySorter<T>
{
public:
    void swap(T &first, T &second);
    void quickSort(T *array, unsigned int first, unsigned int last);
    void sortArray(T *array, unsigned int arraySize);
};
