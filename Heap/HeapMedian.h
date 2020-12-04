#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <functional> // for greater<int>
#include <exception>

class MedianHeap
{
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

public:
    virtual void insert(int value);
    virtual int getMedian();
};
