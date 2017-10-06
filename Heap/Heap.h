#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Heap
{
private:
	static const int CAPACITY;
	int size; 
	std::vector<T> arr; 
	void proclateDown(int position);
	void proclateUp(int position);
	void doubleSize();
public:
	Heap();
	Heap(std::vector<T> &array_variable);
	virtual void add(T value);
	virtual T remove();
	virtual void print();
	virtual bool isEmpty();
	virtual T peek();
	static void heapSort(std::vector<int> &array_variable);
};