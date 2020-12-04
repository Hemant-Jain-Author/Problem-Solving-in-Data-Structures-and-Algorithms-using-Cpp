#include "Searching.h"
/*
int main()
{
	std::vector<int> first = {1, 3, 5, 7, 9, 25, 30};
	std::vector<int> second = {2, 4, 6, 8, 10, 12, 14, 16, 21, 23, 24};

	for (int i = 1; i < 16; i++)
	{
		std::cout << "Index : " << i << " Value : ";
		std::cout << findkth(first, second, i) << std::endl;
	}
	return 0;
}
*/
bool linearSearchUnsorted(std::vector<int> &data, int value)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        if (value == data[i])
        {
            return true;
        }
    }
    return false;
}

bool linearSearchSorted(std::vector<int> &data, int value)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        if (value == data[i])
        {
            return true;
        }
        else if (value < data[i])
        {
            return false;
        }
    }
    return false;
}

bool binarysearch(std::vector<int> &data, int value)
{
    int size = data.size();
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data[mid] == value)
        {
            return true;
        }
        else if (data[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

bool binarysearchRecursive(std::vector<int> &data, int low, int high, int value)
{
    if (low > high)
    {
        return false;
    }
    int mid = (low + high) / 2;
    if (data[mid] == value)
    {
        return true;
    }
    else if (data[mid] < value)
    {
        return binarysearchRecursive(data, mid + 1, high, value);
    }
    else
    {
        return binarysearchRecursive(data, low, mid - 1, value);
    }
}

bool binarysearchRec(std::vector<int> &arr, int value)
{
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    return binarysearchRecursive(arr, low, high, value);
}

int main1()
{
    std::vector<int> first = { 1, 3, 5, 7, 9, 25, 30 };
    std::cout << linearSearchUnsorted(first, 8) << std::endl;
    std::cout << linearSearchSorted(first, 8) << std::endl;
    std::cout << binarysearch(first, 8) << std::endl;
    std::cout << binarysearchRec(first, 8) << std::endl;
    std::cout << linearSearchUnsorted(first, 25) << std::endl;
    std::cout << linearSearchSorted(first, 25) << std::endl;
    std::cout << binarysearch(first, 25) << std::endl;
    std::cout << binarysearchRec(first, 25) << std::endl;
    return 0;
}

void swap(std::vector<int> &data, int first, int second)
{
    int temp = data[first];
    data[first] = data[second];
    data[second] = temp;
}

int firstRepeated(std::vector<int> &data)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (data[i] == data[j])
                return data[i];
        }
    }
    return 0;
}

int main2()
{
    std::vector<int> first = { 34, 56, 77, 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 34, 20, 30 };
    std::cout << firstRepeated(first) << std::endl;
    return 0;
}

void printRepeating(std::vector<int> &data)
{
    int size = data.size();
    std::cout << " Repeating elements are : ";
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (data[i] == data[j])
                std::cout << " " << data[i];
        }
    }
}

void printRepeating2(std::vector<int> &data)
{
    int size = data.size();
    sort(data.begin(), data.end()); // Sort(data,size);
    std::cout << " Repeating elements are : ";

    for (int i = 1; i < size; i++)
    {
        if (data[i] == data[i - 1])
            std::cout << " " << data[i];
    }
}

void printRepeating3(std::vector<int> &data)
{
    std::unordered_set<int> hs;
    int size = data.size();
    std::cout << " Repeating elements are : ";
    for (int i = 0; i < size; i++)
    {
        if (std::find(hs.begin(), hs.end(), data[i]) != hs.end())
            std::cout << " " << data[i];
        else
            hs.insert(data[i]);
    }
}

void printRepeating4(std::vector<int> &data, int range)
{
    int size = data.size();
    std::vector<int> count(range, 0);

    std::cout << " Repeating elements are : ";
    for (int i = 0; i < size; i++)
    {
        if (count[data[i]] == 1)
            std::cout << " " << data[i];
        else
            count[data[i]]++;
    }
}

int main3()
{
    std::vector<int> first = { 1, 3, 5, 3, 9, 1, 30 };
    printRepeating(first);
    printRepeating2(first);
    printRepeating3(first);
    printRepeating4(first, 50);
    return 0;
}


void removeDuplicates(std::vector<int> &data)
{
    int j = 0;
    int size = data.size();
    if (size == 0)
        return;

    sort(data.begin(), data.end()); // Sort(array,size);
    for (int i = 1; i < size; i++)
    {
        if (data[i] != data[j])
        {
            j++;
            data[j] = data[i];
        }
    }
    data.erase(data.begin()+j, data.end());
}

int main4()
{
    std::vector<int> first = { 1, 3, 5, 3, 9, 1, 30 };
    removeDuplicates(first);
    for (int i = 0; i < first.size(); i++)
    {
        std::cout << first[i] + " ";
    }
    return 0;
}

