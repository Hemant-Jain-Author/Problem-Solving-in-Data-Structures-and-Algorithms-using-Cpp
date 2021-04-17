#include <iostream>
#include <vector>
#include <queue>

int circularTour(std::vector<std::vector<int>> &arr, int n)
{
    std::queue<int> que;
    int nextPump = 0, prevPump;
    int count = 0;
    int petrol = 0;
    int ret;

    while (que.size() != n)
    {
        while (petrol >= 0 && que.size() != n)
        {
            que.push(nextPump);
            petrol += (arr[nextPump][0] - arr[nextPump][1]);
            nextPump = (nextPump + 1) % n;
        }
        while (petrol < 0 && que.size() > 0)
        {
            prevPump = que.front();
            que.pop();
            petrol -= (arr[prevPump][0] - arr[prevPump][1]);
        }
        count += 1;
        if (count == n)
            return -1;
    }
    if (petrol >= 0)
    {
        ret = que.front();
        que.pop();
        return ret;
    }
    else
        return -1;
}

int main()
{
    // Testing code
    std::vector<std::vector<int>> tour = { { 8, 6 }, { 1, 4 }, { 7, 6 } };
    std::cout << "Circular Tour : " << circularTour(tour, 3) << std::endl;
    return 0;
}

/*
Circular Tour : 2
*/

int convertXY(int src, int dst)
{
    std::queue<int> que;
    std::vector<int> arr(100);
    int steps = 0;
    int index = 0;
    int value;

    que.push(src);
    while (que.size() != 0)
    {
        value = que.front();
        que.pop();
        arr[index++] = value;

        if (value == dst)
        {
            for (int i = 0; i < index; i++)
                std::cout << arr[i] << std::endl;
            std::cout << "Steps count :: " << steps << std::endl;

            return steps;
        }
        steps++;
        if (value < dst)
            que.push(value * 2);
        else
            que.push(value - 1);
    }
    return -1;
}

int main2()
{
    convertXY(2, 7);
    return 0;
}

/*
2
4
8
7
Steps count :: 3
*/
#include <deque>

void maxSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::deque<int> que;
    for (int i = 0; i < size; i++)
    {
        // Remove out of range elements
        if (que.size() > 0 && que.front() <= i - k)
        {
            que.front();
            que.pop_front();
        }// Remove smaller values at left.

        while (que.size() > 0 && arr[que.back()] <= arr[i])
            que.pop_back();

        que.push_back(i);
        // Largest value in window of size k is at index que[0]
        // It is displayed to the screen.
        if (i >= (k - 1))
            std::cout << arr[que.front()] << " ";
    }
}

int main4()
{
    std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
    int k = 3;
    maxSlidingWindows(arr, 7, 3);
    return 0;
}

/*
75 92 92 92 90
*/

int minOfMaxSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::queue<int> que;
    int minVal = 999999;
    for (int i = 0; i < size; i++)
    {
        // Remove out of range elements
        if (que.size() > 0 && que.front() <= i - k)
        {
            que.front();
            que.pop();
        }

        // Remove smaller values at left.
        while (que.size() > 0 && arr[que.back()] <= arr[i])
        {
            que.front();
            que.pop();
        }

        que.push(i);
        // window of size k
        if (i >= (k - 1) && minVal > arr[que.front()])
            minVal = arr[que.front()];
    }
    std::cout << "Min of max is :: " << minVal << std::endl;
    return minVal;
}

int main5()
{
    std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
    int k = 3;
    minOfMaxSlidingWindows(arr, 7, 3);
    return 0;
}

/*
Min of max is :: 75
*/

void maxOfMinSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::queue<int> que;
    int maxVal = -999999;
    for (int i = 0; i < size; i++)
    {
        // Remove out of range elements
        if (que.size() > 0 && que.front() <= i - k)
        {
            que.front();
            que.pop();
        }// Remove smaller values at left.
        while (que.size() > 0 && arr[que.back()] >= arr[i])
        {
            que.front();
            que.pop();
        }
        que.push(i);
        // window of size k
        if (i >= (k - 1) && maxVal < arr[que.front()])
            maxVal = arr[que.front()];
    }
    std::cout << "Max of min is :: " << maxVal << std::endl;
}

int main6()
{
    std::vector<int> arr = { 11, 2, 75, 92, 59, 90, 55 };
    int k = 3;
    maxOfMinSlidingWindows(arr, 7, 3);
    // Output 59, as minimum values in sliding windows are [2, 2, 59, 59, 55]
    return 0;
}

/*
Max of min is :: 59
*/

void firstNegSlidingWindows(std::vector<int> arr, int size, int k)
{
    std::queue<int> que;

    for (int i = 0; i < size; i++)
    {
        // Remove out of range elements
        if (que.size() > 0 && que.front() <= i - k)
        {
            que.front();
            que.pop();
        }

        if (arr[i] < 0)
            que.push(i);
        // window of size k
        if (i >= (k - 1))
        {
            if (que.size() > 0)
                std::cout << arr[que.front()] << " ";
            else
                std::cout << "NAN" << " ";
        }
    }
}

int main7()
{
    std::vector<int> arr = { 3, -2, -6, 10, -14, 50, 14, 21 };
    int k = 3;
    firstNegSlidingWindows(arr, 8, 3);
    return 0;
}

/*
-2 -2 -6 -14 -14 NAN 
*/