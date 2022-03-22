#include <string>
#include <vector>
#include <iostream>
#include <functional> // for greater<int>
#include <algorithm>
#include <iostream>
#include <map>

void printArray(std::vector<int> &data) {
	int count = data.size();
	std::cout << "[ ";
	for (int i = 0; i < count; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void swap(std::vector<int> &data, int x, int y) {
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
	return;
}

void function2() {
	std::cout << "fun2 line 1" << std::endl;
}

void function1() {
	std::cout << "fun1 line 1" << std::endl;
	function2();
	std::cout << "fun1 line 2" << std::endl;
}

// Testing code.
int main1() {
	std::cout << "main line 1" << std::endl;
	function1();
	std::cout << "main line 2" << std::endl;
	return 0;
}

/*
 main line 1
 fun1 line 1
 fun2 line 1
 fun1 line 2
 main line 2
 */



int factorial(int i) {
	// Termination Condition
	if (i <= 1) {
		return 1;
	}
	// Body, Recursive Expansion
	return i * factorial(i - 1);
}

// Testing code.
int main2() {
	int num = 3;
	std::cout << "Factorial: " << factorial(5) << std::endl;
	return 0;
}

/*
 Factorial: 120
 */

void printInt1(int number) {
	char digit = static_cast<char>(number % 10 + '0');
	number = number / 10;
	if (number != 0) {
		printInt1(number);
	}
	std::cout << digit;
}

void printInt(int number, int const base) {
	std::string conversion = "0123456789ABCDEF";
	char digit = static_cast<char>(number % base);
	number = number / base;
	if (number != 0) {
		printInt(number, base);
	}
	std::cout << conversion[digit];
}

// Testing code.
int main3() {
	printInt(500, 16);
	return 0;
}

/*
 1F4
 */

void towerOfHanoi(int num, char src, char dst, char temp) {
	if (num < 1)
		return;

	towerOfHanoi(num - 1, src, temp, dst);
	std::cout << "Move " << num << " disk  from peg " << src << " to peg "
			<< dst << std::endl;
	towerOfHanoi(num - 1, temp, dst, src);
}

// Testing code.
int main4() {
	int num = 3;
	std::cout << "The sequence of moves involved in the Tower of Hanoi are :"
			<< std::endl;
	towerOfHanoi(num, 'A', 'C', 'B');
	return 0;
}
/*
 The sequence of moves involved in the Tower of Hanoi are :
 Move 1 disk  from peg A to peg C
 Move 2 disk  from peg A to peg B
 Move 1 disk  from peg C to peg B
 Move 3 disk  from peg A to peg C
 Move 1 disk  from peg B to peg A
 Move 2 disk  from peg B to peg C
 Move 1 disk  from peg A to peg C
 */
int gcd(int m, int n) {
	if (n == 0)
		return m;
	if (m == 0)
		return n;
	return (gcd(n, m % n));
}

// Testing code.
int main5() {
	std::cout << "Gcd is:: " << gcd(5, 2) << std::endl;
	return 0;
}

/*
Gcd is:: 1
*/

int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

// Testing code.
int main6() {
	std::cout << fibonacci(10) << std::endl;
	return 0;
}

/*
55
*/

void permutation(std::vector<int> &data, int i, int length) {
	if (length == i) {
		printArray(data);
		return;
	}
	int j = i;
	for (j = i; j < length; j++) {
		swap(data, i, j);
		permutation(data, i + 1, length);
		swap(data, i, j);
	}
	return;
}

// Testing code.
int main7() {
	std::vector<int> data(3);
	for (int i = 0; i < 3; i++) {
		data[i] = i;
	}
	permutation(data, 0, 3);
	return 0;
}
/*
 [ 0 1 2 ]
 [ 0 2 1 ]
 [ 1 0 2 ]
 [ 1 2 0 ]
 [ 2 1 0 ]
 [ 2 0 1 ]
 */

void twoDArrayExample() {
	int data[4][2];
	int count = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			data[i][j] = count++;
		}
	}
	//print2DArray(data);
}

template<typename T, int R, int C>
void print2DArray(T (&data)[R][C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << " " << data[i][j] << std::endl;
		}
	}
}

bool binarySearchRecursive(std::vector<int> &data, int low, int high,
		int value) {
	if (low > high)
		return false;

	int mid = (low + high) / 2;
	if (data[mid] == value) {
		return true;
	} else if (data[mid] < value) {
		return binarySearchRecursive(data, mid + 1, high, value);
	} else {
		return binarySearchRecursive(data, low, mid - 1, value);
	}
}

// Testing code.
int main8() {
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 9 };
	std::cout << binarySearchRecursive(arr, 0, arr.size() - 1, 6) << std::endl;
	std::cout << binarySearchRecursive(arr, 0, arr.size() - 1, 16) << std::endl;
	return 0;
}

/*
 1
 0
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
	main8();
	return 0;
}
