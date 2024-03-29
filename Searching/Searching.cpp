#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

bool linearSearchUnsorted(std::vector<int> &data, int value) {
	int size = data.size();
	for (int i = 0; i < size; i++) {
		if (value == data[i]) {
			return true;
		}
	}
	return false;
}

bool linearSearchSorted(std::vector<int> &data, int value) {
	int size = data.size();
	for (int i = 0; i < size; i++) {
		if (value == data[i]) {
			return true;
		} else if (value < data[i]) {
			return false;
		}
	}
	return false;
}

bool binarySearch(std::vector<int> &data, int value) {
	int size = data.size();
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == value) {
			return true;
		} else if (data[mid] < value) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return false;
}

int binarySearch(std::vector<int> &data, int start, int end, int key,
		bool isInc) {
	int mid;
	if (end < start) {
		return -1;
	}
	mid = (start + end) / 2;
	if (key == data[mid]) {
		return mid;
	}
	if (isInc != false && key < data[mid]
			|| isInc == false && key > data[mid]) {
		return binarySearch(data, start, mid - 1, key, isInc);
	} else {
		return binarySearch(data, mid + 1, end, key, isInc);
	}
}

bool binarySearchRecursive(std::vector<int> &data, int low, int high, int value) {
	if (low > high) {
		return false;
	}
	int mid = (low + high) / 2;
	if (data[mid] == value) {
		return true;
	} else if (data[mid] < value) {
		return binarySearchRecursive(data, mid + 1, high, value);
	} else {
		return binarySearchRecursive(data, low, mid - 1, value);
	}
}

bool binarySearchRec(std::vector<int> &arr, int value) {
	int size = arr.size();
	int low = 0;
	int high = size - 1;
	return binarySearchRecursive(arr, low, high, value);
}

bool fibonacciSearch(std::vector<int> &arr, int value) {
	int size = arr.size();
	/* Initialize fibonacci numbers */
	int fibNMn2 = 0;
	int fibNMn1 = 1;
	int fibN = fibNMn2 + fibNMn1;

	while (fibN < size) {
		fibNMn2 = fibNMn1;
		fibNMn1 = fibN;
		fibN = fibNMn2 + fibNMn1;
	}

	int low = 0;
	while (fibN > 1) { // fibonacci series start with 0, 1, 1, 2
		int i = std::min(low + fibNMn2, size - 1);
		if (arr[i] == value) {
			return true;
		} else if (arr[i] < value) {
			fibN = fibNMn1;
			fibNMn1 = fibNMn2;
			fibNMn2 = fibN - fibNMn1;
			low = i;
		} else { // for feb2 <= 1, these will be invalid.
			fibN = fibNMn2;
			fibNMn1 = fibNMn1 - fibNMn2;
			fibNMn2 = fibN - fibNMn1;
		}
	}
	if (arr[low + fibNMn2] == value) // above loop does not check when fibNMn2 = 0
			{
		return true;
	}
	return false;
}

// Testing code.
int main1() {
	std::vector<int> first = { 1, 3, 5, 7, 9, 25, 30 };
	std::cout << linearSearchUnsorted(first, 8) << std::endl;
	std::cout << linearSearchUnsorted(first, 25) << std::endl;

	std::cout << linearSearchSorted(first, 8) << std::endl;
	std::cout << linearSearchSorted(first, 25) << std::endl;

	std::cout << binarySearch(first, 8) << std::endl;
	std::cout << binarySearch(first, 25) << std::endl;

	std::cout << binarySearchRec(first, 8) << std::endl;
	std::cout << binarySearchRec(first, 25) << std::endl;

	std::cout << fibonacciSearch(first, 8) << std::endl;
	std::cout << fibonacciSearch(first, 25) << std::endl;
	return 0;
}

/*
 0
 1
 0
 1
 0
 1
 0
 1
 0
 1

 */

int sumArray(std::vector<int> &data) {
	int size = data.size();
	int total = 0;
	for (int index = 0; index < size; index++) {
		total += data[index];
	}
	return total;
}

// Testing code.
int main2() {
	std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << "Sum of all the values in array: " << sumArray(data)
			<< std::endl;
	return 0;
}

/*
 Sum of all the values in array: 45
 */

int firstRepeated(std::vector<int> &data) {
	int size = data.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] == data[j])
				return data[i];
		}
	}
	return 0;
}

int firstRepeated2(std::vector<int> &arr) {
	int size = arr.size();
	std::map<int, int> hm;

	for (int i = 0; i < size; i++) {
		if (hm.find(arr[i]) != hm.end()) {
			hm[arr[i]] = 2;
		} else {
			hm[arr[i]] = 1;
		}
	}

	for (int i = 0; i < size; i++) {
		if (hm[arr[i]] == 2) {
			return arr[i];
		}
	}
	return 0;
}

// Testing code.
int main3() {
	std::vector<int> first = { 1, 3, 5, 3, 9, 1, 30 };
	std::cout << firstRepeated(first) << std::endl;
	std::cout << firstRepeated2(first) << std::endl;
	return 0;
}

/*
 1
 1
 */

void printRepeating(std::vector<int> &data) {
	int size = data.size();
	std::cout << "Repeating elements are : ";
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] == data[j])
				std::cout << data[i] << " ";
		}
	}
}

void printRepeating2(std::vector<int> &data) {
	int size = data.size();
	sort(data.begin(), data.end());
	std::cout << "Repeating elements are : ";

	for (int i = 1; i < size; i++) {
		if (data[i] == data[i - 1])
			std::cout << data[i] << " ";
	}
}

void printRepeating3(std::vector<int> &data) {
	std::set<int> hs;
	int size = data.size();
	std::cout << "Repeating elements are : ";
	for (int i = 0; i < size; i++) {
		if (std::find(hs.begin(), hs.end(), data[i]) != hs.end())
			std::cout << data[i] << " ";
		else
			hs.insert(data[i]);
	}
}

void printRepeating4(std::vector<int> &data, int range) {
	int size = data.size();
	std::vector<int> count(range, 0);

	std::cout << " Repeating elements are : ";
	for (int i = 0; i < size; i++) {
		if (count[data[i]] == 1)
			std::cout << data[i] << " ";
		else
			count[data[i]]++;
	}
}

// Testing code.
int main4() {
	std::vector<int> first = { 1, 3, 5, 3, 9, 1, 30 };
	printRepeating(first);
	std::cout << std::endl;
	printRepeating2(first);
	std::cout << std::endl;
	printRepeating3(first);
	std::cout << std::endl;
	printRepeating4(first, 50);
	return 0;
}

/*
 Repeating elements are :  1 3
 Repeating elements are :  1 3
 Repeating elements are :  1 3
 Repeating elements are :  1 3
 */

void removeDuplicates(std::vector<int> &data) {
	int size = data.size();
	if (size == 0)
		return;

	sort(data.begin(), data.end());
	int j = 0;
	for (int i = 1; i < size; i++) {
		if (data[i] != data[j]) {
			j++;
			data[j] = data[i];
		}
	}
	data.erase(data.begin() + j + 1, data.end());
}

void removeDuplicates2(std::vector<int> &arr, int size) {
	std::map<int, int> hm;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (hm.find(arr[i]) == hm.end()) {
			arr[j] = arr[i];
			j++;
			hm[arr[i]] = 1;
		}
	}

	arr.erase(arr.begin() + j + 1, arr.end());
}

// Testing code.
int main5() {
	std::vector<int> arr = { 1, 3, 5, 3, 9, 1, 30 };
	removeDuplicates(arr);
	for (auto i = arr.begin(); i != arr.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::vector<int> arr2 = { 1, 3, 5, 3, 9, 1, 30 };
	removeDuplicates(arr2);
	for (auto i = arr2.begin(); i != arr2.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	return 0;
}

/*
 1 3 5 9 30
 1 3 5 9 30
 */

int findMissingNumber(std::vector<int> &data) {
	int size = data.size();
	int found;
	for (int i = 1; i <= size; i++) {
		found = 0;
		for (int j = 0; j < size; j++) {
			if (data[j] == i) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			return i;
		}
	}
	return std::numeric_limits<int>::max();
}

int findMissingNumber2(std::vector<int> &arr) {
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < size; i++) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	return std::numeric_limits<int>::max();
}

int findMissingNumber3(std::vector<int> &arr) {
	int size = arr.size();
	std::map<int, int> hm;
	for (int i = 0; i < size; i++)
		hm[arr[i]] = 1;

	for (int i = 1; i <= size; i++) {
		if (hm.find(i) == hm.end()) {
			return i;
		}
	}
	return std::numeric_limits<int>::max();
}

int findMissingNumber4(std::vector<int> &arr) {
	int size = arr.size();
	std::vector<int> count(size + 1, -1);
	for (int i = 0; i < size; i++) {
		count[arr[i] - 1] = 1;
	}

	for (int i = 0; i <= size; i++) {
		if (count[i] == -1) {
			return i + 1;
		}
	}

	return std::numeric_limits<int>::max();
}

int findMissingNumber5(std::vector<int> &arr) {
	int size = arr.size();
	int sum = 0;
	// Element value range is from 1 to size+1.
	for (int i = 1; i < (size + 2); i++) {
		sum += i;
	}
	for (int i = 0; i < size; i++) {
		sum -= arr[i];
	}
	return sum;
}

int findMissingNumber6(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		// len(arr)+1 value should be ignored.
		if (arr[i] != size + 1 && arr[i] != size * 3 + 1) {
			// 1 should not become (len(arr)+1) so multiplied by 2
			arr[(arr[i] - 1) % size] += size * 2;
		}
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] < (size * 2)) {
			return i + 1;
		}
	}
	return std::numeric_limits<int>::max();
}

