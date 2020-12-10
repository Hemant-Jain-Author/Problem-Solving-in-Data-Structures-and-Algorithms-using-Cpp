
#include <iostream>
#include <queue>

int main()
{
    std::queue<int> que;

    for (auto i = 1; i <= 5 ; i++ )
    {
        que.push(i);
    }

    for (auto i = 0; i < 5; i++)
    {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;

    return 0;
}
/*
1 2 3 4 5 
*/

#include <iostream>
#include <deque>

int main2()
{
    std::deque<int> que;

    for (auto i = 1; i <= 5 ; i++ )
    {
        que.push_back(i);
    }

    for (auto i = 0; i < 5; i++)
    {
        std::cout << que.back() << " ";
        que.pop_back();  //stack behaviour.
    }
    std::cout << std::endl;

    return 0;
}

/*
5 4 3 2 1 
*/
