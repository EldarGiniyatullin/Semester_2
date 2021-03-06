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
        for (int i = arraySize / 2 /*- 1 + (arraySize % 2 == 0 ? 1 : 0)*/; i >= 1; i--)
        {
            if (array[i - 1] < array[2 * i - 1])
                swap(array[i - 1], array[2 * i - 1]);
            if (arraySize > 2 * i)
            {
                if (array[i - 1] < array[2 * i])
                    swap(array[i - 1], array[2 * i]);
                if (array[2 * i] > array[2 * i - 1])
                    swap(array[2 * i], array[2 * i - 1]);
            }
        }
        if (arraySize > 1)
        {
            swap(array[0], array[arraySize - 1]);
            sortArray(array, arraySize - 1);
        }
    }
};
