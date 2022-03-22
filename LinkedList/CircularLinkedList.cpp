#include "CircularLinkedList.h"

CircularLinkedList::Node::Node(int v, Node *n = nullptr) {
	value = v;
	next = n;
}

CircularLinkedList::CircularLinkedList() {
	tail = nullptr;
	length = 0;
}

int CircularLinkedList::size() {
	return length;
}

bool CircularLinkedList::isEmpty() {
	return length == 0;
}

int CircularLinkedList::peekHead() {
	if (isEmpty())
		throw "EmptyListException";

	return tail->next->value;
}

void CircularLinkedList::print() {
	if (isEmpty()) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node *temp = tail->next;
	while (temp != tail) {
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << temp->value << std::endl;
}

void CircularLinkedList::addHead(int value) {
	Node *temp = new Node(value);
	if (isEmpty()) {
		tail = temp;
		temp->next = temp;
	} else {
		temp->next = tail->next;
		tail->next = temp;
	}
	length++;
}

int CircularLinkedList::removeHead() {
	if (isEmpty()) {
		throw("EmptyListException");
	}
	int value = tail->next->value;
	Node *delMe = tail->next;

	if (tail == tail->next)
		tail = nullptr;
	else
		tail->next = tail->next->next;

	delete delMe;
	length--;
	return value;
}

void CircularLinkedList::addTail(int value) {
	Node *temp = new Node(value);
	if (isEmpty()) {
		tail = temp;
		temp->next = temp;
	} else {
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	length++;
}

bool CircularLinkedList::deleteNode(int key) {
	if (isEmpty())
		return false;

	Node *prev = tail;
	Node *curr = tail->next;
	Node *head = tail->next;

	if (curr->value == key) // head and single node case.
			{
		if (curr == curr->next) // single node case
				{
			tail = nullptr;
		} else // head case
		{
			tail->next = tail->next->next;
		}
		delete curr;
		return true;
	}

	prev = curr;
	curr = curr->next;

	while (curr != head) {
		if (curr->value == key) {
			if (curr == tail) {
				tail = prev;
			}
			prev->next = curr->next;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	return false;
}

bool CircularLinkedList::find(int data) {
	Node *temp = tail;
	for (int i = 0; i < length; i++) {
		if (temp->value == data)
			return true;

		temp = temp->next;
	}
	return false;
}

void CircularLinkedList::freeList() {
	if (tail == nullptr)
		return;

	Node *curr = tail->next;
	Node *next;
	while (curr != tail) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	delete tail;
	tail = nullptr;
	length = 0;
}

CircularLinkedList* CircularLinkedList::copyListReversed() {
	CircularLinkedList *cl = new CircularLinkedList();
	Node *curr = tail->next;
	Node *head = curr;

	if (curr != nullptr) {
		cl->addHead(curr->value);
		curr = curr->next;
	}
	while (curr != head) {
		cl->addHead(curr->value);
		curr = curr->next;
	}
	return cl;
}

CircularLinkedList* CircularLinkedList::copyList() {
	CircularLinkedList *cl = new CircularLinkedList();
	Node *curr = tail->next;
	Node *head = curr;

	if (curr != nullptr) {
		cl->addTail(curr->value);
		curr = curr->next;
	}
	while (curr != head) {
		cl->addTail(curr->value);
		curr = curr->next;
	}
	return cl;
}


// Testing code.
int main1() {
	CircularLinkedList *ll = new CircularLinkedList();
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
	CircularLinkedList *ll = new CircularLinkedList();
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
	CircularLinkedList *ll = new CircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
	ll->print();
	ll->deleteNode(3);
	ll->print();
	return 0;
}

/*
4 3 2 1 
4 2 1 
*/

// Testing code.
int main4() {
	CircularLinkedList *ll = new CircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	CircularLinkedList *ll2 = ll->copyListReversed();
 	ll2->print();
	CircularLinkedList *ll3 = ll->copyList();
 	ll3->print();
	ll->removeHead();
	ll->print();
	return 0;
}

/*
3 2 1 
1 2 3 
3 2 1 
2 1
*/

// Testing code.
int main5() {
	CircularLinkedList *ll = new CircularLinkedList();
	ll->addTail(1);
	ll->addTail(2);
	ll->addTail(3);
	ll->print();
	return 0;
}

/*
1 2 3
 */

int main(){
	main1();
	main2();
	main3();
	main4();
	main5();
	return 0;
}
