#include <iostream>
#include "stack.h"
#define SIZE 10
int main()
{
    Stack S1 = 10;
    for(int i = 0; i < SIZE; i++)
    {
        S1.push(i);
    }
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << S1.pop() << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < SIZE; i++)
    {
        S1.push(i+2);
    }
    S1.stkPrint();
    return 0;
}
