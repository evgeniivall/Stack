#include <iostream>
#include "stack.h"
#include <vector>
int main()
{

    Stack<int> s(10);
    for(int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    for(int i = 0; i < 10; i++)
    {
        std::cout << s.pop() << " ";
    }

    return 0;
}