int findMissingNumber7(std::vector<int> &data) {
	int size = data.size();
	int xorSum = 0;
	// get the XOR of all the numbers from 1 to range
	for (int i = 1; i <= size; i++) {
		xorSum ^= i;
	}
	// loop through the array and get the XOR of elements
	for (int i = 0; i < size; i++) {
		xorSum ^= data[i];
	}
	return xorSum;
}

int findMissingNumber8(std::vector<int> &arr) {
	std::set<int> st;
	int size = arr.size();
	int i = 0;
	while (i < size) {
		st.insert(arr[i]);
		i += 1;
	}
	i = 1;
	while (i <= size) {
		if (st.count(i) == 0)
			return i;
		i += 1;
	}
	std::cout << "NoNumberMissing" << std::endl;
	return std::numeric_limits<int>::max();
}

// Testing code.
int main6() {
	std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9 };
	std::cout << "MissingNumber : " << findMissingNumber(first) << std::endl;
	std::cout << "MissingNumber : " << findMissingNumber2(first) << std::endl;
	std::cout << "MissingNumber : " << findMissingNumber3(first) << std::endl; //
	std::cout << "MissingNumber : " << findMissingNumber4(first) << std::endl;
	std::cout << "MissingNumber : " << findMissingNumber5(first) << std::endl;
	//std::cout << "MissingNumber : " << findMissingNumber6(first) << std::endl;
	//std::cout << "MissingNumber : " << findMissingNumber7(first) << std::endl;//
	std::cout << "MissingNumber : " << findMissingNumber8(first) << std::endl; //
	return 0;
}

/*
 MissingNumber : 6
 MissingNumber : 6
 MissingNumber : 6
 MissingNumber : 6
 MissingNumber : 6
 MissingNumber : 6
 */

void swap(std::vector<int> &data, int first, int second) {
	int temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

void missingValues(std::vector<int> &arr) {
	int size = arr.size();
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}

		if (min > arr[i]) {
			min = arr[i];
		}
	}
	bool found;
	for (int i = min + 1; i < max; i++) {
		found = false;
		for (int j = 0; j < size; j++) {
			if (arr[j] == i) {
				found = true;
				break;
			}
		}
		if (!found) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

void missingValues2(std::vector<int> &arr) {
	std::sort(arr.begin(), arr.end());
	int size = arr.size();
	int value = arr[0];
	int i = 0;
	while (i < size) {
		if (value == arr[i]) {
			value += 1;
			i += 1;
		} else {
			std::cout << value << std::endl;
			value += 1;
		}
	}
}

void missingValues3(std::vector<int> &arr) {
	std::set<int> st;
	int minVal = 999999;
	int maxVal = -999999;
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		st.insert(arr[i]);
		if (minVal > arr[i])
			minVal = arr[i];
		if (maxVal < arr[i])
			maxVal = arr[i];
	}
	for (int i = minVal; i < maxVal + 1; i++) {
		if (st.find(i) == st.end()) {
			std::cout << i << std::endl;
		}
	}
}

// Testing code.
int main7() {
	std::vector<int> arr = { 1, 9, 2, 8, 3, 7, 4, 6 };
	missingValues(arr);
	missingValues2(arr);
	missingValues3(arr);
	return 0;
}

/*
 5
 5
 5
 */

void oddCount(std::vector<int> &arr) {
	int size = arr.size();
	int xorSum = 0;
	for (int i = 0; i < size; i++) {
		xorSum ^= arr[i];
	}
	std::cout << "Odd values: " << xorSum << std::endl;
}

void oddCount2(std::vector<int> &arr) {
	std::map<int, int> ctr;
	int count = 0;
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		if (ctr.find(arr[i]) != ctr.end())
			ctr[arr[i]] += 1;
		else
			ctr[arr[i]] = 1;
	}
	std::cout << "Odd elements are : ";
	for (int i = 0; i < size; i++) {
		if (ctr.find(arr[i]) != ctr.end() && (ctr[arr[i]] % 2 == 1)) {
			std::cout << arr[i] << " ";
			count++;
		}
	}
	std::cout << std::endl << "Odd elements count is :: " << count << std::endl;
}

void oddCount3(std::vector<int> &arr) {
	int xorSum = 0;
	int first = 0;
	int second = 0;
	int setBit;
	int size = arr.size();
	/*
	 * xor of all elements in arr[] even occurrence will cancel each other. sum will
	 * contain sum of two odd elements.
	 */
	for (int i = 0; i < size; i++)
		xorSum = xorSum ^ arr[i];

	/* Rightmost set bit. */
	setBit = xorSum & ~(xorSum - 1);

	/*
	 * Dividing elements in two group: Elements having setBit bit as 1. Elements
	 * having setBit bit as 0. Even elements cancelled themselves if group and we
	 * get our numbers.
	 */
	for (int i = 0; i < size; i++) {
		if ((arr[i] & setBit) != 0)
			first ^= arr[i];
		else
			second ^= arr[i];
	}
	std::cout << "Odd elements are : " << first << " " << second << std::endl;
}

// Testing code.
int main8() {
	std::vector<int> arr = { 10, 25, 30, 10, 15, 25, 15, };
	oddCount(arr);
	std::vector<int> arr2 = { 10, 25, 30, 10, 15, 25, 15, 40 };
	oddCount2(arr2);
	oddCount3(arr2);
	return 0;
}

/*
 Odd values: 30
 Odd elements are : 30 40
 Odd elements count is :: 2
 Odd elements are : 30 40
 */

void sumDistinct(std::vector<int> &arr) {
	int sum = 0;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < (size - 1); i++) {
		if (arr[i] != arr[i + 1])
			sum += arr[i];
	}
	sum += arr[size - 1];
	std::cout << sum << std::endl;
}

// Testing code.
int main9() {
	std::vector<int> arr = { 1, 2, 3, 1, 1, 4, 5, 6 };
	sumDistinct(arr);
	return 0;
}

/*
 21
 */

void minAbsSumPair(std::vector<int> &arr) {
	int l, r, minSum, sum, minFirst, minSecond;
	int size = arr.size();
	// Array should have at least two elements
	if (size < 2) {
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	// Initialization of values
	minFirst = 0;
	minSecond = 1;
	minSum = std::abs(arr[0] + arr[1]);
	for (l = 0; l < size - 1; l++) {
		for (r = l + 1; r < size; r++) {
			sum = std::abs(arr[l] + arr[r]);
			if (sum < minSum) {
				minSum = sum;
				minFirst = l;
				minSecond = r;
			}
		}
	}
	std::cout << "Minimum sum pair : " << arr[minFirst] << " , "
			<< arr[minSecond] << std::endl;
}

void minAbsSumPair2(std::vector<int> &arr) {
	int l, r, minSum, sum, minFirst, minSecond;
	int size = arr.size();
	// Array should have at least two elements
	if (size < 2) {
		std::cout << "Invalid Input" << std::endl;
		return;
	}
	std::sort(arr.begin(), arr.end());

	// Initialization of values
	minFirst = 0;
	minSecond = size - 1;
	minSum = std::abs(arr[minFirst] + arr[minSecond]);
	for (l = 0, r = size - 1; l < r;) {
		sum = (arr[l] + arr[r]);
		if (std::abs(sum) < minSum) {
			minSum = std::abs(sum);    /// just corrected......hemant
			minFirst = l;
			minSecond = r;
		}
		if (sum < 0) {
			l++;
		} else if (sum > 0) {
			r--;
		} else {
			break;
		}
	}
	std::cout << "Minimum sum pair : " << arr[minFirst] << " , "
			<< arr[minSecond] << std::endl;
}

// Testing code.
int main10() {
	std::vector<int> first = { 1, 5, -10, 3, 2, -6, 8, 9, 6 };
	minAbsSumPair2(first);
	minAbsSumPair(first);
	return 0;
}

/*
 Minimum sum pair : -6 , 6
 Minimum sum pair : -6 , 6
 */

bool findPair(std::vector<int> &arr, int value) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((arr[i] + arr[j]) == value) {
				std::cout << "The pair is : " << arr[i] << ", " << arr[j]
						<< std::endl;
				return true;
			}
		}
	}
	return false;
}

bool findPair2(std::vector<int> &arr, int value) {
	int size = arr.size();
	int first = 0, second = size - 1;
	int curr;
	std::sort(arr.begin(), arr.end());
	while (first < second) {
		curr = arr[first] + arr[second];
		if (curr == value) {
			std::cout << "The pair is : " << arr[first] << ", " << arr[second]
					<< std::endl;
			return true;
		} else if (curr < value) {
			first++;
		} else {
			second--;
		}
	}
	return false;
}

bool findPair3(std::vector<int> &arr, int value) {
	std::set<int> hs;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		if (hs.find(value - arr[i]) != hs.end()) {
			std::cout << "The pair is : " << arr[i] << ", " << (value - arr[i])
					<< std::endl;
			return true;
		}
		hs.insert(arr[i]);
	}
	return false;
}
bool findPair4(std::vector<int> &arr, int range, int value) {
	int size = arr.size();
	std::vector<int> count(range + 1, 0);
	for (int i = 0; i < size; i++) {
		if (count[value - arr[i]] > 0) {
			std::cout << "The pair is : " << arr[i] << ", " << (value - arr[i])
					<< std::endl;
			return true;
		}
		count[arr[i]] += 1;
	}
	return false;
}
// Testing code.
int main11() {
	std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
	findPair(first, 8);
	findPair2(first, 8);
	findPair3(first, 8);
	findPair4(first, 9, 8);
	return 0;
}

