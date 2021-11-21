#include <string>
#include <vector>
#include <iostream>

int fibonacci(int n)
{
	if (n <= 2)
		return n - 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacciSeries(int n)
{
	for (int i = 1;i <= n;i++)
		std::cout << fibonacci(i) << " ";
}

int fibonacciBU(int n)
{
	if (n <= 2)
		return n - 1;

	int first = 0, second = 1;
	int temp = 0;

	for (int i = 2; i < n; i++)
	{
		temp = first + second;
		first = second;
		second = temp;
	}
	return temp;
}

void fibonacciSeriesBU(int n)
{
	if (n < 1)
		return;

	std::vector<int> dp(n);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	for (int i = 0;i < n;i++)
		std::cout << dp[i] << " ";
}

int fibonacciSeriesTDUtil(int n, std::vector<int> &dp)
{
	if (n <= 1)
		return dp[n] = n;

	if (dp[n] != 0)
		return dp[n];

	dp[n] = fibonacciSeriesTDUtil(n - 1, dp) + fibonacciSeriesTDUtil(n - 2, dp);
	return dp[n];
}

void fibonacciSeriesTD(int n)
{
	if (n < 1)
		return;

	std::vector<int> dp(n);
	fibonacciSeriesTDUtil(n - 1, dp);

	for (int i = 0;i < n;i++)
		std::cout << dp[i] << " ";
}

int main()
{

	fibonacciSeries(6);
	std::cout << std::endl;

	fibonacciSeriesBU(6);
	std::cout << std::endl;

	fibonacciSeriesTD(6);
	std::cout << std::endl;
	
	std::cout << fibonacci(6) << std::endl;
	std::cout << fibonacciBU(6) << std::endl;
	return 0;
}

/*
0 1 1 2 3 5 
0 1 1 2 3 5 
0 1 1 2 3 5 
5
5
*/