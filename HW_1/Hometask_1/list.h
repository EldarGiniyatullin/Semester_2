#pragma once

class List
{
public:
    virtual ~List()
    {

    }
    virtual void addElement(int number) = 0;
    virtual void deleteElement(int number) = 0;
    virtual void printList() = 0;
    int numberOfElements;
};
