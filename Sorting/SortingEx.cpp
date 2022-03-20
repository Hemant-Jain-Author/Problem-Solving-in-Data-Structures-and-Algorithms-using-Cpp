#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void printArray(std::vector<int> &arr) {
	int size = arr.size();
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void printArray2(std::vector<int> &arr, int size) {
	std::cout << "[";
	for (int i = 0; i < size; i++) {
		std::cout << " " << arr[i];
	}
	std::cout << " ]\n";
}

void swap(std::vector<int> &arr, int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	return;
}

int partition01(std::vector<int> &arr) {
	int size = arr.size();
	int left = 0;
	int right = size - 1;
	int count = 0;
	while (left < right) {
		while (arr[left] == 0)
			left += 1;

		while (arr[right] == 1)
			right -= 1;

		if (left < right) {
			swap(arr, left, right);
			count += 1;
		}
	}
	return count;
}

void partition012(std::vector<int> &arr) {
	int size = arr.size();
    int zero = 0, one = 0, two = 0;
    for (int i =0; i < size;i++) {
        if (arr[i] == 0) {
            zero += 1;
        } else if (arr[i] == 1) {
            one += 1;
        } else {
            two += 1;
        }
    }

    int index = 0;
    while(zero > 0){
        arr[index++] = 0;
        zero -= 1;
    }

    while(one > 0){
        arr[index++] = 1;
        one -= 1;
    }

    while(two > 0){
        arr[index++] = 2;
        two -= 1;
    }
}

void partition012_(std::vector<int> &arr) {
	int size = arr.size();
	int left = 0;
	int right = size - 1;
	int i = 0;
	while (i <= right) {
		if (arr[i] == 0) {
			swap(arr, i, left);
			i += 1;
			left += 1;
		} else if (arr[i] == 2) {
			swap(arr, i, right);
			right -= 1;
		} else {
			i += 1;
		}
	}
}

// Testing code.
int main1() {
	std::vector<int> arr = { 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 };
	partition01(arr);
	printArray(arr);

	std::vector<int> arr2 = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	partition012(arr2);
	printArray(arr2);

	std::vector<int> arr3 = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	partition012(arr3);
	printArray(arr3);

	return 0;
}

/*
 [ 0 0 0 0 0 0 1 1 1 1 1 1 ]
 [ 0 0 0 0 0 1 1 1 1 1 2 2 ]
 */

void rangePartition(std::vector<int> &arr, int lower, int higher) {
	int size = arr.size();
	int start = 0;
	int end = size - 1;
	int i = 0;
	while (i <= end) {
		if (arr[i] < lower) {
			swap(arr, i, start);
			i += 1;
			start += 1;
		} else if (arr[i] > higher) {
			swap(arr, i, end);
			end -= 1;
		} else {
			i += 1;
		}
	}
}

// Testing code.
int main2() {
	std::vector<int> arr = { 15, 16, 19, 18, 5, 17, 6, 7, 8, 14, 9, 13, 10, 12,
			11 };
	rangePartition(arr, 9, 12);
	printArray(arr);
	return 0;
}

/*
 [ 5 8 6 7 11 12 10 9 14 17 13 18 19 16 15 ]
 */

int minSwaps(std::vector<int> &arr, int val) {
	int size = arr.size();
	int swapCount = 0;
	int first = 0;
	int second = size - 1;
	int temp;
	while (first < second) {
		if (arr[first] <= val)
			first += 1;
		else if (arr[second] > val)
			second -= 1;
		else {
			temp = arr[first];
			arr[first] = arr[second];
			arr[second] = temp;
			swapCount += 1;
		}
	}
	return swapCount;
}

// Testing code.
int main3() {
	std::vector<int> arr = { 2, 7, 5, 6, 1, 3, 4, 9, 10, 8 };
	int val = 5;
	std::cout << "minSwaps:: " << minSwaps(arr, val) << std::endl;
	printArray(arr);
	return 0;
}

/*
 minSwaps:: 2
 */

void separateEvenAndOdd(std::vector<int> &data) {
	int size = data.size();
    int left = 0, right = size - 1;
    int aux[size];

    for (int i=0;i< size;i++) {
        if (data[i] % 2 == 0) {
            aux[left] = data[i];
            left++;
        } else if (data[i] % 2 == 1) {
            aux[right] = data[i];
            right--;
        }
    }

    for (int i=0;i< size;i++)
        data[i] = aux[i];
}