/*
 The pair is : 1, 7
 The pair is : 1, 7
 The pair is : 5, 3
 The pair is : 5, 3
 */

bool findPairTwoLists(std::vector<int> &arr1, std::vector<int> &arr2,
		int value) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if ((arr1[i] + arr2[j]) == value) {
				std::cout << "The pair is : " << arr1[i] << ", " << arr2[j]
						<< std::endl;
				return true;
			}
		}
	}
	return false;
}

bool findPairTwoLists2(std::vector<int> &arr1, std::vector<int> &arr2,
		int value) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	std::sort(arr2.begin(), arr2.end());
	for (int i = 0; i < size1; i++) {
		if (binarySearch(arr2, value - arr1[i])) {
			std::cout << "The pair is : " << arr1[i] << ", "
					<< (value - arr1[i]) << std::endl;
		}
		return true;
	}
	return false;
}

bool findPairTwoLists3(std::vector<int> &arr1, std::vector<int> &arr2,
		int value) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	int first = 0, second = size2 - 1, curr = 0;
	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	while (first < size1 && second >= 0) {
		curr = arr1[first] + arr2[second];
		if (curr == value) {
			std::cout << "The pair is : " << arr1[first] << ", " << arr2[second]
					<< std::endl;
			return true;
		} else if (curr < value) {
			first++;
		} else {
			second--;
		}
	}
	return false;
}

bool findPairTwoLists4(std::vector<int> &arr1, std::vector<int> &arr2,
		int value) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	std::set<int> hs;
	for (int i = 0; i < size2; i++) {
		hs.insert(arr2[i]);
	}

	for (int i = 0; i < size1; i++) {
		if (hs.find(value - arr1[i]) != hs.end()) {
			std::cout << "The pair is : " << arr1[i] << ", "
					<< (value - arr1[i]) << std::endl;
			return true;
		}
	}
	return false;
}

bool findPairTwoLists5(std::vector<int> &arr1, std::vector<int> &arr2,
		int range, int value) {
	int size1 = arr1.size();
	int size2 = arr2.size();
	std::vector<int> count(range + 1, 0);

	for (int i = 0; i < size2; i++) {
		count[arr2[i]] = 1;
	}

	for (int i = 0; i < size1; i++) {
		if (count[value - arr1[i]] != 0) {
			std::cout << "The pair is : " << arr1[i] << ", "
					<< (value - arr1[i]) << std::endl;
			return true;
		}
	}
	return false;
}

void main12() {
	std::vector<int> first = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
	std::vector<int> second = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
	findPairTwoLists(first, second, 8);
	findPairTwoLists2(first, second, 8);
	findPairTwoLists3(first, second, 8);
	findPairTwoLists4(first, second, 8);
	findPairTwoLists5(first, second, 9, 8);
}

/*
 The pair is : 1, 7
 The pair is : 1, 7
 The pair is : 1, 7
 The pair is : 1, 7
 The pair is : 1, 7
 */

bool findDifference(std::vector<int> &arr, int value) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (std::abs(arr[i] - arr[j]) == value) {
				std::cout << "The pair is:: " << arr[i] << " & " << arr[j]
						<< std::endl;
				return true;
			}
		}
	}
	return false;
}

bool findDifference2(std::vector<int> &arr, int value) {
	int first = 0;
	int second = 0;
	int diff;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	while (first < size && second < size) {
		diff = std::abs(arr[first] - arr[second]);
		if (diff == value) {
			std::cout << "The pair is:: " << arr[first] << " & " << arr[second]
					<< std::endl;
			return true;
		} else if (diff > value)
			first += 1;
		else
			second += 1;
	}
	return false;
}

void main13() {
	std::vector<int> second = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
	findDifference(second, 6);
	findDifference2(second, 6);
}

/*
 The pair is:: 1 & 7
 The pair is:: 1 & 7
 */

int findMinDiff(std::vector<int> &arr) {
	int size = arr.size();
	int diff = std::numeric_limits<int>::max();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int value = std::abs(arr[i] - arr[j]);
			if (diff > value) {
				diff = value;
			}
		}
	}
	return diff;
}
int findMinDiff2(std::vector<int> &arr) {
	std::sort(arr.begin(), arr.end());
	int diff = std::numeric_limits<int>::max();
	int size = arr.size();

	for (int i = 0; i < (size - 1); i++) {
		if ((arr[i + 1] - arr[i]) < diff)
			diff = arr[i + 1] - arr[i];
	}
	return diff;
}
void main14() {
	std::vector<int> second = { 1, 6, 4, 19, 17, 20 };
	std::cout << "findMinDiff : " << findMinDiff(second) << std::endl;
	std::cout << "findMinDiff : " << findMinDiff2(second) << std::endl;
}

/*
 findMinDiff : 1
 findMinDiff : 1
 */

int minDiffPair(std::vector<int> &arr1, std::vector<int> &arr2) {
	int diff = std::numeric_limits<int>::max();
	int first = 0;
	int second = 0;
	int size1 = arr1.size();
	int size2 = arr2.size();
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			int value = std::abs(arr1[i] - arr2[j]);
			if (diff > value) {
				diff = value;
				first = arr1[i];
				second = arr2[j];
			}
		}
	}
	std::cout << "The pair is :: " << first << " & " << second << std::endl;
	std::cout << "Minimum difference is :: " << diff << std::endl;
	return diff;
}

int minDiffPair2(std::vector<int> &arr1, std::vector<int> &arr2) {
	int minDiff = 9999999;
	int size1 = arr1.size();
	int size2 = arr2.size();
	int first = 0;
	int second = 0;
	int out1 = 0, out2 = 0, diff;
	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	while (first < size1 && second < size2) {
		diff = std::abs(arr1[first] - arr2[second]);
		if (minDiff > diff) {
			minDiff = diff;
			out1 = arr1[first];
			out2 = arr2[second];
		}
		if (arr1[first] < arr2[second])
			first += 1;
		else
			second += 1;
	}
	std::cout << "The pair is :: " << out1 << " & " << out2 << std::endl;
	std::cout << "Minimum difference is :: " << minDiff << std::endl;
	return minDiff;
}

// Testing code.
int main15() {
	std::vector<int> second = { 1, 5, 4, 3, 2, 7, 8, 9, 6 };
	std::vector<int> third = { 6, 4, 19, 17, 20 };
	minDiffPair(second, third);
	minDiffPair2(second, third);
	return 0;
}

/*
 The pair is :: 4 & 4
 Minimum difference is :: 0
 The pair is :: 4 & 4
 Minimum difference is :: 0
 */

void closestPair(std::vector<int> &arr, int value) {
	int diff = 999999;
	int first = -1;
	int second = -1;
	int curr;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			curr = std::abs(value - (arr[i] + arr[j]));
			if (curr < diff) {
				diff = curr;
				first = arr[i];
				second = arr[j];
			}
		}
	}
	std::cout << "closest pair is :: " << first << ", " << second << std::endl;
}

void closestPair2(std::vector<int> &arr, int value) {
	int first = 0, second = 0;
	int start = 0;
	int size = arr.size();
	int stop = size - 1;
	int diff, curr;
	std::sort(arr.begin(), arr.end());
	diff = 9999999;
	while (start < stop) {
		curr = (value - (arr[start] + arr[stop]));
		if (std::abs(curr) < diff) {
			diff = std::abs(curr);
			first = arr[start];
			second = arr[stop];
		}
		if (curr == 0) {
			break;
		} else if (curr > 0) {
			start += 1;
		} else {
			stop -= 1;
		}
	}
	std::cout << "closest pair is :: " << first << ", " << second << std::endl;
}

// Testing code.
int main16() {
	std::vector<int> first = { 10, 20, 3, 4, 50, 80 };
	closestPair(first, 47);
	closestPair2(first, 47);
	return 0;
}

/*
 closest pair is :: 3, 50
 closest pair is :: 3, 50
 */

bool sumPairRestArray(std::vector<int> &arr) {
	int total, low, high, curr, value;
	std::sort(arr.begin(), arr.end());
	total = 0;
	int size = arr.size();
	for (int i = 0; i < size; i++)
		total += arr[i];
	value = total / 2;
	low = 0;
	high = size - 1;
	while (low < high) {
		curr = arr[low] + arr[high];
		if (curr == value) {
			std::cout << "Pair is :: " << arr[low] << ", " << arr[high]
					<< std::endl;
			return true;
		} else if (curr < value)
			low += 1;
		else
			high -= 1;
	}
	return false;
}

// Testing code.
int main17() {
	std::vector<int> first = { 1, 2, 4, 3, 7, 3 };
	sumPairRestArray(first);
	return 0;
}

/*
 Pair is :: 3, 7
 */

void zeroSumTriplets(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < (size - 2); i++) {
		for (int j = i + 1; j < (size - 1); j++) {
			for (int k = j + 1; k < size; k++) {
				if (arr[i] + arr[j] + arr[k] == 0)
					std::cout << "Triplet :: " << arr[i] << " " << arr[j] << " "
							<< arr[k] << " " << std::endl;
			}
		}
	}
}

void zeroSumTriplets2(std::vector<int> &arr) {
	int start, stop;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < (size - 2); i++) {
		start = i + 1;
		stop = size - 1;

		while (start < stop) {
			if (arr[i] + arr[start] + arr[stop] == 0) {
				std::cout << "Triplet :: " << arr[i] << " " << arr[start] << " "
						<< arr[stop] << " " << std::endl;
				start += 1;
				stop -= 1;
			} else if (arr[i] + arr[start] + arr[stop] > 0)
				stop -= 1;
			else
				start += 1;
		}
	}
}

