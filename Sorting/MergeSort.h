#pragma once

#include <vector>

class MergeSort
{
private:
    std::vector<int>& arr;
    void merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex);
    void mergeSrt(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int upperIndex);

public:
    MergeSort(std::vector<int> &data);
    virtual void sort();
};
