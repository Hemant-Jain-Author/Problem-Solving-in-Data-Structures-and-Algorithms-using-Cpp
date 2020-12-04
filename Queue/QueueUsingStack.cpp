#include "QueueUsingStack.h"

int main()
{
    QueueUsingStack que;
    que.add(1);
    que.add(11);
    que.add(111);
    std::cout << que.remove() << std::endl;
    que.add(2);
    que.add(21);
    que.add(211);
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;
    return 0;
}

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
