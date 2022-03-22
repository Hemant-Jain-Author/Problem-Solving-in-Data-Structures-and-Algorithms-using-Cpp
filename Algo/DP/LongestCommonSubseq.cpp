#include <vector>
#include <iostream>

void PrintLCS(std::vector<std::vector<int>> &p, std::vector<char> &X, int i,
		int j) {
	if (i == 0 || j == 0)
		return;

	if (p[i][j] == 0) {
		PrintLCS(p, X, i - 1, j - 1);
		std::cout << X[i - 1];
	} else if (p[i][j] == 1)
		PrintLCS(p, X, i - 1, j);
	else
		PrintLCS(p, X, i, j - 1);
}

int LCSubStr(const std::string &st1, const std::string &st2) {
	std::vector<char> X(st1.begin(), st1.end());
	std::vector<char> Y(st2.begin(), st2.end());
	int m = st1.length();
	int n = st2.length();
	std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(m + 1,
			std::vector<int>(n + 1, 0)); // Dynamic programming array.
	std::vector<std::vector<int>> p = std::vector<std::vector<int>>(m + 1,
			std::vector<int>(n + 1, 0)); // For printing the substring.

	// Fill dp array in bottom up fashion.
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				p[i][j] = 0;
			} else {
				dp[i][j] =
						(dp[i - 1][j] > dp[i][j - 1]) ?
								dp[i - 1][j] : dp[i][j - 1];
				p[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? 1 : 2;
			}
		}
	}
	PrintLCS(p, X, m, n);
	std::cout << std::endl;
	return dp[m][n];
}

// Testing code.
int main() {
	std::string X = "carpenter";
	std::string Y = "sharpener";
	std::cout << LCSubStr(X, Y) << std::endl;
	return 0;
}

/*
 arpener
 7
 */
