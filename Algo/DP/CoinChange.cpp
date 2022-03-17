#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

int minCoins(std::vector<int> &coins, int n, int val) // Greedy may be wrong.
		{
	if (val <= 0)
		return 0;

	int count = 0;
	std::sort(coins.begin(), coins.end());

	for (int i = n - 1; i >= 0 && val > 0;) {
		if (coins[i] <= val) {
			count++;
			val -= coins[i];
		} else {
			i--;
		}
	}
	return (val == 0) ? count : -1;
}

int minCoins2(std::vector<int> &coins, int n, int val) // Brute force.
		{
	if (val == 0) {
		return 0;
	}

	int count = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		if (coins[i] <= val) {
			int subCount = minCoins2(coins, n, val - coins[i]);
			if (subCount >= 0) {
				count = std::min(count, subCount + 1);
			}
		}
	}
	return (count != std::numeric_limits<int>::max()) ? count : -1;
}

int minCoinsTD(std::vector<int> &dp, std::vector<int> &coins, int n, int val) {
	// Base Case
	if (val == 0) {
		return 0;
	}

	if (dp[val] != std::numeric_limits<int>::max()) {
		return dp[val];
	}

	// Recursion
	for (int i = 0; i < n; i++) {
		if (coins[i] <= val) { // check validity of a sub-problem
			int subCount = minCoinsTD(dp, coins, n, val - coins[i]);
			if (subCount != std::numeric_limits<int>::max()) {
				dp[val] = std::min(dp[val], subCount + 1);
			}
		}
	}
	return dp[val];
}

int minCoinsTD(std::vector<int> &coins, int n, int val) {
	std::vector<int> dp(val + 1, std::numeric_limits<int>::max());
	return minCoinsTD(dp, coins, n, val);
}

int minCoinsBU(std::vector<int> &coins, int n, int val) { // DP bottom up approach.
	std::vector<int> dp(val + 1, std::numeric_limits<int>::max());
	dp[0] = 0; // Base value.

	for (int i = 1; i <= val; i++) {
		for (int j = 0; j < n; j++) {
			// For all coins smaller than or equal to i.
			if (coins[j] <= i) {
				if (dp[i - coins[j]] != std::numeric_limits<int>::max()) {
					dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
	}

	return (dp[val] != std::numeric_limits<int>::max()) ? dp[val] : -1;
}

int main() {
	std::vector<int> coins = { 1, 4, 6, 9, 12 };
	int value = 15;
	int n = coins.size();
	std::cout << "Count is:" << minCoins(coins, n, value) << std::endl;
	std::cout << "Count is:" << minCoins2(coins, n, value) << std::endl;
	std::cout << "Count is:" << minCoinsBU(coins, n, value) << std::endl;
	std::cout << "Count is:" << minCoinsTD(coins, n, value) << std::endl;
}

/*
 Count is:4
 Count is:2
 Count is:2
 Count is:2
 */
