#include <string>
#include <vector>
#include <iostream>
#include <limits>

int MatrixChainMulBruteForceUtil(std::vector<int> &p, int i, int j) {
	if (i == j)
		return 0;

	int min = std::numeric_limits<int>::max();

	// place parenthesis at different places between first and last matrix, recursively calculate
	// count of multiplications for each parenthesis placement and return the minimum count
	for (int k = i; k < j; k++) {
		int count = MatrixChainMulBruteForceUtil(p, i, k)
				+ MatrixChainMulBruteForceUtil(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	return min; // Return minimum count
}

int MatrixChainMulBruteForce(std::vector<int> &p, int n) {
	int i = 1, j = n - 1;
	return MatrixChainMulBruteForceUtil(p, i, j);
}

int MatrixChainMulTDUtil(std::vector<std::vector<int>> &dp, std::vector<int> &p,
		int i, int j) {
	// Base Case
	if (i == j)
		return 0;

	if (dp[i][j] != std::numeric_limits<int>::max())
		return dp[i][j];

	for (int k = i; k < j; k++) {
		dp[i][j] = std::min(dp[i][j],
				MatrixChainMulTDUtil(dp, p, i, k)
						+ MatrixChainMulTDUtil(dp, p, k + 1, j)
						+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}

int MatrixChainMulTD(std::vector<int> &p, int n) {
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));
	return MatrixChainMulTDUtil(dp, p, 1, n - 1);
}

int MatrixChainMulBU(std::vector<int> &p, int n) {
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(n, std::numeric_limits<int>::max()));
	for (int i = 1; i < n; i++)
		dp[i][i] = 0;

	for (int l = 1; l < n; l++) // l is length of range.
			{
		for (int i = 1, j = i + l; j < n; i++, j++) {
			for (int k = i; k < j; k++)
				dp[i][j] = std::min(dp[i][j],
						dp[i][k] + p[i - 1] * p[k] * p[j] + dp[k + 1][j]);
		}
	}
	return dp[1][n - 1];
}

// Testing code.
int main() {
	std::vector<int> arr = { 1, 2, 3, 4 };
	int n = arr.size();
	std::cout << "Matrix Chain Multiplication is: "
			<< MatrixChainMulBruteForce(arr, n) << std::endl;
	std::cout << "Matrix Chain Multiplication is: " << MatrixChainMulTD(arr, n)
			<< std::endl;
	std::cout << "Matrix Chain Multiplication is: " << MatrixChainMulBU(arr, n)
			<< std::endl;
	return 0;
}

/*
 Matrix Chain Multiplication is: 18
 Matrix Chain Multiplication is: 18
 Matrix Chain Multiplication is: 18
 */
