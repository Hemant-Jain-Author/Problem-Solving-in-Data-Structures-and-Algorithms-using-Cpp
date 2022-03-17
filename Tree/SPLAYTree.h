#pragma once

#include <string>
#include <vector>
#include <iostream>

class SPLAYTree {
private:
	class Node {
	public:
		int data = 0;
		Node *left, *right, *parent;
		~Node();
		Node(int d, Node *l, Node *r);
	};

	Node *root;

public:
	~SPLAYTree();
	SPLAYTree();
	bool find(int data);
	void insert(int data);
	void remove(int data);
	void printTree();
	void printInOrder();

private:
	void printTree(Node *node, std::string indent, bool isLeft);
	Node* rightRotate(Node *x); // Function to right rotate subtree rooted with x
	Node* leftRotate(Node *x); // Function to left rotate subtree rooted with x
	Node* getParent(Node *node);
	void splay(Node *node);
	Node* findMinNode(Node *curr);
	void printInOrder(Node *node); // In order
};

