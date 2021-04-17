#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort(std::vector<int> &data):
    arr(data)
{
}

void QuickSort::swap(std::vector<int> &arr, int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void QuickSort::quickSortUtil(std::vector<int> &arr, int lower, int upper)
{
    if (upper <= lower)
    {
        return;
    }
    int pivot = arr[lower];
    int start = lower;
    int stop = upper;

    while (lower < upper)
    {
        while (arr[lower] <= pivot && lower < upper)
        {
            lower++;
        }
        while (arr[upper] > pivot && lower <= upper)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr, upper, lower);
        }
    }
    swap(arr, upper, start); // upper is the pivot position

    quickSortUtil(arr, start, upper - 1); // pivot -1 is the upper for left sub array.
    quickSortUtil(arr, upper + 1, stop); // pivot + 1 is the lower for right sub array.
}

void QuickSort::sort()
{
    int size = arr.size();
    quickSortUtil(arr, 0, size - 1);
}

int main()
{
    std::vector<int> data = { 3, 4, 2, 1, 6, 5, 7, 8, 1, 1 };
    QuickSort q = QuickSort(data);
    q.sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    return 0;
}

/*
1 1 1 2 3 4 5 6 7 8
*/