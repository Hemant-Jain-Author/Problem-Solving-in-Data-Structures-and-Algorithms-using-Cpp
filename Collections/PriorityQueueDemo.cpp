#include <iostream>
#include <functional>
#include <queue>

int minheapdemo()
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	std::vector<int> arr = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };

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

int maxheapdemo()
{
	std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
	std::vector<int> arr = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };

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

int main()
{
	minheapdemo();
	maxheapdemo();
	return 0;
}