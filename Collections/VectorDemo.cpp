#include <vector>
#include <iostream>
#include <algorithm>

int main1() {
	std::vector<int> arr(10);
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	for (auto i = arr.begin(); i != arr.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
 0 1 2 3 4 5 6 7 8 9
 */

int main() {
	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);

	std::cout << "Contents of Array : ";
	for (auto i = arr.begin(); i != arr.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	int val = 2;
	auto res = std::find(arr.begin(), arr.end(), val) != arr.end();
	std::cout << "Contents 2 : " << res << std::endl;
	std::cout << "Array Size: " << arr.size() << std::endl;
	std::cout << "Array IsEmpty: " << arr.empty() << std::endl;
	arr.pop_back();
	std::cout << "Array Size: " << arr.size() << std::endl;
	arr.clear();
	std::cout << "Array IsEmpty: " << arr.empty() << std::endl;
	return 0;
}
/*
 Contents of Array : 1 2 3
 Contents 2 : 1
 Array Size: 3
 Array IsEmpty: 0
 Array Size: 2
 Array IsEmpty: 1
 */
