#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <exception>
#include <limits>

class Tree {
public:
	struct Node {
		int value;
		Node *lChild;
		Node *rChild;
		Node(int v, Node *l, Node *r);
		Node(int v);
		~Node();
	};
	Node *root;

public:
	Tree();
	~Tree();
	// Other Tree methods.

	void levelOrderBinaryTree(int arr[], int size);

	Node* levelOrderBinaryTree(int arr[], int start, int size);

	void insert(int value);

private:
	Node* insert(int value, Node *node);

public:
	void printPreOrder();

private:
	void printPreOrder(Node *node); // pre order

public:
	void nthPreOrder(int index);

private:
	void nthPreOrder(Node *node, int index, int &counter); // pre order

public:
	void printPostOrder();

private:
	void printPostOrder(Node *node); // post order

public:
	void nthPostOrder(int index);

private:
	void nthPostOrder(Node *node, int index, int &counter); // post order

public:
	void printInOrder();

private:
	void printInOrder(Node *node); // In order

public:
	void nthInOrder(int index);

private:
	void nthInOrder(Node *node, int index, int &counter);

public:
	void printBredthFirst();

	void printDepthFirst();

	bool find(int value);

	bool find2(int value);

	int findMin();

	int findMax();

	void remove(int value);

	void empty();

private:
	Node* findMax(Node *curr);

	Node* findMin(Node *curr);

	Node* remove(Node *node, int value);

public:
	int treeDepth();

private:
	int treeDepth(Node *root);

public:
	bool isEqual(Tree *T2);

private:
	bool isEqual(Node *node1, Node *node2);

public:
	Node* ancestor(int first, int second);

private:
	Node* ancestor(Node *curr, int first, int second);

public:
	Tree* copyTree();

private:
	Node* copyTree(Node *curr);

public:
	Tree* copyMirrorTree();

private:
	Node* copyMirrorTree(Node *curr);

public:
	int numNodes();

	int numNodes(Node *curr);

	int numFullNodesBT();

	int numFullNodesBT(Node *curr);

	int maxLengthPathBT();

private:
	int maxLengthPathBT(Node *curr); // diameter

public:
	int numLeafNodes();

private:
	int numLeafNodes(Node *curr);

public:
	int sumAllBT();

private:
	int sumAllBT(Node *curr);

public:
	void iterativePreOrder();

	void iterativePostOrder();

	void iterativeInOrder();

	bool isBST3(Node *root);
	bool isBST3();

	bool isBST();

	bool isBST(Node *curr, int min, int max);

public:
	bool isBST2();

	bool isBST2(Node *root, int &count); // in order traversal

	Node* treeToListRec();

public:
	Node* treeToListRec(Node *curr);
	void printDLL(Node *root);

public:
	void printAllPath();

private:
	void printAllPath(Node *curr, std::vector<int> &stk);

public:
	int lca(int first, int second);

private:
	Node* lca(Node *curr, int first, int second);

public:
	int lcaBST(int first, int second);

	int lcaBST(Node *curr, int first, int second);

	void trimOutsideRange(int min, int max);

	Node* trimOutsideRange(Node *curr, int min, int max);

	void printInRange(int min, int max);

private:
	void printInRange(Node *root, int min, int max);

public:
	int floorBST(int val);

	int ceilBST(int val);

	int findMaxBT();

private:
	int findMaxBT(Node *curr);

public:
	bool searchBT(Node *root, int value);
	bool searchBT(int value);
	void createBinarySearchTree(int arr[], int size);
	void printLevelOrderLineByLine();
	void printLevelOrderLineByLine2();
	void printSpiralTree();
	bool isCompleteTree();
	bool isCompleteTree2();
	bool isHeap();
	bool isHeap2();

private:
	bool isCompleteTreeUtil(Node *curr, int index, int count);
	bool isHeapUtil(Node *curr, int parentValue);
	bool isHeapUtil2(Node *curr, int index, int count, int parentValue);
	Node* createBinarySearchTree(int arr[], int start, int end);
};
