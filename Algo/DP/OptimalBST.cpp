#include <string>
#include <vector>
#include <iostream>
#include <limits>

int sum(std::vector<int> &freq, int i, int j) {
	int s = 0;
	for (int k = i; k <= j; k++)
		s += freq[k];

	return s;
}

std::vector<int> sumInit(std::vector<int> &freq, int n) {
	std::vector<int> sum(n);
	sum[0] = freq[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + freq[i];
	return sum;
}

int sumRange(std::vector<int> &sum, int i, int j) {
	if (i == 0)
		return sum[j];
	return sum[j] - sum[i - 1];
}

int optCostUtil(std::vector<int> &freq, int i, int j) {
	if (i > j)
		return 0;

	if (j == i) // one element in this subarray
		return freq[i];

	int min = std::numeric_limits<int>::max();
	for (int r = i; r <= j; r++)
		min = std::min(min,
				optCostUtil(freq, i, r - 1) + optCostUtil(freq, r + 1, j));

	return min + sum(freq, i, j);
}

int optCost(std::vector<int> &keys, std::vector<int> &freq) {
	int n = freq.size();
	return optCostUtil(freq, 0, n - 1);
}

int optCostTDUtil(std::vector<int> &freq, std::vector<std::vector<int>> &cost,
		int i, int j) {
	if (i > j)
		return 0;

	if (cost[i][j] != std::numeric_limits<int>::max())
		return cost[i][j];

	int s = sum(freq, i, j);
	for (int r = i; r <= j; r++) {
		cost[i][j] = std::min(cost[i][j],
				optCostTDUtil(freq, cost, i, r - 1)
						+ optCostTDUtil(freq, cost, r + 1, j) + s);
	}
	return cost[i][j];
}

int optCostTD(std::vector<int> &keys, std::vector<int> &freq) {
	int n = freq.size();
	std::vector<std::vector<int>> cost = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	return optCostTDUtil(freq, cost, 0, n - 1);
}

int optCostBU(std::vector<int> &keys, std::vector<int> &freq) {
	int n = freq.size();
	std::vector<std::vector<int>> cost = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	int sm = 0;
	for (int l = 1; l < n; l++) // l is length of range.
			{
		for (int i = 0, j = i + l; j < n; i++, j++) {
			sm = sum(freq, i, j);
			for (int r = i; r <= j; r++) {
				cost[i][j] = std::min(cost[i][j],
						sm + ((r - 1 >= i) ? cost[i][r - 1] : 0)
								+ ((r + 1 <= j) ? cost[r + 1][j] : 0));
			}
		}
	}
	return cost[0][n - 1];
}

int optCostBU2(std::vector<int> &keys, std::vector<int> &freq) {
	int n = freq.size();
	std::vector<std::vector<int>> cost = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));
	std::vector<int> sumArr = sumInit(freq, n);

	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];

	int sm = 0;
	for (int l = 1; l < n; l++) // l is length of range.
			{
		for (int i = 0, j = i + l; j < n; i++, j++) {
			sm = sumRange(sumArr, i, j);
			for (int r = i; r <= j; r++) {
				cost[i][j] = std::min(cost[i][j],
						sm + ((r - 1 >= i) ? cost[i][r - 1] : 0)
								+ ((r + 1 <= j) ? cost[r + 1][j] : 0));
			}
		}
	}
	return cost[0][n - 1];
}

// Testing code.
int main() {
	std::vector<int> keys = { 9, 15, 25 };
	std::vector<int> freq = { 30, 10, 40 };
	std::cout << "OBST cost:" << optCost(keys, freq) << std::endl;
	std::cout << "OBST cost:" << optCostTD(keys, freq) << std::endl;
	std::cout << "OBST cost:" << optCostBU(keys, freq) << std::endl;
	std::cout << "OBST cost:" << optCostBU2(keys, freq) << std::endl;
}

/*
 OBST cost:130
 OBST cost:130
 OBST cost:130
 OBST cost:130
 */
