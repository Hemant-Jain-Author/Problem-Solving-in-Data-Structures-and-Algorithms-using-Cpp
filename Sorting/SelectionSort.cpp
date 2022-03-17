#include <vector>
#include <iostream>

bool less(int value1, int value2) {
	return value1 < value2;
}

bool more(int value1, int value2) {
	return value1 > value2;
}

void selectionSort(std::vector<int> &arr) {
	int size = arr.size();
	int i, j, max, temp;
	for (i = 0; i < size - 1; i++) {
		max = 0;
		for (j = 1; j < size - 1 - i; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[max];
		arr[max] = temp;
	}
}

void selectionSort2(std::vector<int> &arr) {
	int size = arr.size();
	int i, j, min, temp;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {
	std::vector<int> data = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	selectionSort(data);
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int> data2 = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	selectionSort2(data2);
	for (int i = 0; i < data2.size(); i++) {
		std::cout << data2[i] << " ";
	}
	return 0;
}

/*
 1 2 3 4 5 6 7 8 9
 */
