#include <string>
#include <vector>
#include <iostream>

int min(int x, int y, int z) {
	x = std::min(x, y);
	return std::min(x, z);
}

int editDistUtil(const std::string &str1, const std::string &str2, int m,
		int n) {
	// If any one string is empty, then empty the other string.
	if (m == 0 || n == 0)
		return m + n;

	// If last characters of both strings are same then ignore last characters.
	if (str1[m - 1] == str2[n - 1]) {
		return editDistUtil(str1, str2, m - 1, n - 1);
	}

	// If last characters are different then consider all three cases:
	// 1) Insert last char of second into first.
	// 2) Remove last char of first.
	// 3) Replace last char of first with second.
	return 1
			+ min(editDistUtil(str1, str2, m, n - 1),
					editDistUtil(str1, str2, m - 1, n),
					editDistUtil(str1, str2, m - 1, n - 1)); // Replace
}

int editDist(const std::string &str1, const std::string &str2) {
	int m = str1.length();
	int n = str2.length();
	return editDistUtil(str1, str2, m, n);
}

int editDistDP(const std::string &str1, const std::string &str2) {
	int m = str1.length();
	int n = str2.length();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(m + 1,
			std::vector<int>(n + 1, 0));

	// Fill dp[][] in bottom up manner.
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If any one string is empty then empty the other string.
			if (i == 0 || j == 0) {
				dp[i][j] = (i + j);
			}
			// If last characters of both strings are same then ignore last characters.
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// If last characters are different then consider all three operations:
			// 1) Insert last char of second into first.
			// 2) Remove last char of first.
			// 3) Replace last char of first with second.
			else {
				dp[i][j] = 1
						+ min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]); // Replace
			}
		}
	}
	return dp[m][n];
}

int main() {
	std::string str1 = "sunday";
	std::string str2 = "saturday";
	std::cout << "EditDist is " << editDist(str1, str2) << std::endl;
	std::cout << "EditDist is " << editDistDP(str1, str2) << std::endl;
	return 0;
}

/*
 EditDist is 3
 EditDist is 3
 */
