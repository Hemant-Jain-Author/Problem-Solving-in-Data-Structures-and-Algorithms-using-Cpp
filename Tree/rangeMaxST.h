#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

class rangeMaxST
{
private:
	std::vector<int> segArr;
	int n = 0;

public:
	rangeMaxST(std::vector<int> &input);
	int getMax(int start, int end);
	void update(int ind, int val);
	int max(int first, int second);

private:
	int constructST(std::vector<int> &input, int start, int end, int index);
	int getMaxUtil(int segStart, int segEnd, int queryStart, int queryEnd, int index);
	int updateUtil(int segStart, int segEnd, int ind, int val, int index);
};


