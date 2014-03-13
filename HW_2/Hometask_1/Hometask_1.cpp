#include <iostream>
#include "arrayheapsorter.h"

using namespace std;

template <typename T>

void printArray(T *array)
{
    cout << "\n";
    for (int i = 0; i < 5; i++)
        cout << array[i] << " ";
}

int main()
{
    int *a = new int[5];
    double *b = new double[5];
    a[0] = 4;
    a[1] = 6;
    a[2] = 2;
    a[3] = 1;
    a[4] = 3;
    b[0] = 1.5;
    b[1] = 2.37;
    b[2] = 7.843;
    b[3] = 2.333;
    b[4] = -3;
    ArrayHeapSorter<int> *c = new ArrayHeapSorter<int>;
    c->sortArray(a, 5);  //why "undefined reference to `ArrayHeapSorter<int>::sortArray(int*, unsigned int)'" ?
    printArray(a);
    printArray(b);
    delete a;
    delete b;
    delete c;
}

