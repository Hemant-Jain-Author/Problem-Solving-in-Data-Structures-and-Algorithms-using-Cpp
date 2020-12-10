#include <iostream>
#include <functional>
#include <queue>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::vector<int> arr = { 1, 2, 3, 4, 6, 5 };

    for (auto i : arr)
        minHeap.push(i);

    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;
    return 0;
}
/*
1 2 3 4 5 6 
*/


int main2()
{
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    std::vector<int> arr = { 1, 2, 3, 4, 6, 5 };

    for (auto i : arr)
        maxHeap.push(i);

    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;
    return 0;
}

/*
6 5 4 3 2 1
*/