// Testing code.
int main18() {
	std::vector<int> first = { 1, 2, -4, 3, 7, -3 };
	zeroSumTriplets(first);
	zeroSumTriplets2(first);
	return 0;
}

/*
 Triplet :: 1 2 -3
 Triplet :: 1 -4 3
 Triplet :: -4 7 -3
 Triplet :: -4 -3 7
 Triplet :: -4 1 3
 Triplet :: -3 1 2
 */

void findTriplet(std::vector<int> &arr, int value) {
	int size = arr.size();
	for (int i = 0; i < (size - 2); i++)
		for (int j = i + 1; j < (size - 1); j++)
			for (int k = j + 1; k < size; k++) {
				if ((arr[i] + arr[j] + arr[k]) == value)
					std::cout << "Triplet :: " << arr[i] << " " << arr[j] << " "
							<< arr[k] << std::endl;
			}
}

void findTriplet2(std::vector<int> &arr, int value) {
	int start, stop;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < size - 2; i++) {
		start = i + 1;
		stop = size - 1;
		while (start < stop) {
			if (arr[i] + arr[start] + arr[stop] == value) {
				std::cout << "Triplet :: " << arr[i] << " " << arr[start] << " "
						<< arr[stop] << std::endl;
				start += 1;
				stop -= 1;
			} else if (arr[i] + arr[start] + arr[stop] > value)
				stop -= 1;
			else
				start += 1;
		}
	}
}

// Testing code.
int main19() {
	std::vector<int> first = { 1, 2, -4, 3, 7, -3 };
	findTriplet(first, 6);
	findTriplet2(first, 6);
	return 0;
}

/*
 Triplet :: 1 2 3
 Triplet :: 2 7 -3
 Triplet :: -4 3 7
 Triplet :: -4 3 7
 Triplet :: -3 2 7
 Triplet :: 1 2 3
 */

void abcTriplet(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (k != i && k != j && arr[i] + arr[j] == arr[k]) {
					std::cout << "abcTriplet:: " << arr[i] << " " << arr[j]
							<< " " << arr[k] << std::endl;
				}
			}
		}
	}
}
void abcTriplet2(std::vector<int> &arr) {
	int start, stop;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < (size - 1); i++) {
		start = 0;
		stop = size - 1;
		while (start < stop) {
			if (arr[i] == arr[start] + arr[stop]) {
				std::cout << "abcTriplet :: " << arr[i] << " " << arr[start]
						<< " " << arr[stop] << std::endl;
				start += 1;
				stop -= 1;
			} else if (arr[i] < arr[start] + arr[stop])
				stop -= 1;
			else
				start += 1;
		}
	}
}

// Testing code.
int main20() {
	std::vector<int> first = { 1, 2, -4, 3, 7, -3 };
	abcTriplet(first);
	abcTriplet2(first);
	return 0;
}

/*
 abcTriplet:: 1 2 3
 abcTriplet:: 1 -4 -3
 abcTriplet:: -4 7 3
 abcTriplet :: -3 -4 1
 abcTriplet :: 3 -4 7
 abcTriplet :: 3 1 2
 */

void smallerThenTripletCount(std::vector<int> &arr, int value) {
	int size = arr.size();
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				if (arr[i] + arr[j] + arr[k] < value) {
					count += 1;
				}
			}
		}
	}
	std::cout << "smallerThenTripletCount:: " << count << std::endl;
}

void smallerThenTripletCount2(std::vector<int> &arr, int value) {
	int start, stop;
	int count = 0;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < (size - 2); i++) {
		start = i + 1;
		stop = size - 1;
		while (start < stop) {
			if (arr[i] + arr[start] + arr[stop] >= value)
				stop -= 1;
			else {
				count += stop - start;
				start += 1;
			}
		}
	}
	std::cout << "smallerThenTripletCount:: " << count << std::endl;
}

void main21() {
	std::vector<int> first = { -2, -1, 0, 1 };
	smallerThenTripletCount(first, 2);
	smallerThenTripletCount2(first, 2);
}

/*
 smallerThenTripletCount:: 4
 smallerThenTripletCount:: 4
 */

void APTriplets(std::vector<int> &arr) {
	int i, j, k;
	int size = arr.size();
	for (i = 1; i < size - 1; i++) {
		j = i - 1;
		k = i + 1;
		while (j >= 0 && k < size) {
			if (arr[j] + arr[k] == 2 * arr[i]) {
				std::cout << "AP Triplet ::" << arr[j] << " " << arr[i] << " "
						<< arr[k] << std::endl;
				k += 1;
				j -= 1;
			} else if (arr[j] + arr[k] < 2 * arr[i])
				k += 1;
			else
				j -= 1;
		}
	}
}

// Testing code.
int main22() {
	std::vector<int> first = { 1, 2, 3, 4, 9, 17, 23 };
	APTriplets(first);
	return 0;
}

/*
 Triplet ::1 2 3
 Triplet ::2 3 4
 Triplet ::1 9 17
 */

void GPTriplets(std::vector<int> &arr) {
	int i, j, k;
	int size = arr.size();
	for (i = 1; i < size - 1; i++) {
		j = i - 1;
		k = i + 1;
		while (j >= 0 && k < size) {
			if (arr[j] * arr[k] == arr[i] * arr[i]) {
				std::cout << "GP Triplet:: " << arr[j] << " " << arr[i] << " "
						<< arr[k] << std::endl;
				k += 1;
				j -= 1;
			} else if (arr[j] + arr[k] < 2 * arr[i])
				k += 1;
			else
				j -= 1;
		}
	}
}

// Testing code.
int main23() {
	std::vector<int> first = { 1, 2, 3, 4, 9, 17, 23 };
	GPTriplets(first);
	return 0;
}

/*
 Triplet is :: 1 3 9
 */

int numberOfTriangles(std::vector<int> &arr) {
	int i, j, k, count = 0;
	int size = arr.size();
	for (i = 0; i < (size - 2); i++) {
		for (j = i + 1; j < (size - 1); j++) {
			for (k = j + 1; k < size; k++) {
				if ((arr[i] + arr[j] > arr[k]) && (arr[k] + arr[j] > arr[i])
						&& (arr[i] + arr[k] > arr[j]))
					count += 1;
			}
		}
	}
	return count;
}

int numberOfTriangles2(std::vector<int> &arr) {
	int i, j, k, count = 0;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());

	for (i = 0; i < (size - 2); i++) {
		k = i + 2;
		for (j = i + 1; j < (size - 1); j++) {
			/*
			 * if sum of arr[i] & arr[j] is greater arr[k] then sum of arr[i] & arr[j + 1]
			 * is also greater than arr[k] this improvement make algo O(n2)
			 */
			while (k < size && arr[i] + arr[j] > arr[k])
				k += 1;

			count += k - j - 1;
		}
	}
	return count;
}

// Testing code.
int main24() {
	std::vector<int> first = { 1, 2, 3, 4, 5 };
	std::cout << "numberOfTriangles : " << numberOfTriangles(first)
			<< std::endl;
	std::cout << "numberOfTriangles : " << numberOfTriangles2(first)
			<< std::endl;
	return 0;
}

/*
 numberOfTriangles : 3
 numberOfTriangles : 3
 */

int getMax(std::vector<int> &arr) {
	int max = arr[0], count = 1, maxCount = 1;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		count = 1;
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}
		if (count > maxCount) {
			max = arr[i];
			maxCount = count;
		}
	}
	return max;
}

int getMax2(std::vector<int> &arr) {
	int max = arr[0], maxCount = 1;
	int curr = arr[0], currCount = 1;
	int size = arr.size();
	std::sort(arr.begin(), arr.end());
	for (int i = 1; i < size; i++) {
		if (arr[i] == arr[i - 1]) {
			currCount++;
		} else {
			currCount = 1;
			curr = arr[i];
		}
		if (currCount > maxCount) {
			maxCount = currCount;
			max = curr;
		}
	}
	return max;
}

int getMax3(std::vector<int> &arr, int range) {
	int max = arr[0], maxCount = 1;
	int size = arr.size();
	std::vector<int> count(range, 0);
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
		if (count[arr[i]] > maxCount) {
			maxCount = count[arr[i]];
			max = arr[i];
		}
	}
	return max;
}

// Testing code.
int main25() {
	std::vector<int> first = { 1, 30, 5, 13, 9, 31, 5 };
	std::cout << getMax(first) << std::endl;
	std::cout << getMax2(first) << std::endl;
	std::cout << getMax3(first, 50) << std::endl;
	return 0;
}

/*
 5
 5
 5
 */

bool isMajority(std::vector<int> &arr) {
	int size = arr.size();
	int count = 0;
	int mid = arr[size / 2];
	for (int i = 0; i < size; i++) {
		if (arr[i] == mid) {
			count += 1;
		}
	}

	if (count > size / 2) {
		return true;
	}
	return false;
}

/* Using binary search method. */
int firstIndex(std::vector<int> &arr, int low, int high, int value) {
	int mid = 0;
	if (high >= low)
		mid = (low + high) / 2;

	/*
	 * Find first occurrence of value, either it should be the first element of the
	 * array or the value before it is smaller than it.
	 */
	if ((mid == 0 || arr[mid - 1] < value) && (arr[mid] == value))
		return mid;
	else if (arr[mid] < value)
		return firstIndex(arr, mid + 1, high, value);
	else
		return firstIndex(arr, low, mid - 1, value);
}

