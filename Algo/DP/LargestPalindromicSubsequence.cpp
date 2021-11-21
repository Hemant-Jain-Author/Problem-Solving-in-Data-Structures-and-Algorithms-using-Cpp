#include <string>
#include <vector>
#include <iostream>

int palindromicSubsequence(const std::string &str)
{
	int n = str.length();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

	for (int i = 0;i < n;i++) // each char is itself palindromic with length 1
		dp[i][i] = 1;

	for (int l = 1; l < n; l++)
	{
		for (int i = 0, j = l; j < n; i++, j++)
		{
			if (str[i] == str[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][n - 1];
}

int main()
{
	std::string str = "ABCAUCBCxxCBA";
	std::cout << "Max Palindromic Subsequence length: " << palindromicSubsequence(str) << std::endl;
	return 0;
}

/*
Max Palindromic Subsequence length: 9
*/