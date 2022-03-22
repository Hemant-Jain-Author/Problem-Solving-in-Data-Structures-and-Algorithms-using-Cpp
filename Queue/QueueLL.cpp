#include "QueueLL.h"

Queue::Node::Node(int v, Node *n) {
	value = v;
	next = n;
}

int Queue::size() {
	return length;
}

bool Queue::isEmpty() {
	return length == 0;
}

int Queue::front() {
	if (isEmpty())
		throw("QueueEmptyException");

	return head->value;
}

void Queue::print() {
	Node *temp = head;
	while (temp != nullptr) {
		std::wcout << temp->value << std::wstring(L" ");
		temp = temp->next;
	}
}

void Queue::add(int value) {
	Node *temp = new Node(value, nullptr);

	if (head == nullptr) {
		head = tail = temp;
	} else {
		tail->next = temp;
		tail = temp;
	}
	length++;
}

int Queue::remove() {
	if (isEmpty())
		throw("QueueEmptyException");

	int value = head->value;
	Node *delMe = head;
	head = head->next;
	delete delMe;
	length--;
	return value;
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
}

/*
isEmpty : 0
size : 3
Queue remove : 1
Queue remove : 2
 */