int findMissingNumber(std::vector<int> &data)
{
    int found;
    int size = data.size();
    for (int i = 1; i <= size; i++)
    {
        found = 0;
        for (int j = 0; j < size; j++)
        {
            if (data[j] == i)
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
    throw ("NoNumberMissing");
}

int findMissingNumber2(std::vector<int> &data, int range)
{
    int size = data.size();
    int xorSum = 0;
    // get the XOR of all the numbers from 1 to range
    for (int i = 1; i <= range; i++)
    {
        xorSum ^= i;
    }
    // loop through the array and get the XOR of elements
    for (int i = 0; i < size; i++)
    {
        xorSum ^= data[i];
    }
    return xorSum;
}

int findMissingNumber3(std::vector<int> &arr, int upperRange)
{
    std::set<int> st;
    int size = arr.size();
    int i = 0;
    while (i < size)
    {
        st.insert(arr[i]);
        i += 1;
    }
    i = 1;
    while (i <= upperRange)
    {
        if (st.count(i) == 0)
            return i;
        i += 1;
    }
    std::cout << "NoNumberMissing" << std::endl;
    return -1;
}

int main5()
{
    std::vector<int> first= { 1, 3, 5, 4, 6, 8, 7 };
    std::cout << findMissingNumber(first) << std::endl;
    std::cout << findMissingNumber2(first, 8) << std::endl;
    std::cout << findMissingNumber3(first, 8) << std::endl;
    return 0;
}

void MissingValues(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int size = arr.size();
    int value = arr[0];
    int i = 0;
    while (i < size)
    {
        if (value == arr[i])
        {
            value += 1;
            i += 1;
        }
        else
        {
            std::cout << value << std::endl;
            value += 1;
        }
    }
}

void MissingValues2(std::vector<int> &arr)
{
    std::set<int> st;
    int minVal = 999999;
    int maxVal = -999999;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        st.insert(arr[i]);
        if (minVal > arr[i])
            minVal = arr[i];
        if (maxVal < arr[i])
            maxVal = arr[i];
    }
    for (int i = minVal; i < maxVal + 1; i++)
    {
        if (st.find(i) == st.end())
        {
            std::cout << i << std::endl;
        }
    }
}

int main6()
{
    std::vector<int> arr = { 1, 9, 2, 8, 3, 7, 4, 6 };
    int size = arr.size();
    MissingValues(arr);
    MissingValues2(arr);
    return 0;
}


void OddCount(std::vector<int> &arr)
{
    std::map<int, int> ctr;
    int count = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (ctr.find(arr[i]) != ctr.end())
            ctr[arr[i]] +=  1;
        else
            ctr[arr[i]] = 1;
    }
    for (int i = 0; i < size; i++)
    {
        if (ctr.find(arr[i]) != ctr.end() && (ctr[arr[i]] % 2 == 1))
        {
            std::cout << arr[i] << std::endl;
            count++;
            ctr.erase(arr[i]);
        }
    }
    std::cout << "Odd count is :: " << count << std::endl;
}

void OddCount2(std::vector<int> &arr)
{
    int xorSum = 0;
    int first = 0;
    int second = 0;
    int setBit;
    int size = arr.size();
    /*
     * xor of all elements in arr[] even occurrence will cancel each other. sum will
     * contain sum of two odd elements.
     */
    for (int i = 0; i < size; i++)
        xorSum = xorSum ^ arr[i];

    /* Rightmost set bit. */
    setBit = xorSum & ~(xorSum - 1);

    /*
     * Dividing elements in two group: Elements having setBit bit as 1. Elements
     * having setBit bit as 0. Even elements cancelled themselves if group and we
     * get our numbers.
     */
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] & setBit) != 0)
            first ^= arr[i];
        else
            second ^= arr[i];
    }
    std::cout << first + second << std::endl;
}

void SumDistinct(std::vector<int> &arr)
{
    int sum = 0;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < (size - 1); i++)
    {
        if (arr[i] != arr[i + 1])
            sum += arr[i];
    }
    sum += arr[size - 1];
    std::cout << sum << std::endl;
}

void minAbsSumPair(std::vector<int> &arr)
{
    int l, r, minSum, sum, minFirst, minSecond;
    int size = arr.size();
    // Array should have at least two elements
    if (size < 2)
    {
        std::cout << "Invalid Input" << std::endl;
        return;
    }
    // Initialization of values
    minFirst = 0;
    minSecond = 1;
    minSum = std::abs(arr[0] + arr[1]);
    for (l = 0; l < size - 1; l++)
    {
        for (r = l + 1; r < size; r++)
        {
            sum = std::abs(arr[l] + arr[r]);
            if (sum < minSum)
            {
                minSum = sum;
                minFirst = l;
                minSecond = r;
            }
        }
    }
    std::cout << " Minimum sum elements are : " << arr[minFirst] << " , " << arr[minSecond] << std::endl;
}

void minAbsSumPair2(std::vector<int> &arr)
{
    int l, r, minSum, sum, minFirst, minSecond;
    int size = arr.size();
    // Array should have at least two elements
    if (size < 2)
    {
        std::cout << "Invalid Input" << std::endl;
        return;
    }
    std::sort(arr.begin(), arr.end());

    // Initialization of values
    minFirst = 0;
    minSecond = size - 1;
    minSum = std::abs(arr[minFirst] + arr[minSecond]);
    for (l = 0, r = size - 1; l < r;)
    {
        sum = (arr[l] + arr[r]);
        if (std::abs(sum) < minSum)
        {
            minSum = std::abs(sum);/// just corrected......hemant
            minFirst = l;
            minSecond = r;
        }
        if (sum < 0)
        {
            l++;
        }
        else if (sum > 0)
        {
            r--;
        }
        else
        {
            break;
        }
    }
    std::cout << " Minimum sum pair : " << arr[minFirst] << " , " << arr[minSecond] << std::endl;
}

int main7()
{
    std::vector<int> first = { 1, 5, -10, 3, 2, -6, 8, 9, 6 };
    minAbsSumPair2(first);
    minAbsSumPair(first);
    return 0;
}

bool findPair(std::vector<int> &arr, int value)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] + arr[j]) == value)
            {
                std::cout << "The pair is : " << arr[i] << "," << arr[j] << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool findPair2(std::vector<int> &arr, int value)
{
    int size = arr.size();
    int first = 0, second = size - 1;
    int curr;
    std::sort(arr.begin(), arr.end());
    while (first < second)
    {
        curr = arr[first] + arr[second];
        if (curr == value)
        {
            std::cout << "The pair is " << arr[first] << "," << arr[second] << std::endl;
            return true;
        }
        else if (curr < value)
        {
            first++;
        }
        else
        {
            second--;
        }
    }
    return false;
}

bool findPair3(std::vector<int> &arr, int value)
{
    std::set<int> hs;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (hs.find(value - arr[i]) != hs.end())
        {
            std::cout << "The pair is : " << arr[i] << " , " << (value - arr[i]) << std::endl;
            return true;
        }
        hs.insert(arr[i]);
    }
    return false;
}


int main8()
{
    std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
    std::cout << findPair(first, 8) << std::endl;
    std::cout << findPair2(first, 8) << std::endl;
    std::cout << findPair3(first, 8) << std::endl;
    return 0;
}

