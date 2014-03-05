#pragma once

class Stack
{
public:
    virtual ~Stack()
    {

    }
    virtual void push(int numberToPush) = 0;
    virtual void push(char symbolToPush) = 0;
    virtual void pop() = 0;
    virtual void printStack() = 0;
};
