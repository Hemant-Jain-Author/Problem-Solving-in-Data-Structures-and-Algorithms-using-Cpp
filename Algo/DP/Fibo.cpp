#include <string>
#include <vector>
#include <iostream>

int fibonacci(int n) {
	if (n < 2)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciBU(int n) {
	if (n < 2)
		return n;

	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int fibonacciTDUtil(int n, int dp[]) {
	if (n < 2) {
		dp[n] = n;
		return n;
	}

	if (dp[n] == 0)
		dp[n] = fibonacciTDUtil(n - 1, dp) + fibonacciTDUtil(n - 2, dp);

	return dp[n];
}

int fibonacciTD(int n) {
	int dp[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	return fibonacciTDUtil(n, dp);
}

int main() {
	std::cout << fibonacci(6) << std::endl;
	std::cout << fibonacciBU(6) << std::endl;
	std::cout << fibonacciTD(6) << std::endl;
	return 0;
}

/*
 */