void separateEvenAndOdd2(std::vector<int> &data) {
	int size = data.size();
	int left = 0, right = size - 1;
	while (left < right) {
		if (data[left] % 2 == 0)
			left++;
		else if (data[right] % 2 == 1)
			right--;
		else {
			swap(data, left, right);
			left++;
			right--;
		}
	}
}

// Testing code.
int main4() {
	std::vector<int> array = { 2, 7, 5, 6, 1, 3, 4, 9, 10, 8 };
	separateEvenAndOdd(array);
	printArray(array);

	std::vector<int> array2 = { 2, 7, 5, 6, 1, 3, 4, 9, 10, 8 };
	separateEvenAndOdd2(array2);
	printArray(array2);
	return 0;
}

/*
[ 2 6 4 10 8 9 3 1 5 7 ]
[ 2 8 10 6 4 3 1 9 5 7 ] 
*/

bool absGreater(int value1, int value2, int ref) {
	return (std::abs(value1 - ref) > std::abs(value2 - ref));
}

void absBubbleSort(std::vector<int> &arr, int ref) {
	int size = arr.size();
	for (int i = 0; i < (size - 1); i++) {
		for (int j = 0; j < (size - i - 1); j++) {
			if (absGreater(arr[j], arr[j + 1], ref)) {
				swap(arr, j, j + 1);
			}
		}
	}
}

// Testing code.
int main5() {
	std::vector<int> array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	int ref = 5;
	absBubbleSort(array, ref);
	printArray(array);
	return 0;
}

/*
 [ 5 6 4 7 3 8 2 9 1 ]
 */

bool eqGreater(int value1, int value2, int A) {
	value1 = A * value1 * value1;
	value2 = A * value2 * value2;
	return value1 > value2;
}

void arrayReduction(std::vector<int> &arr) {
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	int count = 1;
	int reduction = arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i] - reduction > 0) {
			reduction = arr[i];
			count += 1;
		}
	}
	std::cout << "Total number of reductions " << count << std::endl;
}

// Testing code.
int main6() {
	std::vector<int> arr = { 5, 1, 1, 1, 2, 3, 5 };
	arrayReduction(arr);
	return 0;
}

/*
 Total number of reductions 4
 */

void sortByOrder(std::vector<int> &arr, std::vector<int> &arr2) {
	int size = arr.size();
	int size2 = arr2.size();
	std::map<int, int> ht;
	int value;
	for (int i = 0; i < size; i++) {
		if (ht.find(arr[i]) != ht.end()) {
			value = ht[arr[i]];
			ht[arr[i]] = value + 1;
		} else {
			ht[arr[i]] = 1;
		}
	}

	for (int j = 0; j < size2; j++) {
		if (ht.find(arr2[j]) != ht.end()) {
			value = ht[arr2[j]];
			for (int k = 0; k < value; k++) {
				std::cout << arr2[j] << " ";
			}
			ht.erase(arr2[j]);
		}
	}

	for (int i = 0; i < size; i++) {
		if (ht.find(arr[i]) != ht.end()) {
			value = ht[arr[i]];
			for (int k = 0; k < value; k++) {
				std::cout << arr[i] << " ";
			}
			ht.erase(arr[i]);
		}
	}
	std::cout << std::endl;
}

// Testing code.
int main7() {
	std::vector<int> arr = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
	std::vector<int> arr2 = { 2, 1, 8, 3 };
	sortByOrder(arr, arr2);
	return 0;
}

/*
 2 2 1 1 8 8 3 5 7 9 6
 */

void merge(std::vector<int> &arr1, std::vector<int> &arr2) {
	int size1 = arr1.size();
	int size2 = arr2.size();

	int index = 0;
	while (index < size1) {
		if (arr1[index] <= arr2[0]) {
			index += 1;
		} else {
			// always first element of arr2 is compared.
			arr1[index] ^= arr2[0] ^= arr1[index] ^= arr2[0];
			index += 1;
			// After swap arr2 may be unsorted.
			// Insertion of the element in proper sorted position.
			for (int i = 0; i < (size2 - 1); i++) {
				if (arr2[i] < arr2[i + 1])
					break;
				arr2[i] ^= arr2[i + 1] ^= arr2[i] ^= arr2[i + 1];
			}
		}
	}
}

// Testing code.
int main8() {
	std::vector<int> arr1 = { 1, 5, 9, 10, 15, 20 };
	std::vector<int> arr2 = { 2, 3, 8, 13 };
	merge(arr1, arr2);
	printArray(arr1);
	printArray(arr2);
	return 0;
}

