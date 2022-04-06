#include <string>
#include <vector>
#include <iostream>
#include <limits>

int maxVal(std::vector<std::vector<int>> &max, int i, int j) {
	if (max[i][j] != std::numeric_limits<int>::min())
		return max[i][j];

	for (int k = i; k < j; k++)
		max[i][j] = std::max(max[i][j],
				std::max(maxVal(max, i, k), maxVal(max, k + 1, j)));

	return max[i][j];
}

int minCostBstTDUtil(std::vector<std::vector<int>> &dp,
		std::vector<std::vector<int>> &max, int i, int j,
		std::vector<int> &arr) {
	if (j <= i)
		return 0;

	if (dp[i][j] != std::numeric_limits<int>::max())
		return dp[i][j];

	for (int k = i; k < j; k++) {
		dp[i][j] = std::min(dp[i][j],
				minCostBstTDUtil(dp, max, i, k, arr)
						+ minCostBstTDUtil(dp, max, k + 1, j, arr)
						+ maxVal(max, i, k) * maxVal(max, k + 1, j));
	}
	return dp[i][j];
}

int minCostBstTD(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));

	std::vector<std::vector<int>> max = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::min()));

	for (int i = 0; i < n; i++)
		max[i][i] = arr[i];

	return minCostBstTDUtil(dp, max, 0, n - 1, arr);
}

int minCostBstBU(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(n, 0));
	std::vector<std::vector<int>> max = std::vector<std::vector<int>>(n,
			std::vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		max[i][i] = arr[i];

	for (int l = 1; l < n; l++) // l is length of range.
			{
		for (int i = 0, j = i + l; j < n; i++, j++) {
			dp[i][j] = std::numeric_limits<int>::max();
			for (int k = i; k < j; k++) {
				dp[i][j] = std::min(dp[i][j],
						dp[i][k] + dp[k + 1][j] + max[i][k] * max[k + 1][j]);
				max[i][j] = std::max(max[i][k], max[k + 1][j]);
			}
		}
	}
	return dp[0][n - 1];
}

// Testing code.
int main() {
	std::vector<int> arr = { 6, 2, 4 };
	std::cout << "Total cost: " << minCostBstTD(arr) << std::endl;
	std::cout << "Total cost: " << minCostBstBU(arr) << std::endl;
	return 0;
}

/*
 Total cost: 32
 Total cost: 32
 */
