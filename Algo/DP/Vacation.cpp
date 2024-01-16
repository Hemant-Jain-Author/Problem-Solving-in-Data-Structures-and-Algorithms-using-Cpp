#include <string>
#include <vector>
#include <iostream>

int minCost(std::vector<int> &days, std::vector<int> &costs) {
	int n = days.size();
	int max = days[n - 1];
	std::vector<int> dp(max + 1);

	int j = 0;
	for (int i = 1; i <= max; i++) {
		if (days[j] == i) { // That days is definitely traveled.
			j++;
			dp[i] = dp[i - 1] + costs[0];
			dp[i] = std::min(dp[i], dp[std::max(0, i - 7)] + costs[1]);
			dp[i] = std::min(dp[i], dp[std::max(0, i - 30)] + costs[2]);
		} else
			dp[i] = dp[i - 1]; // day may be ignored.
	}
	return dp[max];
}

// Testing code.
int main() {
	std::vector<int> days = { 1, 3, 5, 7, 12, 20, 30 };
	std::vector<int> costs = { 2, 7, 20 };
	std::cout << "Min cost is:" << minCost(days, costs) << std::endl;
	return 0;
}

/*
 Min cost is:13
 */
