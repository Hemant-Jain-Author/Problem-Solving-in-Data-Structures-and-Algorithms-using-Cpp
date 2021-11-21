#include <string>
#include <vector>
#include <iostream>

int getMax(std::vector<int> &arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void countSort(std::vector<int> &arr, int n, int dividend)
{
	std::vector<int> temp(arr);
	std::vector<int> count(10, 0);

	// Store count of occurrences in count array.
	// (number / dividend) % 10 is used to find the working digit.
	for (int i = 0; i < n; i++)
		count[(temp[i] / dividend) % 10]++;

	// Change count[i] so that count[i] contains 
	// number of elements till index i in output.
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	// Copy content to input arr.
	for (int i = n - 1; i >= 0; i--)
	{
		int index = (temp[i] / dividend) % 10;
		arr[count[index] - 1] = temp[i];
		count[index]--;
	}
}

void RadixSort(std::vector<int> &arr)
{
	int n = arr.size();
	int m = getMax(arr, n);

	// Counting sort for every digit.
	// The dividend passed is used to calculate current working digit.
	for (int div = 1; m / div > 0; div *= 10)
	{
		countSort(arr, n, div);
	}
}

void printArray(std::vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> array = {100, 49, 65, 91, 702, 29, 4, 55};
	RadixSort(array);
	printArray(array);
}

/*
4 29 49 55 65 91 100 702 
*/