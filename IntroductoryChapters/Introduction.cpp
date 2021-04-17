#include <string>
#include <vector>
#include <iostream>
#include <functional> // for greater<int>
#include <algorithm>
#include <iostream>
#include <map>

void printArray(std::vector<int> &data)
{
    int count = data.size();
    std::cout << "[ ";
    for (int i = 0; i < count; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void swap(std::vector<int> &data, int x, int y)
{
    int temp = data[x];
    data[x] = data[y];
    data[y] = temp;
    return;
}

int sumArray(std::vector<int> &data)
{
    int size = data.size();
    int total = 0;
    for (int index = 0; index < size; index++)
    {
        total +=  data[index];
    }
    return total;
}

int main1()
{
    std::vector<int> data = { 1,2,3,4,5,6,7,8,9 };
    std::cout << "Sum of all the values in array: " << sumArray(data) << std::endl;
    return 0;
}

/*
Sum of all the values in array: 45
*/

void function2()
{
    std::cout << "fun2 line 1" << std::endl;
}

void function1()
{
    std::cout << "fun1 line 1" << std::endl;
    function2();
    std::cout << "fun1 line 2" << std::endl;
}

int main2()
{
    std::cout << "main line 1" << std::endl;
    function1();
    std::cout << "main line 2" << std::endl;
    return 0;
}

/*
main line 1
fun1 line 1
fun2 line 1
fun1 line 2
main line 2
*/

int sequentialSearch(std::vector<int> &data, int value)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        if (value == data[i])
            return i;
    }
    return -1;
}

