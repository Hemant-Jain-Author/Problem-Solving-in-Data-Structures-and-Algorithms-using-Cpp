#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

void bucketSort(std::vector<int> &arr, int maxValue, int numBucket) {
	int length = arr.size();
	if (length == 0) {
		return;
	}

	// Create empty buckets
	std::vector<std::vector<int>> bucket(numBucket);
	for (int i = 0; i < numBucket; i++)
		bucket.push_back(std::vector<int>());

	int div = std::ceil(static_cast<double>(maxValue) / numBucket);

	// Add elements into the buckets
	for (int i = 0; i < length; i++) {
		if (arr[i] < 0 || arr[i] > maxValue) {
			std::cout << "Value out of range." << std::endl;
			return;
		}

		int bucketIndex = (arr[i] / div);

		// Maximum value will be assigned to last bucket.
		if (bucketIndex >= numBucket) {
			bucketIndex = numBucket - 1;
		}
		bucket[bucketIndex].push_back(arr[i]);
	}

	// Sort the elements of each bucket.
	for (int i = 0; i < numBucket; i++)
		std::sort(bucket[i].begin(), bucket[i].end());

	// Populate output from the sorted subarray.
	int index = 0, count;
	for (int i = 0; i < numBucket; i++) {
		std::vector<int> temp = bucket[i];
		count = temp.size();
		for (int j = 0; j < count; j++) {
			arr[index++] = temp[j];
		}
	}
}

void bucketSort(std::vector<int> &arr, int maxValue) {
	int numBucket = 5;
	bucketSort(arr, maxValue, numBucket);
}

int main() {
	std::vector<int> array = { 1, 34, 7, 99, 5, 23, 45, 88, 77, 19, 91, 100 };
	int maxValue = 100;
	bucketSort(array, maxValue);
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}
}

/*
 1 5 7 19 23 34 45 77 88 91 99 100
 */
