#include "DoublyLinkedList.h"
#include <exception>

DoublyLinkedList::Node::Node(int v, Node *nxt, Node *prv) {
	value = v;
	next = nxt;
	prev = prv;
}

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	length = 0;
}

int DoublyLinkedList::size() {
	return length;
}

bool DoublyLinkedList::isEmpty() {
	return length == 0;
}

int DoublyLinkedList::peekHead() {
	if (isEmpty())
		throw("EmptyListException");

	return head->value;
}

void DoublyLinkedList::addHead(int value) {
	Node *newNode = new Node(value);
	if (length == 0) {
		tail = head = newNode;
	} else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	length++;
}

void DoublyLinkedList::addTail(int value) {
	Node *newNode = new Node(value);
	if (length == 0) {
		head = tail = newNode;
	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

int DoublyLinkedList::removeHead() {
	if (isEmpty())
		throw("EmptyListException");
	Node *deleteMe;
	int value = head->value;
	deleteMe = head;
	head = head->next;

	if (head == nullptr) {
		tail = nullptr;
	} else {
		head->prev = nullptr;
	}
	delete deleteMe;
	length--;
	return value;
}

bool DoublyLinkedList::deleteNode(int key) {
	Node *curr = head;
	Node *deleteMe;
	if (curr == nullptr) // empty list
		return false;

	if (curr->value == key) // head is the node with value key.
			{
		deleteMe = curr;
		curr = curr->next;
		delete deleteMe;
		length--;
		if (curr != nullptr) {
			head = curr;
			head->prev = nullptr;
		} else
			tail = nullptr; // only one element in list.

		return true;
	}

	while (curr->next != nullptr) {
		if (curr->next->value == key) {
			deleteMe = curr->next;
			curr->next = curr->next->next;
			if (curr->next == nullptr) // last element case.
				tail = curr;
			else
				curr->next->prev = curr;
			delete deleteMe;
			length--;
			return true;
		}
		curr = curr->next;
	}
	return false;
}

bool DoublyLinkedList::find(int key) {
	Node *temp = head;
	while (temp != nullptr) {
		if (temp->value == key)
			return true;

		temp = temp->next;
	}
	return false;
}

void DoublyLinkedList::freeList() {
	Node *curr = head;
	Node *next;
	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	tail = head = nullptr;
	length = 0;
}

void DoublyLinkedList::print() {
	Node *temp = head;
	while (temp != nullptr) {
		std::cout << temp->value << std::string(" ");
		temp = temp->next;
	}
	std::cout << std::endl;
}

void DoublyLinkedList::sortedInsert(int value) {
	Node *temp = new Node(value);

	if (head == nullptr) { // first element
		tail = head = temp;
		return;
	}
	
	if (head->value >= value) { // at the begining
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}

	Node *curr = head;

	while (curr->next != nullptr && curr->next->value < value) { // treversal
		curr = curr->next;
	}

	if (curr->next == nullptr) { // at the end
		tail = temp;
		temp->prev = curr;
		curr->next = temp;
	} else { // all other
		temp->next = curr->next;
		temp->prev = curr;
		curr->next = temp;
		temp->next->prev = temp;
	}
	length++;
}

void DoublyLinkedList::reverseList() {
	Node *curr = head;
	Node *tempNode;
	while (curr != nullptr) {
		tempNode = curr->next;
		curr->next = curr->prev;
		curr->prev = tempNode;
		if (curr->prev == nullptr) {
			tail = head;
			head = curr;
			return;
		}
		curr = curr->prev;
	}
	return;
}

void DoublyLinkedList::removeDuplicate() {
	Node *curr = head;
	Node *deleteMe;
	while (curr != nullptr) {
		if ((curr->next != nullptr) && curr->value == curr->next->value) {
			deleteMe = curr->next;
			curr->next = deleteMe->next;
			if (deleteMe != tail)
				curr->next->prev = curr;
			if (deleteMe == tail)
				tail = curr;
			delete deleteMe;
		} else {
			curr = curr->next;
		}
	}
}

DoublyLinkedList* DoublyLinkedList::copyListReversed() {
	DoublyLinkedList *dll = new DoublyLinkedList();	
	Node *curr = head;
	while (curr != nullptr) {
		dll->addHead(curr->value);
		curr = curr->next;
	}
	return dll;
}

DoublyLinkedList* DoublyLinkedList::copyList() {
	DoublyLinkedList *dll = new DoublyLinkedList();	
	Node *curr = head;
	while (curr != nullptr) {
		dll->addTail(curr->value);
		curr = curr->next;
	}
	return dll;
}

// Testing code.
int main1() {
	DoublyLinkedList *ll = new DoublyLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	std::cout << "size : " << ll->size() << std::endl;
 	std::cout << "isEmpty : " << ll->isEmpty() << std::endl;
 	std::cout << "peek : " << ll->peekHead() << std::endl;
	ll->removeHead();
	ll->print();
	return 0;
}

/*
3 2 1 
size : 3
isEmpty : 0
peek : 3
2 1 
 */

// Testing code.
int main2() {
	DoublyLinkedList *ll = new DoublyLinkedList();
	ll->sortedInsert(2);
	ll->sortedInsert(1);
	ll->sortedInsert(3);
	ll->print();
	return 0;
}
/*
1 2 3 
*/

// Testing code.
int main3() {
	DoublyLinkedList *ll = new DoublyLinkedList();
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
int main4() {
	DoublyLinkedList *ll = new DoublyLinkedList();
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
int main5() {
	DoublyLinkedList *ll = new DoublyLinkedList();
	for(int i =1;i<5;i++) {
		ll->sortedInsert(i);
		ll->sortedInsert(i);
	}
	ll->print();
	ll->removeDuplicate();
 	ll->print();
	return 0;
}

/*
1 1 2 2 3 3 4 4 
1 2 3 4 
*/

// Testing code.
int main6() {
	DoublyLinkedList *ll = new DoublyLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	DoublyLinkedList *ll2 = ll->copyListReversed();
 	ll2->print();
	DoublyLinkedList *ll3 = ll->copyList();
 	ll3->print();
	return 0;
}

/*
3 2 1 
1 2 3 
3 2 1 
*/

// Testing code.
int main7() {
	DoublyLinkedList *ll = new DoublyLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	ll->reverseList();
	ll->print();	
	return 0;
}

/*
3 2 1 
1 2 3  
*/

int main(){
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	return 0;
}
