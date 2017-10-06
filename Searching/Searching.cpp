#include "stdafx.h"
#include "Searching.h"

int main()
{
	std::vector<int> first = { 1, 3, 5, 7, 9, 25, 30 };
	std::vector<int> second = { 2, 4, 6, 8, 10, 12, 14, 16, 21, 23, 24 };

	for (int i = 1; i < 16; i++)
	{
		std::cout << "Index : " << i << " Value : ";
		std::cout << findkth(first, second, i) << std::endl;
	}
	return 0;
}

int findkth(std::vector<int> &first, std::vector<int> &second, int k) // buggy code 
{
	int sizeFirst = first.size();
	int sizeSecond = second.size();

	if (sizeFirst + sizeSecond < k)
	{
		throw std::exception("OutOfBoundException");
	}

	if (k == 1)
	{
		return min(first[0], second[0]);
	}

	int i = min(sizeFirst, k / 2);
	int j = min(sizeSecond, k - i);

	int step = max(1, min(i, j) / 2);

	while (step > 0)
	{
		if (first[i - 1] > second[j - 1] && first[i - 1] > second[min(second.size(), j + step) - 1])
		{
			j = min(second.size(), j + step);
			i = k - j;

		}
		else if (first[i - 1] < second[j - 1] && first[min(first.size(), i + step) - 1] < second[j - 1])
		{
			i = min(first.size(), i + step);
			j = k - i;
		}
		step = step / 2;
	}
	return max(first[i - 1], second[j - 1]);
}

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