bool isMajority2(std::vector<int> &arr) {
	int size = arr.size();
	int majority = arr[size / 2];
	int i = firstIndex(arr, 0, size - 1, majority);

	/*
	 * we are using majority element form array so we will get some valid index
	 * always.
	 */
	if (((i + size / 2) <= (size - 1)) && arr[i + size / 2] == majority)
		return true;
	else
		return false;
}

// Testing code.
int main30() {
	std::vector<int> first = { 3, 3, 3, 3, 4, 5, 10 };
	std::cout << isMajority(first) << std::endl;
	std::cout << isMajority2(first) << std::endl;
	return 0;
}

/*
 1
 1
 */



int getMajority(std::vector<int> &data) {
	int size = data.size();
	int max = 0, count = 0, maxCount = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] == data[j]) {
				count++;
			}
		}
		if (count > maxCount) {
			max = data[i];
			maxCount = count;
		}
	}
	if (maxCount > size / 2)
		return max;
	else
		throw("MajorityDoesNotExist");
}

int getMajority2(std::vector<int> &data) {
	int size = data.size();
	int majIndex = size / 2, count = 1;
	int candidate;
	sort(data.begin(), data.end());
	candidate = data[majIndex];
	count = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] == candidate)
			count++;
	}

	if (count > size / 2)
		return data[majIndex];
	else
		throw("MajorityDoesNotExist");
}

int getMajority3(std::vector<int> &data) {
	int majIndex = 0, count = 1;
	int candidate;
	int size = data.size();

	for (int i = 1; i < size; i++) {
		if (data[majIndex] == data[i])
			count++;
		else
			count--;

		if (count == 0) {
			majIndex = i;
			count = 1;
		}
	}
	candidate = data[majIndex];
	count = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] == candidate) {
			count++;
		}
	}
	if (count > size / 2)
		return data[majIndex];
	else
		throw("MajorityDoesNotExist");
}

// Testing code.
int main26() {
	std::vector<int> first = { 1, 5, 5, 13, 5, 31, 5 };
	std::cout << getMajority(first) << std::endl;
	std::cout << getMajority2(first) << std::endl;
	std::cout << getMajority3(first) << std::endl;
	return 0;
}

/*
 5
 5
 5
 */

int getMedian(std::vector<int> &data) {
	int size = data.size();
	sort(data.begin(), data.end());
	return data[size / 2];
}

void quickSelectUtil(std::vector<int> &arr, int lower, int upper, int k) {
	if (upper <= lower)
		return;

	int pivot = arr[lower];
	int start = lower;
	int stop = upper;

	while (lower < upper) {
		while (arr[lower] <= pivot) {
			lower++;
		}
		while (arr[upper] > pivot) {
			upper--;
		}
		if (lower < upper) {
			swap(arr, upper, lower);
		}
	}

	swap(arr, upper, start); // upper is the pivot position
	if (k < upper)
		quickSelectUtil(arr, start, upper - 1, k); // pivot -1 is the upper for left sub array.
	if (k > upper)
		quickSelectUtil(arr, upper + 1, stop, k); // pivot + 1 is the lower for right sub array.
}

int getMedian2(std::vector<int> &arr) {
	int size = arr.size();
	quickSelectUtil(arr, 0, size - 1, size / 2);
	return arr[size / 2];
}

void main27() {
	std::vector<int> first = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
	std::cout << getMedian(first) << std::endl;
	std::cout << getMedian2(first) << std::endl;
}

/*
 6
 6
 */

int searchBitonicArrayMax(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size - 2; i++) {
		if (arr[i] > arr[i + 1]) {
			return arr[i];
		}
	}
	std::cout << "error not a bitonic array" << std::endl;
	return 0;
}

int searchBitonicArrayMax2(std::vector<int> &arr) {
	int size = arr.size();
	int start = 0, end = size - 1;
	int mid = (start + end) / 2;
	int maximaFound = 0;
	if (size < 3) {
		std::cout << "error" << std::endl;
		return 0;
	}
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) // maxima
				{
			maximaFound = 1;
			break;
		} else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) // increasing
				{
			start = mid + 1;
		} else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) // decreasing
				{
			end = mid - 1;
		} else {
			break;
		}
	}
	if (maximaFound == 0) {
		std::cout << "error" << std::endl;
		return 0;
	}
	return arr[mid];
}

int findBitonicArrayMaxIndex(std::vector<int> &arr) {
	int size = arr.size();
	int start = 0, end = size - 1, mid;
	if (size < 3) {
		std::cout << "error" << std::endl;
		return -1;
	}
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) // maxima
			return mid;
		else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) // increasing
			start = mid + 1;
		else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) // increasing
			end = mid - 1;
		else
			break;
	}
	std::cout << "error" << std::endl;
	return -1;
}

int searchBitonicArray(std::vector<int> &arr, int key) {
	int size = arr.size();
	int max = findBitonicArrayMaxIndex(arr);
	int k = binarySearch(arr, 0, max, key, true);
	if (k != -1) {
		return k;
	} else {
		return binarySearch(arr, max + 1, size - 1, key, false);
	}
}

void main28() {
	std::vector<int> first = { 1, 5, 10, 13, 20, 30, 8, 7, 6 };
	std::cout << searchBitonicArrayMax(first) << std::endl;
	std::cout << searchBitonicArrayMax2(first) << std::endl;
	std::cout << searchBitonicArray(first, 7) << std::endl;
	std::cout << first[findBitonicArrayMaxIndex(first)] << std::endl;
}

/*
 30
 30
 7
 30
 */

int findKeyCount(std::vector<int> &arr, int key) {
	int count = 0;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			count++;
		}
	}
	return count;
}

int findLastIndex(std::vector<int> &arr, int start, int end, int key) {
	if (end < start) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (key == arr[mid] && (mid == end || arr[mid + 1] != key)) {
		return mid;
	}
	if (key < arr[mid])  // <
			{
		return findLastIndex(arr, start, mid - 1, key);
	} else {
		return findLastIndex(arr, mid + 1, end, key);
	}
}

int findFirstIndex(std::vector<int> &arr, int start, int end, int key) {
	int mid;
	if (end < start) {
		return -1;
	}
	mid = (start + end) / 2;
	if (key == arr[mid] && (mid == start || arr[mid - 1] != key)) {
		return mid;
	}
	if (key <= arr[mid])  // <= is us the number.t in sorted array.
			{
		return findFirstIndex(arr, start, mid - 1, key);
	} else {
		return findFirstIndex(arr, mid + 1, end, key);
	}
}

int findKeyCount2(std::vector<int> &arr, int key) {
	int firstIndex, lastIndex;
	int size = arr.size();
	firstIndex = findFirstIndex(arr, 0, size - 1, key);
	lastIndex = findLastIndex(arr, 0, size - 1, key);
	return (lastIndex - firstIndex + 1);
}

// Testing code.
int main29() {
	std::vector<int> first = { 1, 5, 10, 13, 20, 30, 8, 7, 6 };
	std::cout << findKeyCount(first, 6) << std::endl;
	std::cout << findKeyCount2(first, 6) << std::endl;
	return 0;
}
/*
 1
 1
 */


int maxProfit(std::vector<int> &stocks) {
	int size = stocks.size();
	int maxProfit = 0;
	int buy = 0, sell = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (maxProfit < stocks[j] - stocks[i]) {
				maxProfit = stocks[j] - stocks[i];
				buy = i;
				sell = j;
			}
		}
	}
	std::cout << "Purchase day is " << buy << " at price " << stocks[buy]
			<< std::endl;
	std::cout << "Sell day is " << sell << " at price " << stocks[sell]
			<< std::endl;
	std::cout << "Profit is " << maxProfit << std::endl;
	return maxProfit;
}

int maxProfit2(std::vector<int> &stocks) {
	int size = stocks.size();
	int buy = 0, sell = 0;
	int curMin = 0;
	int currProfit = 0;
	int maxProfit = 0;
	for (int i = 0; i < size; i++) {
		if (stocks[i] < stocks[curMin]) {
			curMin = i;
		}
		currProfit = stocks[i] - stocks[curMin];
		if (currProfit > maxProfit) {
			buy = curMin;
			sell = i;
			maxProfit = currProfit;
		}
	}
	std::cout << "Purchase day is " << buy << " at price " << stocks[buy]
			<< std::endl;
	std::cout << "Sell day is " << sell << " at price " << stocks[sell]
			<< std::endl;
	std::cout << "Profit is " << maxProfit << std::endl;
	return maxProfit;
}

// Testing code.
int main31() {
	std::vector<int> first = { 10, 150, 6, 67, 61, 16, 86, 6, 67, 78, 150, 3,
			28, 143 };
	maxProfit(first);
	maxProfit2(first);
	return 0;
}

/*
 Purchase day is 2 at price 6
 Sell day is 10 at price 150
 Profit is 144

 Purchase day is 2 at price 6
 Sell day is 10 at price 150
 Profit is 144
 */

int findMedian(std::vector<int> arrFirst, std::vector<int> arrSecond) {
	int sizeFirst = arrFirst.size();
	int sizeSecond = arrSecond.size();

	int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) % 2)
			/ 2;  // ceiling
	int i = 0, j = 0;
	int count = 0;
	while (count < medianIndex - 1) {
		if (i < sizeFirst - 1 && arrFirst[i] < arrSecond[j]) {
			i++;
		} else {
			j++;
		}
		count++;
	}
	if (arrFirst[i] < arrSecond[j]) {
		return arrFirst[i];
	} else {
		return arrSecond[j];
	}
}

