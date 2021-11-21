#include "rangeMaxST.h"

rangeMaxST::rangeMaxST(std::vector<int> &input)
{
	n = input.size();
	// Height of segment tree.
	int x = static_cast<int>(std::ceil(std::log(n) / std::log(2)));
	//Maximum size of segment tree
	int max_size = 2 * static_cast<int>(std::pow(2, x)) - 1;
	// Allocate memory for segment tree
	segArr = std::vector<int>(max_size);
	constructST(input, 0, n - 1, 0);
}

int rangeMaxST::constructST(std::vector<int> &input, int start, int end, int index)
{
	// Store it in current node of the segment tree and return
	if (start == end)
	{
		segArr[index] = input[start];
		return input[start];
	}

	// If there are more than one elements, 
	// then traverse left and right subtrees 
	// and store the minimum of values in current node.
	int mid = (start + end) / 2;
	segArr[index] = max(constructST(input, start, mid, index * 2 + 1), constructST(input, mid + 1, end, index * 2 + 2));
	 return segArr[index];
}

int rangeMaxST::max(int first, int second)
{
	if (first > second)
	{
		return first;
	}
	else
	{
		return second;
	}
}

int rangeMaxST::getMax(int start, int end)
{
	// Check for error conditions.
	if (start > end || start < 0 || end > n - 1)
	{
		std::cout << "Invalid Input." << std::endl;
		return std::numeric_limits<int>::min();
	}
	return getMaxUtil(0, n - 1, start, end, 0);
}

int rangeMaxST::getMaxUtil(int segStart, int segEnd, int queryStart, int queryEnd, int index)
{
	if (queryStart <= segStart && segEnd <= queryEnd) // complete overlapping case.
	{
		return segArr[index];
	}

	if (segEnd < queryStart || queryEnd < segStart) // no overlapping case.
	{
		return std::numeric_limits<int>::min();
	}

	// Segment tree is partly overlaps with the query range.
	int mid = (segStart + segEnd) / 2;
	return max(getMaxUtil(segStart, mid, queryStart, queryEnd, 2 * index + 1), getMaxUtil(mid + 1, segEnd, queryStart, queryEnd, 2 * index + 2));
}

void rangeMaxST::update(int ind, int val)
{
	// Check for error conditions.
	if (ind < 0 || ind > n - 1)
	{
		std::cout << "Invalid Input." << std::endl;
		return;
	}

	// Update the values in segment tree
	updateUtil(0, n - 1, ind, val, 0);
}

int rangeMaxST::updateUtil(int segStart, int segEnd, int ind, int val, int index)
{
	// Update index lies outside the range of current segment.
	// So minimum will not change.
	if (ind < segStart || ind > segEnd)
	{
		return segArr[index];
	}

	// If the input index is in range of this node, then update the
	// value of the node and its children

	if (segStart == segEnd)
	{
		if (segStart == ind)
		{ // Index value need to be updated.
			segArr[index] = val;
			return val;
		}
		else
		{
			return segArr[index]; // index value is not changed.
		}
	}

	int mid = (segStart + segEnd) / 2;

	// Current node value is updated with min. 
	segArr[index] = max(updateUtil(segStart, mid, ind, val, 2 * index + 1), updateUtil(mid + 1, segEnd, ind, val, 2 * index + 2));

	// Value of diff is propagated to the parent node.
	return segArr[index];
}

int main()
{
	std::vector<int> arr = {1, 8, 2, 7, 3, 6, 4, 5};
	rangeMaxST *tree = new rangeMaxST(arr);
	std::cout << "Max value in the range(1, 5): " << tree->getMax(1, 5) << std::endl;
	std::cout << "Max value in the range(2, 7): " << tree->getMax(2, 7) << std::endl;
	std::cout << "Max value of all the elements: " << tree->getMax(0, arr.size() - 1) << std::endl;

	tree->update(2, 9);
	std::cout << "Max value in the range(1, 5): " << tree->getMax(1, 5) << std::endl;
	std::cout << "Max value of all the elements: " << tree->getMax(0, arr.size() - 1) << std::endl;

	delete tree;
}

/*
Max value in the range(1, 5): 8
Max value in the range(2, 7): 7
Max value of all the elements: 8
Max value in the range(1, 5): 9
Max value of all the elements: 9
*/