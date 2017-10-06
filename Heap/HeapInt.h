#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Heap
{
private:
	static const int CAPACITY = 16;
	int size; // Number of elements in heap
	std::vector<int> arr; // The heap array

public:
	Heap();
	Heap(std::vector<int> &array_in);
	// Other Methods.

private:
	void proclateDown(int position);
	void proclateUp(int position);

public:
	virtual void add(int value);
	virtual int remove();
	virtual void print();
	virtual bool IsMinHeap(std::vector<int> &arr, int size);
	virtual bool IsMaxHeap(std::vector<int> &arr, int size);
	virtual bool isEmpty();
	virtual int peek();
	static void heapSort(std::vector<int> &array_in);
};