bool FindDifference(std::vector<int> &arr, int value)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (std::abs(arr[i] - arr[j]) == value)
            {
                std::cout << "The pair is:: " << arr[i] << " & " << arr[j] << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool FindDifference2(std::vector<int> &arr, int value)
{
    int first = 0;
    int second = 0;
    int diff;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    while (first < size && second < size)
    {
        diff = std::abs(arr[first] - arr[second]);
        if (diff == value)
        {
            std::cout << "The pair is::" << arr[first] << " & " << arr[second] << std::endl;
            return true;
        }
        else if (diff > value)
            first += 1;
        else
            second += 1;
    }
    return false;
}

int findMinDiff(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int diff = 9999999;
    int size = arr.size();

    for (int i = 0; i < (size - 1); i++)
    {
        if ((arr[i + 1] - arr[i]) < diff)
            diff = arr[i + 1] - arr[i];
    }
    return diff;
}

int MinDiffPair(std::vector<int> &arr1, std::vector<int> &arr2)
{
    int minDiff = 9999999;
    int size1 = arr1.size();
    int size2 = arr2.size();
    int first = 0;
    int second = 0;
    int out1 = 0, out2 = 0, diff;
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    while (first < size1 && second < size2)
    {
        diff = std::abs(arr1[first] - arr2[second]);
        if (minDiff > diff)
        {
            minDiff = diff;
            out1 = arr1[first];
            out2 = arr2[second];
        }
        if (arr1[first] < arr2[second])
            first += 1;
        else
            second += 1;
    }
    std::cout << "The pair is :: " << out1 << out2 << std::endl;
    std::cout << "Minimum difference is :: " + minDiff << std::endl;
    return minDiff;
}

int main88()
{
    std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
    std::cout << FindDifference(first, 6) << std::endl;
    std::cout << FindDifference2(first, 6) << std::endl;
    std::cout << findMinDiff(first) << std::endl;
    std::cout << MinDiffPair(first, first) << std::endl;
    return 0;
}

void ClosestPair(std::vector<int> &arr, int value)
{
    int diff = 999999;
    int first = -1;
    int second = -1;
    int curr;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            curr = std::abs(value - (arr[i] + arr[j]));
            if (curr < diff)
            {
                diff = curr;
                first = arr[i];
                second = arr[j];
            }
        }
    }
    std::cout << "closest pair is ::" << first << second << std::endl;
}

void ClosestPair2(std::vector<int> &arr, int value)
{
    int first = 0, second = 0;
    int start = 0;
    int size = arr.size();
    int stop = size - 1;
    int diff, curr;
    std::sort(arr.begin(), arr.end());
    diff = 9999999;
    {
        while (start < stop)
        {
            curr = (value - (arr[start] + arr[stop]));
            if (std::abs(curr) < diff)
            {
                diff = std::abs(curr);
                first = arr[start];
                second = arr[stop];
            }
            if (curr == 0)
            {
                break;
            }
            else if (curr > 0)
            {
                start += 1;
            }
            else
            {
                stop -= 1;
            }
        }
    }
    std::cout << "closest pair is :: " << first << second << std::endl;
}

int main99()
{
    std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
    ClosestPair(first, 6);
    ClosestPair2(first, 6);
    return 0;
}

bool SumPairRestArray(std::vector<int> &arr)
{
    int total, low, high, curr, value;
    std::sort(arr.begin(), arr.end());
    total = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
        total += arr[i];
    value = total / 2;
    low = 0;
    high = size - 1;
    while (low < high)
    {
        curr = arr[low] + arr[high];
        if (curr == value)
        {
            std::cout << "Pair is :: " << arr[low] << arr[high] << std::endl;
            return true;
        }
        else if (curr < value)
            low += 1;
        else
            high -= 1;
    }
    return false;
}

void ZeroSumTriplets(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < (size - 2); i++)
    {
        for (int j = i + 1; j < (size - 1); j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                    std::cout << "Triplet :: " << arr[i] << arr[j] << arr[k] << std::endl;
            }
        }
    }
}

void ZeroSumTriplets2(std::vector<int> &arr)
{
    int start, stop;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < (size - 2); i++)
    {
        start = i + 1;
        stop = size - 1;

        while (start < stop)
        {
            if (arr[i] + arr[start] + arr[stop] == 0)
            {
                std::cout << "Triplet :: " << arr[i] << arr[start] << arr[stop] << std::endl;
                start += 1;
                stop -= 1;
            }
            else if (arr[i] + arr[start] + arr[stop] > 0)
                stop -= 1;
            else
                start += 1;
        }
    }
}

void findTriplet(std::vector<int> &arr, int value)
{
    int size = arr.size();
    for (int i = 0; i < (size - 2); i++)
        for (int j = i + 1; j < (size - 1); j++)
            for (int k = j + 1; k < size; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == value)
                    std::cout << "Triplet :: " << arr[i] << " " << arr[j] << " " << arr[k] << std::endl;
            }
}

void findTriplet2(std::vector<int> &arr, int value)
{
    int start, stop;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < size - 2; i++)
    {
        start = i + 1;
        stop = size - 1;
        while (start < stop)
        {
            if (arr[i] + arr[start] + arr[stop] == value)
            {
                std::cout << "Triplet ::" << arr[i] << " " << arr[start] << " " << arr[stop] << std::endl;
                start += 1;
                stop -= 1;
            }
            else if (arr[i] + arr[start] + arr[stop] > value)
                stop -= 1;
            else
                start += 1;
        }
    }
}

void ABCTriplet(std::vector<int> &arr)
{
    int start, stop;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < (size - 1); i++)
    {
        start = 0;
        stop = size - 1;
        while (start < stop)
        {
            if (arr[i] == arr[start] + arr[stop])
            {
                std::cout << "Triplet ::%d, %d, %d" << arr[i] << " " << arr[start] << " " << arr[stop] << std::endl;
                start += 1;
                stop -= 1;
            }
            else if (arr[i] < arr[start] + arr[stop])
                stop -= 1;
            else
                start += 1;
        }
    }
}

