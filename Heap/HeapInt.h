#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Heap {
private:
	std::vector<int> arr; // Array to store heap.
	int(* compare)(int , int);
	int length = 0;

public:
	Heap(int(* comp)(int , int));
	Heap(std::vector<int> &array_in, int(* comp)(int , int));
	void add(int value);
	int remove();
	int peek();
	void print();
	int size();
	bool isEmpty();
	bool deleteValue(int value);

private:
	void proclateDown(int position);
	void proclateUp(int position);
	void doubleSize();
};
