#include "TwoStack.h"

int main()
{
    TwoStack st;
    for (int i = 0; i < 3; i++)
        st.push1(i);

    for (int j = 0; j < 3; j++)
        st.push2(j + 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << "stack one pop value is : " << st.pop1() << std::endl;
        std::cout << "stack two pop value is : " << st.pop2() << std::endl;
    }
    return 0;
}

TwoStack::TwoStack()
{
    top1 = -1;
    top2 = MAX_SIZE;
}

void TwoStack::push1(int value)
{
    if (top1 < top2 - 1)
    {
        data[++top1] = value;
    }
    else
    {
        throw ("StackFullException");
    }
}

void TwoStack::push2(int value)
{
    if (top1 < top2 - 1)
    {
        data[--top2] = value;
    }
    else
    {
        throw ("StackFullException");
    }
}

int TwoStack::pop1()
{
    if (top1 >= 0)
    {
        int value = data[top1--];
        return value;
    }
    else
    {
        throw ("StackEmptyException");
    }
}

int TwoStack::pop2()
{
    if (top2 < MAX_SIZE)
    {
        int value = data[top2++];
        return value;
    }
    else
    {
        throw ("StackEmptyException");
    }
}
