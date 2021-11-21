#include <string>
#include <vector>
#include <iostream>

int minCost(std::vector<int> &cost, int n)
{
	// base case
	if (n == 1)
		return cost[0];

	std::vector<int> dp(n);
	dp[0] = cost[0];
	dp[1] = cost[1];

	for (int i = 2; i < n; i++)
		dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];

	return std::min(dp[n - 2], dp[n - 1]);
}

int main()
{
	std::vector<int> a = {1, 5, 6, 3, 4, 7, 9, 1, 2, 11};
	int n = a.size();
	std::cout << minCost(a, n);
	return 0;
}

/*
18
*/