// Testing code.
int main32() {
	std::vector<int> first = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
	std::vector<int> second = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
	std::cout << findMedian(first, second) << std::endl;
	return 0;
}

/*
 6
 */

int search01(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		if (arr[i] == 1) {
			return i;
		}
	}
	return -1;
}

int binarySearch01Util(std::vector<int> &arr, int start, int end) {
	if (end < start) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (1 == arr[mid] && 0 == arr[mid - 1]) {
		return mid;
	}
	if (0 == arr[mid]) {
		return binarySearch01Util(arr, mid + 1, end);
	} else {
		return binarySearch01Util(arr, start, mid - 1);
	}
}

int binarySearch01(std::vector<int> &arr) {
	int size = arr.size();
	if (size == 1 && arr[0] == 1) {
		return 0;
	}
	return binarySearch01Util(arr, 0, size - 1);
}

// Testing code.
int main33() {
	std::vector<int> first = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };
	std::cout << search01(first) << std::endl;
	std::cout << binarySearch01(first) << std::endl;
	return 0;
}

/*
 8
 8
 */

int rotationMax(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return arr[i];
		}
	}
	return -1;
}

int rotationMaxUtil(std::vector<int> &arr, int start, int end) {
	if (end <= start) {
		return arr[start];
	}
	int mid = (start + end) / 2;
	if (arr[mid] > arr[mid + 1])
		return arr[mid];

	if (arr[start] <= arr[mid]) /* increasing part. */
		return rotationMaxUtil(arr, mid + 1, end);
	else
		return rotationMaxUtil(arr, start, mid - 1);
}

int rotationMax2(std::vector<int> &arr) {
	int size = arr.size();
	return rotationMaxUtil(arr, 0, size - 1);
}

// Testing code.
int main34() {
	std::vector<int> first = { 8, 9, 10, 11, 3, 5, 7 };
	std::cout << "RotationMax is ::" << rotationMax(first) << std::endl;
	std::cout << "RotationMax is ::" << rotationMax2(first) << std::endl;
	return 0;
}

/*
 RotationMax is ::11
 RotationMax is ::11
 */

int findRotationMax(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return i;
		}
	}
	return -1;
}

int findRotationMaxUtil(std::vector<int> &arr, int start, int end) {
	/* single element case. */
	if (end <= start)
		return start;

	int mid = (start + end) / 2;
	if (arr[mid] > arr[mid + 1])
		return mid;

	if (arr[start] <= arr[mid]) /* increasing part. */
		return findRotationMaxUtil(arr, mid + 1, end);
	else
		return findRotationMaxUtil(arr, start, mid - 1);
}

int findRotationMax2(std::vector<int> &arr) {
	int size = arr.size();
	return findRotationMaxUtil(arr, 0, size - 1);
}

// Testing code.
int main35() {
	std::vector<int> first = { 34, 56, 77, 1, 5, 6, 6, 8, 10, 20, 30, 34 };
	std::cout << "findRotationMax is :: " << findRotationMax(first)
			<< std::endl;
	std::cout << "findRotationMax is :: " << findRotationMax2(first)
			<< std::endl;
	return 0;
}

/*
 findRotationMax is :: 2
 findRotationMax is :: 2
 */

int countRotation(std::vector<int> &arr) {
	int size = arr.size();
	int maxIndex = findRotationMaxUtil(arr, 0, size - 1);
	return (maxIndex + 1) % size;
}

// Testing code.
int main36() {
	std::vector<int> first = { 34, 56, 77, 1, 5, 6, 6, 8, 10, 20, 30, 34 };
	std::cout << countRotation(first) << std::endl;
	return 0;
}
/*
 3
 */

int searchRotateArray(std::vector<int> &arr, int key) {
	int size = arr.size();
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

int binarySearchRotateArrayUtil(std::vector<int> &arr, int start, int end,
		int key) {
	if (end < start) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (key == arr[mid]) {
		return mid;
	}
	if (arr[mid] > arr[start]) {
		if (arr[start] <= key && key < arr[mid]) {
			return binarySearchRotateArrayUtil(arr, start, mid - 1, key);
		} else {
			return binarySearchRotateArrayUtil(arr, mid + 1, end, key);
		}
	} else {
		if (arr[mid] < key && key <= arr[end]) {
			return binarySearchRotateArrayUtil(arr, mid + 1, end, key);
		} else {
			return binarySearchRotateArrayUtil(arr, start, mid - 1, key);
		}
	}
}

int binarySearchRotateArray(std::vector<int> &arr, int key) {
	int size = arr.size();
	return binarySearchRotateArrayUtil(arr, 0, size - 1, key);
}

// Testing code.
int main37() {
	std::vector<int> first = { 34, 56, 77, 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13,
			20, 30 };
	std::cout << searchRotateArray(first, 20) << std::endl;
	std::cout << binarySearchRotateArray(first, 20) << std::endl;
	return 0;
}

/*
 15
 15
 */

int minAbsDiffAdjCircular(std::vector<int> &arr) {
	int diff = 9999999;
	int size = arr.size();
	if (size < 2)
		return -1;

	for (int i = 0; i < size; i++)
		diff = std::min(diff, std::abs(arr[i] - arr[(i + 1) % size]));

	return diff;
}

// Testing code.
int main38() {
	std::vector<int> arr = { 5, 29, 18, 51, 11 };
	std::cout << minAbsDiffAdjCircular(arr) << std::endl;
	return 0;
}

/*
 6
 */

void swapch(char arr[], int first, int second) {
	char temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void transformArrayAB1(char arr[], int size) {
	int N = size / 2, i, j;
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			swapch(arr, N - i + 2 * j, N - i + 2 * j + 1);
		}
	}
}

// Testing code.
int main39() {
	char str[] = "aaaabbbb";
	transformArrayAB1(str, 8);
	std::cout << str << std::endl;
	return 0;
}

/*
 abababab
 */

bool checkPermutation(std::string data1, std::string data2) {
	int size1 = data1.size();
	int size2 = data2.size();

	if (size1 != size2)
		return false;

	sort(data1.begin(), data1.end());
	sort(data2.begin(), data2.end());

	for (int i = 0; i < size1; i++) {
		if (data1[i] != data2[i])
			return false;
	}
	return true;
}

bool checkPermutation2(std::string data1, std::string data2) {
	int size1 = data1.size();
	int size2 = data2.size();

	if (size1 != size2)
		return false;

	std::map<char, int> al;

	for (int i = 0; i < size1; i++) {
		al[data1[i]] += 1;
		al[data2[i]] -= 1;
	}

	for (int i = 0; i < size1; i++) {
		if (al[data1[i]] != 0)
			return false;
	}
	return true;
}

bool checkPermutation3(std::string array1, std::string array2) {
	int size1 = array1.size();
	int size2 = array2.size();

	if (size1 != size2) {
		return false;
	}
	std::vector<int> count(256, 0);
	for (int i = 0; i < size1; i++) {
		count[array1[i]]++;
		count[array2[i]]--;
	}

	for (int i = 0; i < size1; i++) {
		if (count[i] != 0) {
			return false;
		}
	}
	return true;
}

// Testing code.
int main40() {
	auto str1 = "aaaabbbb";
	auto str2 = "bbaaaabb";
	std::cout << checkPermutation(str1, str2) << std::endl;
	std::cout << checkPermutation2(str1, str2) << std::endl;
	std::cout << checkPermutation3(str1, str2) << std::endl;
	return 0;
}

/*
 1
 1
 1
 */

bool findElementIn2DArray(std::vector<std::vector<int>> &arr, int r, int c,
		int value) {
	int row = 0;
	int column = c - 1;
	while (row < r && column >= 0) {
		if (arr[row][column] == value) {
			return true;
		} else if (arr[row][column] > value) {
			column--;
		} else {
			row++;
		}
	}
	return false;
}

bool isAP(std::vector<int> &arr) {
	int size = arr.size();
	if (size <= 1)
		return true;
	std::sort(arr.begin(), arr.end());
	int diff = arr[1] - arr[0];
	for (int i = 2; i < size; i++) {
		if (arr[i] - arr[i - 1] != diff)
			return false;
	}
	return true;
}

bool isAP2(std::vector<int> &arr) {
	int first = 9999999;
	int second = 9999999;
	int value;
	int size = arr.size();
	std::set<int> hs;
	for (int i = 0; i < size; i++) {
		if (arr[i] < first) {
			second = first;
			first = arr[i];
		} else if (arr[i] < second)
			second = arr[i];
	}
	int diff = second - first;

	for (int i = 0; i < size; i++) {
		if (hs.find(arr[i]) != hs.end())
			return false;
		hs.insert(arr[i]);
	}
	for (int i = 0; i < size; i++) {
		value = first + i * diff;
		if (hs.find(value) == hs.end())
			return false;
	}
	return true;
}

bool isAP3(std::vector<int> &arr) {
	int first = 9999999;
	int second = 9999999;
	int size = arr.size();
	std::vector<int> count(size, 0);
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] < first) {
			second = first;
			first = arr[i];
		} else if (arr[i] < second)
			second = arr[i];
	}
	int diff = second - first;

	for (int i = 0; i < size; i++) {
		index = (arr[i] - first) / diff;
		if (index > size - 1 || count[index] != 0)
			return false;
		count[index] = 1;
	}

	for (int i = 0; i < size; i++) {
		if (count[i] != 1)
			return false;
	}
	return true;
}

// Testing code.
int main41() {
	std::vector<int> arr = { 3, 6, 9, 12, 15 };
	std::cout << isAP(arr) << std::endl;
	std::cout << isAP2(arr) << std::endl;
	std::cout << isAP3(arr) << std::endl;
	return 0;
}

