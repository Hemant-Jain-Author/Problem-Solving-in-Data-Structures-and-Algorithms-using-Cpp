#pragma once
#include <string>
#include <iostream>

class Queue
{
private:
	struct Node
	{
		int value = 0;
		Node *next;
		Node(int v, Node *n);
	};

	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;

public:
	virtual int size();
	virtual bool isEmpty();
	virtual int peek();
	virtual void push(int value);
	virtual int pop();
	virtual void print();
};