int binarySearch(std::vector<int> &data, int value)
{
    int size = data.size();
    int mid;
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data[mid] == value)
        {
            return mid;
        }
        else
        {
            if (data[mid] < value)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main3()
{
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << "Sequential Search: " << sequentialSearch(arr, 7) << std::endl;
    std::cout << "Binary Search: " << binarySearch(arr, 7) << std::endl;
    return 0;
}

/*
Sequential Search: 6
Binary Search: 6
*/

void reverseArray(std::vector<int> &data, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

void reverseArray(std::vector<int> &data)
{
    int start = 0;
    int end = data.size() - 1;
    for (int i = start, j = end; i < j; i++, j--)
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}
void rotateArray(std::vector<int> &data, int k)
{
    int n = data.size();
    reverseArray(data, 0, k - 1);
    reverseArray(data, k, n - 1);
    reverseArray(data, 0, n - 1);
}
int main4()
{
    std::vector<int>  arr = { 1, 2, 3, 4, 5, 6 };
    rotateArray(arr, 2);
    printArray(arr);
    return 0;
}
/*
[ 1 2 3 4 5 6  ]
*/

int maxSubArraySum(std::vector<int> &data)
{
    int size = data.size();
    int maxSoFar = 0, maxEndingHere = 0;

    for (int i = 0; i < size; i++)
    {
        maxEndingHere = maxEndingHere + data[i];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}

int main5()
{
    std::vector<int> data = { 1,-2,3,4,-4,6,-4,8,2 };
    std::cout << "Max sub array sum :" << maxSubArraySum(data);
    return 0;
}

/*
Max sub array sum :15
*/



void waveArray(std::vector<int> &arr)
{
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for(int i = 0 ; i < size -1 ; i+= 2)
    {
        swap(arr, i, i+1);
    }
}
void waveArray2(std::vector<int> &arr)
{
    int size = arr.size();
    /* Odd elements are lesser then even elements. */
    for (int i = 1; i < size; i += 2)
    {
        if ((i - 1) >= 0 && arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if ((i + 1) < size && arr[i] > arr[i + 1])
        {
            swap(arr, i, i + 1);
        }
    }
}

/* Testing code */
int main6()
{
    std::vector<int> arr = { 8, 1, 2, 3, 4, 5, 6, 4, 2 };
    waveArray(arr);
    printArray(arr);;
    std::vector<int> arr2 = { 8, 1, 2, 3, 4, 5, 6, 4, 2 };
    waveArray2(arr2);
    printArray(arr2);
    return 0;
}
/*
[ 2 1 3 2 4 4 6 5 8 ]
[ 8 1 3 2 5 4 6 2 4 ]
*/
void indexArray(std::vector<int>& arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int curr = i;
        int value = -1;

        /* swaps to move elements in proper position. */
        while (arr[curr] != -1 && arr[curr] != curr)
        {
            int temp = arr[curr];
            arr[curr] = value;
            value = curr = temp;
        }

        /* check if some swaps happened. */
        if (value != -1)
        {
            arr[curr] = value;
        }
    }
}

void indexArray2(std::vector<int>& arr, int size)
{
    int temp, temp2;
    for (int i = 0; i < size; i++)
    {
        while (arr[i] != -1 && arr[i] != i)
        {
            /* swap arr[i] and arr[arr[i]] */
            temp = arr[i];
            temp2 = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp2;
        }
    }
}

/* Testing code */
int main7()
{
    std::vector<int> arr = { 8, -1, 6, 1, 9, 3, 2, 7, 4, -1 };
    int size = arr.size();
    indexArray2(arr, size);
    printArray(arr);
    std::vector<int> arr2 = { 8, -1, 6, 1, 9, 3, 2, 7, 4, -1 };
    size = arr2.size();
    indexArray(arr2, size);
    printArray(arr2);
    return 0;
}
/*
[ 8 -1 6 1 9 3 2 7 4 -1 ]
[ 8 -1 6 1 9 3 2 7 4 -1 ]
*/
void sort1toN(std::vector<int> &arr, int size)
{
    int curr, value, next;
    for (int i = 0; i < size; i++)
    {
        curr = i;
        value = -1;
        /* swaps to move elements in proper position. */
        while (curr >= 0 && curr < size && arr[curr] != curr + 1)
        {
            next = arr[curr];
            arr[curr] = value;
            value = next;
            curr = next - 1;
        }
    }
}

void sort1toN2(std::vector<int> &arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        while (arr[i] != i + 1 && arr[i] > 1)
        {
            temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }
}

int main8()
{
    std::vector<int> arr = { 8, 5, 6, 1, 9, 3, 2, 7, 4, 10 };
    int size = arr.size();
    sort1toN2(arr, size);
    printArray(arr);
    std::vector<int> arr2 = { 8, 5, 6, 1, 9, 3, 2, 7, 4, 10 };
    size = arr2.size();
    sort1toN(arr2, size);
    printArray(arr2);
    return 0;
}
/*
[ 1 2 3 4 5 6 7 8 9 10 ]
[ 1 2 3 4 5 6 7 8 9 10 ]
*/

int smallestPositiveMissingNumber(std::vector<int> &arr, int size)
{
    int found;
    for (int i = 1; i < size + 1; i++)
    {
        found = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == i)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            return i;
        }
    }
    return -1;
}

int smallestPositiveMissingNumber2(std::vector<int> &arr, int size)
{
    std::map<int, int> hs;
    for (int i = 0; i < size; i++)
    {
        hs[arr[i]] = 1;
    }
    for (int i = 1; i < size + 1; i++)
    {
        if (hs.find(i) == hs.end())
        {
            return i;
        }
    }
    return -1;
}

int smallestPositiveMissingNumber3(std::vector<int> &arr, int size)
{
    std::vector<int> aux(size, -1);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] <= size)
        {
            aux[arr[i] - 1] = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (aux[i] != i + 1)
        {
            return i + 1;
        }
    }
    return -1;
}

int smallestPositiveMissingNumber4(std::vector<int> &arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        while (arr[i] != i + 1 && arr[i] > 0 && arr[i] <= size)
        {
            temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return -1;
}

int main9()
{
    std::vector<int> arr = { 8, 5, 6, 1, 9, 11, 2, 7, 4, 10 };
    int size = arr.size();

    std::cout << "Smallest Positive Missing Number: " << smallestPositiveMissingNumber(arr, size) << std::endl;
    std::cout << "Smallest Positive Missing Number: " << smallestPositiveMissingNumber2(arr, size) << std::endl;
    std::cout << "Smallest Positive Missing Number: " << smallestPositiveMissingNumber3(arr, size) << std::endl;
    std::cout << "Smallest Positive Missing Number: " << smallestPositiveMissingNumber4(arr, size) << std::endl;
    return 0;
}

/*
Smallest Positive Missing Number: 3
Smallest Positive Missing Number: 3
Smallest Positive Missing Number: 3
Smallest Positive Missing Number: 3
*/

void maxMinArr(std::vector<int> &arr, int size)
{
    std::vector<int> aux = arr;
    int start = 0;
    int stop = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = aux[stop];
            stop -= 1;
        }
        else
        {
            arr[i] = aux[start];
            start += 1;
        }
    }
}

