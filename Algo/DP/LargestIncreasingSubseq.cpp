#include <string>
#include <vector>
#include <iostream>

int lis(std::vector<int> &arr) {
	int n = arr.size();
	std::vector<int> lis(n);
	int max = 0;

	// Populating LIS values in bottom up manner.
	for (int i = 0; i < n; i++) {
		lis[i] = 1; // Initialize LIS values for all indexes as 1.
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}

		if (max < lis[i]) // Max LIS values.
			max = lis[i];
	}
	return max;
}

// Testing code.
int main() {
	std::vector<int> arr = { 10, 12, 9, 23, 25, 55, 49, 70 };
	std::cout << "Length of lis is " << lis(arr) << std::endl;
	return 0;
}

/*
 Length of lis is 6
 */

