#include <iostream>
#include <stack>

int main()
{
    std::stack<int> stk;

    for (auto i = 1; i <= 5 ; i++ )
    {
        stk.push(i);
    }

    for (auto i = 0; i < 5; i++)
    {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}

/*
5 4 3 2 1 
*/