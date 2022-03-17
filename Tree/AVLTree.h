#pragma once

#include <string>
#include <vector>
#include <iostream>

class AVLTree {
private:
	struct Node {
		int data = 0;
		Node *left;
		Node *right;
		int height = 0;

		~Node();
		Node(int d, Node *l, Node *r);
	};

	Node *root;

public:
	~AVLTree();
	AVLTree();
	void insert(int data);
	void deleteNode(int data);
	void printTree();
	int max(int a, int b);

private:
	Node* insert(Node *node, int data);
	Node* rightRotate(Node *x); // Function to right rotate subtree rooted with x
	Node* leftRotate(Node *x); // Function to left rotate subtree rooted with x
	Node* rightLeftRotate(Node *x); // Function to right then left rotate subtree rooted with x
	Node* leftRightRotate(Node *x); // Function to left then right rotate subtree rooted with x
	Node* deleteNode(Node *node, int data);
	Node* findMin(Node *curr);
	int height(Node *n);
	int getBalance(Node *node);
	void printTree(Node *node, std::string indent, bool isLeft);
};
