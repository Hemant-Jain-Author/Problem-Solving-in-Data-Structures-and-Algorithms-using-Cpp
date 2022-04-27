#include "StackLinkedList.h"
#include <exception>

Stack::Node::Node(int v, Node *n) {
	value = v;
	next = n;
}

int Stack::size() {
	return length;
}

bool Stack::isEmpty() {
	return length == 0;
}

int Stack::top() {
	if (isEmpty())
		throw "StackEmptyException";

	return head->value;
}

void Stack::push(int value) {
	head = new Node(value, head);
	length++;
}

int Stack::pop() {
	if (isEmpty())
		throw "StackEmptyException";

	int value = head->value;
	Node *delMe = head;
	head = head->next;
	delete delMe;
	length--;
	return value;
}

void Stack::insertAtBottom(int value) {
	if (isEmpty()) {
		push(value);
	} else {
		int temp = pop();
		insertAtBottom(value);
		push(temp);
	}
}

void Stack::print() {
	Node *temp = head;
	while (temp != nullptr) {
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

// Testing code.
int main() {
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