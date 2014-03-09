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
    bool isEmpty();
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
public:
    Element *head;
protected:
    Element *popElement();
private:
    Element *createElement();
};
