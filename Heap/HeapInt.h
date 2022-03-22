#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

const int CAPACITY = 100;

class Heap {
private:
	int size; // Number of elements in heap.
	std::vector<int> arr; // Array to store heap.
	int(* compare)(int , int);

public:
	Heap(int(* comp)(int , int));
	Heap(std::vector<int> &array_in, int(* comp)(int , int));
	// Other Methods.

private:
	void proclateDown(int position);
	void proclateUp(int position);
	void doubleSize();

public:
	void add(int value);
	int remove();
	void print();
	int length();
	bool isMinHeapArr(std::vector<int> &arr, int size);
	bool isMaxHeapArr(std::vector<int> &arr, int size);
	bool isEmpty();
	int peek();
	static void heapSort(std::vector<int> &array, bool inc);
	static int greater(int a, int b); 
	static int less(int a, int b);
};
