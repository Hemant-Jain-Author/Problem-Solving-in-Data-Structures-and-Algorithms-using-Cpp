#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <array>
class TwoStack
{
private:
    const static int MAX_SIZE = 5000;
    int top1 = 0;
    int top2 = 0;
    std::array<int, MAX_SIZE> data;// We can also use c stype array int data[MAX_SIZE];

public:
    TwoStack();
    virtual void push1(int value);
    virtual void push2(int value);
    virtual int pop1();
    virtual int pop2();
};
