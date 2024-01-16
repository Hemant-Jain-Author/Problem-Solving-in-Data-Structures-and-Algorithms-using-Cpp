#include <string>
#include <vector>
#include <iostream>

class BTree {
private:
	struct Node {
		int n = 0; // Current number of keys
		std::vector<int> keys; // An array of keys
		std::vector<Node*> arr; // An array of child pointers
		bool leaf = false; // Is true when node is leaf. Otherwise false

		// Constructor
		Node(bool leaf, int max);
		~Node();
	};

	Node *root; // Pointer to root node
	int max = 0; // Maximum degree
	int min = 0; // Minimum degree

public:
	~BTree();
	BTree(int dg);
	void printTree();
	void insert(int key);
	void remove(int key);
	bool search(int key);

private:
	void printTree(Node *node, std::string indent);
	void printInOrder(Node *node);
	bool search(Node *node, int key);
	// Insert a new key in this node
	// Arguments are parent, child, index of child and key.
	void insert(Node *parent, Node *child, int index, int key);
	void split(Node *parent, Node *child, int index);
	void remove(Node *node, int key);
	// Returns the index of first key which is greater than or equal to key.
	int findKey(Node *node, int key);
	// Remove the index key from leaf node.
	void removeFromLeaf(Node *node, int index);
	// Remove the index key from a non-leaf node.
	void removeFromNonLeaf(Node *node, int index);
	// To get predecessor of keys[index]
	int getPred(Node *node, int index);
	// To get successor of keys[index]
	int getSucc(Node *node, int index);
	// Make sure that the node have at least min number of keys
	void fixBTree(Node *node, int index);
	// Move a key from parent to right and left to parent.
	void borrowFromLeft(Node *node, int index);
	// Move a key from parent to left and right to parent.
	void borrowFromRight(Node *node, int index);
	// Merge node's children at index and index+1.
	void merge(Node *node, int index);
};
/*
 key[0]:1
 key[0]:2
 key[0]:3
 key[0]:4
 key[0]:5
 key[0]:6
 key[0]:7
 key[1]:8
 key[0]:9
 key[1]:10

 6 : Present
 11 : Not Present

 key[0]:1
 key[1]:2
 key[0]:4
 key[0]:5
 key[1]:8
 key[0]:9
 key[1]:10
 */
