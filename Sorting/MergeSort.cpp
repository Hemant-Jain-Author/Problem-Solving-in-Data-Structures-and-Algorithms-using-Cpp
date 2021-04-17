#include "MergeSort.h"
#include <iostream>

void MergeSort::merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int middleIndex, int upperIndex)
{
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperStop = upperIndex;
    int count = lowerIndex;
    while (lowerStart <= lowerStop && upperStart <= upperStop)
    {
        if (arr[lowerStart] < arr[upperStart])
        {
            tempArray[count++] = arr[lowerStart++];
        }
        else
        {
            tempArray[count++] = arr[upperStart++];
        }
    }
    while (lowerStart <= lowerStop)
    {
        tempArray[count++] = arr[lowerStart++];
    }
    while (upperStart <= upperStop)
    {
        tempArray[count++] = arr[upperStart++];
    }
    for (int i = lowerIndex; i <= upperIndex; i++)
    {
        arr[i] = tempArray[i];
    }
}

void MergeSort::mergeSrt(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex, int upperIndex)
{
    if (lowerIndex >= upperIndex)
    {
        return;
    }
    int middleIndex = (lowerIndex + upperIndex) / 2;
    mergeSrt(arr, tempArray, lowerIndex, middleIndex);
    mergeSrt(arr, tempArray, middleIndex + 1, upperIndex);
    merge(arr, tempArray, lowerIndex, middleIndex, upperIndex);
}

void MergeSort::sort()
{
    int size = arr.size();
    std::vector<int> tempArray(size);
    mergeSrt(arr, tempArray, 0, size - 1);
}

MergeSort::MergeSort(std::vector<int> &data):
    arr(data)
{
}

int main()
{
    std::vector<int> data = { 3, 4, 2, 1, 6, 5, 7, 8, 1, 1 };
    MergeSort m = MergeSort(data);
    m.sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    return 0;
}

/*
1 1 1 2 3 4 5 6 7 8
*/