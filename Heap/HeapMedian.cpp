// HeapMedian.cpp : Defines the entry point for the console application.

#include "HeapMedian.h"

void MedianHeap::insert(int value)
{
	if (maxHeap.size() == 0 || maxHeap.top() >= value)
		maxHeap.push(value);
	else
		minHeap.push(value);

	// size balancing
	if (maxHeap.size() > minHeap.size() + 1) 
	{
		value = maxHeap.top(); 
		maxHeap.pop();
		minHeap.push(value);
	}

	if (minHeap.size() > maxHeap.size() + 1)
	{
		value = minHeap.top(); 
		minHeap.pop();
		maxHeap.push(value);
	}
}

int MedianHeap::getMedian()
{
	if (maxHeap.size() == 0 && minHeap.size() == 0)
		throw "HeapEmptyException";

	if (maxHeap.size() == minHeap.size())
		return (maxHeap.top() + minHeap.top()) / 2;
	else if (maxHeap.size() > minHeap.size())
		return maxHeap.top();
	else
		return minHeap.top();
}

int  main()
{
	std::vector<int> arr = { 1, 9, 2, 8, 3, 7, 4, 6, 5, 1, 9, 2, 8, 3, 7, 4, 6, 5, 10, 10 };
	MedianHeap hp;

	for (int i = 0; i < 20; i++)
	{
		hp.insert(arr[i]);
		std::cout << "Median after insertion of " << arr[i] << " is " << hp.getMedian() << std::endl;
	}
}