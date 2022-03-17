#include <string>
#include <vector>
#include <iostream>

void printSubset(std::vector<bool> &flags, std::vector<int> &arr, int size) {
	for (int i = 0; i < size; i++) {
		if (flags[i]) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

void subsetSum(std::vector<int> &arr, int n, std::vector<bool> &flags, int sum,
		int curr, int target) {
	if (target == sum) {
		printSubset(flags, arr, n); // Solution found.
		return;
	}

	if (curr >= n || sum > target) { // Constraint check and Backtracking.
		return;
	}

	flags[curr] = true; // Current element included.
	subsetSum(arr, n, flags, sum + arr[curr], curr + 1, target);

	flags[curr] = false; // Current element excluded.
	subsetSum(arr, n, flags, sum, curr + 1, target);
}

void subsetSum(std::vector<int> &arr, int n, int target) {
	std::vector<bool> flags(n);
	subsetSum(arr, n, flags, 0, 0, target);
}

// Testing code.
int main() {
	std::vector<int> arr = { 15, 22, 14, 26, 32, 9, 16, 8 };
	int target = 53;
	int n = arr.size();
	subsetSum(arr, n, target);
	return 0;
}

/*
 15 22 16
 15 14 16 8
 22 14 9 8
 */
