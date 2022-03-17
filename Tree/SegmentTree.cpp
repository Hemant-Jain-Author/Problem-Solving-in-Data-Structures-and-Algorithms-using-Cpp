#include "SegmentTree.h"

SegmentTree::SegmentTree(std::vector<int> &input) {
	size = input.size();
	// Height of segment tree.
	int x = static_cast<int>(std::ceil(std::log(size) / std::log(2)));
	//Maximum size of segment tree
	int max_size = 2 * static_cast<int>(std::pow(2, x)) - 1;
	// Allocate memory for segment tree
	segArr = std::vector<int>(max_size);
	constructST(input, 0, size - 1, 0);
}

int SegmentTree::constructST(std::vector<int> &input, int start, int end,
		int index) {
	// Store it in current node of the segment tree and return
	if (start == end) {
		segArr[index] = input[start];
		return input[start];
	}

	// If there are more than one elements, 
	// then traverse left and right subtrees 
	// and store the sum of values in current node.
	int mid = (start + end) / 2;
	segArr[index] = constructST(input, start, mid, index * 2 + 1)
			+ constructST(input, mid + 1, end, index * 2 + 2);
	return segArr[index];
}

int SegmentTree::getSum(int start, int end) {
	// Check for error conditions.
	if (start > end || start < 0 || end > size - 1) {
		std::cout << "Invalid Input." << std::endl;
		return -1;
	}
	return getSumUtil(0, size - 1, start, end, 0);
}

int SegmentTree::getSumUtil(int segStart, int segEnd, int queryStart,
		int queryEnd, int index) {
	if (queryStart <= segStart && segEnd <= queryEnd) // complete overlapping case.
			{
		return segArr[index];
	}

	if (segEnd < queryStart || queryEnd < segStart) // no overlapping case.
			{
		return 0;
	}

	// Segment tree is partly overlaps with the query range.
	int mid = (segStart + segEnd) / 2;
	return getSumUtil(segStart, mid, queryStart, queryEnd, 2 * index + 1)
			+ getSumUtil(mid + 1, segEnd, queryStart, queryEnd, 2 * index + 2);
}

void SegmentTree::set(std::vector<int> &arr, int ind, int val) {
	// Check for error conditions.
	if (ind < 0 || ind > size - 1) {
		std::cout << "Invalid Input." << std::endl;
		return;
	}

	arr[ind] = val;

	// Set new value in segment tree
	setUtil(0, size - 1, ind, val, 0);
}

int SegmentTree::setUtil(int segStart, int segEnd, int ind, int val,
		int index) {
	// set index lies outside the range of current segment.
	// So diff to its parent node will be zero.
	if (ind < segStart || ind > segEnd) {
		return 0;
	}

	// If the input index is in range of this node, then set the
	// value of the node and its children

	if (segStart == segEnd) {
		if (segStart == ind) { // Index that need to be set.
			int diff = val - segArr[index];
			segArr[index] = val;
			return diff;
		} else {
			return 0;
		}
	}

	int mid = (segStart + segEnd) / 2;
	int diff = setUtil(segStart, mid, ind, val, 2 * index + 1)
			+ setUtil(mid + 1, segEnd, ind, val, 2 * index + 2);

	// Current node value is set with diff. 
	segArr[index] = segArr[index] + diff;

	// Value of diff is propagated to the parent node.
	return diff;
}

// Testing code.
int main() {
	std::vector<int> arr = { 1, 2, 4, 8, 16, 32, 64 };
	SegmentTree *tree = new SegmentTree(arr);
	std::cout << "Sum of values in the range(0, 3): " << tree->getSum(1, 3)
			<< std::endl;
	std::cout << "Sum of values of all the elements: "
			<< tree->getSum(0, arr.size() - 1) << std::endl;

	tree->set(arr, 1, 10);
	std::cout << "Sum of values in the range(0, 3): " << tree->getSum(1, 3)
			<< std::endl;
	std::cout << "Sum of values of all the elements: "
			<< tree->getSum(0, arr.size() - 1) << std::endl;

	delete tree;
}

/*
 Sum of values in the range(0, 3): 14
 Sum of values of all the elements: 127
 Sum of values in the range(0, 3): 22
 Sum of values of all the elements: 135
 */
