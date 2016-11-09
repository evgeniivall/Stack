#ifndef STACK_H
#define STACK_H


class Stack
{
    int *elem;
    int top;
    int size;
    inline bool isempty();
    inline bool isfull();
public:
    Stack(int stackSize)
    {
        size = stackSize;
        elem = new int[size];
        top = 0;
    }
    ~Stack()
    {
        delete[]elem;
    }

    void push(int data);
    int pop();
    int stkTop();
    void stkPrint();
};


#endif // STACK_H


