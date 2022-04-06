#include <string>
#include <vector>
#include <iostream>

bool matchExpUtil(const std::string &exp, const std::string &str, int m,
		int n) {
	if (m == exp.size() && (n == str.size() || exp[m - 1] == '*'))
		return true;

	if ((m == exp.size() && n != str.size())
		|| (m != exp.size() && n == str.size()))
		return false;

	if (exp[m] == '?' || exp[m] == str[n])
		return matchExpUtil(exp, str, m + 1, n + 1);

	if (exp[m] == '*')
		return matchExpUtil(exp, str, m + 1, n)
				|| matchExpUtil(exp, str, m, n + 1);

	return false;
}

bool matchExp(const std::string &exp, const std::string &str) {
	return matchExpUtil(exp, str, 0, 0);
}

bool matchExpDPUtil(const std::string &exp, const std::string &str, int m,
		int n) {
	std::vector<std::vector<bool>> lookup = std::vector<std::vector<bool>>(
			m + 1, std::vector<bool>(n + 1, false));
	lookup[0][0] = true; // empty exp and empty str match.

	// 0 row will remain all false. empty exp can't match any str.
	// '*' can match with empty string, column 0 update.
	for (int i = 1; i <= m; i++) {
		if (exp[i - 1] == '*')
			lookup[i][0] = lookup[i - 1][0];
		else
			break;
	}

	// Fill the table in bottom-up fashion
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// If we see a '*' in pattern:
			// 1) We ignore '*' character and consider next character in the pattern.
			// 2) We ignore one character in the input str and consider next character.
			if (exp[i - 1] == '*')
				lookup[i][j] = lookup[i - 1][j] || lookup[i][j - 1];
			// Condition when both the pattern and input string have same character. 
			// Also '?' match with all the characters.
			else if (exp[i - 1] == '?' || str[j - 1] == exp[i - 1])
				lookup[i][j] = lookup[i - 1][j - 1];
			// If characters don't match
			else
				lookup[i][j] = false;
		}
	}
	return lookup[m][n];
}

bool matchExpDP(const std::string &exp, const std::string &str) {
	return matchExpDPUtil(exp, str, exp.length(), str.length());
}

// Testing code.
int main() {
	std::cout << matchExp("*llo,?World?", "Hello, World!") << std::endl;
	std::cout << matchExpDP("*llo,?World?", "Hello, World!") << std::endl;
}

/*
 1
 1
 */
