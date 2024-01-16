#include <string>
#include <vector>
#include <iostream>

int stairUniqueWaysBU(int n) {
	if (n < 2)
		return n;

	int first = 1, second = 2, temp = 0;

	for (int i = 2; i < n; i++) {
		temp = first + second;
		first = second;
		second = temp;
	}
	return temp;
}

int stairUniqueWaysBU2(int n) {
	if (n < 2)
		return n;

	std::vector<int> ways(n);
	ways[0] = 1;
	ways[1] = 2;

	for (int i = 2; i < n; i++)
		ways[i] = ways[i - 1] + ways[i - 2];

	return ways[n - 1];
}

// Testing code.
int main() {
	std::cout << "Unique way to reach top:: " << stairUniqueWaysBU(4) << std::endl;
	std::cout << "Unique way to reach top:: " << stairUniqueWaysBU2(4) << std::endl;
}

/*
 Unique way to reach top:: 5
 Unique way to reach top:: 5
 */
