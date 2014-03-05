#pragma once

#include "stack.h"

class LinkedStack : public Stack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(int numberToPush);
    void push(char symbolToPush);
    void printStack();
    void pop();
protected:
    struct Element
    {
        bool isSymbol;
        union
        {
            int number;
            char symbol;
        }Data;
        Element *next;
    };
    Element *popElement();
private:
    Element *head;
    Element *createElement();
};
