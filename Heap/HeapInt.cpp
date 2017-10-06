#include "stdafx.h"
#include "HeapInt.h"

int main()
{
	std::vector<int> a = { 1, 9, 6, 7, 8, -1, 2, 4, 5, 3 };
	Heap *hp = new Heap(a);
	hp->print();
	std::cout << "value pop from heap::" << std::endl;
	for (int i = 0; i < a.size(); i++) {
		std::cout << "pop value :: " << hp->remove() << std::endl;
	}

	Heap::heapSort(a);
	std::cout << "value after heap sort::" << std::endl;
	for (int i = 0; i < a.size(); i++) {
		std::cout << " " << a[i];
	}
	return 0;
}

Heap::Heap()
{
	arr = std::vector<int>(CAPACITY);
	size = 0;
}

Heap::Heap(std::vector<int> &array_in)
{
	size = array_in.size();
	arr = std::vector<int>(array_in.size() + 1);
	auto it = arr.begin();

	copy(array_in.begin(), array_in.end(), ++it); // we do not use 0 index

	// Build Heap operation over array
	for (int i = (size / 2); i > 0; i--)
	{
		proclateDown(i);
	}
}

void Heap::proclateDown(int position)
{
	int lChild = 2 * position;
	int rChild = lChild + 1;
	int small = -1;
	int temp;

	if (lChild <= size)
	{
		small = lChild;
	}

	if (rChild <= size && (arr[rChild] - arr[lChild]) < 0)
	{
		small = rChild;
	}

	if (small != -1 && (arr[small] - arr[position]) < 0)
	{
		temp = arr[position];
		arr[position] = arr[small];
		arr[small] = temp;
		proclateDown(small);
	}
}

void Heap::proclateUp(int position)
{
	int parent = position / 2;
	int temp;
	if (parent == 0)
		return;

	if ((arr[parent] - arr[position]) < 0)
	{
		temp = arr[position];
		arr[position] = arr[parent];
		arr[parent] = temp;
		proclateUp(parent);
	}
}

void Heap::add(int value)
{
	arr[++size] = value;
	proclateUp(size);
}

int Heap::remove()
{
	if (isEmpty())
		throw std::exception("HeapEmptyException.");

	int value = arr[1];
	arr[1] = arr[size];
	size--;
	proclateDown(1);
	return value;
}

void Heap::print()
{
	std::cout << "Printing content of heap::" << std::endl;
	for (int i = 1; i <= size; i++)
	{
		std::cout << arr[i] << std::endl;
	}

}

bool Heap::IsMinHeap(std::vector<int> &arr, int size)
{
	for (int i = 0; i <= (size - 2) / 2; i++)
	{
		if (2 * i + 1 < size)
		{
			if (arr[i] > arr[2 * i + 1])
			{
				return false;
			}
		}
		if (2 * i + 2 < size)
		{
			if (arr[i] > arr[2 * i + 2])
			{
				return false;
			}
		}
	}
	return true;
}

bool Heap::IsMaxHeap(std::vector<int> &arr, int size)
{
	for (int i = 0; i <= (size - 2) / 2; i++)
	{
		if (2 * i + 1 < size)
		{
			if (arr[i] < arr[2 * i + 1])
			{
				return false;
			}
		}
		if (2 * i + 2 < size)
		{
			if (arr[i] < arr[2 * i + 2])
			{
				return false;
			}
		}
	}
	return true;
}

bool Heap::isEmpty()
{
	return (size == 0);
}

int Heap::peek()
{
	if (isEmpty())
		throw std::exception("Heap empty exception.");

	return arr[1];
}

void Heap::heapSort(std::vector<int> &array_in)
{
	Heap *hp = new Heap(array_in);
	for (int i = 0; i < array_in.size(); i++)
	{
		array_in[i] = hp->remove();
	}
}