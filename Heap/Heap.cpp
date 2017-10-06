#pragma once
#include "stdafx.h"
#include "Heap.h"
#include <exception>

template<typename T>
Heap<T>::Heap()
{
	arr = std::vector<T>(CAPACITY);
	size = 0;
}

template<typename T>
Heap<T>::Heap(std::vector<T> &array_variable)
{
	size = array_variable.size();
	arr = std::vector<T>(array_variable.size() + 1);
	for (int i = 0; i < size; i++)
	{
		arr[i + 1] = array_variable[i];
	}

	// Build Heap operation over array
	for (int i = (size / 2); i > 0; i--)
	{
		proclateDown(i);
	}
}

template<typename T>
void Heap<T>::proclateDown(int position)
{
	int lChild = 2 * position;
	int rChild = lChild + 1;
	int small = -1;
	T temp;

	if (lChild < size)
	{
		small = lChild;
	}

	if (rChild < size && arr[rChild]->compare(arr[lChild]) < 0)
	{
		small = rChild;
	}

	if (small != -1 && arr[small]->compare(arr[position]) < 0)
	{
		temp = arr[position];
		arr[position] = arr[small];
		arr[small] = temp;
		proclateDown(small);
	}
}

template<typename T>
void Heap<T>::proclateUp(int position)
{
	int parent = position / 2;
	T temp;
	if (parent == 0)
	{
		return;
	}

	if (arr[parent]->compare(arr[position]) < 0)
	{
		temp = arr[position];
		arr[position] = arr[parent];
		arr[parent] = temp;
		proclateUp(parent);
	}
}

template<typename T>
void Heap<T>::add(T value)
{
	if (size == arr.size() - 1)
	{
		doubleSize();
	}

	arr[++size] = value;
	proclateUp(size);
}

template<typename T>
void Heap<T>::doubleSize()
{
	std::vector<T> old = arr;
	arr = static_cast<std::vector<T>>(std::vector<Comparable>(arr.size() * 2));
	System::arraycopy(old, 1, arr, 1, size);
}

template<typename T>
T Heap<T>::remove()
{
	if (isEmpty())
	{
		throw std::exception("HeapEmptyException");
	}

	T value = arr[1];
	arr[1] = arr[size];
	size--;
	proclateDown(1);
	return value;
}

template<typename T>
void Heap<T>::print()
{
	for (int i = 1; i < size; i++)
	{
		std::cout << "value is :: " << arr[i] << std::endl;
	}

}

template<typename T>
bool Heap<T>::isEmpty()
{
	return (size == 0);
}

template<typename T>
T Heap<T>::peek()
{
	if (isEmpty())
	{
		throw std::exception("HeapEmptyException");
	}
	return arr[1];
}

template<typename T>
void Heap<T>::heapSort(std::vector<int> &array_variable)
{
	Heap<int> *hp = new Heap<int>(array_variable);
	for (int i = 0; i < array_variable.size(); i++)
	{
		array_variable[i] = hp->remove();
	}
}


int main()
{
	int num[] = { 1, 9, 6, 7, 8, 0, 2, 4, 5, 3 };
	std::vector<int> a(num, num + sizeof(num));
	Heap<int> *hp = new Heap<int>(a);
	hp->print();
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << "pop value :: " << hp->remove() << std::endl;
	}

	Heap<int>::heapSort(a);
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << "value is :: " << a[i] << std::endl;
	}
	return 0;
}