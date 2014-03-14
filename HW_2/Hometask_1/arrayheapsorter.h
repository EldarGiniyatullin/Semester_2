#pragma once

#include "arraysorter.h"

template <typename T>

class ArrayHeapSorter : public ArraySorter<T>
{
public:
    void swap(T &first, T &second)
    {
        if (first != second)
        {
            T temp = first;
            first = second;
            second = temp;
//            first = first ^ second;
//            second = first ^ second;
//            first = first ^ second;
        }
    }
    void sortArray(T *array, unsigned int arraySize)
    {
        for (int i = (arraySize + 1) / 2 - 1; i >= 0; i--)
        {
            if (array[i] < array[2 * i])
                swap(array[i], array[2 * i]);
            if (array[i] < array[(2 * i) + 1])
                swap(array[i], array[(2 * i) + 1]);
            if (array[2 * i] > array[(2 * i) + 1])
                swap(array[2 * i], array[(2 * i) + 1]);
        }
        if (arraySize > 1)
        {
            swap(array[1], array[arraySize]);
            sortArray(array, arraySize - 1);
        }
    }
};
