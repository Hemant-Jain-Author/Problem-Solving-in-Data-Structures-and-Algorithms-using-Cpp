#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

class rmqST
{
private:
	std::vector<int> segArr;
	int n = 0;

public:
	rmqST(std::vector<int> &input);
	int getMin(int start, int end);
	void update(int ind, int val);

private:
	int constructST(std::vector<int> &input, int start, int end, int index);
	int getMinUtil(int segStart, int segEnd, int queryStart, int queryEnd, int index);
	int updateUtil(int segStart, int segEnd, int ind, int val, int index);
};