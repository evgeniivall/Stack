#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename StackType>
class Stack;

template <typename StackType>
std::ostream& operator <<(std::ostream &os, const Stack<StackType>& stk)
{
    for(int i = 0; i < stk.top_; i++)
    {
        os << stk.data_[i] << ' ';
    }
    return os;
}

template <typename StackType>
class Stack
{
private:
    StackType *data_;
    int top_;
    int size_;
    inline bool isempty();
    inline bool isfull();
public:
    Stack(int stack_size)
    {
        size_ = stack_size;
        data_ = new StackType[size_];
        top_ = 0;
    }
    ~Stack()
    {
        delete[]data_;
    }

    void push(StackType);
    StackType  pop();
    StackType  peek();

    friend std::ostream& operator<<<>(std::ostream &os, const Stack& stk);
};



template <typename StackType>
bool Stack<StackType>::isfull()
{
    if(top_ == size_)
        return 1;
    else
        return 0;
}
template <typename StackType>
bool Stack<StackType>::isempty()
{
    if(top_ == 0)
        return 1;
    else
        return 0;
}



template <typename StackType>
StackType Stack<StackType>::pop()
{
    if(!isempty())
    {
        top_--;
        return data_[top_];
    }
    else
    {
        std::cerr << "Stack is empty";
        return 0;
    }
}
template <typename StackType>
StackType Stack<StackType>::peek()
{
    if(!isempty())
    {
        return data_[top_];
    }
    else
    {
        std::cerr << "Stack is empty";
        return (StackType)0;
    }
}



template <typename StackType>
void Stack<StackType>::push(StackType element)
{
    if(!isfull())
    {
        data_[top_] = element;
        top_++;
    }
    else
    {
        std::cerr << "Stack is full";
    }
}


#endif // STACK_H


