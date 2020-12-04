#pragma once

#include <vector>

class SelectionSort
{
private:
    std::vector<int>& arr;
    bool less(int value1, int value2);
    bool more(int value1, int value2);

public:
    SelectionSort(std::vector<int> &data);
    virtual void sort(); // back array
    virtual void sort2(); // front array
};
