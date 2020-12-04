#pragma once

#include <string>
#include <vector>
#include <iostream>

class BubbleSort
{
private:
    std::vector<int>& arr;
    bool less(int value1, int value2);
    bool more(int value1, int value2);
public:
    BubbleSort(std::vector<int> &data);
    virtual void sort();
    virtual void sort2();
};