/*
 1
 1
 1
 */

int findBalancedPoint(std::vector<int> &arr) {
	int first = 0;
	int second = 0;
	int size = arr.size();
	for (int i = 1; i < size; i++)
		second += arr[i];

	for (int i = 0; i < size; i++) {
		if (first == second) {
			std::cout << i << std::endl;
			return i;
		}
		if (i < size - 1)
			first += arr[i];
		second -= arr[i + 1];
	}
	return -1;
}

// Testing code.
int main42() {
	std::vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
	std::cout << findBalancedPoint(arr) << std::endl;
	return 0;
}

/*
 3
 */

int findFloor(std::vector<int> &arr, int value) {
	int size = arr.size();
	int start = 0;
	int stop = size - 1;
	int mid;
	while (start <= stop) {
		mid = (start + stop) / 2;
		/*
		 * search value is equal to arr[mid] value.. search value is
		 * greater than mid index value and less than mid+1 index value.
		 * value is greater than arr[size-1] then floor is arr[size-1]
		 */
		if (arr[mid] == value
				|| (arr[mid] < value
						&& (mid == size - 1 || arr[mid + 1] > value)))
			return mid;
		else if (arr[mid] < value)
			start = mid + 1;
		else
			stop = mid - 1;
	}
	return -1;
}

int findCeil(std::vector<int> &arr, int value) {
	int size = arr.size();
	int start = 0;
	int stop = size - 1;
	int mid;

	while (start <= stop) {
		mid = (start + stop) / 2;
		/*
		 * search value is equal to arr[mid] value.. search value is less
		 * than mid index value and greater than mid-1 index value. value
		 * is less than arr[0] then ceil is arr[0]
		 */
		if (arr[mid] == value
				|| (arr[mid] > value && (mid == 0 || arr[mid - 1] < value)))
			return mid;
		else if (arr[mid] < value)
			start = mid + 1;
		else
			stop = mid - 1;
	}
	return -1;
}

// Testing code.
int main43() {
	std::vector<int> arr = { -7, 1, 2, 3, 6, 8, 10 };
	std::cout << arr[findFloor(arr, 4)] << std::endl;
	std::cout << arr[findCeil(arr, 4)] << std::endl;
	return 0;
}

/*
3
6
 */

int closestNumber(std::vector<int> &arr, int num) {
	int size = arr.size();
	int start = 0;
	int stop = size - 1;
	int output = -1;
	int minDist = 9999;
	int mid;

	while (start <= stop) {
		mid = (start + stop) / 2;
		if (minDist > std::abs(arr[mid] - num)) {
			minDist = std::abs(arr[mid] - num);
			output = arr[mid];
		}
		if (arr[mid] == num)
			break;
		else if (arr[mid] > num)
			stop = mid - 1;
		else
			start = mid + 1;
	}
	return output;
}

// Testing code.
int main44() {
	std::vector<int> arr = { 2, 4, 8, 16 };
	std::cout << "closestNumber : " << closestNumber(arr, 7);
	return 0;
}

/*
 closestNumber : 8
 */

bool duplicateKDistance(std::vector<int> &arr, int k) {
	std::map<int, int> hm;
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		if (hm.find(arr[i]) != hm.end() && i - hm[arr[i]] <= k) {
			std::cout << "Value:" << arr[i] << " Index: " << hm[arr[i]] << " & "
					<< i << std::endl;
			return true;
		} else
			hm[arr[i]] = i;
	}
	return false;
}

// Testing code.
int main45() {
	std::vector<int> arr = { 1, 2, 3, 1, 4, 5 };
	duplicateKDistance(arr, 3);
	return 0;
}

/*
 Value:1 Index: 0 & 3
 */

void frequencyCounts(std::vector<int> &arr, int size) {
	std::map<int, int> hm;
	for (int i = 0; i < size; i++) {
		if (hm.find(arr[i]) != hm.end()) {
			hm[arr[i]] += 1;
		} else {
			hm[arr[i]] = 1;
		}
	}
	for (auto key : hm) {
		std::cout << "(" << key.first << " : " << hm[key.first] << ") ";
	}
	std::cout << std::endl;
}

void frequencyCounts2(std::vector<int> &arr, int size) {
	std::sort(arr.begin(), arr.end());
	int count = 1;
	for (int i = 1; i < size; i++) {
		if (arr[i] == arr[i - 1]) {
			count++;
		} else {
			std::cout << "(" << arr[i - 1] << " : " << count << ") ";
			count = 1;
		}
	}
	std::cout << "(" << arr[size - 1] << " : " << count << ") ";
	std::cout << std::endl;
}

void frequencyCounts3(std::vector<int> &arr, int size) {
	std::vector<int> aux(size + 1);
	for (int i = 0; i < size; i++) {
		aux[arr[i]] += 1;
	}
	for (int i = 0; i < size + 1; i++) {
		if (aux[i] > 0) {
			std::cout << "(" << i << " : " << aux[i] << ") ";
		}
	}
	std::cout << std::endl;
}

void frequencyCounts4(std::vector<int> &arr) {
	int index;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		while (arr[i] > 0) {
			index = arr[i] - 1;
			if (arr[index] > 0) {
				arr[i] = arr[index];
				arr[index] = -1;
			} else {
				arr[index] -= 1;
				arr[i] = 0;
			}
		}
	}
	for (int i = 0; i < size; i++)
		if (arr[i] != 0)
			std::cout << "(" << (i + 1) << " : " << std::abs(arr[i]) << ")"
					<< std::endl;
}

// Testing code.
int main46() {
	std::vector<int> arr = { 1, 2, 2, 2, 1 };
	frequencyCounts(arr, arr.size());
	frequencyCounts2(arr, arr.size());
	frequencyCounts3(arr, arr.size());
	frequencyCounts4(arr);
	return 0;
}

/*
 (1 : 2) (2 : 3)
 (1 : 2) (2 : 3)
 (1 : 2) (2 : 3)
 (1 : 2) (2 : 3)
 */

int kLargestElements(std::vector<int> &arrIn, int k) {
	auto size = arrIn.size();
	std::vector<int> arr(size);
	for (int i = 0; i < size; i++)
		arr[i] = arrIn[i];

	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < size; i++) {
		if (arrIn[i] >= arr[size - k]) {
			std::cout << arrIn[i] << " ";
		}
	}
	std::cout << std::endl;
	return -1;
}

int kLargestElements2(std::vector<int> &arrIn, int k) {
	int size = arrIn.size();
	std::vector<int> arr(size);
	for (int i = 0; i < size; i++)
		arr[i] = arrIn[i];

	quickSelectUtil(arr, 0, size - 1, size - k);
	for (int i = 0; i < size; i++) {
		if (arrIn[i] >= arr[size - k]) {
			std::cout << arrIn[i] << " ";
		}
	}
	std::cout << std::endl;
	return -1;
}

// Testing code.
int main47() {
	std::vector<int> arr = { 10, 50, 30, 60, 15 };
	kLargestElements(arr, 2);
	kLargestElements2(arr, 2);
	return 0;
}

/*
 50 60
 50 60
 */

/* linear search method */
int fixPoint(std::vector<int> &arr) {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		if (arr[i] == i)
			return i;
	} /* fix point not found so return invalid index */
	return -1;
}

/* Binary search method */
int fixPoint2(std::vector<int> &arr) {
	int size = arr.size();
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == mid)
			return mid;
		else if (arr[mid] < mid)
			low = mid + 1;
		else
			high = mid - 1;
	}
	/* fix point not found so return invalid index */
	return -1;
}

// Testing code.
int main48() {
	std::vector<int> arr = { -10, -2, 0, 3, 11, 12, 35, 51, 200 };
	std::cout << fixPoint(arr) << std::endl;
	std::cout << fixPoint2(arr) << std::endl;
	return 0;
}

/*
 3
 3
 */

bool subArraySums(std::vector<int> &arr, int value) {
	int first = 0;
	int second = 0;
	int sum = arr[first];
	int size = arr.size();
	while (second < size && first < size) {
		if (sum == value) {
			std::cout << first << " & " << second << std::endl;
			return true;
		}

		if (sum < value) {
			second += 1;
			if (second < size)
				sum += arr[second];
		} else {
			sum -= arr[first];
			first += 1;
		}
	}
	return false;
}

// Testing code.
int main49() {
	std::vector<int> arr = { 15, 5, 5, 20, 10, 5, 5, 20, 10, 10 };
	std::cout << subArraySums(arr, 20) << std::endl;
	return 0;
}

/*
 0 & 1
 1
 */

int maxConSub(std::vector<int> &arr) {
	int currMax = 0;
	int maximum = 0;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		currMax = std::max(arr[i], currMax + arr[i]);
		if (currMax < 0)
			currMax = 0;
		if (maximum < currMax)
			maximum = currMax;
	}
	std::cout << "maximum : " << maximum << std::endl;
	return maximum;
}

// Testing code.
int main50() {
	std::vector<int> arr = { 1, -2, 3, 4, -4, 6, -4, 8, 2 };
	maxConSub(arr);
	return 0;
}

/*
 maximum : 15
 */

int maxConSubArr(std::vector<int> &A, std::vector<int> &B) {
	int currMax = 0;
	int maximum = 0;
	std::set<int> hs;
	int sizeA = A.size();
	int sizeB = B.size();

	for (int i = 0; i < sizeB; i++)
		hs.insert(B[i]);

	for (int i = 0; i < sizeA; i++) {
		if (hs.find(A[i]) != hs.end())
			currMax = 0;
		else
			currMax = std::max(A[i], currMax + A[i]);
		if (currMax < 0)
			currMax = 0;
		if (maximum < currMax)
			maximum = currMax;
	}
	return maximum;
}

