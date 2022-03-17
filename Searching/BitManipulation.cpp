#include <string>
#include <vector>
#include <iostream>

int andEx(int a, int b) {
	return a & b;
}

int orEx(int a, int b) {
	return a | b;
}

int xorEx(int a, int b) {
	return a ^ b;
}

int leftShiftEx(int a) // multiply by 2
		{
	return a << 1;
}

int rightShiftEx(int a) // divide by 2
		{
	return a >> 1;
}

int bitReversalEx(int a) {
	return ~a;
}

int twoComplementEx(int a) {
	return -a;
}

bool kthBitCheck(int a, int k) {
	return (a & 1 << (k - 1)) > 0;
}

int kthBitSet(int a, int k) {
	return (a | 1 << (k - 1));
}

int kthBitReset(int a, int k) {
	return (a & ~(1 << (k - 1)));
}

int kthBitToggle(int a, int k) {
	return (a ^ (1 << (k - 1)));
}

int rightMostBit(int a) {
	return a & -a;
}

int resetRightMostBit(int a) {
	return a & (a - 1);
}

bool isPowerOf2(int a) {
	if ((a & (a - 1)) == 0) {
		return true;
	} else {
		return false;
	}
}

int countBits(int a) {
	int count = 0;
	while (a > 0) {
		count += 1;
		a = a & (a - 1); // reset least significant bit.
	}
	return count;
}

int main() {
	int a = 4;
	int b = 8;
	std::cout << andEx(a, b) << std::endl;
	std::cout << orEx(a, b) << std::endl;
	std::cout << xorEx(a, b) << std::endl;
	std::cout << leftShiftEx(a) << std::endl; // multiply by 2
	std::cout << rightShiftEx(a) << std::endl; // divide by 2
	std::cout << bitReversalEx(a) << std::endl;
	std::cout << twoComplementEx(a) << std::endl;
	std::cout << kthBitCheck(a, 3) << std::endl;
	std::cout << kthBitSet(a, 2) << std::endl;
	std::cout << kthBitReset(a, 3) << std::endl;
	std::cout << kthBitToggle(a, 3) << std::endl;
	std::cout << rightMostBit(a) << std::endl;
	std::cout << resetRightMostBit(a) << std::endl;
	std::cout << isPowerOf2(a) << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << i << " bit count : " << countBits(i) << std::endl;
	}
	return 0;
}

/*
 0
 12
 12
 8
 2
 -5
 -4
 1
 6
 0
 0
 4
 0
 1
 0 bit count : 0
 1 bit count : 1
 2 bit count : 1
 3 bit count : 2
 4 bit count : 1
 5 bit count : 2
 6 bit count : 2
 7 bit count : 3
 8 bit count : 1
 9 bit count : 2
 */
