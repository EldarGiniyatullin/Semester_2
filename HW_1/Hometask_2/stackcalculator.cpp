#include <iostream>
#include "stackcalculator.h"

using std::cin;
using std::cout;

StackCalculator::StackCalculator()
{
    operators = new LinkedStack();
    originalExpression = new DoublyLinkedList();
    convertedExpression = new DoublyLinkedList();
    isOperatorLast = true;
    isExpressionConverted = false;
    isCorrect = true;
}

StackCalculator::~StackCalculator()
{
    delete operators;
    delete originalExpression;
    delete convertedExpression;
}


void StackCalculator::readOriginalExpression()
{
    char symbol = '\0';
    cin.get(symbol);
    while (!isOtherSymbol(symbol))
    {
        if (isBreak(symbol))
        {
            originalExpression->addElement(symbol);
            if (symbol == '(')
                isOperatorLast = true;
        }
        else if (isOperator(symbol))
        {
            if (isOperatorLast)
            {                                       // for 5+(-25)
                if (symbol == '+' || symbol == '-')
                {
                    cin.putback(symbol);
                    readingNumber();
                }
                else                                // for 5+(/25)
                    incorrectExpression();
            }
            else
            {
                originalExpression->addElement(symbol);
                isOperatorLast = true;
            }
        }
        else if (isOperand(symbol))
        {
            cin.putback(symbol);
            readingNumber();
        }
        cin.get(symbol);
    }
    if (isOperatorLast)
        isCorrect = false;
}

void StackCalculator::reversePolishNotation()
{
    if (isCorrect)
    {
        DoublyLinkedList::Element *tmp;
        while (originalExpression->head)
        {
            tmp = originalExpression->head;
            originalExpression->head = originalExpression->head->next;
            tmp->next = nullptr;
            if (!tmp->isSymbol)
                convertedExpression->addElement(tmp->Data.number);
            else
            {
                if (isBreak(tmp->Data.symbol))                                  //breaks
                {
                    if (tmp->Data.symbol == '(')
                        operators->push('(');
                    else
                    {
                        while (operators->head && operators->head->Data.symbol != '(')
                        {
                            convertedExpression->addElement(operators->head->Data.symbol);
                            operators->pop();
                        }
                        if (operators->head->Data.symbol == '(')
                        {
                            operators->pop();
                        }
                        else
                        {
                            incorrectExpression();
                            break;
                        }
                    }
                }
                else                                                              //operators
                {
                    if (!operators->head)
                    {
                        operators->push(tmp->Data.symbol);
                    }
                    else
                    {                                                                                               //priorities
                        if (orderOfOperator(tmp->Data.symbol) > orderOfOperator(operators->head->Data.symbol))
                            operators->push(tmp->Data.symbol);
                        else if (orderOfOperator(tmp->Data.symbol) == orderOfOperator(operators->head->Data.symbol))
                        {
                            convertedExpression->addElement(operators->head->Data.symbol);
                            operators->pop();
                            operators->push(tmp->Data.symbol);
                        }
                        else
                        {
                            while (operators->head && orderOfOperator(operators->head->Data.symbol)>= orderOfOperator(tmp->Data.symbol))
                            {
                                convertedExpression->addElement(operators->head->Data.symbol);
                                operators->pop();
                            }
                            operators->push(tmp->Data.symbol);
                        }
                    }
                }
            }
        }
        while (operators->head)
        {
            convertedExpression->addElement(operators->head->Data.symbol);
            operators->pop();
        }
    }
}

double StackCalculator::calculateReversePolishNotation()
{

}

bool StackCalculator::isOtherSymbol(char symbol)
{
    return !(isOperator(symbol) || isBreak(symbol) || isOperand(symbol));
}

bool StackCalculator::isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool StackCalculator::isOperand(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

bool StackCalculator::isBreak(char symbol)
{
    return (symbol == '(' || symbol == ')');
}

void StackCalculator::incorrectExpression()
{
    cout << "\nIncorrect expression";
    isCorrect = false;
}

unsigned char StackCalculator::orderOfOperator(char symbolOfOperator)
{
    switch (symbolOfOperator)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

void StackCalculator::readingNumber()
{
    int tempNumber = 0;
    cin >> tempNumber;
    originalExpression->addElement(tempNumber);
    isOperatorLast = false;
}
