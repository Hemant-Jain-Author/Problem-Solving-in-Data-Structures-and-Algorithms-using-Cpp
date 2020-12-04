#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <exception>

class Queue
{
private:
    int length = 0;
    int Capacity = 100;
    int* data;
    int front = 0;
    int back = 0;

public:
    Queue();
    virtual bool add(int value);
    virtual int remove();
    virtual bool isEmpty();
    virtual int size();
};
