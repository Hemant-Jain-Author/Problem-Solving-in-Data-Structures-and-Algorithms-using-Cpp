#include <vector>
#include <iostream>

void swap(std::vector<int> &arr, int first, int second) {
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void quickSelect(std::vector<int> &arr, int lower, int upper, int k) {
	if (upper <= lower) {
		return;
	}

	int pivot = arr[lower];

	int start = lower;
	int stop = upper;

	while (lower < upper) {
		while (arr[lower] <= pivot && lower < upper) {
			lower++;
		}
		while (arr[upper] > pivot && lower <= upper) {
			upper--;
		}
		if (lower < upper) {
			swap(arr, upper, lower);
		}
	}

	swap(arr, upper, start); // upper is the pivot position

	if (k < upper) {
		quickSelect(arr, start, upper - 1, k); // pivot -1 is the upper for left sub array.
	}

	if (k > upper) {
		quickSelect(arr, upper + 1, stop, k); // pivot + 1 is the lower for right sub array.
	}

}

int quickSelect(std::vector<int> &arr, int k) {
	quickSelect(arr, 0, arr.size() - 1, k-1);
	return arr[k - 1];
}

// Testing code.
int main() {
	std::vector<int> data = { 3, 4, 2, 1, 6, 5, 7, 8, 10, 9 };
	int value = quickSelect(data, 5);
	std::cout << "Value at index 5 is " << value;
	return 0;
}

/*
 Value at index 5 is 5
 */
