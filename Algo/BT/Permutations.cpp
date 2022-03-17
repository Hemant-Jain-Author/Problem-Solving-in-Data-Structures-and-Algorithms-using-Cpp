#include <string>
#include <vector>
#include <iostream>
#include <cmath>

void printArray(std::vector<int> &arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void swap(std::vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void permutation(std::vector<int> &arr, int i, int length) {
	if (length == i) {
		printArray(arr, length);
		return;
	}

	for (int j = i; j < length; j++) {
		swap(arr, i, j);
		permutation(arr, i + 1, length);
		swap(arr, i, j);
	}
	return;
}

bool isValid(std::vector<int> &arr, int n) {
	for (int j = 1; j < n; j++) {
		if (std::abs(arr[j] - arr[j - 1]) < 2) {
			return false;
		}
	}
	return true;
}

void permutation2(std::vector<int> &arr, int i, int length) {
	if (length == i) {
		if (isValid(arr, length)) {
			printArray(arr, length);
		}
		return;
	}

	for (int j = i; j < length; j++) {
		swap(arr, i, j);
		permutation2(arr, i + 1, length);
		swap(arr, i, j);
	}
	return;
}

bool isValid2(std::vector<int> &arr, int i) {
	if (i < 1 || std::abs(arr[i] - arr[i - 1]) >= 2) {
		return true;
	}
	return false;
}

void permutation3(std::vector<int> &arr, int i, int length) {
	if (length == i) {
		printArray(arr, length);
		return;
	}

	for (int j = i; j < length; j++) {
		swap(arr, i, j);
		if (isValid2(arr, i)) {
			permutation3(arr, i + 1, length);
		}
		swap(arr, i, j);
	}
	return;
}

// Testing code.
int main() {
	std::vector<int> arr(4);
	for (int i = 0; i < 4; i++) {
		arr[i] = i + 1;
	}
	permutation(arr, 0, 4);
	std::cout << std::endl;
	permutation2(arr, 0, 4);
	std::cout << std::endl;
	permutation3(arr, 0, 4);
	return 0;
}

/*
 1 2 3 4
 1 2 4 3
 ....
 4 1 3 2
 4 1 2 3

 2 4 1 3
 3 1 4 2

 2 4 1 3
 3 1 4 2
 */