bool Binarysearch(std::vector<int> &data, int value)
{
	int size = data.size();
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2; // To avoid the overflow
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

bool BinarySearchRecursive(std::vector<int> &data, int low, int high, int value)
{
	if (low > high)
	{
		return false;
	}
	int mid = low + (high - low) / 2; // To avoid the overflow
	if (data[mid] == value)
	{
		return true;
	}
	else if (data[mid] < value)
	{
		return BinarySearchRecursive(data, mid + 1, high, value);
	}
	else
	{
		return BinarySearchRecursive(data, low, mid - 1, value);
	}
}

void printRepeating(std::vector<int> &data)
{
	int size = data.size();
	std::cout << " Repeating elements are : " ;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (data[i] == data[j])
				std::cout << " " << data[i] ;
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

void printRepeating4(std::vector<int> &data)
{
	int size = data.size();
	std::vector<int> count(size);
	for (int i = 0; i < size; i++)
	{
		count[i] = 0;
	}
	std::cout << " Repeating elements are : ";
	for (int i = 0; i < size; i++)
	{
		if (count[data[i]] == 1)
			std::cout << " " << data[i];
		else
			count[data[i]]++;
	}
}

int getMax(std::vector<int> &data)
{
	int size = data.size();
	int max = data[0], count = 1, maxCount = 1;
	for (int i = 0; i < size; i++)
	{
		count = 1;
		for (int j = i + 1; j < size; j++)
		{
			if (data[i] == data[j])
				count++;
		}
		if (count > maxCount)
		{
			max = data[i];
			maxCount = count;
		}
	}
	return max;
}

int getMax2(std::vector<int> &data)
{
	int size = data.size();
	int max = data[0], maxCount = 1;
	int curr = data[0], currCount = 1;
	sort(data.begin(), data.end()); // Sort(data,size);
	for (int i = 1; i < size; i++)
	{
		if (data[i] == data[i - 1])
			currCount++;
		else
		{
			currCount = 1;
			curr = data[i];
		}
		if (currCount > maxCount)
		{
			maxCount = currCount;
			max = curr;
		}
	}
	return max;
}

int getMax3(std::vector<int> &data, int range)
{
	int max = data[0], maxCount = 1;
	int size = data.size();
	std::vector<int> count(range);
	for (int i = 0; i < size; i++)
	{
		count[data[i]]++;
		if (count[data[i]] > maxCount)
		{
			maxCount = count[data[i]];
			max = data[i];
		}
	}
	return max;
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
		throw std::exception("MajorityDoesNotExist");
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
		throw std::exception("MajorityDoesNotExist");
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
		throw std::exception("MajorityDoesNotExist");
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
	throw std::exception("NoNumberMissing");
}

int findMissingNumber(std::vector<int> &data, int range)
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

bool FindPair(std::vector<int> &data, int value)
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ((data[i] + data[j]) == value)
			{
				std::cout << "The pair is : " << data[i] << "," << data[j] << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool FindPair2(std::vector<int> &data, int value)
{
	int size = data.size();
	int first = 0, second = size - 1;
	int curr;
	sort(data.begin(), data.end()); // Sort(data, size);
	while (first < second)
	{
		curr = data[first] + data[second];
		if (curr == value)
		{
			std::cout << "The pair is " << data[first] << "," << data[second] << std::endl;
			return true;
		}
		else if (curr < value)
			first++;
		else
			second--;
	}
	return false;
}

bool FindPair3(std::vector<int> &data, int value)
{
	std::unordered_set<int> hs;
	int i;
	int size = data.size();
	for (i = 0; i < size; i++)
	{
		if (std::find(hs.begin(), hs.end(), value - data[i]) != hs.end())
		{
			std::cout << "The pair is : " << data[i] << " , " << (value - data[i]) << std::endl;
			return true;
		}
		hs.insert(data[i]);
	}
	return false;
}

void minabsSumPair(std::vector<int> &data)
{
	int minSum, sum, minFirst, minSecond;
	int size = data.size();
	// Array should have at least two elements
	if (size < 2)
	{
		throw std::exception("InvalidInput");
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
		throw std::exception("InvalidInput");
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

int SearchBotinicArrayMax(std::vector<int> &data)
{
	int size = data.size();
	int start = 0, end = size - 1;
	int mid = (start + end) / 2;
	int maximaFound = 0;
	if (size < 3)
	{
		throw std::exception("InvalidInput");
	}
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (data[mid - 1] < data[mid] && data[mid + 1] < data[mid]) // maxima
		{
			maximaFound = 1;
			break;
		}
		else if (data[mid - 1] < data[mid] && data[mid] < data[mid + 1]) // increasing
			start = mid + 1;
		else if (data[mid - 1] > data[mid] && data[mid] > data[mid + 1]) // decreasing
			end = mid - 1;
		else
			break;
	}
	if (maximaFound == 0)
		throw std::exception("NoMaximaFound");

	return data[mid];
}

int SearchBitonicArray(std::vector<int> &data, int key)
{
	int size = data.size();
	int max = FindMaxBitonicArray(data);
	int k = BinarySearch(data, 0, max, key, true);
	if (k != -1)
	{
		return k;
	}
	else
	{
		return BinarySearch(data, max + 1, size - 1, key, false);
	}
}

int FindMaxBitonicArray(std::vector<int> &data)
{
	int size = data.size();
	int start = 0, end = size - 1, mid;
	if (size < 3)
	{
		throw std::exception("InvalidInput");
	}
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (data[mid - 1] < data[mid] && data[mid + 1] < data[mid]) // maxima
		{
			return mid;
		}
		else if (data[mid - 1] < data[mid] && data[mid] < data[mid + 1]) // increasing
		{
			start = mid + 1;
		}
		else if (data[mid - 1] > data[mid] && data[mid] > data[mid + 1]) // decreasing
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

int BinarySearch(std::vector<int> &data, int start, int end, int key, bool isInc)
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
		return BinarySearch(data, start, mid - 1, key, isInc);
	}
	else
	{
		return BinarySearch(data, mid + 1, end, key, isInc);
	}
}

int findKeyCount(std::vector<int> &data, int key)
{
	int count = 0;
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		if (data[i] == key)
			count++;
	}
	return count;
}

int findKeyCount2(std::vector<int> &data, int key)
{
	int firstIndex, lastIndex;
	int size = data.size();
	firstIndex = findFirstIndex(data, 0, size - 1, key);
	lastIndex = findLastIndex(data, 0, size - 1, key);
	return (lastIndex - firstIndex + 1);
}

int findFirstIndex(std::vector<int> &data, int start, int end, int key)
{
	int mid;
	if (end < start)
		return -1;

	mid = (start + end) / 2;
	if (key == data[mid] && (mid == start || data[mid - 1] != key))
		return mid;

	if (key <= data[mid]) // <= is us the number.t in sorted array.
		return findFirstIndex(data, start, mid - 1, key);
	else
		return findFirstIndex(data, mid + 1, end, key);
}

int findLastIndex(std::vector<int> &data, int start, int end, int key)
{
	int mid;
	if (end < start)
		return -1;

	mid = (start + end) / 2;
	if (key == data[mid] && (mid == end || data[mid + 1] != key))
		return mid;

	if (key < data[mid]) 
		return findLastIndex(data, start, mid - 1, key);
	else
		return findLastIndex(data, mid + 1, end, key);
}

void swap(std::vector<int> &data, int first, int second)
{
	int temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

void seperateEvenAndOdd(std::vector<int> &data)
{
	int size = data.size();
	int left = 0, right = size - 1;
	while (left < right)
	{
		if (data[left] % 2 == 0)
			left++;
		else if (data[right] % 2 == 1)
			right--;
		else
		{
			swap(data, left, right);
			left++;
			right--;
		}
	}
}

void maxProfit(std::vector<int> &stocks)
{
	int size = stocks.size();
	int buy = 0, sell = 0;
	int curMin = 0;
	int currProfit = 0;
	int maxProfit = 0;

	for (int i = 0; i < size; i++)
	{
		if (stocks[i] < stocks[curMin])
			curMin = i;

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
}

int getMedian(std::vector<int> &data)
{
	int size = data.size();
	sort(data.begin(), data.end()); // Sort(data, size);
	return data[size / 2];
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

int BinarySearch01(std::vector<int> &data)
{
	int size = data.size();
	if (size == 1 && data[0] == 1)
	{
		return 0;
	}
	return BinarySearch01Util(data, 0, size - 1);
}

int BinarySearch01Util(std::vector<int> &data, int start, int end)
{
	int mid;
	if (end < start)
	{
		return -1;
	}
	mid = (start + end) / 2;
	if (1 == data[mid] && 0 == data[mid - 1])
	{
		return mid;
	}
	if (0 == data[mid])
	{
		return BinarySearch01Util(data, mid + 1, end);
	}
	else
	{
		return BinarySearch01Util(data, start, mid - 1);
	}
}

int BinarySearchRotateArrayUtil(std::vector<int> &data, int start, int end, int key)
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
	if (data[mid] > data[start])
	{
		if (data[start] <= key && key < data[mid])
		{
			return BinarySearchRotateArrayUtil(data, start, mid - 1, key);
		}
		else
		{
			return BinarySearchRotateArrayUtil(data, mid + 1, end, key);
		}
	}
	else
	{
		if (data[mid] < key && key <= data[end])
		{
			return BinarySearchRotateArrayUtil(data, mid + 1, end, key);
		}
		else
		{
			return BinarySearchRotateArrayUtil(data, start, mid - 1, key);
		}
	}
}

int BinarySearchRotateArray(std::vector<int> &data, int key)
{
	int size = data.size();
	return BinarySearchRotateArrayUtil(data, 0, size - 1, key);
}

int FirstRepeated(std::vector<int> &data)
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

int removeDuplicates(std::vector<int> &data)
{
	int j = 0;
	int size = data.size();
	if (size == 0)
		return 0;

	sort(data.begin(), data.end());	// Sort(array,size);
	for (int i = 1; i < size; i++)
	{
		if (data[i] != data[j])
		{
			j++;
			data[j] = data[i];
		}
	}
	return j + 1;
}

bool FindElementIn2DArray(int** data, int r, int c, int value)
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