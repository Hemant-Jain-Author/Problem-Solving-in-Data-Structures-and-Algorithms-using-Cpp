#include <string>
#include <vector>
#include <iostream>

int uniqueWays(int m, int n) {
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(m,
			std::vector<int>(n, 0));
	dp[0][0] = 1;

	// Initialize first column.
	for (int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0];

	// Initialize first row.
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1];

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int unique3Ways(int m, int n) {
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(m,
			std::vector<int>(n, 0));
	dp[0][0] = 1;

	// Initialize first column.
	for (int i = 1; i < m; i++)
		dp[i][0] = dp[i - 1][0];

	// Initialize first row.
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1];

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	std::cout << uniqueWays(3, 3) << std::endl;
	std::cout << unique3Ways(3, 3) << std::endl;
	return 0;
}
/*
 6
 13
 */
