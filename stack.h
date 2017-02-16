#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <deque>
#define out_of_range -1

template <class Type, class Container = std::deque<Type>>
class Stack
{
private:
    Container *data_;
    std::size_t top_;
    std::size_t size_;
public:
    explicit Stack(std::size_t size):data_(new Container(size)), top_(0), size_(size){}
    explicit Stack(const Container& cont = Container());
    Stack(const Stack& other);
    Stack& operator =(const Stack& other);

    ~Stack()
    {
        delete data_;
    }

    void push(Type);
    Type pop();
    Type peek();

    std::size_t size();
    bool full();
    bool empty();
};

template <class Type, class Container>
Stack<Type, Container>::Stack(const Container& cont)
{
    data_ = new Container(cont);
    top_ = cont.size();
    size_ = top_;
}

template <class Type, class Container>
Stack<Type, Container>::Stack(const Stack& other)
{
    data_ = new Container(*(other.data_));
    top_ = other.top_;
    size_ = other.size_;
}

template <class Type, class Container>
Stack<Type, Container>& Stack<Type, Container>::operator =(const Stack& other)
{
    if(&other != this)
    {
        delete data_;
        data_ = new Container(*(other.data_));
        top_ = other.top_;
        size_ = other.size_;
    }
    return *this;
}

template <class Type, class Container>
std::size_t Stack<Type, Container>::size()
{
    return top_;
}

template <class Type, class Container>
bool Stack<Type, Container>::full()
{
    return(top_ == size_);
}

template <class Type, class Container>
bool Stack<Type, Container>::empty()
{
    return(top_ == 0);
}


template <class Type, class Container>
void Stack<Type, Container>::push(Type element)
{
    try
    {
        if(top_ == size_)
            throw out_of_range;
        (*data_)[top_] = element;
        top_++;
    }
    catch(int)
    {
        std::cerr << "Stack is full";
    }
}

template <class Type, class Container>
Type Stack<Type, Container>::pop()
{
    try
    {
        if(empty())
            throw out_of_range;
        --top_;
        return (*data_)[top_];
    }
    catch(int)
    {
        std::cerr << "Stack is empty";
        return Type();
    }
}

template <class Type, class Container>
Type Stack<Type, Container>::peek()
{
    try
    {
        if(empty())
            throw out_of_range;
        return (*data_)[top_];
    }
    catch(int)
    {
        std::cerr << "Stack is empty";
        return Type();
    }
}

#endif // STACK_H


