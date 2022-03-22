#include <string>
#include <vector>
#include <iostream>

class RBTree {
private:
	struct Node {
		Node *left, *right, *parent, *nullNode;
		int data = 0;
		bool colour = false; // true for red colour, false for black colour
		~Node();
		Node(int data, Node *nullNode);
	};

	Node *root;
	Node *nullNode;

public:
	~RBTree();
	RBTree();
	void printTree();
	void insert(int data);
	void remove(int data);

private:
	bool isRed(Node *node); // To check whether node is of colour red or not.
	Node* getUncle(Node *node);
	Node* rightRotate(Node *x); // Function to right rotate subtree rooted with x
	Node* leftRotate(Node *x); // Function to left rotate subtree rooted with x
	Node* rightLeftRotate(Node *node);
	Node* leftRightRotate(Node *node);
	Node* find(int data);
	void printTree(Node *node, std::string indent, bool isLeft);
	Node* insert(Node *node, int data);
	void fixRedRed(Node *x);
	void remove(Node *node, int key);
	void fixDoubleBlack(Node *x);
	Node* getSibling(Node *node);
	void joinParentChild(Node *u, Node *v);
	Node* minimum(Node *node);
};
