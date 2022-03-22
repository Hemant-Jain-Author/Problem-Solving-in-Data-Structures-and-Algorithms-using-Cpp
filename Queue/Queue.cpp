#include "Queue.h"

Queue::Queue() {
	length = 0;
	data = new int[100];
}

bool Queue::add(int value) {
	if (length >= Capacity) {
		throw("QueueFullException");
		return false;
	} else {
		length++;
		data[back] = value;
		back = (++back) % (Capacity - 1);
	}
	return true;
}

int Queue::remove() {
	int value;
	if (length <= 0) {
		throw("QueueEmptyException");
	} else {
		length--;
		value = data[front];
		front = (++front) % (Capacity - 1);
	}
	return value;
}

bool Queue::isEmpty() {
	return length == 0;
}

int Queue::size() {
	return length;
}

// Testing code.
int main() {
	Queue que;
	que.add(1);
	que.add(2);
	que.add(3);
	std::cout << "isEmpty : " << que.isEmpty() << std::endl;
	std::cout << "size : " << que.size() << std::endl;
	std::cout << "Queue remove : " << que.remove() << std::endl;
	std::cout << "Queue remove : " << que.remove() << std::endl;
	return 0;
}

/*
isEmpty : 0
size : 3
Queue remove : 1
Queue remove : 2
 */
