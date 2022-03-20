#include <string>
#include <iostream>

class DoublyLinkedList {
private:
	struct Node {
		int value;
		Node *next;
		Node *prev;
		Node(int v, Node *nxt = nullptr, Node *prv = nullptr);
	};

	Node *head;
	Node *tail;
	int length;

public:
	DoublyLinkedList();
	virtual int size();
	virtual bool isEmpty();
	virtual void addHead(int value);
	virtual int removeHead();
	virtual void print();
	// Other methods.

	virtual int peekHead();
	virtual void addTail(int value);
	virtual bool deleteNode(int key);
	virtual bool find(int key);
	virtual void freeList();
	virtual void sortedInsert(int value);
	virtual void reverseList();
	virtual void removeDuplicate();
	virtual DoublyLinkedList* copyListReversed();
	virtual DoublyLinkedList* copyList();
};
