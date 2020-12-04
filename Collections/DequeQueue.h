#pragma once

#include <string>
#include <vector>
#include <deque>

template<typename T>
class DequeQueue
{

private:
    deque<T> que;

public:
    virtual void enqueue(T obj)
    {
        que.add(obj);
    }

    virtual T dequeue()
    {
        return que.remove();
    }

    virtual T peek()
    {
        return que.peekFirst();
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
