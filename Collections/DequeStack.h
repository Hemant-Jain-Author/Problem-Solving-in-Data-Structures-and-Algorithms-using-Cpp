#pragma once

#include <string>
#include <vector>
#include <deque>

template<typename T>
class DequeStack
{

private:
    deque<T> que;;

public:
    virtual void push(T obj)
    {
        que.push(obj);
    }

    virtual T pop()
    {
        return que.pop();
    }

    virtual T top()
    {
        return que.peekLast();
    }

    virtual int size()
    {
        return que.size();
    }

    virtual bool isEmpty()
    {
        return que.isEmpty();
    }
};
