#include <string>
#include <vector>
#include <iostream>

int maxCost01Util(std::vector<int> &wt, std::vector<int> &cost, int n,
		int capacity) {
	// Base Case
	if (n == 0 || capacity == 0)
		return 0;

	// Return the maximum of two cases:
	// (1) nth item is included
	// (2) nth item is not included
	int first = 0;
	if (wt[n - 1] <= capacity)
		first = cost[n - 1]
				+ maxCost01Util(wt, cost, n - 1, capacity - wt[n - 1]);

	int second = maxCost01Util(wt, cost, n - 1, capacity);
	return std::max(first, second);
}

int maxCost01(std::vector<int> &wt, std::vector<int> &cost, int capacity) {
	int n = wt.size();
	return maxCost01Util(wt, cost, n, capacity);
}

int maxCost01TDUtil(std::vector<std::vector<int>> &dp, std::vector<int> &wt,
		std::vector<int> &cost, int i, int w) {
	if (w == 0 || i == 0)
		return 0;

	if (dp[w][i] != 0)
		return dp[w][i];

	// Their are two cases:
	// (1) ith item is included
	// (2) ith item is not included
	int first = 0;
	if (wt[i - 1] <= w)
		first = maxCost01TDUtil(dp, wt, cost, i - 1, w - wt[i - 1])
				+ cost[i - 1];

	int second = maxCost01TDUtil(dp, wt, cost, i - 1, w);
	return dp[w][i] = std::max(first, second);
}

int maxCost01TD(std::vector<int> &wt, std::vector<int> &cost, int capacity) {
	int n = wt.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(
			capacity + 1, std::vector<int>(n + 1, 0));
	return maxCost01TDUtil(dp, wt, cost, n, capacity);
}

void printItems(int n, std::vector<std::vector<int>>& dp, std::vector<int> &wt, std::vector<int> &cost, int capacity) {
    int totalProfit = dp[capacity][n];
    std::cout << "Selected items are: ";
    for (int i = n-1; i > -1; i--) {
        if (totalProfit != dp[capacity][i - 1]) {
            std::cout << "(wt:" << wt[i] << ", cost:" << cost[i] <<") ";
            capacity -= wt[i];
            totalProfit -= cost[i];
		}
	}
	std::cout << std::endl;
}

int maxCost01BU(std::vector<int> &wt, std::vector<int> &cost, int capacity) {
	int n = wt.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(
			capacity + 1, std::vector<int>(n + 1, 0));

	// Build table dp[][] in bottom up approach.
	// Weights considered against capacity.
	for (int w = 1; w <= capacity; w++) {
		for (int i = 1; i <= n; i++) {
			// Their are two cases:
			// (1) ith item is included
			// (2) ith item is not included
			int first = 0;
			if (wt[i - 1] <= w)
				first = dp[w - wt[i - 1]][i - 1] + cost[i - 1];

			int second = dp[w][i - 1];
			dp[w][i] = std::max(first, second);
		}
	}
	printItems(n, dp, wt, cost, capacity);
	return dp[capacity][n]; // Number of weights considered and final capacity.
}


int KS01UnboundBU(std::vector<int> &wt, std::vector<int> &cost, int capacity) {
	int n = wt.size();
	std::vector<int> dp(capacity + 1);

	// Build table dp[] in bottom up approach.
	// Weights considered against capacity.
	for (int w = 1; w <= capacity; w++) {
		for (int i = 1; i <= n; i++) {
			// Their are two cases:
			// (1) ith item is included 
			// (2) ith item is not included
			if (wt[i - 1] <= w)
				dp[w] = std::max(dp[w], dp[w - wt[i - 1]] + cost[i - 1]);
		}
	}
	
	return dp[capacity]; // Number of weights considered and final capacity.
}

// Testing code.
int main() {
	std::vector<int> wt = { 10, 40, 20, 30 };
	std::vector<int> cost = { 60, 40, 90, 120 };
	int capacity = 50;
	double maxCost = KS01UnboundBU(wt, cost, capacity);
	std::cout << "Maximum cost obtained = " << maxCost << std::endl;
	maxCost = maxCost01(wt, cost, capacity);
	std::cout << "Maximum cost obtained = " << maxCost << std::endl;
	maxCost = maxCost01BU(wt, cost, capacity);
	std::cout << "Maximum cost obtained = " << maxCost << std::endl;
	maxCost = maxCost01TD(wt, cost, capacity);
	std::cout << "Maximum cost obtained = " << maxCost << std::endl;
	return 0;
}

/*
 Maximum cost obtained = 300
 Maximum cost obtained = 210
 Maximum cost obtained = 210
 Maximum cost obtained = 210
 */
