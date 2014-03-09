#pragma once

#include "list.h"

class DoublyLinkedList : public List
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addElement(int number);
    void addElement(char symbol);
    void deleteElement(int number);
    void printList();
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
        Element *previous;
    };
    Element *ending;
public:
    Element *head;
private:
    Element *createElement();
};
