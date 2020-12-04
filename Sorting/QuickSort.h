#pragma once

#include <vector>

class QuickSort
{
private:
    std::vector<int>& arr;
    void swap(std::vector<int> &arr, int first, int second);
    void quickSortUtil(std::vector<int> &arr, int lower, int upper);

public:
    QuickSort(std::vector<int> &data);
    virtual void sort();
};
