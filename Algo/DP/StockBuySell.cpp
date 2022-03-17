#include <string>
#include <vector>
#include <iostream>

int maxProfit(std::vector<int> &arr) {
	int buyProfit = -arr[0]; // Buy stock profit
	int sellProfit = 0; // Sell stock profit
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int newBuyProfit =
				(sellProfit - arr[i] > buyProfit) ?
						sellProfit - arr[i] : buyProfit;
		int newSellProfit =
				(buyProfit + arr[i] > sellProfit) ?
						buyProfit + arr[i] : sellProfit;
		buyProfit = newBuyProfit;
		sellProfit = newSellProfit;
	}
	return sellProfit;
}

int maxProfitTC(std::vector<int> &arr, int t) {
	int buyProfit = -arr[0];
	int sellProfit = 0;
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int newBuyProfit =
				((sellProfit - arr[i]) > buyProfit) ?
						(sellProfit - arr[i]) : buyProfit;
		int newSellProfit =
				((buyProfit + arr[i] - t) > sellProfit) ?
						(buyProfit + arr[i] - t) : sellProfit;
		buyProfit = newBuyProfit;
		sellProfit = newSellProfit;
	}
	return sellProfit;
}

int maxProfit2(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(2, 0));
	dp[0][0] = -arr[0]; // Buy stock profit
	dp[0][1] = 0; // Sell stock profit

	for (int i = 1; i < n; i++) {
		dp[i][0] =
				(dp[i - 1][1] - arr[i] > dp[i - 1][0]) ?
						dp[i - 1][1] - arr[i] : dp[i - 1][0];
		dp[i][1] =
				(dp[i - 1][0] + arr[i] > dp[i - 1][1]) ?
						dp[i - 1][0] + arr[i] : dp[i - 1][1];
	}
	return dp[n - 1][1];
}

int maxProfitTC2(std::vector<int> &arr, int t) {
	int n = arr.size();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(2, 0));
	dp[0][0] = -arr[0];
	dp[0][1] = 0;

	for (int i = 1; i < n; i++) {
		dp[i][0] =
				((dp[i - 1][1] - arr[i]) > dp[i - 1][0]) ?
						(dp[i - 1][1] - arr[i]) : dp[i - 1][0];
		dp[i][1] =
				((dp[i - 1][0] + arr[i] - t) > dp[i - 1][1]) ?
						(dp[i - 1][0] + arr[i] - t) : dp[i - 1][1];
	}
	return dp[n - 1][1];
}

// Testing code.
int main() {
	std::vector<int> arr = { 10, 12, 9, 23, 25, 55, 49, 70 };
	std::cout << "Total profit: " << maxProfit(arr) << std::endl;
	std::cout << "Total profit: " << maxProfit2(arr) << std::endl;
	std::cout << "Total profit: " << maxProfitTC(arr, 2) << std::endl;
	std::cout << "Total profit: " << maxProfitTC2(arr, 2) << std::endl;
}

/*
 Total profit: 69
 Total profit: 69
 Total profit: 63
 Total profit: 63
 */
