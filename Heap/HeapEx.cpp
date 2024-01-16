#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <functional> // for greater<int>
#include <exception>
#include <algorithm>
#include <cmath>

// Testing code.
int main1() {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int arr[] = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };
	int value;

	for (int i : arr)
		pq.push(i);

	std::cout << "Dequeue elements of Priority Queue ::";
	while (pq.empty() == false) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
	return 0;
}

/*
 Dequeue elements of Priority Queue :: 1 2 3 4 5 6 7 8 9 10
 */

int KthSmallest(int arr[], int size, int k) {
	std::sort(arr, arr + size);
	return arr[k - 1];
}

int KthSmallest2(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < size; i++) {
		pq.push(arr[i]);
	}

	int value = 0;
	for (int i = 0; i < size && i < k; i++) {
		value = pq.top();
		pq.pop();
	}
	return value;
}

int KthSmallest3(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int i = 0; i < size; i++) {
		if (i < k) {
			pq.push(arr[i]);
		} else {
			if (pq.top() > arr[i]) {
				pq.push(arr[i]);
				pq.pop();
			}
		}
	}
	return pq.top();
}

// Testing code.
int main2() {
	int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest :: " << KthSmallest(arr, 8, 3) << std::endl;
	int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest :: " << KthSmallest2(arr2, 8, 3) << std::endl;
	int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest :: " << KthSmallest3(arr3, 8, 3) << std::endl;
	return 0;
}

/*
 Kth Smallest :: 5
 Kth Smallest :: 5
 */

int KSmallestProduct(int arr[], int size, int k) {
	std::sort(arr, arr + size);
	int product = 1;
	for (int i = 0; i < k; i++)
		product *= arr[i];
	return product;
}

int KSmallestProduct2(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int product = 1;
	for (int i = 0; i < size; i++)
		pq.push(arr[i]);

	for (int i = 0; i < size && i < k; i++) {
		product *= pq.top();
		pq.pop();
	}
	return product;
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void QuickSelectUtil(int arr[], int lower, int upper, int k) {
	if (upper <= lower)
		return;

	int pivot = arr[lower];
	int start = lower;
	int stop = upper;

	while (lower < upper) {
		while (lower < upper && arr[lower] <= pivot) {
			lower++;
		}
		while (lower <= upper && arr[upper] > pivot) {
			upper--;
		}
		if (lower < upper) {
			swap(arr, upper, lower);
		}
	}

	swap(arr, upper, start); // upper is the pivot position
	if (k < upper)
		QuickSelectUtil(arr, start, upper - 1, k); // pivot -1 is the upper for left sub array.
	if (k > upper)
		QuickSelectUtil(arr, upper + 1, stop, k); // pivot + 1 is the lower for right sub array.
}

int KSmallestProduct3(int arr[], int size, int k) {
	QuickSelectUtil(arr, 0, size - 1, k);
	int product = 1;
	for (int i = 0; i < k; i++)
		product *= arr[i];
	return product;
}

int KSmallestProduct4(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int i = 0; i < size; i++) {
		if (i < k)
			pq.push(arr[i]);
		else {
			if (pq.top() > arr[i]) {
				pq.push(arr[i]);
				pq.pop();
				;
			}
		}
	}
	int product = 1;
	for (int i = 0; i < k; i++) {
		product *= pq.top();
		pq.pop();
		;
	}
	return product;
}

