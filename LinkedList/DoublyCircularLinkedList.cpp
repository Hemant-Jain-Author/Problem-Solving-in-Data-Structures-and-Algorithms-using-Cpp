#include "DoublyCircularLinkedList.h"
#include <exception>

DoublyCircularLinkedList::Node::Node(int v) {
	value = v;
	next = this;
	prev = this;
}

DoublyCircularLinkedList::DoublyCircularLinkedList() {
	head = nullptr;
	length = 0;
}

int DoublyCircularLinkedList::size() {
	return length;
}

bool DoublyCircularLinkedList::isEmpty() {
	return length == 0;
}

int DoublyCircularLinkedList::peekHead() {
	if (isEmpty()) {
		throw("EmptyListException");
	}
	return head->value;
}

void DoublyCircularLinkedList::addHead(int value) {
	Node *newNode = new Node(value);
	if (length == 0) {
		tail = head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	} else {
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev = newNode;
		newNode->prev->next = newNode;
		head = newNode;
	}
	length++;
}

void DoublyCircularLinkedList::addTail(int value) {
	Node *newNode = new Node(value);
	if (length == 0) {
		head = tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	} else {
		newNode->next = tail->next;
		newNode->prev = tail;
		tail->next = newNode;
		newNode->next->prev = newNode;
		tail = newNode;
	}
	length++;
}

int DoublyCircularLinkedList::removeHead() {
	if (length == 0)
		throw("EmptyListException");

	int value = head->value;
	length--;

	if (length == 0) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return value;
	}

	Node *next = head->next;
	next->prev = tail;
	tail->next = next;
	delete head;
	head = next;
	return value;
}

int DoublyCircularLinkedList::removeTail() {
	if (length == 0)
		throw("EmptyListException");

	int value = tail->value;
	length--;

	if (length == 0) {
		delete tail;
		head = tail = nullptr;
		return value;
	}

	Node *prev = tail->prev;
	prev->next = head;
	head->prev = prev;
	delete tail;
	tail = prev;
	return value;
}

bool DoublyCircularLinkedList::find(int key) {
	Node *temp = head;
	if (head == nullptr)
		return false;

	do {
		if (temp->value == key) {
			return true;
		}
		temp = temp->next;
	} while (temp != head);

	return false;
}

void DoublyCircularLinkedList::freeList() {
	if (head == nullptr)
		return;

	Node *curr = head->next;
	Node *next;
	while (curr != head) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	length = 0;
}

void DoublyCircularLinkedList::print() {
	if (isEmpty())
		return;

	Node *temp = head;
	do {
		std::cout << temp->value << " ";
		temp = temp->next;
	} while (temp != head);
	std::cout << std::endl;
}


// Testing code.
int main1() {
	DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	std::cout << "size : " << ll->size() << std::endl;
 	std::cout << "isEmpty : " << ll->isEmpty() << std::endl;
 	std::cout << "peek : " << ll->peekHead() << std::endl;
	return 0;
}

/*
3 2 1 
size : 3
isEmpty : 0
peek : 3
 */

// Testing code.
int main2() {
	DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	std::cout << "Find : " << ll->find(4) << std::endl;
	std::cout << "Find : " << ll->find(2) << std::endl;
	return 0;
}

/*
Find : 0
Find : 1
*/

// Testing code.
int main3() {
	DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
	ll->print();
	ll->removeHead();
	ll->print();
	ll->removeTail();
	ll->print();
	ll->addTail(5);
	ll->print();
	ll->freeList();
	ll->print();
	return 0;
}

/*
4 3 2 1 
3 2 1 
3 2 
3 2 5 
*/

// Testing code.
int main4() {
	DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();
	ll->addTail(1);
	ll->addTail(2);
	ll->addTail(3);
	ll->print();
	return 0;
}

/*
1 2 3 
*/

// Testing code.
int main5() {
	DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	ll->removeTail();
	ll->print();
}

/*
3 2 1 
3 2 
*/

int main(){
	main1();
	main2();
	main3();
	main4();
	main5();
	return 0;
}