void SmallerThenTripletCount(std::vector<int> &arr, int value)
{
    int start, stop;
    int count = 0;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < (size - 2); i++)
    {
        start = i + 1;
        stop = size - 1;
        while (start < stop)
        {
            if (arr[i] + arr[start] + arr[stop] >= value)
                stop -= 1;
            else
            {
                count += stop - start;
                start += 1;
            }
        }
    }
    std::cout << count << std::endl;
}

void APTriplets(std::vector<int> &arr)
{
    int i, j, k;
    int size = arr.size();
    for (i = 1; i < size - 1; i++)
    {
        j = i - 1;
        k = i + 1;
        while (j >= 0 && k < size)
        {
            if (arr[j] + arr[k] == 2 * arr[i])
            {
                std::cout << "Triplet ::" << arr[i] << " " << arr[j] << " " << arr[k] << std::endl;
                k += 1;
                j -= 1;
            }
            else if (arr[j] + arr[k] < 2 * arr[i])
                k += 1;
            else
                j -= 1;
        }
    }
}

void GPTriplets(std::vector<int> &arr)
{
    int i, j, k;
    int size = arr.size();
    for (i = 1; i < size - 1; i++)
    {
        j = i - 1;
        k = i + 1;
        while (j >= 0 && k < size)
        {
            if (arr[j] * arr[k] == arr[i] * arr[i])
            {
                std::cout << "Triplet is :: " << arr[i] << " " << arr[j] << " " << arr[k] << std::endl;
                k += 1;
                j -= 1;
            }
            else if (arr[j] + arr[k] < 2 * arr[i])
                k += 1;
            else
                j -= 1;
        }
    }
}

int numberOfTriangles(std::vector<int> &arr)
{
    int i, j, k, count = 0;
    int size = arr.size();
    for (i = 0; i < (size - 2); i++)
    {
        for (j = i + 1; j < (size - 1); j++)
        {
            for (k = j + 1; k < size; k++)
            {
                if ((arr[i] + arr[j] > arr[k]) && (arr[k] + arr[j] > arr[i]) && (arr[i] + arr[k] > arr[j]))
                    count += 1;
            }
        }
    }
    return count;
}

int numberOfTriangles2(std::vector<int> &arr)
{
    int i, j, k, count = 0;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());

    for (i = 0; i < (size - 2); i++)
    {
        k = i + 2;
        for (j = i + 1; j < (size - 1); j++)
        {
            /*
             * if sum of arr[i] & arr[j] is greater arr[k] then sum of arr[i] & arr[j + 1]
             * is also greater than arr[k] this improvement make algo O(n2)
             */
            while (k < size && arr[i] + arr[j] > arr[k])
                k += 1;

            count += k - j - 1;
        }
    }
    return count;
}

int getMax(std::vector<int> &arr)
{
    int max = arr[0], count = 1, maxCount = 1;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            max = arr[i];
            maxCount = count;
        }
    }
    return max;
}

int getMax2(std::vector<int> &arr)
{
    int max = arr[0], maxCount = 1;
    int curr = arr[0], currCount = 1;
    int size = arr.size();
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currCount++;
        }
        else
        {
            currCount = 1;
            curr = arr[i];
        }
        if (currCount > maxCount)
        {
            maxCount = currCount;
            max = curr;
        }
    }
    return max;
}

int getMax3(std::vector<int> &arr, int range)
{
    int max = arr[0], maxCount = 1;
    int size = arr.size();
    std::vector<int> count(range, 0);
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] > maxCount)
        {
            maxCount = count[arr[i]];
            max = arr[i];
        }
    }
    return max;
}

int main9()
{
    std::vector<int> first = { 1, 30, 5, 13, 9, 31, 5 };
    std::cout << getMax(first) << std::endl;
    std::cout << getMax2(first) << std::endl;
    std::cout << getMax3(first, 50) << std::endl;
    return 0;
}


int getMajority(std::vector<int> &data)
{
    int size = data.size();
    int max = 0, count = 0, maxCount = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (data[i] == data[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            max = data[i];
            maxCount = count;
        }
    }
    if (maxCount > size / 2)
        return max;
    else
        throw ("MajorityDoesNotExist");
}

int getMajority2(std::vector<int> &data)
{
    int size = data.size();
    int majIndex = size / 2, count = 1;
    int candidate;
    sort(data.begin(), data.end()); // Sort(data,size);
    candidate = data[majIndex];
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == candidate)
            count++;
    }

    if (count > size / 2)
        return data[majIndex];
    else
        throw ("MajorityDoesNotExist");
}

int getMajority3(std::vector<int> &data)
{
    int majIndex = 0, count = 1;
    int candidate;
    int size = data.size();

    for (int i = 1; i < size; i++)
    {
        if (data[majIndex] == data[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }
    candidate = data[majIndex];
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == candidate)
        {
            count++;
        }
    }
    if (count > size / 2)
        return data[majIndex];
    else
        throw ("MajorityDoesNotExist");
}


int main10()
{
    std::vector<int> first = { 1, 5, 5, 13, 5, 31, 5 };
    std::cout << getMajority(first) << std::endl;
    std::cout << getMajority2(first) << std::endl;
    std::cout << getMajority3(first) << std::endl;
    return 0;
}


int getMedian(std::vector<int> &data)
{
    int size = data.size();
    sort(data.begin(), data.end()); // Sort(data, size);
    return data[size / 2];
}


int searchBitonicArrayMax(std::vector<int> &arr)
{
    int size = arr.size();
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;
    int maximaFound = 0;
    if (size < 3)
    {
        std::cout << "error" << std::endl;
        return 0;
    }
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])// maxima
        {
            maximaFound = 1;
            break;
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])  // increasing
        {
            start = mid + 1;
        }
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])  // decreasing
        {
            end = mid - 1;
        }
        else
        {
            break;
        }
    }
    if (maximaFound == 0)
    {
        std::cout << "error" << std::endl;
        return 0;
    }
    return arr[mid];
}

int searchBitonicArray(std::vector<int> &arr, int key)
{
    int size = arr.size();
    int max = findMaxBitonicArray(arr);
    int k = binarysearch(arr, 0, max, key, true);
    if (k != -1)
    {
        return k;
    }
    else
    {
        return binarysearch(arr, max + 1, size - 1, key, false);
    }
}

