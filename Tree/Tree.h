#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <exception>
#include <limits>
class Tree
{
private:
	struct Node
	{
		int value;
		Node *lChild;
		Node *rChild;
		Node(int v, Node *l, Node *r);
		Node(int v);
	};

	Node *root;

public:
	Tree();
	// Other Tree methods.


	virtual void levelOrderBinaryTree(int arr[], int size);

	virtual Node *levelOrderBinaryTree(int arr[], int start, int size);

	virtual void InsertNode(int value);

private:
	Node *InsertNode(int value, Node *node);

public:
	virtual void PrintPreOrder();

private:
	void PrintPreOrder(Node *node); // pre order

public:
	virtual void NthPreOrder(int index);

private:
	void NthPreOrder(Node *node, int index, int& counter); // pre order

public:
	virtual void PrintPostOrder();

private:
	void PrintPostOrder(Node *node); // post order

public:
	virtual void NthPostOrder(int index);

private:
	void NthPostOrder(Node *node, int index, int& counter); // post order

public:
	virtual void PrintInOrder();

private:
	void PrintInOrder(Node *node); // In order

public:
	virtual void NthInOrder(int index);

private:
	void NthInOrder(Node *node, int index, int& counter);

public:
	virtual void PrintBredthFirst();

	virtual void PrintDepthFirst();

	virtual bool Find(int value);

	virtual bool Find2(int value);

	virtual int FindMin();

	virtual int FindMax();

	virtual Node *FindMax(Node *curr);

	virtual Node *FindMin(Node *curr);

	virtual void Free();

	virtual void FreeTree(Node* node);

	virtual void DeleteNode(int value);

private:
	Node *DeleteNode(Node *node, int value);

public:
	virtual int TreeDepth();

private:
	int TreeDepth(Node *root);

public:
	virtual bool isEqual(Tree *T2);

private:
	bool Identical(Node *node1, Node *node2);

public:
	virtual Node *Ancestor(int first, int second);

private:
	Node *Ancestor(Node *curr, int first, int second);

public:
	virtual Tree *CopyTree();

private:
	Node *CopyTree(Node *curr);

public:
	virtual Tree *CopyMirrorTree();

private:
	Node *CopyMirrorTree(Node *curr);

public:
	virtual int numNodes();

	virtual int numNodes(Node *curr);

	virtual int numFullNodesBT();

	virtual int numFullNodesBT(Node *curr);

	virtual int maxLengthPathBT();

private:
	int maxLengthPathBT(Node *curr); // diameter

public:
	virtual int numLeafNodes();

private:
	int numLeafNodes(Node *curr);

public:
	virtual int sumAllBT();

private:
	int sumAllBT(Node *curr);

public:
	virtual void iterativePreOrder();

	virtual void iterativePostOrder();

	virtual void iterativeInOrder();

	virtual bool isBST3(Node *root);

	virtual bool isBST();

	virtual bool isBST(Node *curr, int min, int max);

public:
	virtual bool isBST2();

	virtual bool isBST2(Node *root, int &count); // in order traversal

	virtual Node *treeToListRec();

private:
	Node *treeToListRec(Node *curr);

public:
	virtual void printAllPath();


private:
	void printAllPath(Node *curr, std::vector<int>& stk);

public:
	virtual int LCA(int first, int second);

private:
	Node *LCA(Node *curr, int first, int second);

public:
	virtual int LcaBST(int first, int second);

	virtual int LcaBST(Node *curr, int first, int second);

	virtual void trimOutsideRange(int min, int max);

	virtual Node *trimOutsideRange(Node *curr, int min, int max);

	virtual void printInRange(int min, int max);

private:
	void printInRange(Node *root, int min, int max);

public:
	virtual int FloorBST(int val);

	virtual int CeilBST(int val);

	virtual int findMaxBT();

private:
	int findMaxBT(Node *curr);

public:
	virtual bool searchBT(Node *root, int value);

	virtual void CreateBinaryTree(int arr[], int size);

	virtual Node *CreateBinaryTree(int arr[], int start, int end);

virtual void PrintLevelOrderLineByLine();
virtual void PrintLevelOrderLineByLine2();
virtual void PrintSpiralTree();
bool isCompleteTree();
bool isCompleteTreeUtil(Node* curr, int index, int count);
bool isCompleteTree2();
bool isHeapUtil(Node* curr, int parentValue);
bool isHeap();
bool isHeapUtil2(Node* curr, int index, int count, int parentValue);
bool isHeap2();


};