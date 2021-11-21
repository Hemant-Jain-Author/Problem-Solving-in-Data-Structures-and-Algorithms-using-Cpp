#include <vector>
#include <iostream>

void printArray(std::vector<int> &arr)
{
	std::cout << "[ ";
	for (auto i : arr)
	{
		std::cout << i << " ";
	}
	std::cout << "] ";
}

void swap(std::vector<int> &arr, int first, int second)
{
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int partition(std::vector<int> &arr, int low, int high, int pivot)
{
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr, i, j);
			i++;
		}
		else if (arr[j] == pivot)
		{
			swap(arr, high, j);
			j--;
		}
	}
	swap(arr, i, high);
	return i;
}

void makePairs(std::vector<int> &nuts, std::vector<int> &bolts, int low, int high)
{
	if (low < high)
	{
		// Choose first element of bolts array as pivot to partition nuts.
		int pivot = partition(nuts, low, high, bolts[low]);
		// Using nuts[pivot] as pivot to partition bolts.
		partition(bolts, low, high, nuts[pivot]);
		// Recursively lower and upper half of nuts and bolts are matched.
		makePairs(nuts, bolts, low, pivot - 1);
		makePairs(nuts, bolts, pivot + 1, high);
	}
}

void makePairs(std::vector<int> &nuts, std::vector<int> &bolts)
{
	makePairs(nuts, bolts, 0, nuts.size() - 1);
	std::cout << "Matched nuts and bolts are : ";
	printArray(nuts);
	printArray(bolts);
}

int main()
{
	std::vector<int> nuts = {1, 2, 6, 5, 4, 3};
	std::vector<int> bolts = {6, 4, 5, 1, 3, 2};
	makePairs(nuts, bolts);
	return 0;
}

/*
Matched nuts and bolts are : [ 1 2 3 4 5 6 ] [ 1 2 3 4 5 6 ] 
*/