int findMaxBitonicArray(std::vector<int> &arr)
{
    int size = arr.size();
    int start = 0, end = size - 1, mid;
    if (size < 3)
    {
        std::cout << "error" << std::endl;
        return -1;
    }
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])// maxima
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])  // increasing
        {
            start = mid + 1;
        }
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])  // increasing
        {
            end = mid - 1;
        }
        else
        {
            break;
        }
    }
    std::cout << "error" << std::endl;
    return -1;
}

int main11()
{
    std::vector<int> first = { 1, 5, 10, 13, 20, 30, 8, 7, 6 };

    std::cout << searchBitonicArrayMax(first) << std::endl;
    std::cout << searchBitonicArray(first, 7) << std::endl;
    return 0;
}

int findKeyCount(std::vector<int> &arr, int key)
{
    int count = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            count++;
        }
    }
    return count;
}

int findKeyCount2(std::vector<int> &arr, int key)
{
    int firstIndex, lastIndex;
    int size = arr.size();
    firstIndex = findFirstIndex(arr, 0, size - 1, key);
    lastIndex = findLastIndex(arr, 0, size - 1, key);
    return (lastIndex - firstIndex + 1);
}

/* Using binary search method. */
int FirstIndex(std::vector<int> &arr, int low, int high, int value)
{
    int mid = 0;
    if (high >= low)
        mid = (low + high) / 2;

    /*
     * Find first occurrence of value, either it should be the first element of the
     * array or the value before it is smaller than it.
     */
    if ((mid == 0 || arr[mid - 1] < value) && (arr[mid] == value))
        return mid;
    else if (arr[mid] < value)
        return FirstIndex(arr, mid + 1, high, value);
    else
        return FirstIndex(arr, low, mid - 1, value);
}

bool isMajority(std::vector<int> &arr)
{
    int size = arr.size();
    int majority = arr[size / 2];
    int i = FirstIndex(arr, 0, size - 1, majority);
    /*
     * we are using majority element form array so we will get some valid index
     * always.
     */
    if (((i + size / 2) <= (size - 1)) && arr[i + size / 2] == majority)
        return true;
    else
        return false;
}

int findFirstIndex(std::vector<int> &arr, int start, int end, int key)
{
    int mid;
    if (end < start)
    {
        return -1;
    }
    mid = (start + end) / 2;
    if (key == arr[mid] && (mid == start || arr[mid - 1] != key))
    {
        return mid;
    }
    if (key <= arr[mid])// <= is us the number.t in sorted array.
    {
        return findFirstIndex(arr, start, mid - 1, key);
    }
    else
    {
        return findFirstIndex(arr, mid + 1, end, key);
    }
}

int findLastIndex(std::vector<int> &arr, int start, int end, int key)
{
    if (end < start)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (key == arr[mid] && (mid == end || arr[mid + 1] != key))
    {
        return mid;
    }
    if (key < arr[mid])// <
    {
        return findLastIndex(arr, start, mid - 1, key);
    }
    else
    {
        return findLastIndex(arr, mid + 1, end, key);
    }
}

int main12()
{
    std::vector<int> first = { 1, 5, 10, 13, 20, 30, 8, 7, 6 };
    std::cout << findKeyCount(first, 6) << std::endl;
    std::cout << findKeyCount2(first, 6) << std::endl;
    return 0;
}

int maxProfit(std::vector<int> &stocks)
{
    int size = stocks.size();
    int buy = 0, sell = 0;
    int curMin = 0;
    int currProfit = 0;
    int maxProfit = 0;
    for (int i = 0; i < size; i++)
    {
        if (stocks[i] < stocks[curMin])
        {
            curMin = i;
        }
        currProfit = stocks[i] - stocks[curMin];
        if (currProfit > maxProfit)
        {
            buy = curMin;
            sell = i;
            maxProfit = currProfit;
        }
    }
    std::cout << "Purchase day is- " << buy << " at price " << stocks[buy] << std::endl;
    std::cout << "Sell day is- " << sell << " at price " << stocks[sell] << std::endl;
    return maxProfit;
}

int main133()
{
    std::vector<int> first = { 10, 150, 6, 67, 61, 16, 86, 6, 67, 78, 150, 3, 28, 143 };
    std::cout << maxProfit(first) << std::endl;
    return 0;
}

int findMedian(std::vector<int> arrFirst, std::vector<int>  arrSecond)
{
    int sizeFirst = arrFirst.size();
    int sizeSecond = arrSecond.size();

    int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) % 2) / 2;// cealing
    // function.
    int i = 0, j = 0;
    int count = 0;
    while (count < medianIndex - 1)
    {
        if (i < sizeFirst - 1 && arrFirst[i] < arrSecond[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        count++;
    }
    if (arrFirst[i] < arrSecond[j])
    {
        return arrFirst[i];
    }
    else
    {
        return arrSecond[j];
    }
}

int main13()
{
    std::vector<int> first = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
    std::vector<int> second = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
    std::cout << findMedian(first, second) << std::endl;
    return 0;
}

int binarysearch01(std::vector<int> &arr)
{
    int size = arr.size();
    if (size == 1 && arr[0] == 1)
    {
        return 0;
    }
    return binarysearch01Util(arr, 0, size - 1);
}

int binarysearch01Util(std::vector<int> &arr, int start, int end)
{
    if (end < start)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (1 == arr[mid] && 0 == arr[mid - 1])
    {
        return mid;
    }
    if (0 == arr[mid])
    {
        return binarysearch01Util(arr, mid + 1, end);
    }
    else
    {
        return binarysearch01Util(arr, start, mid - 1);
    }
}

int main14()
{
    std::vector<int> first = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };
    std::cout << binarysearch01(first) << std::endl;
    return 0;
}

int RotationMaxUtil(std::vector<int> &arr, int start, int end)
{
    if (end <= start)
    {
        return arr[start];
    }
    int mid = (start + end) / 2;
    if (arr[mid] > arr[mid + 1])
        return arr[mid];

    if (arr[start] <= arr[mid]) /* increasing part. */
        return RotationMaxUtil(arr, mid + 1, end);
    else
        return RotationMaxUtil(arr, start, mid - 1);
}

