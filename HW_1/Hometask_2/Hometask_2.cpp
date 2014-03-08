#include <iostream>
#include "linkedstack.h"
#include "arraystack.h"
//#include "stackcalculator.h"

using namespace std;

int main()
{
    Stack *myStack = new LinkedStack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->printStack();
    myStack->pop();
    myStack->printStack();
    myStack->push(4);
    myStack->printStack();
    delete myStack;
    Stack *a = new ArrayStack(5);
    a->push(1);
    a->push('+');
    a->push(2);
    a->push('=');
    a->push(4);
    a->push(3);
    a->pop();
    a->push(3);
    a->printStack();
    delete a;
}
