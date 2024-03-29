#include <vector>
#include <iostream>

void merge(std::vector<int> &arr, std::vector<int> &tempArray, int lowerIndex,
		int middleIndex, int upperIndex) {
	int lowerStart = lowerIndex;
	int lowerStop = middleIndex;
	int upperStart = middleIndex + 1;
	int upperStop = upperIndex;
	int count = lowerIndex;
	while (lowerStart <= lowerStop && upperStart <= upperStop) {
		if (arr[lowerStart] < arr[upperStart]) {
			tempArray[count++] = arr[lowerStart++];
		} else {
			tempArray[count++] = arr[upperStart++];
		}
	}
	while (lowerStart <= lowerStop) {
		tempArray[count++] = arr[lowerStart++];
	}
	while (upperStart <= upperStop) {
		tempArray[count++] = arr[upperStart++];
	}
	for (int i = lowerIndex; i <= upperIndex; i++) {
		arr[i] = tempArray[i];
	}
}

void mergeSortUtil(std::vector<int> &arr, std::vector<int> &tempArray,
		int lowerIndex, int upperIndex) {
	if (lowerIndex >= upperIndex) {
		return;
	}
	int middleIndex = (lowerIndex + upperIndex) / 2;
	mergeSortUtil(arr, tempArray, lowerIndex, middleIndex);
	mergeSortUtil(arr, tempArray, middleIndex + 1, upperIndex);
	merge(arr, tempArray, lowerIndex, middleIndex, upperIndex);
}

void mergeSort(std::vector<int> &arr) {
	int size = arr.size();
	std::vector<int> tempArray(size);
	mergeSortUtil(arr, tempArray, 0, size - 1);
}

// Testing code.
int main() {
	std::vector<int> data = { 3, 4, 2, 1, 6, 5, 7, 8, 1, 1 };
	mergeSort(data);
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << " ";
	}
	return 0;
}

/*
 1 1 1 2 3 4 5 6 7 8
 */
