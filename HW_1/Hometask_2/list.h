#pragma once

//template <typename UniversalType>

class List
{
public:
    virtual ~List()
    {

    }
    virtual void addElement(double number) = 0;
    virtual void deleteElement(int number) = 0;
    virtual void printList() = 0;
    int numberOfElements;
};
