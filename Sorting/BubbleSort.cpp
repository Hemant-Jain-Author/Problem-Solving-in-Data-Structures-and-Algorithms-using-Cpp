#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<int> &data):
    arr(data)
{
}

bool BubbleSort::less(int value1, int value2)
{
    return value1 < value2;
}

bool BubbleSort::more(int value1, int value2)
{
    return value1 > value2;
}

void BubbleSort::sort()
{
    int size = arr.size();
    int i, j, temp;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (more(arr[j], arr[j + 1]))
            {
                /* Swapping */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSort::sort2()
{
    int size = arr.size();
    int i, j, temp, swapped = 1;
    for (i = 0; i < (size - 1) && swapped == 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (more(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
    }
}

int main()
{
    std::vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    BubbleSort bs = BubbleSort(data);
    bs.sort();
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> data2 = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    BubbleSort bs2 = BubbleSort(data2);
    bs2.sort2();
    for (int i = 0; i < data2.size(); i++)
    {
        std::cout << data2[i] << " ";
    }
    return 0;
}

/*
1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 8 9
*/
