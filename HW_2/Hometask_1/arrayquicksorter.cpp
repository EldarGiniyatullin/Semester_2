#include "arrayquicksorter.h"

template <typename T>

void ArrayQuickSorter<T>::swap(T &first, T &second)
{
    if (first != second)
    {
        first = first ^ second;
        second = first ^ second;
        first = first ^ second;
    }
}

template <typename T>

void ArrayQuickSorter<T>::quickSort(T *array, unsigned int first, unsigned int last)
{
    int x = array[first + (last - first) / 2];
    int i = 0;
    int j = last;
    while(i <= j)
    {
        while(array[i] < x)
        {
            i++;
        }
        while(array[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (first < j)
        quickSort(array, 0, j);
    if (i < last)
        quickSort(array, i, last);
}

template <typename T>

void ArrayQuickSorter<T>::sortArray(T *array, unsigned int arraySize)
{
    quickSort(array, 0, arraySize - 1);
}
