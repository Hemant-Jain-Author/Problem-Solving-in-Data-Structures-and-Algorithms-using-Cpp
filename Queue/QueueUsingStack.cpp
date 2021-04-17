#include "QueueUsingStack.h"

void QueueUsingStack::add(int value)
{
    stk1.push(value);
}

int QueueUsingStack::remove()
{
    int value;
    if (stk2.empty() == false)
    {
        value = stk2.top();
        stk2.pop();
        return value;
    }

    while (stk1.empty() == false)
    {
        value = stk1.top();
        stk1.pop();
        stk2.push(value);
    }

    value = stk2.top();
    stk2.pop();
    return value;
}

int main()
{
    QueueUsingStack que;
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