int RotationMax(std::vector<int> &arr)
{
    int size = arr.size();
    return RotationMaxUtil(arr, 0, size - 1);
}

int FindRotationMaxUtil(std::vector<int> &arr, int start, int end)
{
    /* single element case. */
    if (end <= start)
        return start;

    int mid = (start + end) / 2;
    if (arr[mid] > arr[mid + 1])
        return mid;

    if (arr[start] <= arr[mid]) /* increasing part. */
        return FindRotationMaxUtil(arr, mid + 1, end);
    else
        return FindRotationMaxUtil(arr, start, mid - 1);
}

int FindRotationMax(std::vector<int> &arr)
{
    int size = arr.size();
    return FindRotationMaxUtil(arr, 0, size - 1);
}

int CountRotation(std::vector<int> &arr)
{
    int size = arr.size();
    int maxIndex = FindRotationMaxUtil(arr, 0, size - 1);
    return (maxIndex + 1) % size;
}

int binarysearchRotateArrayUtil(std::vector<int> &arr, int start, int end, int key)
{
    if (end < start)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    if (arr[mid] > arr[start])
    {
        if (arr[start] <= key && key < arr[mid])
        {
            return binarysearchRotateArrayUtil(arr, start, mid - 1, key);
        }
        else
        {
            return binarysearchRotateArrayUtil(arr, mid + 1, end, key);
        }
    }
    else
    {
        if (arr[mid] < key && key <= arr[end])
        {
            return binarysearchRotateArrayUtil(arr, mid + 1, end, key);
        }
        else
        {
            return binarysearchRotateArrayUtil(arr, start, mid - 1, key);
        }
    }
}

int binarysearchRotateArray(std::vector<int> &arr, int key)
{
    int size = arr.size();
    return binarysearchRotateArrayUtil(arr, 0, size - 1, key);
}

int main555()
{
    std::vector<int> first = { 34, 56, 77, 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
    std::cout << binarysearchRotateArray(first, 20) << std::endl;
    std::cout << CountRotation(first) << std::endl;
    std::cout << first[FindRotationMax(first)] << std::endl;
    return 0;
}


int minAbsDiffAdjCircular(std::vector<int> &arr)
{
    int diff = 9999999;
    int size = arr.size();
    if (size < 2)
        return -1;

    for (int i = 0; i < size; i++)
        diff = std::min(diff, std::abs(arr[i] - arr[(i + 1) % size]));

    return diff;
}

/*
 * Testing code
 */
int main666()
{
    std::vector<int> arr = { 5, 29, 18, 51, 11 };
    std::cout << minAbsDiffAdjCircular(arr) << std::endl;
    return 0;
}

void swapch(char arr[], int first, int second)
{
    char temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void transformArrayAB1(char arr[], int size)
{
    int N = size / 2, i, j;
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            swapch(arr, N - i + 2 * j, N - i + 2 * j + 1);
        }
    }
}

int main16()
{
    char str[] = "aaaabbbb";
    transformArrayAB1(str, 8);
    std::cout << str << std::endl;
    return 0;
}


bool checkPermutation(char array1[], int size1, char array2[], int size2)
{
    if (size1 != size2)
    {
        return false;
    }
    std::sort(array1, array1+size1);
    std::sort(array2, array2+size2);
    for (int i = 0; i < size1; i++)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

int main17()
{
    char str1[] = "aaaabbbb";
    char str2[] = "bbaaaabb";

    std::cout << checkPermutation(str1, sizeof(str1)/sizeof(char), str2, sizeof(str2)/sizeof(char)) << std::endl;
    return 0;
}

bool findElementIn2DArray(std::vector<std::vector<int>> &arr, int r, int c, int value)
{
    int row = 0;
    int column = c - 1;
    while (row < r && column >= 0)
    {
        if (arr[row][column] == value)
        {
            return true;
        }
        else if (arr[row][column] > value)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

bool isAP(std::vector<int> &arr)
{
    int size = arr.size();
    if (size <= 1)
        return true;
    std::sort(arr.begin(), arr.end());
    int diff = arr[1] - arr[0];
    for (int i = 2; i < size; i++)
    {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

bool isAP2(std::vector<int> &arr)
{
    int first = 9999999;
    int second = 9999999;
    int value;
    int size = arr.size();
    std::set<int> hs;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second)
            second = arr[i];
    }
    int diff = second - first;

    for (int i = 0; i < size; i++)
    {
        if (hs.find(arr[i]) != hs.end())
            return false;
        hs.insert(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        value = first + i * diff;
        if (hs.find(value) == hs.end())
            return false;
    }
    return true;
}

bool isAP3(std::vector<int> &arr)
{
    int first = 9999999;
    int second = 9999999;
    int size = arr.size();
    std::vector<int> count(size, 0);
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second)
            second = arr[i];
    }
    int diff = second - first;

    for (int i = 0; i < size; i++)
        index = (arr[i] - first) / diff;
    if (index > size - 1 || count[index] != 0)
        return false;
    count[index] = 1;

    for (int i = 0; i < size; i++)
        if (count[i] != 1)
            return false;
    return true;
}

int findBalancedPoint(std::vector<int> &arr)
{
    int first = 0;
    int second = 0;
    int size = arr.size();
    for (int i = 1; i < size; i++)
        second += arr[i];

    for (int i = 0; i < size; i++)
    {
        if (first == second)
        {
            std::cout << i << std::endl;
            return i;
        }
        if (i < size - 1)
            first += arr[i];
        second -= arr[i + 1];
    }
    return -1;
}

/*
 * Testing code
 */
int main18()
{
    std::vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
    std::cout << findBalancedPoint(arr) << std::endl;
    return 0;
}

int findFloor(std::vector<int> &arr, int value)
{
    int size = arr.size();
    int start = 0;
    int stop = size - 1;
    int mid;
    while (start <= stop)
    {
        mid = (start + stop) / 2;
        /*
         * search value is equal to arr[mid] value.. search value is greater than mid
         * index value and less than mid+1 index value. value is greater than
         * arr[size-1] then floor is arr[size-1]
         */
        if (arr[mid] == value || (arr[mid] < value && (mid == size - 1 || arr[mid + 1] > value)))
            return mid;
        else if (arr[mid] < value)
            start = mid + 1;
        else
            stop = mid - 1;
    }
    return -1;
}

int findCeil(std::vector<int> &arr, int value)
{
    int size = arr.size();
    int start = 0;
    int stop = size - 1;
    int mid;

    while (start <= stop)
    {
        mid = (start + stop) / 2;
        /*
         * search value is equal to arr[mid] value.. search value is less than mid index
         * value and greater than mid-1 index value. value is less than arr[0] then ceil
         * is arr[0]
         */
        if (arr[mid] == value || (arr[mid] > value && (mid == 0 || arr[mid - 1] < value)))
            return mid;
        else if (arr[mid] < value)
            start = mid + 1;
        else
            stop = mid - 1;
    }
    return -1;
}

int ClosestNumber(std::vector<int> &arr, int num)
{
    int size = arr.size();
    int start = 0;
    int stop = size - 1;
    int output = -1;
    int minDist = 9999;
    int mid;

    while (start <= stop)
    {
        mid = (start + stop) / 2;
        if (minDist > std::abs(arr[mid] - num))
        {
            minDist = std::abs(arr[mid] - num);
            output = arr[mid];
        }
        if (arr[mid] == num)
            break;
        else if (arr[mid] > num)
            stop = mid - 1;
        else
            start = mid + 1;
    }
    return output;
}

bool DuplicateKDistance(std::vector<int> &arr, int k)
{
    std::map<int, int> hm;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        if (hm.find(arr[i]) != hm.end() && i - hm[arr[i]] <= k)
        {
            std::cout << "Value:" << arr[i] <<
                      " Index: " << hm[arr[i]] << " & " << i << std::endl;
            return true;
        }
        else
            hm[arr[i]] = i;
    }
    return false;
}

/*
 * Testing code
 */
int main66()
{
    std::vector<int> arr = { 1, 2, 3, 1, 4, 5 };
    DuplicateKDistance(arr, 3);
    return 0;
}

void frequencyCounts(std::vector<int> &arr)
{
    int index;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        while (arr[i] > 0)
        {
            index = arr[i] - 1;
            if (arr[index] > 0)
            {
                arr[i] = arr[index];
                arr[index] = -1;
            }
            else
            {
                arr[index] -= 1;
                arr[i] = 0;
            }
        }
    }
    for (int i = 0; i < size; i++)
        std::cout << (i + 1) << std::abs(arr[i]) << std::endl;
}

