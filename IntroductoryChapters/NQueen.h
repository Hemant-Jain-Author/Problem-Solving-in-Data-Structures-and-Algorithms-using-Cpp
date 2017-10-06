#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>


	void print(std::vector<int> &Q, int n);
	bool Feasible(std::vector<int> &Q, int k);
	void NQueens(std::vector<int> &Q, int k, int n);
	void TOHUtil(int num, char from, char to, char temp);
	void TowersOfHanoi(int num);
