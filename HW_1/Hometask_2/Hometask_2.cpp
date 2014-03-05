#include <iostream>
#include "linkedstack.h"
//#include "stackcalculator.h"

using namespace std;

int main()
{
    LinkedStack *myStack = new LinkedStack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->printStack();
    myStack->pop();
    myStack->printStack();
    myStack->push(4);
    myStack->printStack();
}
