#include "consoledisplayer.h"

#include <iostream>

using std::cout;

void ConsoleDisplayer::displaySpiral(int **array, unsigned int arraySize)
{
    int horizontal = 1;
    int vertical = -1;
    int reverse = -1;
    int printLen = 1;
    int currRow = arraySize / 2;
    int currColumn = arraySize / 2;
    cout << array[currRow][currColumn] << " ";
    currColumn++;
    while (printLen != arraySize)
    {
        int printed = 0;
        for(int i = currColumn; printed < printLen; i += horizontal)
        {
            printed++;
            cout << array[currRow][i] << " ";
            currColumn += horizontal;
        }
        currColumn -= horizontal;
        horizontal *= reverse;
        currRow += vertical;
        printed = 0;
        for (int i = currRow; printed < printLen; i += vertical)
        {
            printed++;
            cout << array[i][currColumn] << " ";
            currRow += vertical;
        }
        currRow -= vertical;
        vertical *= reverse;
        currColumn += horizontal;
        printLen++;
    }
    if (arraySize != 1)
    {
        for (int i = 1; i < arraySize; i++)
        {
            cout << array[arraySize - 1][i] << " ";
        }
    }
}