// Testing code.
int main3() {
	int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest product:: " << KSmallestProduct(arr, 8, 3)
			<< std::endl;
	int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest product:: " << KSmallestProduct2(arr2, 8, 3)
			<< std::endl;
	int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest product:: " << KSmallestProduct3(arr3, 8, 3)
			<< std::endl;
	int arr4[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "Kth Smallest product:: " << KSmallestProduct4(arr3, 8, 3)
			<< std::endl;
	return 0;
}

/*
 Kth Smallest product:: 10
 Kth Smallest product:: 10
 Kth Smallest product:: 10
 Kth Smallest product:: 10
 */

void PrintLargerHalf(int arr[], int size) {
	std::sort(arr, arr + size);
	for (int i = size / 2; i < size; i++)
		std::cout << (arr[i]) << " ";
	std::cout << std::endl;
}

void PrintLargerHalf2(int arr[], int size) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;

	for (int i = 0; i < size; i++) {
		pq.push(arr[i]);
	}
	int half = size / 2;
	for (int i = 0; i < half; i++) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

void PrintLargerHalf3(int arr[], int size) {
	QuickSelectUtil(arr, 0, size - 1, size / 2);
	for (int i = size / 2; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void PrintLargerHalf4(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int i = 0; i < size; i++) {
		if (i < k) {
			pq.push(arr[i]);
		} else {
			if (pq.top() > arr[i]) {
				pq.push(arr[i]);
				pq.pop();
			}
		}
	}
	for (int i = 0; i < size / 2; i++) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
}

// Testing code.
int main4() {
	int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	PrintLargerHalf(arr, 8);
	int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	PrintLargerHalf2(arr2, 8);
	int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	PrintLargerHalf3(arr3, 8);
	int arr4[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	PrintLargerHalf3(arr4, 8);
	return 0;
}

/*
 6 7 7 8
 8 7 7 6
 6 7 7 8
 6 7 7 8
 */

void sortK(int arr[], int size, int k) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < k; i++)
		pq.push(arr[i]);

	int index = 0;
	for (int i = k; i < size; i++) {
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}
	while (pq.size() > 0) {
		arr[index++] = pq.top();
		pq.pop();
	}
}

// Testing code.
int main5() {
	int k = 3;
	int arr[] = { 1, 5, 4, 10, 50, 9 };
	int size = sizeof(arr) / sizeof(int);
	sortK(arr, size, k);
	for (auto i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}

/*
 1 4 5 9 10 50
 */

int ChotaBhim(int cups[], int size) {
	std::sort(cups, cups + size, std::less<int>());
	int total = 0, time = 60;
	int index, temp;
	while (time > 0) {
		total += cups[0];
		cups[0] = ceil(cups[0] / 2.0);
		index = 0;
		temp = cups[0];
		while (index < size - 1 && temp < cups[index + 1]) {
			cups[index] = cups[index + 1];
			index += 1;
		}
		cups[index] = temp;
		time -= 1;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int ChotaBhim2(int cups[], int size) {
	std::sort(cups, cups + size, std::greater<int>());
	int total = 0, time = 60;
	int i, temp;
	while (time > 0) {
		total += cups[0];
		cups[0] = ceil(cups[0] / 2.0);
		i = 0;
		// Insert into proper location.
		while (i < size - 1) {
			if (cups[i] > cups[i + 1])
				break;
			temp = cups[i];
			cups[i] = cups[i + 1];
			cups[i + 1] = temp;
			i += 1;
		}
		time -= 1;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int ChotaBhim3(int cups[], int size) {
	std::priority_queue<int, std::vector<int>, std::less<int>> pq;
	for (int i = 0; i < size; i++) {
		pq.push(cups[i]);
	}

	int total = 0, time = 60, value;
	while (time > 0) {
		value = pq.top();
		pq.pop();
		total += value;
		value = std::ceil(value / 2.0);
		pq.push(value);
		time -= 1;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int JoinRopes(int ropes[], int size) {
	std::sort(ropes, ropes + size, std::greater<>());
	int total = 0, value = 0;
	int temp, index;
	int length = size;

	while (length >= 2) {
		value = ropes[length - 1] + ropes[length - 2];
		total += value;
		index = length - 2;

		while (index > 0 && ropes[index - 1] < value) {
			ropes[index] = ropes[index - 1];
			index -= 1;
		}
		ropes[index] = value;
		length--;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

int JoinRopes2(int ropes[], int size) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < size; i++)
		pq.push(ropes[i]);

	int total = 0, value = 0;
	while (pq.size() > 1) {
		value = pq.top();
		pq.pop();
		value += pq.top();
		pq.pop();
		pq.push(value);
		total += value;
	}
	std::cout << "Total : " << total << std::endl;
	return total;
}

// Testing code.
int main6() {
	int cups[] = { 2, 1, 7, 4, 2 };
	ChotaBhim(cups, 5);
	int cups2[] = { 2, 1, 7, 4, 2 };
	ChotaBhim2(cups2, 5);
	int cups3[] = { 2, 1, 7, 4, 2 };
	ChotaBhim3(cups3, 5);

	int ropes[] = { 2, 1, 7, 4, 2 };
	JoinRopes(ropes, 5);
	int rope2[] = { 2, 1, 7, 4, 2 };
	JoinRopes2(rope2, 5);
	return 0;
}

/*
 Total : 76
 Total : 76
 Total : 76
 Total : 33
 Total : 33
 */

int kthLargestStream(int k) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int size = 0;
	int data = 0;
	while (true) {
		std::cout << "Enter data: ";
		if (size < k - 1)
			pq.push(data);
		else {
			if (size == k - 1)
				pq.push(data);
			else if (pq.top() < data) {
				pq.push(data);
				pq.pop();
			}
			std::cout << "Kth larges element is :: " << pq.top() << std::endl;
		}
		size += 1;
	}
}

// Testing code.
int mainSS() {
	kthLargestStream(3);
	return 0;
}

bool isMinHeap(int arr[], int size) {
	int lchild, rchild;
	// last element index size - 1
	for (int parent = 0; parent < (size / 2 + 1); parent++) {
		lchild = parent * 2 + 1;
		rchild = parent * 2 + 2;
		// heap property check.
		if (((lchild < size) && (arr[parent] > arr[lchild]))
				|| ((rchild < size) && (arr[parent] > arr[rchild])))
			return false;
	}
	return true;
}

bool isMinHeapArr(std::vector<int> &arr, int size) {
	for (int i = 0; i <= (size - 2) / 2; i++) {
		if (2 * i + 1 < size) {
			if (arr[i] > arr[2 * i + 1]) {
				return false;
			}
		}
		if (2 * i + 2 < size) {
			if (arr[i] > arr[2 * i + 2]) {
				return false;
			}
		}
	}
	return true;
}

bool isMaxHeapArr(std::vector<int> &arr, int size) {
	for (int i = 0; i <= (size - 2) / 2; i++) {
		if (2 * i + 1 < size) {
			if (arr[i] < arr[2 * i + 1]) {
				return false;
			}
		}
		if (2 * i + 2 < size) {
			if (arr[i] < arr[2 * i + 2]) {
				return false;
			}
		}
	}
	return true;
}

bool isMaxHeap(int arr[], int size) {
	int lchild, rchild;
	// last element index size - 1
	for (int parent = 0; parent < (size / 2 + 1); parent++) {
		lchild = parent * 2 + 1;
		rchild = lchild + 1;
		// heap property check.
		if (((lchild < size) && (arr[parent] < arr[lchild]))
				|| ((rchild < size) && (arr[parent] < arr[rchild])))
			return false;
	}
	return true;
}

// Testing code.
int main7() {
	int arr4[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
	std::cout << "isMaxHeap :: " << isMaxHeap(arr4, 8) << std::endl;
	int arr5[] = { 1, 2, 5, 7, 5, 6, 7, 8 };
	std::cout << "isMinHeap :: " << isMinHeap(arr5, 8) << std::endl;
	return 0;
}

/*
 isMaxHeap :: 1
 isMinHeap :: 1
 */

// Testing code.
int main() {
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	return 0;
}
