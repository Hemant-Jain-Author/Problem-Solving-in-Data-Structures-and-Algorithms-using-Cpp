#pragma once

#include <string>
#include <vector>
#include <iostream>

class CircularLinkedList
{
private:
	struct Node
	{
		int value;
		Node *next;
		Node(int v, Node *n);
		Node(int v);
	};

private:
	Node *tail;
	int list_size;

public:
	CircularLinkedList();
	virtual int size();
	virtual bool isEmpty();
	virtual int peek();
	virtual void addHead(int value);
	virtual int removeHead();
	// Other methods.


	virtual void addTail(int value);
	virtual bool removeNode(int key);
	virtual CircularLinkedList* copyListReversed();
	virtual CircularLinkedList* copyList();
	virtual bool isPresent(int data);
	virtual void freeList();
	virtual void print();
};