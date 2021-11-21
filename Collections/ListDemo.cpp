#include <iostream>
#include <list>

int main()
{
    std::list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);

    for (auto var : ll)
        std::cout << var << " ";
    std::cout << std::endl;

    ll.pop_front();
    ll.pop_back();

    for (auto var : ll)
        std::cout << var << " ";
    std::cout << std::endl;

    return 0;
}
/*
1 2 3 
2
*/