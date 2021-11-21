#pragma once

#include <string>
#include <vector>
#include <iostream>

class BinaryIndexTree
{
private:
	std::vector<int> BIT;
	int size = 0;

public:
	BinaryIndexTree(std::vector<int> &arr);
	void set(std::vector<int> &arr, int index, int val);
	void update(int index, int val);
	int rangeSum(int start, int end); // Range sum in the range start to end.
	int prefixSum(int index); // Prefix sum in the range 0 to index.
};
