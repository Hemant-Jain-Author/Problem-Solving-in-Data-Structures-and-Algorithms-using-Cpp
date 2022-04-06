#include "HeapInt.h"

Heap::Heap(int(* comp)(int , int)) {
	arr = std::vector<int>(100); // Initial array size 100
	compare = comp;
}

Heap::Heap(std::vector<int> &array, int(* comp)(int , int)) {
	arr = array;
	compare = comp;
	length = array.size();
	// Build Heap operation over array
	for (int i = (length / 2); i >= 0; i--) {
		proclateDown(i);
	}
}

void Heap::proclateDown(int parent) {
	int lChild = 2 * parent + 1;
	int rChild = lChild + 1;
	int child = -1;

	if (lChild < length) {
		child = lChild;
	}

	if (rChild < length && compare(arr[lChild], arr[rChild])) {
		child = rChild;
	}

	if (child != -1 && compare(arr[parent], arr[child])) {
		int temp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = temp;
		proclateDown(child);
	}
}

void Heap::proclateUp(int child) {
	int parent = (child - 1) / 2;
	if (parent < 0) {
		return;
	}

	if (compare(arr[parent], arr[child])) {
		int temp = arr[child];
		arr[child] = arr[parent];
		arr[parent] = temp;
		proclateUp(parent);
	}
}

void Heap::add(int value) {
	if (length == arr.size()) {
		doubleSize();
	}

	arr[length++] = value;
	proclateUp(length - 1);
}

void Heap::doubleSize() {
	std::vector<int> old = arr;
	arr = std::vector<int>(arr.size() * 2);
	for (int i = 0; i < length; i++) {
		arr[i] = old[i];
	}
}

int Heap::remove() {
	if (isEmpty())
		throw "HeapEmptyException.";

	int value = arr[0];
	arr[0] = arr[length - 1];
	length--;
	proclateDown(0);
	return value;
}

void Heap::print() {
	std::cout << "Heap :: ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

bool Heap::isEmpty() {
	return (length == 0);
}

int Heap::size() {
	return length;
}

int Heap::peek() {
	if (isEmpty())
		throw "Heap empty exception.";

	return arr[0];
}

bool Heap::deleteValue(int value) {
    for (int i = 0; i < length; i++) {
        if(arr[i] == value){
            arr[i] = arr[length-1];
            length -= 1;
            proclateUp(i);
            proclateDown(i);
            return true;
        }
    }
    return false;
}

// min heap compare function.
int greater(int a, int b) {
    return a > b;
}

// max heap compare function.
int less(int a, int b) {
    return a < b;
}

// Testing code.
int main1() {
	Heap hp = Heap(greater);
	hp.add(1);
	hp.add(9);
	hp.add(6);
	hp.add(7);
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}

/*
Heap :: 1 7 6 9 
1 6 7 9 
 */

// Testing code.
int main2() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, greater); // Min Heap
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
Heap :: 0 1 2 4 5 3 
0 1 2 3 4 5 
 */

// Testing code.
int main3() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, less); // Max Heap
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
Heap :: 5 4 3 1 0 2 
5 4 3 2 1 0 
 */


void heapSort(std::vector<int> &array, bool inc) {
	// min heap for decreasing and max heap for increasing.
	Heap hp = Heap(array, ( inc ) ? less : greater );
	int length = array.size();
	for (int i = length-1; i >=0; i--)
        array[i] = hp.remove();
}

// Testing code.
int main4() {
	std::vector<int> a = { 1, 9, 6, 7, 8, 10, 2, 4, 5, 3 };
	heapSort(a, true);
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 
*/

// Testing code.
int main5() {
	std::vector<int> a = { 1, 0, 2, 4, 5, 3 };
	Heap hp = Heap(a, greater); // Min Heap
	hp.print();
	hp.deleteValue(3);
	hp.print();
	while (hp.isEmpty() == false) {
		std::cout << hp.remove() << " ";
	}
	std::cout << std::endl;
	return 0;
}

int main() {
	main1();
	main2();
	main3();
	main4();
	main5();
}
