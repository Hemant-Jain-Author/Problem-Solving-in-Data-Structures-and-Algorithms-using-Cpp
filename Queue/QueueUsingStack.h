
#include <string>
#include <stack>
#include <iostream>

class QueueUsingStack
{
private:
    std::stack<int> stk1;
    std::stack<int> stk2;

public:
    virtual void add(int value);
    virtual int remove();
};
