#pragma once

#include <vector>

class InsertionSort
{
private:
    std::vector<int>& arr;
    bool more(int value1, int value2);
public:
    InsertionSort(std::vector<int> &data);
    virtual void sort();
};
