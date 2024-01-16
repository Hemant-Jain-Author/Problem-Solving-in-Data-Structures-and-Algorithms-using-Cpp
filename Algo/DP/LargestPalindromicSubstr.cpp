#include <string>
#include <vector>
#include <iostream>

int palindromicSubstring(const std::string &str) {
	int n = str.length();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(n,
			std::vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;

	int max = 1;
	int start = 0;

	for (int l = 1; l < n; l++) {
		for (int i = 0, j = i + l; j < n; i++, j++) {
			if (str[i] == str[j] && dp[i + 1][j - 1] == j - i - 1) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
				if (dp[i][j] > max) {
					max = dp[i][j]; // Keeping track of max length and
					start = i; // starting position of sub-string.
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}
	return max;
}

// Testing code.
int main() {
	std::string str = "ABCAUCBCxxCBA";
	int length = palindromicSubstring(str);
	std::cout << "Max Palindromic Substrings len: " << length << std::endl;
	return 0;
}

/*
 Max Palindromic Substrings len: 6
 */