int KLargestElements(int arrIn[], int size, int k)
{
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++)
        arr[i] = arrIn[i];

    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {
        if (arrIn[i] >= arr[size - k])
        {
            std::cout << arrIn[i] << std::endl;
            return arrIn[i];
        }

    }
    return -1;
}

void QuickSelectUtil(std::vector<int> &arr, int lower, int upper, int k)
{
    if (upper <= lower)
        return;

    int pivot = arr[lower];
    int start = lower;
    int stop = upper;

    while (lower < upper)
    {
        while (arr[lower] <= pivot)
        {
            lower++;
        }
        while (arr[upper] > pivot)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr, upper, lower);
        }
    }

    swap(arr, upper, start); // upper is the pivot position
    if (k < upper)
        QuickSelectUtil(arr, start, upper - 1, k); // pivot -1 is the upper for left sub array.
    if (k > upper)
        QuickSelectUtil(arr, upper + 1, stop, k); // pivot + 1 is the lower for right sub array.
}

int KLargestElements2(int arrIn[], int size, int k)
{
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++)
        arr[i] = arrIn[i];

    QuickSelectUtil(arr, 0, size - 1, size - k);
    for (int i = 0; i < size; i++)
    {
        if (arrIn[i] >= arr[size - k])
        {
            std::cout << arrIn[i] << std::endl;
            return arrIn[i];
        }
    }
    return -1;
}

/* linear search method */
int FixPoint(std::vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == i)
            return i;
    } /* fix point not found so return invalid index */
    return -1;
}

/* Binary search method */
int FixPoint2(std::vector<int> &arr)
{
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == mid)
            return mid;
        else if (arr[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    /* fix point not found so return invalid index */
    return -1;
}

int subArraySums(std::vector<int> &arr, int value)
{
    int first = 0;
    int second = 0;
    int sum = arr[first];
    int size = arr.size();
    while (second < size && first < size)
    {
        if (sum == value)
            std::cout << first << second << std::endl;

        if (sum < value)
        {
            second += 1;
            if (second < size)
                sum += arr[second];
        }
        else
        {
            sum -= arr[first];
            first += 1;
        }
    }
    return sum;
}

int MaxConSub(std::vector<int> &arr)
{
    int currMax = 0;
    int maximum = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        currMax = std::max(arr[i], currMax + arr[i]);
        if (currMax < 0)
            currMax = 0;
        if (maximum < currMax)
            maximum = currMax;
    }
    std::cout << maximum << std::endl;
    return maximum;
}

int MaxConSubArr(std::vector<int> &A, std::vector<int> &B)
{
    int currMax = 0;
    int maximum = 0;
    std::set<int> hs;
    int sizeA = A.size();
    int sizeB = B.size();


    for (int i = 0; i < sizeB; i++)
        hs.insert(B[i]);

    for (int i = 0; i < sizeA; i++)
        if (hs.find(A[i]) != hs.end())
            currMax = 0;
        else
            currMax = std::max(A[i], currMax + A[i]);
    if (currMax < 0)
        currMax = 0;
    if (maximum < currMax)
        maximum = currMax;
    std::cout << maximum << std::endl;
    return maximum;
}

int MaxConSubArr2(std::vector<int> &A, std::vector<int> &B)
{
    std::sort(B.begin(), B.end());
    int currMax = 0;
    int maximum = 0;
    int sizeA = A.size();
    int sizeB = B.size();

    for (int i = 0; i < sizeA; i++)
    {
        if (binarysearch(B, A[i]))
            currMax = 0;
        else
        {
            currMax = std::max(A[i], currMax + A[i]);
            if (currMax < 0)
                currMax = 0;
            if (maximum < currMax)
                maximum = currMax;
        }
    }
    std::cout << maximum << std::endl;
    return maximum;
}

