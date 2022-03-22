#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

int minCoins(std::vector<int> &d, int n, int val) { // Greedy may be wrong.
	if (val <= 0)
		return 0;

	int count = 0;
	std::sort(d.begin(), d.end());

	for (int i = n - 1; i >= 0 && val > 0;) {
		if (d[i] <= val) {
			count++;
			val -= d[i];
		} else {
			i--;
		}
	}
	return (val == 0) ? count : -1;
}

int minCoins2(std::vector<int> &d, int n, int val) { // Brute force.
	if (val == 0)
		return 0;

	int count = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		if (d[i] <= val) {
			int subCount = minCoins2(d, n, val - d[i]);
			if (subCount != -1) {
				count = std::min(count, subCount + 1);
			}
		}
	}
	return (count != std::numeric_limits<int>::max()) ? count : -1;
}

int minCoinsTD(std::vector<int> &coins, std::vector<int> &d, int n, int val) {
	// Base Case
	if (coins[val] != std::numeric_limits<int>::max())
		return coins[val];

	// Recursion
	for (int i = 0; i < n; i++) {
		if (d[i] <= val) { // check validity of a sub-problem
			int subCount = minCoinsTD(coins, d, n, val - d[i]);
			if (subCount != std::numeric_limits<int>::max()) {
				coins[val] = std::min(coins[val], subCount + 1);
			}
		}
	}
	return coins[val];
}

int minCoinsTD(std::vector<int> &d, int n, int val) {
	std::vector<int> coins(val + 1, std::numeric_limits<int>::max());
	coins[0] = 0;
	return minCoinsTD(coins, d, n, val);
}

int minCoinsBU(std::vector<int> &d, int n, int val) { // DP bottom up approach.
	std::vector<int> coins(val + 1, std::numeric_limits<int>::max());
	coins[0] = 0; // Base value.

	for (int i = 1; i <= val; i++) {
		for (int j = 0; j < n; j++) {
			// For all coins smaller than or equal to i.
			if (d[j] <= i
					&& coins[i - d[j]] != std::numeric_limits<int>::max()) {
				coins[i] = std::min(coins[i], coins[i - d[j]] + 1);
			}
		}
	}

	return (coins[val] != std::numeric_limits<int>::max()) ? coins[val] : -1;
}

void printCoinsUtil(std::vector<int> &deno, int val) {
	if (val > 0) {
		printCoinsUtil(deno, val - deno[val]);
		printf("%d ", deno[val]);
	}
}

void printCoins(std::vector<int> &deno, int val) {
	printf("Coins are : ");
	printCoinsUtil(deno, val);
	printf("\n");
}

int minCoinsBU2(std::vector<int> &d, int n, int val) { // DP bottom up approach.
	std::vector<int> coins(val + 1, std::numeric_limits<int>::max());
	std::vector<int> deno(val + 1, std::numeric_limits<int>::max());

	coins[0] = 0; // Base value.

	for (int i = 1; i <= val; i++) {
		for (int j = 0; j < n; j++) {
			// For all coins smaller than or equal to i.
			if (d[j] <= i && coins[i - d[j]] != std::numeric_limits<int>::max()
					&& coins[i] > (coins[i - d[j]] + 1)) {
				coins[i] = coins[i - d[j]] + 1;
				deno[i] = d[j];
			}
		}
	}
	printCoins(deno, val);
	return (coins[val] != std::numeric_limits<int>::max()) ? coins[val] : -1;
}

// Testing code.
int main() {
	std::vector<int> d = { 1, 4, 6, 9, 12 };
	int value = 15;
	int n = d.size();
	std::cout << "Count is:" << minCoins(d, n, value) << std::endl;
	std::cout << "Count is:" << minCoins2(d, n, value) << std::endl;
	std::cout << "Count is:" << minCoinsBU(d, n, value) << std::endl;
	std::cout << "Count is:" << minCoinsTD(d, n, value) << std::endl;
	std::cout << "Count is:" << minCoinsBU2(d, n, value) << std::endl;
	return 0;
}

/*
 Count is:4
 Count is:2
 Count is:2
 Count is:2
 */
