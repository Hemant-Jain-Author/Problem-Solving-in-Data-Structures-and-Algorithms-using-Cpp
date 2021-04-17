#pragma once

#include <string>
#include <vector>
#include <iostream>

class Stack
{
private:
    static const int MIN_CAPACITY = 10;
    int* data;
    int stack_top = -1;
    int capacity;

public:
    Stack();
    Stack(int capacity);
    ~Stack();
    virtual int size();
    virtual bool isEmpty();
    virtual int top();
    virtual void push(int value);
    virtual int pop();
    virtual void gPush(int value); // Self growing stack capacity.
    virtual int gPop(); // Self reducing stack capacity.
    virtual void print();
};