int RainWater(std::vector<int> &arr)
{
    int size = arr.size();
    std::vector<int> leftHigh(size, 0);
    std::vector<int> rightHigh(size, 0);

    int max = arr[0];
    leftHigh[0] = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
        leftHigh[i] = max;
    }
    max = arr[size - 1];
    rightHigh[size - 1] = arr[size - 1];
    for (int i = (size - 2); i >= 0; i--)
    {
        if (max < arr[i])
            max = arr[i];
        rightHigh[i] = max;
    }

    int water = 0;
    for (int i = 0; i < size; i++)
        water += std::min(leftHigh[i], rightHigh[i]) - arr[i];
    std::cout << "Water : " << water << std::endl;
    return water;
}

int RainWater2(std::vector<int> &arr)
{
    int water = 0;
    int leftMax = 0, rightMax = 0;
    int left = 0;
    int size = arr.size();
    int right = size - 1;

    while (left <= right)
    {
        if (arr[left] < arr[right])
        {
            if (arr[left] > leftMax)
                leftMax = arr[left];
            else
                water += leftMax - arr[left];
            left += 1;
        }
        else
        {
            if (arr[right] > rightMax)
                rightMax = arr[right];
            else
                water += rightMax - arr[right];
            right -= 1;
        }
    }
    std::cout << "Water : " << water << std::endl;
    return water;
}

void seperateEvenAndOdd(std::vector<int> &arr)
{
    int size = arr.size();
    int left = 0, right = size - 1;
    while (left < right)
    {
        if (arr[left] % 2 == 0)
        {
            left++;
        }
        else if (arr[right] % 2 == 1)
        {
            right--;
        }
        else
        {
            swap(arr, left, right);
            left++;
            right--;
        }
    }
}

int main()
{
    std::vector<int> first = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
    seperateEvenAndOdd(first);
    for (int val : first)
    {
        std::cout << val << " " ;
    }
    return 0;
}

void minabsSumPair(std::vector<int> &data)
{
    int minSum, sum, minFirst, minSecond;
    int size = data.size();
    // Array should have at least two elements
    if (size < 2)
    {
        throw ("InvalidInput");
    }
    // Initialization of values
    minFirst = 0;
    minSecond = 1;
    minSum = std::abs(data[0] + data[1]);
    for (int l = 0; l < size - 1; l++)
    {
        for (int r = l + 1; r < size; r++)
        {
            sum = std::abs(data[l] + data[r]);
            if (sum < minSum)
            {
                minSum = sum;
                minFirst = l;
                minSecond = r;
            }
        }
    }
    std::cout << " The two elements with minimum sum are : " << data[minFirst] << " , " << data[minSecond] << std::endl;
}

void minabsSumPair2(std::vector<int> &data)
{
    int minSum, sum, minFirst, minSecond;
    int size = data.size();
    // Array should have at least two elements
    if (size < 2)
    {
        throw ("InvalidInput");
    }
    sort(data.begin(), data.end()); // Sort(data, size);

    // Initialization of values
    minFirst = 0;
    minSecond = size - 1;
    minSum = std::abs(data[minFirst] + data[minSecond]);
    for (int l = 0, r = size - 1; l < r;)
    {
        sum = (data[l] + data[r]);
        if (std::abs(sum) < minSum)
        {
            minSum = std::abs(sum); /// just corrected......hemant
            minFirst = l;
            minSecond = r;
        }

        if (sum < 0)
            l++;
        else if (sum > 0)
            r--;
        else
            break;
    }
    std::cout << " The two elements with minimum sum are : " << data[minFirst] << " , " << data[minSecond] << std::endl;
}



int binarysearch(std::vector<int> &data, int start, int end, int key, bool isInc)
{
    int mid;
    if (end < start)
    {
        return -1;
    }
    mid = (start + end) / 2;
    if (key == data[mid])
    {
        return mid;
    }
    if (isInc != false && key < data[mid] || isInc == false && key > data[mid])
    {
        return binarysearch(data, start, mid - 1, key, isInc);
    }
    else
    {
        return binarysearch(data, mid + 1, end, key, isInc);
    }
}

int findMedian(std::vector<int> &dataFirst, int sizeFirst, std::vector<int> &dataSecond, int sizeSecond)
{
    int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) % 2) / 2; // cealing function.
    int i = 0, j = 0;
    int count = 0;
    while (count < medianIndex - 1)
    {
        if (i < sizeFirst - 1 && dataFirst[i] < dataSecond[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        count++;
    }
    if (dataFirst[i] < dataSecond[j])
    {
        return dataFirst[i];
    }
    else
    {
        return dataSecond[j];
    }
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

void transformArrayAB1(std::vector<int> &data)
{
    int size = data.size();
    int N = size / 2;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            swap(data, N - i + 2 * j, N - i + 2 * j + 1);
    }
}

bool checkPermutation(std::vector<int> &data1, std::vector<int> &data2)
{
    int size1 = data1.size();
    int size2 = data2.size();

    if (size1 != size2)
        return false;

    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    for (int i = 0; i < size1; i++)
    {
        if (data1[i] != data2[i])
            return false;
    }
    return true;
}

bool checkPermutation2(std::vector<int> &data1, std::vector<int> &data2)
{
    int size1 = data1.size();
    int size2 = data2.size();

    if (size1 != size2)
        return false;

    std::vector<int> al;

    for (int i = 0; i < size1; i++)
        al.push_back(data1[i]);

    for (int i = 0; i < size2; i++)
    {
        if (std::find(al.begin(), al.end(), data2[i]) != al.end() == false)
            return false;

        al.erase(al.begin() + data2[i]);
    }
    return true;
}

bool findElementIn2DArray(int **data, int r, int c, int value)
{
    int row = 0;
    int column = c - 1;
    while (row < r && column >= 0)
    {
        if (data[row][column] == value)
        {
            return true;
        }
        else if (data[row][column] > value)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return false;
}