int maxConSubArr2(std::vector<int> &A, std::vector<int> &B) {
	std::sort(B.begin(), B.end());
	int currMax = 0;
	int maximum = 0;
	int sizeA = A.size();
	int sizeB = B.size();

	for (int i = 0; i < sizeA; i++) {
		if (binarySearch(B, A[i]))
			currMax = 0;
		else {
			currMax = std::max(A[i], currMax + A[i]);
			if (currMax < 0)
				currMax = 0;
			if (maximum < currMax)
				maximum = currMax;
		}
	}
	return maximum;
}

// Testing code.
int main51() {
	std::vector<int> arr1 = { 1, 2, 3, 4, 4, 6, 4, 8, 2 };
	std::vector<int> arr2 = { 2, 4, 8, 18, 10 };
	std::cout << maxConSubArr(arr1, arr2) << std::endl;
	std::cout << maxConSubArr2(arr1, arr2) << std::endl;
	return 0;
}

/*
 6
 6
 */

int rainWater(std::vector<int> &arr) {
	int size = arr.size();
	std::vector<int> leftHigh(size, 0);
	std::vector<int> rightHigh(size, 0);

	int max = arr[0];
	leftHigh[0] = arr[0];
	for (int i = 1; i < size; i++) {
		if (max < arr[i])
			max = arr[i];
		leftHigh[i] = max;
	}
	max = arr[size - 1];
	rightHigh[size - 1] = arr[size - 1];
	for (int i = (size - 2); i >= 0; i--) {
		if (max < arr[i])
			max = arr[i];
		rightHigh[i] = max;
	}

	int water = 0;
	for (int i = 0; i < size; i++)
		water += std::min(leftHigh[i], rightHigh[i]) - arr[i];
	std::cout << "Water : " << water << std::endl;
	return water;
}

int rainWater2(std::vector<int> &arr) {
	int water = 0;
	int leftMax = 0, rightMax = 0;
	int left = 0;
	int size = arr.size();
	int right = size - 1;

	while (left <= right) {
		if (arr[left] < arr[right]) {
			if (arr[left] > leftMax)
				leftMax = arr[left];
			else
				water += leftMax - arr[left];
			left += 1;
		} else {
			if (arr[right] > rightMax)
				rightMax = arr[right];
			else
				water += rightMax - arr[right];
			right -= 1;
		}
	}
	std::cout << "Water : " << water << std::endl;
	return water;
}

// Testing code.
int main52() {
	std::vector<int> arr = { 4, 0, 1, 5 };
	rainWater(arr);
	rainWater2(arr);
	return 0;
}

/*
 Water : 7
 Water : 7
 */

int findMedian(std::vector<int> &dataFirst, int sizeFirst,
		std::vector<int> &dataSecond, int sizeSecond) {
	int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) % 2)
			/ 2; // Ceiling function.
	int i = 0, j = 0;
	int count = 0;
	while (count < medianIndex - 1) {
		if (i < sizeFirst - 1 && dataFirst[i] < dataSecond[j]) {
			i++;
		} else {
			j++;
		}
		count++;
	}
	if (dataFirst[i] < dataSecond[j]) {
		return dataFirst[i];
	} else {
		return dataSecond[j];
	}
}

// Testing code.
int main54() {
	std::vector<int> first = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
	std::vector<int> second = { 1, 5, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13, 20, 30 };
	std::cout << findMedian(first, second);
	return 0;
}

/*
 6
 */



int arrayIndexMaxDiff(std::vector<int> &arr, int size) {
	int maxDiff = -1;
	int j;
	for (int i = 0; i < size; i++) {
		j = size - 1;
		while (i < j) {
			if (arr[i] <= arr[j]) {
				maxDiff = std::max(maxDiff, j - i);
				break;
			}
			j -= 1;
		}
	}
	return maxDiff;
}

int arrayIndexMaxDiff2(std::vector<int> &arr, int size) {
	std::vector<int> rightMax(size);
	rightMax[size - 1] = arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
		rightMax[i] = std::max(rightMax[i + 1], arr[i]);

	int maxDiff = -1;
	for (int i = 0, j = 1; i < size && j < size;) {
		if (arr[i] <= rightMax[j]) {
			if (i < j)
				maxDiff = std::max(maxDiff, j - i);
			j = j + 1;
		} else {
			i = i + 1;
		}
	}
	return maxDiff;
}

// Testing code.
int main55() {
	std::vector<int> arr = { 33, 9, 10, 3, 2, 60, 30, 33, 1 };
	std::cout << "ArrayIndexMaxDiff : " << arrayIndexMaxDiff(arr, arr.size())
			<< std::endl;
	std::cout << "ArrayIndexMaxDiff : " << arrayIndexMaxDiff2(arr, arr.size())
			<< std::endl;
	return 0;
}

/*
 ArrayIndexMaxDiff : 7
 ArrayIndexMaxDiff : 7
 */




int maxSubArraySum(std::vector<int> &data) {
	int size = data.size();
	int maxSoFar = 0, maxEndingHere = 0;

	for (int i = 0; i < size; i++) {
		maxEndingHere = maxEndingHere + data[i];
		if (maxEndingHere < 0)
			maxEndingHere = 0;
		if (maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}
	return maxSoFar;
}

// Testing code.
int main56() {
	std::vector<int> data = { 1, -2, 3, 4, -4, 6, -4, 3, 2 };
	std::cout << "Max sub array sum :" << maxSubArraySum(data);
	return 0;
}

/*
 Max sub array sum :10
 */

int maxPathSum(int arr1[], int size1, int arr2[], int size2) {
	int i = 0, j = 0, result = 0, sum1 = 0, sum2 = 0;

	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			sum1 += arr1[i];
			i += 1;
		} else if (arr1[i] > arr2[j]) {
			sum2 += arr2[j];
			j += 1;
		} else {
			result += std::max(sum1, sum2);
			result = result + arr1[i];
			sum1 = 0;
			sum2 = 0;
			i += 1;
			j += 1;
		}
	}
	while (i < size1) {
		sum1 += arr1[i];
		i += 1;
	}

	while (j < size2) {
		sum2 += arr2[j];
		j += 1;
	}

	result += std::max(sum1, sum2);
	return result;
}

// Testing code.
int main57() {
	int arr1[] = { 12, 13, 18, 20, 22, 26, 70 };
	int arr2[] = { 11, 15, 18, 19, 20, 26, 30, 31 };
	std::cout << "Max Path Sum :: " << maxPathSum(arr1, 7, arr2, 8)
			<< std::endl;
	return 0;
}

/*
 Max Path Sum :: 201
 */

int smallestPositiveMissingNumber(std::vector<int> &arr, int size) {
	int found;
	for (int i = 1; i < size + 1; i++) {
		found = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] == i) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			return i;
		}
	}
	return -1;
}

int smallestPositiveMissingNumber2(std::vector<int> &arr, int size) {
	std::map<int, int> hs;
	for (int i = 0; i < size; i++) {
		hs[arr[i]] = 1;
	}
	for (int i = 1; i < size + 1; i++) {
		if (hs.find(i) == hs.end()) {
			return i;
		}
	}
	return -1;
}

int smallestPositiveMissingNumber3(std::vector<int> &arr, int size) {
	std::vector<int> aux(size, -1);

	for (int i = 0; i < size; i++) {
		if (arr[i] > 0 && arr[i] <= size) {
			aux[arr[i] - 1] = arr[i];
		}
	}
	for (int i = 0; i < size; i++) {
		if (aux[i] != i + 1) {
			return i + 1;
		}
	}
	return -1;
}

int smallestPositiveMissingNumber4(std::vector<int> &arr, int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		while (arr[i] != i + 1 && arr[i] > 0 && arr[i] <= size) {
			temp = arr[i];
			arr[i] = arr[temp - 1];
			arr[temp - 1] = temp;
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	return -1;
}

// Testing code.
int main58() {
	std::vector<int> arr = { 8, 5, 6, 1, 9, 11, 2, 7, 4, 10 };
	int size = arr.size();

	std::cout << "Smallest Positive Missing Number : "
			<< smallestPositiveMissingNumber(arr, size) << std::endl;
	std::cout << "Smallest Positive Missing Number : "
			<< smallestPositiveMissingNumber2(arr, size) << std::endl;
	std::cout << "Smallest Positive Missing Number : "
			<< smallestPositiveMissingNumber3(arr, size) << std::endl;
	std::cout << "Smallest Positive Missing Number : "
			<< smallestPositiveMissingNumber4(arr, size) << std::endl;
	return 0;
}

/*
 Smallest Positive Missing Number : 3
 Smallest Positive Missing Number : 3
 Smallest Positive Missing Number : 3
 Smallest Positive Missing Number : 3
 */


// Testing code.
int main() {
	/*
	main1();
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
	main15();
	main16();
	main17();
	main18();
	main19();
	main20();
	main21();
	main22();
	main23();
	main24();
	main25();
	main26();
	main27();
	main28();
	main29();
	main30();
	main31();
	main32();
	main33();
	main34();
	main35();
	main36();
	main37();
	main38();
	main39();
	main40();
	main41();
	main42();
	*/
	main43();
	main44();
	main45();
	main46();
	main47();
	main48();
	main49();
	main50();
	main51();
	main52();
	main54();
	main55();
	main56();
	main57();
	main58();
	return 0;
}
