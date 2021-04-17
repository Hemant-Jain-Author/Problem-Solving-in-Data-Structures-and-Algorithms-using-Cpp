#include "Queue.h"

Queue::Queue()
{
    length = 0;
    data = new int[100];
}

bool Queue::add(int value)
{
    if (length >= Capacity)
    {
        throw ("QueueFullException");
        return false;
    }
    else
    {
        length++;
        data[back] = value;
        back = (++back) % (Capacity - 1);
    }
    return true;
}

int Queue::remove()
{
    int value;
    if (length <= 0)
    {
        throw ("QueueEmptyException");
    }
    else
    {
        length--;
        value = data[front];
        front = (++front) % (Capacity - 1);
    }
    return value;
}

bool Queue::isEmpty()
{
    return length == 0;
}

int Queue::size()
{
    return length;
}


int main()
{
    Queue que;
    que.add(1);
    que.add(2);
    que.add(3);       
    for (int i = 0; i < 3; i++)
        std::cout << que.remove() << " ";

    return 0;
}

/*
1 2 3
*/