#include <string>
#include <vector>
#include <iostream>
#include <cmath>

void print(std::vector<int> &Q, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << Q[i] << " ";
	}
	std::cout << std::endl;
}

bool feasible(std::vector<int> &Q, int k) {
	for (int i = 0; i < k; i++) {
		if (Q[k] == Q[i] || std::abs(Q[i] - Q[k]) == std::abs(i - k)) {
			return false;
		}
	}
	return true;
}

void nQueens(std::vector<int> &Q, int k, int n) {
	if (k == n) {
		print(Q, n);
		return;
	}
	for (int i = 0; i < n; i++) {
		Q[k] = i;
		if (feasible(Q, k)) {
			nQueens(Q, k + 1, n);
		}
	}
}

// Testing code.
int main() {
	std::vector<int> Q(8);
	nQueens(Q, 0, 8);
	return 0;
}

/*
 0 4 7 5 2 6 1 3
 0 5 7 2 6 3 1 4
 ....
 7 2 0 5 1 4 6 3
 7 3 0 2 5 1 6 4
 */
