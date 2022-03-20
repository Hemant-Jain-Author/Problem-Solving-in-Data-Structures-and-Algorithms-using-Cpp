#include <string>
#include <vector>
#include <iostream>

class CircularLinkedList {
private:
	struct Node {
		int value;
		Node *next;
		Node(int v, Node *n);
	};

private:
	Node *tail;
	int length;

public:
	CircularLinkedList();
	virtual int size();
	virtual bool isEmpty();
	virtual void addHead(int value);
	virtual int removeHead();
	// Other methods.

	virtual int peekHead();
	virtual void addTail(int value);
	virtual bool deleteNode(int key);
	virtual CircularLinkedList* copyListReversed();
	virtual CircularLinkedList* copyList();
	virtual bool find(int data);
	virtual void freeList();
	virtual void print();
};
