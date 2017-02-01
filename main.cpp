#include <iostream>
#include "stack.h"

int main()
{
    Stack <int> s(10);
    for(int i = 0; i < 10; i++)
    {
        s.push(i);
    }
    std::cout << s;
    return 0;
}
