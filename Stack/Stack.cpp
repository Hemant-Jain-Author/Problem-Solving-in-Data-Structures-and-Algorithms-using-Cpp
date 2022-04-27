#include "Stack.h"
#include <exception>

Stack::Stack(int size) {
	data = new int[size];
	capacity = size;
	minCapacity = size; // dynamic stack
}

Stack::~Stack() {
	delete[] data;
}

int Stack::size() {
	return stktop + 1;
}

bool Stack::isEmpty() {
	return (stktop == -1);
}

void Stack::push(int value) {
	if (stktop + 1 == capacity) {
		throw "StackOverflowException";
	}
	stktop++;
	data[stktop] = value;
}

int Stack::top() {
	if (isEmpty()) {
		throw "StackEmptyException";
	}
	return data[stktop];
}

int Stack::pop() {
	if (isEmpty()) {
		throw "StackEmptyException";
	}
	int topVal = data[stktop];
	stktop--;
	return topVal;
}

void Stack::print() {
	for (int i = stktop; i >= 0 ; i--)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

void Stack::dynamicPush(int value) {
	if (stktop + 1 == capacity) {
		std::cout << "stack size doubled" << std::endl;
		int *delMe = data;
		capacity = 2 * capacity;
		data = new int[capacity];
		for (int i = stktop; i >= 0; i--) {
			data[i] = delMe[i];
		}
		delete[] delMe;
	}
	stktop++;
	data[stktop] = value;
}

int Stack::dynamicPop() {
	if (isEmpty()) {
		throw "StackEmptyException";
	}

	int topVal = data[stktop];
	stktop--;
	if (stktop + 1 < (capacity / 2) && capacity > minCapacity) {
		std::cout << "stack size halfed." << std::endl;
		capacity = capacity / 2;
		int *delMe = data;
		data = new int[capacity];
		for (int i = stktop; i >= 0; i--) {
			data[i] = delMe[i];
		}
		delete[] delMe;
	}
	return topVal;
}

// Testing code.
int main1() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.print();
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	return 0;
}

/*
 3 2 1
 3
 2
 1
 */

// Testing code.
int main2() {
	Stack s(5);
	for (int i = 0; i <= 11; i++) {
		s.dynamicPush(i);
	}
	for (int i = 0; i <= 11; i++) {
		std::cout << s.dynamicPop() << " ";
	}
	return 0;
}

/*
stack size doubled
stack size doubled
11
stack size reduced
10
9
8
7
6
stack size reduced
5
4
3
2
1
*/


// Testing code.
int main() {
	//main1();
	main2();
	return 0;
}