/*
 [ 1 2 3 5 8 9 ]
 [ 10 13 15 20 ]
 */

bool checkReverse(std::vector<int> &arr) {
	int size = arr.size();
	int start = -1;
	int stop = -1;
	for (int i = 0; i < (size - 1); i++) {
		if (arr[i] > arr[i + 1]) {
			start = i;
			break;
		}
	}

	if (start == -1)
		return true;

	for (int i = start; i < (size - 1); i++) {
		if (arr[i] < arr[i + 1]) {
			stop = i;
			break;
		}
	}

	if (stop == -1)
		return true;

	// increasing property after reversal the sub array should fit in the array.
	if (arr[start - 1] > arr[stop] || arr[stop + 1] < arr[start])
		return false;

	for (int i = stop + 1; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

// Testing code.
int main9() {
	std::vector<int> arr = { 1, 3, 8, 5, 4, 3, 10, 11, 12, 18, 28 };
	std::cout << "checkReverse : " << checkReverse(arr) << std::endl;
	return 0;
}

/*
 checkReverse : 1
 */

void unionIntersectionSorted(std::vector<int> &arr1, std::vector<int> &arr2) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	int first = 0, second = 0;
	std::vector<int> unionArr(size1 + size2, 0);
	int minlen = (size1 < size2) ? size1 : size2;
	std::vector<int> interArr(minlen, 0);
	int uIndex = 0;
	int iIndex = 0;

	while (first < size1 && second < size2) {
		if (arr1[first] == arr2[second]) {
			unionArr[uIndex++] = arr1[first];
			interArr[iIndex++] = arr1[first];
			first += 1;
			second += 1;
		} else if (arr1[first] < arr2[second]) {
			unionArr[uIndex++] = arr1[first];
			first += 1;
		} else {
			unionArr[uIndex++] = arr2[second];
			second += 1;
		}
	}

	while (first < size1) {
		unionArr[uIndex++] = arr1[first];
		first += 1;
	}

	while (second < size2) {
		unionArr[uIndex++] = arr2[second];
		second += 1;
	}
	printArray2(unionArr, uIndex);
	printArray2(interArr, iIndex);
}

void unionIntersectionUnsorted(std::vector<int> &arr1, std::vector<int> &arr2) {
	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	unionIntersectionSorted(arr1, arr2);
}

// Testing code.
int main10() {
	std::vector<int> arr1 = { 1, 11, 2, 3, 14, 5, 6, 8, 9 };
	std::vector<int> arr2 = { 2, 4, 5, 12, 7, 8, 13, 10 };
	unionIntersectionUnsorted(arr1, arr2);
	return 0;
}

/*
 [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ]
 [ 2 5 8 ]
 */

void reverseArray(std::vector<int> &data, int start, int end) {
	for (int i = start, j = end; i < j; i++, j--) {
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

void reverseArray(std::vector<int> &data) {
	int start = 0;
	int end = data.size() - 1;
	for (int i = start, j = end; i < j; i++, j--) {
		int temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}
void rotateArray(std::vector<int> &data, int k) {
	int n = data.size();
	reverseArray(data, 0, k - 1);
	reverseArray(data, k, n - 1);
	reverseArray(data, 0, n - 1);
}
// Testing code.
int main11() {
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6 };
	rotateArray(arr, 2);
	printArray(arr);
	return 0;
}
/*
 [ 3 4 5 6 1 2 ]
 */


void waveArray(std::vector<int> &arr) {
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < size - 1; i += 2) {
		swap(arr, i, i + 1);
	}
}
void waveArray2(std::vector<int> &arr) {
	int size = arr.size();
	/* Odd elements are lesser then even elements. */
	for (int i = 1; i < size; i += 2) {
		if ((i - 1) >= 0 && arr[i] > arr[i - 1]) {
			swap(arr, i, i - 1);
		}
		if ((i + 1) < size && arr[i] > arr[i + 1]) {
			swap(arr, i, i + 1);
		}
	}
}

// Testing code.
int main12() {
	std::vector<int> arr = { 8, 1, 2, 3, 4, 5, 6, 4, 2 };
	waveArray(arr);
	printArray(arr);
	;
	std::vector<int> arr2 = { 8, 1, 2, 3, 4, 5, 6, 4, 2 };
	waveArray2(arr2);
	printArray(arr2);
	return 0;
}
/*
 [ 2 1 3 2 4 4 6 5 8 ]
 [ 8 1 3 2 5 4 6 2 4 ]
 */
void indexArray(std::vector<int> &arr, int size) {
	for (int i = 0; i < size; i++) {
		int curr = i;
		int value = -1;

		/* swaps to move elements in proper position. */
		while (arr[curr] != -1 && arr[curr] != curr) {
			int temp = arr[curr];
			arr[curr] = value;
			value = curr = temp;
		}

		/* check if some swaps happened. */
		if (value != -1) {
			arr[curr] = value;
		}
	}
}

void indexArray2(std::vector<int> &arr, int size) {
	int temp, temp2;
	for (int i = 0; i < size; i++) {
		while (arr[i] != -1 && arr[i] != i) {
			/* swap arr[i] and arr[arr[i]] */
			temp = arr[i];
			temp2 = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp2;
		}
	}
}

// Testing code.
int main13() {
	std::vector<int> arr = { 8, -1, 6, 1, 9, 3, 2, 7, 4, -1 };
	int size = arr.size();
	indexArray2(arr, size);
	printArray(arr);
	std::vector<int> arr2 = { 8, -1, 6, 1, 9, 3, 2, 7, 4, -1 };
	size = arr2.size();
	indexArray(arr2, size);
	printArray(arr2);
	return 0;
}
/*
 [ -1 1 2 3 4 -1 6 7 8 9 ]
 [ -1 1 2 3 4 -1 6 7 8 9 ]
 */

void sort1toN(std::vector<int> &arr, int size) {
	int curr, value, next;
	for (int i = 0; i < size; i++) {
		curr = i;
		value = -1;
		/* swaps to move elements in proper position. */
		while (curr >= 0 && curr < size && arr[curr] != curr + 1) {
			next = arr[curr];
			arr[curr] = value;
			value = next;
			curr = next - 1;
		}
	}
}

void sort1toN2(std::vector<int> &arr, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		while (arr[i] != i + 1 && arr[i] > 1) {
			temp = arr[i];
			arr[i] = arr[temp - 1];
			arr[temp - 1] = temp;
		}
	}
}

// Testing code.
int main14() {
	std::vector<int> arr = { 8, 5, 6, 1, 9, 3, 2, 7, 4, 10 };
	int size = arr.size();
	sort1toN2(arr, size);
	printArray(arr);
	std::vector<int> arr2 = { 8, 5, 6, 1, 9, 3, 2, 7, 4, 10 };
	size = arr2.size();
	sort1toN(arr2, size);
	printArray(arr2);
	return 0;
}
/*
 [ 1 2 3 4 5 6 7 8 9 10 ]
 [ 1 2 3 4 5 6 7 8 9 10 ]
 */

void maxMinArr(std::vector<int> &arr, int size) {
	std::vector<int> aux = arr;
	int start = 0;
	int stop = size - 1;
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			arr[i] = aux[stop];
			stop -= 1;
		} else {
			arr[i] = aux[start];
			start += 1;
		}
	}
}

