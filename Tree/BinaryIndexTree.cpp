#include "BinaryIndexTree.h"

BinaryIndexTree::BinaryIndexTree(std::vector<int> &arr)
{
	size = arr.size();
	BIT = std::vector<int>(size+1, 0);
	for (int i = 0; i < size; i++) // Populating bit.
	{
		update(i, arr[i]);
	}
}

void BinaryIndexTree::set(std::vector<int> &arr, int index, int val)
{
	int diff = val - arr[index];
	arr[index] = val;

	// Difference is propagated.
	update(index, diff);
}

void BinaryIndexTree::update(int index, int val)
{
	// Index in bit is 1 more than the input array.
	index = index + 1;

	// Traverse to ancestors of nodes.
	while (index <= size)
	{
		// Add val to current node of Binary Index Tree.
		BIT[index] += val;

		// Next element which need to store val.
		index += index & (-index);
	}
}

int BinaryIndexTree::rangeSum(int start, int end)
{
	// Check for error conditions.
	if (start > end || start < 0 || end > size - 1)
	{
		std::cout << "Invalid Input." << std::endl;
		return -1;
	}

	return prefixSum(end) - prefixSum(start - 1);
}

int BinaryIndexTree::prefixSum(int index)
{
	int sum = 0;
	index = index + 1;

	// Traverse ancestors of Binary Index Tree nodes.
	while (index > 0)
	{
		// Add current element to sum.
		sum += BIT[index];

		// Parent index calculation.
		index -= index & (-index);
	}
	return sum;
}

int main()
{
	std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	BinaryIndexTree *tree = new BinaryIndexTree(arr);
	std::cout << "Sum of elements in range(0, 5): " << tree->prefixSum(5) << std::endl;
	std::cout << "Sum of elements in range(2, 5): " << tree->rangeSum(2, 5) << std::endl;
	// Set fourth element to 10.
	tree->set(arr, 3, 10); 

	// Find sum after the value is updated
	std::cout << "Sum of elements in range(0, 5): " << tree->prefixSum(5) << std::endl;
	delete tree;
}

/*
Sum of elements in range(0, 5): 21
Sum of elements in range(2, 5): 18
Sum of elements in range(0, 5): 27
*/