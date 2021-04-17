#include "InsertionSort.h"
#include <iostream>

InsertionSort::InsertionSort(std::vector<int> &data):
    arr(data)
{
}

bool InsertionSort::more(int value1, int value2)
{
    return value1 > value2;
}

void InsertionSort::sort()
{
    int size = arr.size();
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && more(arr[j - 1], temp); j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main()
{
    std::vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    InsertionSort is = InsertionSort(data);
    is.sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";

    }
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 
*/
