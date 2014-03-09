/*****
 *
 * Calculator is potentially expand to a larger number of operators
 *
 *****/

#pragma once

#include "stack.h"
#include "doublylinkedlist.h"
#include "linkedstack.h"

class StackCalculator: public LinkedStack, public DoublyLinkedList
{
public:
    StackCalculator();
    ~StackCalculator();
    void readOriginalExpression();
    void reversePolishNotation();
    double calculateReversePolishNotation();
    DoublyLinkedList *originalExpression;
    DoublyLinkedList *convertedExpression;
protected:
    bool isOperatorLast; // '(' too
    bool isExpressionConverted; // to reverse polish notation
    LinkedStack *operators;
    bool isOtherSymbol(char symbol);
    bool isOperator(char symbol);
    bool isOperand(char symbol);
    bool isBreak(char symbol);
    void incorrectExpression();
    bool isCorrect;
    unsigned char orderOfOperator(char symbolOfOperator);
private:
    void readingNumber();
};
