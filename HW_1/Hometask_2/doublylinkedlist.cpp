#include <iostream>
#include "doublylinkedList.h"

using std::cin;
using std::cout;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    ending = nullptr;
    numberOfElements = 0;
}


DoublyLinkedList::~DoublyLinkedList()
{
    Element *tmp = head;
    while (head)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }
    numberOfElements = 0;
}

DoublyLinkedList::Element *DoublyLinkedList::createElement()
{
    Element *newEl = new Element;
    newEl->next = nullptr;
    newEl->previous = ending;
    if (!ending)
    {
        head = newEl;
        ending = newEl;
    }
    else
    {
        ending->next = newEl;
        ending = newEl;
    }
    numberOfElements++;
    return newEl;
}

void DoublyLinkedList::addElement(int number)
{
    Element *newEl = createElement();
    newEl->Data.number = number;
    newEl->isSymbol = false;
}

void DoublyLinkedList::addElement(char symbol)
{
    Element *newEl = createElement();
    newEl->Data.symbol = symbol;
    newEl->isSymbol = true;
}

void DoublyLinkedList::deleteElement(int number)
{
    if (numberOfElements < number)
        cout << "\nNumber of elements in list is less than the number";
    else
    {
        Element **tmp = &head;
        for (int i = 1; i < number; i++)
            tmp = &((*tmp)->next);
        Element *elementToDelete = *tmp;
        *tmp = (*tmp)->next;
        if (!*tmp)
            ending = ending->previous;
        if (!head)
            ending = nullptr;
        delete elementToDelete;
        numberOfElements--;
    }
}

void DoublyLinkedList::printList()
{
    cout << "\n";
    Element *tmp = head;
    if (!tmp)
        cout << "There is nothing to print";
    else
    {
        cout << "The list content:";
        while (tmp)
        {
            cout << " ";
            if (tmp->isSymbol)
                cout << tmp->Data.symbol;
            else
                cout << tmp->Data.number;
            tmp = tmp->next;
        }
    }
}