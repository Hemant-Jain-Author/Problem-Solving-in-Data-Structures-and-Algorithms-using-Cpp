#include <string>
#include <vector>
#include <iostream>

bool more(int value1, int value2) {
	return value1 > value2;
}

void shellSort(std::vector<int> &arr) {
	int n = arr.size();

	// Gap starts with n/2 and half in each iteration.
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort.
		for (int i = gap; i < n; i += 1) {
			int curr = arr[i];

			// Shift elements of already sorted list
			// to find right position for curr value.
			int j;
			for (j = i; j >= gap && more(arr[j - gap], curr); j -= gap) {
				arr[j] = arr[j - gap];
			}

			// Put current value in its correct location
			arr[j] = curr;
		}
	}
}

int main() {
	std::vector<int> array = { 36, 32, 11, 6, 19, 31, 17, 3 };
	shellSort(array);
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
}
