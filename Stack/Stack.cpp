#include "Stack.h"
#include <exception>

int main()
{
    Stack s(100);
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    return 0;
}

/*
3 2 1 
3
2
1 
*/

Stack::Stack() : Stack(MIN_CAPACITY)
{
}

Stack::Stack(int maxCapacity)
{
    data = new int[maxCapacity];
    capacity = maxCapacity;
}

Stack::~Stack()
{
    delete[] data;
}

int Stack::size()
{
    return (stack_top + 1);
}

bool Stack::isEmpty()
{
    return (stack_top == -1);
}

void Stack::push(int value)
{
    if (size() == capacity)
    {
        throw "StackOvarflowException";
    }
    stack_top++;
    data[stack_top] = value;
}

int Stack::top()
{
    if (isEmpty())
    {
        throw "StackEmptyException";
    }
    return data[stack_top];
}

int Stack::pop()
{
    if (isEmpty())
    {
        throw "StackEmptyException";
    }
    int topVal = data[stack_top];
    stack_top--;
    return topVal;
}

void Stack::print()
{
    for (int i = stack_top; i > -1; i--)
        std::cout << data[i] << " ";

    std::cout << std::endl;
}

void Stack::gPush(int value)
{
    if (size() == capacity)
    {
        int *delMe = data;
        capacity = 2 * capacity;
        data = new int[capacity];
        for (int i = stack_top; i > -1; i--)
        {
            data[i] = delMe[i];
        }
        delete[] delMe;
        std::cout << "stack size doubled" << std::endl;
    }
    stack_top++;
    data[stack_top] = value;
}

int Stack::gPop()
{
    if (isEmpty())
    {
        throw "StackEmptyException";
    }

    int topVal = data[stack_top];
    stack_top--;
    if (stack_top < capacity / 2 && stack_top > MIN_CAPACITY)
    {
        capacity = capacity / 2;
        int *delMe = data;
        data = new int[capacity];
        for (int i = stack_top; i > -1; i--)
        {
            data[i] = delMe[i];
        }
        std::cout << "stack size reduced" << std::endl;
    }
    return topVal;
}