void reverseArr(std::vector<int> &arr, int start, int stop) {
	while (start < stop) {
		swap(arr, start, stop);
		start += 1;
		stop -= 1;
	}
}

void maxMinArr2(std::vector<int> &arr, int size) {
	for (int i = 0; i < (size - 1); i++) {
		reverseArr(arr, i, size - 1);
	}
}

// Testing code.
int main15() {
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	int size = arr.size();
	maxMinArr(arr, size);
	printArray(arr);
	std::vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	int size2 = arr.size();
	maxMinArr2(arr2, size2);
	printArray(arr2);
	return 0;
}

/*
 [ 7 1 6 2 5 3 4 ]
 [ 7 1 6 2 5 3 4 ]
 */

int maxCircularSum(std::vector<int> &arr, int size) {
	int sumAll = 0;
	int currVal = 0;
	int maxVal;

	for (int i = 0; i < size; i++) {
		sumAll += arr[i];
		currVal += (i * arr[i]);
	}
	maxVal = currVal;
	for (int i = 1; i < size; i++) {
		currVal = (currVal + sumAll) - (size * arr[size - i]);
		if (currVal > maxVal) {
			maxVal = currVal;
		}
	}
	return maxVal;
}

// Testing code.
int main16() {
	std::vector<int> arr = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::cout << "MaxCirculrSum: " << maxCircularSum(arr, arr.size())
			<< std::endl;
	return 0;
}

/*
 MaxCirculrSum: 290
 */


// Testing code.
int main() {
/*	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	main8();
	main9();
	main10();

	main11();
	main12();
	main13();
	main14();
	*/
	main15();
	main16();
	return 0;
}
