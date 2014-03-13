#pragma once

#include "arraysorter.h"

template <typename T>

class ArrayHeapSorter : public ArraySorter<T>
{
public:
    void swap(T &first, T &second);
    void sortArray(T *array, unsigned int arraySize);
};