void reverseArr(std::vector<int> &arr, int start, int stop)
{
    while (start < stop)
    {
        swap(arr, start, stop);
        start += 1;
        stop -= 1;
    }
}

void maxMinArr2(std::vector<int> &arr, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        reverseArr(arr, i, size - 1);
    }
}

/* Testing code */
int main10()
{
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
    int size = arr.size();
    maxMinArr(arr, size);
    printArray(arr);
    std::vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
    int size2 = arr.size();
    maxMinArr2(arr2, size2);
    printArray(arr2);
    return 0;
}

/*
[ 7 1 6 2 5 3 4 ]
[ 7 1 6 2 5 3 4 ]
*/

int maxCircularSum(std::vector<int> &arr, int size)
{
    int sumAll = 0;
    int currVal = 0;
    int maxVal;

    for (int i = 0; i < size; i++)
    {
        sumAll += arr[i];
        currVal += (i * arr[i]);
    }
    maxVal = currVal;
    for (int i = 1; i < size; i++)
    {
        currVal = (currVal + sumAll) - (size * arr[size - i]);
        if (currVal > maxVal)
        {
            maxVal = currVal;
        }
    }
    return maxVal;
}

/* Testing code */
int main11()
{
    std::vector<int> arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    std::cout << "MaxCirculrSm: " << maxCircularSum(arr, arr.size()) << std::endl;
    return 0;
}

/*
MaxCirculrSm: 290
*/

int arrayIndexMaxDiff(std::vector<int> &arr, int size)
{
    int maxDiff = -1;
    int j;
    for (int i = 0; i < size; i++)
    {
        j = size - 1;
        while (j > i)
        {
            if (arr[j] > arr[i])
            {
                maxDiff = std::max(maxDiff, j - i);
                break;
            }
            j -= 1;
        }
    }
    return maxDiff;
}

int arrayIndexMaxDiff2(std::vector<int> &arr, int size)
{
    std::vector<int> leftMin(size);
    std::vector<int> rightMax(size);
    leftMin[0] = arr[0];
    int i, j;
    int maxDiff;
    for (i = 1; i < size; i++)
    {
        if (leftMin[i - 1] < arr[i])
        {
            leftMin[i] = leftMin[i - 1];
        }
        else
        {
            leftMin[i] = arr[i];
        }
    }
    rightMax[size - 1] = arr[size - 1];
    for (i = size - 2; i >= 0; i--)
    {
        if (rightMax[i + 1] > arr[i])
        {
            rightMax[i] = rightMax[i + 1];
        }
        else
        {
            rightMax[i] = arr[i];
        }
    }
    i = 0;
    j = 0;
    maxDiff = -1;
    while (j < size && i < size)
    {
        if (leftMin[i] < rightMax[j])
        {
            maxDiff = std::max(maxDiff, j - i);
            j = j + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    return maxDiff;
}

int main12()
{
    std::vector<int> arr = { 33, 9, 10, 3, 2, 60, 30, 33, 1 };
    std::cout << "ArrayIndexMaxDiff : " << arrayIndexMaxDiff(arr, arr.size()) << std::endl;
    std::cout << "ArrayIndexMaxDiff : " << arrayIndexMaxDiff2(arr, arr.size()) << std::endl;
    return 0;
}

/*
ArrayIndexMaxDiff : 6
ArrayIndexMaxDiff : 6
*/

int maxPathSum(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, result = 0, sum1 = 0, sum2 = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            sum1 += arr1[i];
            i += 1;
        }
        else if (arr1[i] > arr2[j])
        {
            sum2 += arr2[j];
            j += 1;
        }
        else
        {
            result += std::max(sum1, sum2);
            result = result + arr1[i];
            sum1 = 0;
            sum2 = 0;
            i += 1;
            j += 1;
        }
    }
    while (i < size1)
    {
        sum1 += arr1[i];
        i += 1;
    }

    while (j < size2)
    {
        sum2 += arr2[j];
        j += 1;
    }

    result += std::max(sum1, sum2);
    return result;
}

