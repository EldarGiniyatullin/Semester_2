#include <iostream>
#include "arraystack.h"

using std::cout;

ArrayStack::ArrayStack(unsigned int length)
{
    lengthOfStack = length;
    array = new Element[lengthOfStack];
    currentPositionOfBottom = 0;
}

ArrayStack::ArrayStack()
{
    ArrayStack(100);
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

bool ArrayStack::isStackFull()
{
    return (currentPositionOfBottom == lengthOfStack);
}

void ArrayStack::push(int numberToPush)
{
    if (isStackFull())
        cout << "\nThe stack is full";
    else
    {
        array[currentPositionOfBottom].Data.number = numberToPush;
        array[currentPositionOfBottom].isSymbol = false;
        currentPositionOfBottom++;
    }
}

void ArrayStack::push(char symbolToPush)
{
    if (isStackFull())
        cout << "\nThe stack is full";
    else
    {
        array[currentPositionOfBottom].Data.symbol = symbolToPush;
        array[currentPositionOfBottom].isSymbol = true;
        currentPositionOfBottom++;
    }
}

void ArrayStack::pop()
{
    if (currentPositionOfBottom == 0)
        cout << "\nThe stack is empty";
    else
        currentPositionOfBottom--;
}

void ArrayStack::printStack()
{
    cout << "\nThe stack data: ";
    if (currentPositionOfBottom == 0)
        cout << "is empty";
    else
    {
        int i = currentPositionOfBottom - 1;
        while (i >= 0)
        {
            if (array[i].isSymbol)                      // I didn't write
                cout << array[i].Data.symbol << " ";    // cout << (array[i].isSymbol ? array[i].Data.symbol : array[i].Data.number);
            else                                        // here because it prints symbols
                cout << array[i].Data.number << " ";    // as numbers
            i--;
        }
    }
}
