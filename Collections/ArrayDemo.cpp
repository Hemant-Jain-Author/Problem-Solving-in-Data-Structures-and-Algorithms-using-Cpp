
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> arr(10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    for (auto  i = arr.begin(); i != arr.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 
*/