/* Testing code */
int main13()
{
    int arr1[] = { 12, 13, 18, 20, 22, 26, 70 };
    int arr2[] = { 11, 15, 18, 19, 20, 26, 30, 31 };
    std::cout << "Max Path Sum :: " << maxPathSum(arr1, 7, arr2, 8) << std::endl;
    return 0;
}

/*
Max Path Sum :: 201
*/

int factorial(int i)
{
    // Termination Condition
    if (i <= 1)
    {
        return 1;
    }
    // Body, Recursive Expansion
    return i * factorial(i - 1);
}

void printInt1(int number)
{
    char digit = static_cast<char>(number % 10 + '0');
    number = number / 10;
    if (number != 0)
    {
        printInt1(number);
    }
    std::cout << digit;
}

void printInt(int number, int const base)
{
    std::string conversion = "0123456789ABCDEF";
    char digit = static_cast<char>(number % base);
    number = number / base;
    if (number != 0)
    {
        printInt(number, base);
    }
    std::cout << " " << conversion[digit];
}


void towerOfHanoi(int num, char src, char dst, char temp)
{
    if (num < 1)
        return;

    towerOfHanoi(num - 1, src, temp, dst);
    std::cout << "Move " << num << " disk  from peg " << src << " to peg " << dst << std::endl;
    towerOfHanoi(num - 1, temp, dst, src);
}

int main14()
{
    int num = 3;
    std::cout << "The sequence of moves involved in the Tower of Hanoi are :" << std::endl;
    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}
/*
The sequence of moves involved in the Tower of Hanoi are :
Move 1 disk  from peg A to peg C
Move 2 disk  from peg A to peg B
Move 1 disk  from peg C to peg B
Move 3 disk  from peg A to peg C
Move 1 disk  from peg B to peg A
Move 2 disk  from peg B to peg C
Move 1 disk  from peg A to peg C
*/
int gcd(int m, int n)
{
    if (m < n)
    {
        return gcd(n, m);
    }
    if (m % n == 0)
    {
        return (n);
    }
    return gcd(n, m % n);
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void permutation(std::vector<int> &data, int i, int length)
{
    if (length == i)
    {
        printArray(data);
        return;
    }
    int j = i;
    for (j = i; j < length; j++)
    {
        swap(data, i, j);
        permutation(data, i + 1, length);
        swap(data, i, j);
    }
    return;
}

int main15()
{
    std::vector<int> data(3);
    for (int i = 0; i < 3; i++)
    {
        data[i] = i;
    }
    permutation(data, 0, 3);
    return 0;
}
/*
[ 0 1 2 ]
[ 0 2 1 ]
[ 1 0 2 ]
[ 1 2 0 ]
[ 2 1 0 ]
[ 2 0 1 ]
*/

void twoDArrayExample()
{
    int  data[4][2];
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            data[i][j] = count++;
        }
    }
    //print2DArray(data);
}

template<typename T, int R, int C>
void print2DArray(T(&data)[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            std::cout << " " << data[i][j] << std::endl;
        }
    }
}


bool binarySearchRecursive(std::vector<int> &data, int low, int high, int value)
{
    if(low > high)
        return false;
    
    int mid = (low + high) / 2;
    if (data[mid] == value)
    {
        return true;
    }
    else if (data[mid] < value)
    {
        return binarySearchRecursive(data, mid + 1, high, value);
    }
    else
    {
        return binarySearchRecursive(data, low, mid - 1, value);
    }
}

/* Testing code */
int main16()
{
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 9 };
    std::cout << binarySearchRecursive(arr, 0, arr.size() - 1, 6) << std::endl;
    std::cout << binarySearchRecursive(arr, 0, arr.size() - 1, 16) << std::endl;
    return 0;
}

/*
1
0
*/

int main()
{
    main1();
    main2();
    main3();
    main4();
    main5();
    main6();
    main7();
    main8();
    main9();
    main10();
    main11();
    main12();
    main13();
    main14();
    main15();
    main16();
    return 0;
}