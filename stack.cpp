#include "stack.h"
#include <iostream>

bool Stack::isfull()
{
    if(top == size)
        return 1;
    else
        return 0;
}

bool Stack::isempty()
{
    if(top == 0)
        return 1;
    else
        return 0;
}

void Stack::push(int data)
{
    if(!isfull())
    {
        elem[top] = data;
        top++;
    }
    else
    {
        std::cout << "Stack is full";
    }
}

int Stack::pop()
{
    int data;
    if(!isempty())
    {
        top--;
        data = elem[top];
        return data;
    }
    else
    {
        std::cout << "Stack is empty";
        return 0;
    }
}

void Stack::stkPrint()
{
    int i = top;
    if(isempty())
        return;
    do
    {
        i--;
        std::cout << elem[i] << " ";
    }
    while (i>0);

}
