#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class SegmentTree
{
private:
	std::vector<int> segArr;
	int size = 0;
	
public:
	SegmentTree(std::vector<int> &input);
	int getSum(int start, int end);
	void set(std::vector<int> &arr, int ind, int val);

private:
	int constructST(std::vector<int> &input, int start, int end, int index);
	int getSumUtil(int segStart, int segEnd, int queryStart, int queryEnd, int index);
	int setUtil(int segStart, int segEnd, int ind, int val, int index);
};
