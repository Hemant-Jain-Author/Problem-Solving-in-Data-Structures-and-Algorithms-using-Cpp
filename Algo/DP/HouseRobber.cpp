#include <string>
#include <vector>
#include <iostream>

int maxRobbery(std::vector<int> &house) {
	int n = house.size();
	std::vector<int> dp(n);
	dp[0] = house[0];
	dp[1] = house[1];
	dp[2] = dp[0] + house[2];

	for (int i = 3; i < n; i++) {
		dp[i] = std::max(dp[i - 2], dp[i - 3]) + house[i];
	}

	return std::max(dp[n - 1], dp[n - 2]);
}

int maxRobbery2(std::vector<int> &house) {
	int n = house.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n, std::vector<int>(2, 0));
	dp[0][1] = house[0];
	dp[0][0] = 0;

	for (int i = 1; i < n; ++i) {
		dp[i][1] = std::max(dp[i - 1][0] + house[i], dp[i - 1][1]);
		dp[i][0] = dp[i - 1][1];
	}
	return std::max(dp[n - 1][1], dp[n - 1][0]);
}

// Testing code.
int main() {
	std::vector<int> arr = { 10, 12, 9, 23, 25, 55, 49, 70 };
	std::cout << "Total cash: " << maxRobbery(arr) << std::endl;
	std::cout << "Total cash: " << maxRobbery2(arr) << std::endl;
	return 0;
}

/*
 Total cash: 160
 Total cash: 160
 */
