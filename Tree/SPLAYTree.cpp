#include "SPLAYTree.h"

SPLAYTree::Node::Node(int d, Node *l, Node *r) {
	data = d;
	left = l;
	right = r;
	parent = nullptr;
}

SPLAYTree::Node::~Node() {
	delete left;
	delete right;
}

SPLAYTree::SPLAYTree() {
	root = nullptr;
}

SPLAYTree::~SPLAYTree() {
	delete root;
}

void SPLAYTree::printTree() {
	printTree(root, "", false);
	std::cout << std::endl;
}

void SPLAYTree::printTree(Node *node, std::string indent, bool isLeft) {
	if (node == nullptr) {
		return;
	}
	if (isLeft) {
		std::cout << indent << "L:";
		indent += "|  ";
	} else {
		std::cout << indent << "R:";
		indent += "   ";
	}

	std::cout << node->data << std::endl;
	printTree(node->left, indent, true);
	printTree(node->right, indent, false);
}

SPLAYTree::Node* SPLAYTree::rightRotate(Node *x) {
	Node *y = x->left;
	Node *T = y->right;

	// Rotation
	y->parent = x->parent;
	y->right = x;
	x->parent = y;
	x->left = T;
	if (T != nullptr) {
		T->parent = x;
	}

	if (y->parent != nullptr && y->parent->left == x) {
		y->parent->left = y;
	} else if (y->parent != nullptr && y->parent->right == x) {
		y->parent->right = y;
	}
	// Return new root
	return y;
}

SPLAYTree::Node* SPLAYTree::leftRotate(Node *x) {
	Node *y = x->right;
	Node *T = y->left;

	// Rotation
	y->parent = x->parent;
	y->left = x;
	x->parent = y;
	x->right = T;
	if (T != nullptr) {
		T->parent = x;
	}

	if (y->parent != nullptr && y->parent->left == x) {
		y->parent->left = y;
	} else if (y->parent != nullptr && y->parent->right == x) {
		y->parent->right = y;
	}
	// Return new root
	return y;
}

SPLAYTree::Node* SPLAYTree::getParent(Node *node) {
	if (node == nullptr || node->parent == nullptr) {
		return nullptr;
	}
	return node->parent;
}

void SPLAYTree::splay(Node *node) {
	Node *parent, *grand;
	while (node != root) {
		parent = getParent(node);
		grand = getParent(parent);
		if (parent == nullptr) { // rotations had created new root, always last condition.
			root = node;
		} else if (grand == nullptr) { // single rotation case.
			if (parent->left == node) {
				node = rightRotate(parent);
			} else {
				node = leftRotate(parent);
			}
		} else if (grand->left == parent && parent->left == node) { // Zig Zig case.
			rightRotate(grand);
			node = rightRotate(parent);
		} else if (grand->right == parent && parent->right == node) { // Zag Zag case.
			leftRotate(grand);
			node = leftRotate(parent);
		} else if (grand->left == parent && parent->right == node) { //Zig Zag case.
			leftRotate(parent);
			node = rightRotate(grand);
		} else if (grand->right == parent && parent->left == node) { // Zag Zig case.
			rightRotate(parent);
			node = leftRotate(grand);
		}
	}
}

bool SPLAYTree::find(int data) {
	Node *curr = root;
	while (curr != nullptr) {
		if (curr->data == data) {
			splay(curr);
			return true;
		} else if (curr->data > data) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}
	return false;
}

void SPLAYTree::insert(int data) {
	Node *newNode = new Node(data, nullptr, nullptr);
	if (root == nullptr) {
		root = newNode;
		return;
	}

	Node *node = root;
	Node *parent = nullptr;
	while (node != nullptr) {
		parent = node;
		if (node->data > data) {
			node = node->left;
		} else if (node->data < data) {
			node = node->right;
		} else {
			splay(node); // duplicate insertion not allowed but splaying for it.
			return;
		}
	}

	newNode->parent = parent;
	if (parent->data > data) {
		parent->left = newNode;
	} else {
		parent->right = newNode;
	}
	splay(newNode);
}

SPLAYTree::Node* SPLAYTree::findMinNode(Node *curr) {
	Node *node = curr;
	if (node == nullptr) {
		return nullptr;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

void SPLAYTree::remove(int data) {
	Node *node = root;
	Node *parent = nullptr;
	Node *next = nullptr;
	while (node != nullptr) {
		if (node->data == data) {
			parent = node->parent;
			if (node->left == nullptr && node->right == nullptr) {
				next = nullptr;
			} else if (node->left == nullptr) {
				next = node->right;
			} else if (node->right == nullptr) {
				next = node->left;
			}

			if (node->left == nullptr || node->right == nullptr) {
				if (node == root) {
					root = next;
					return;
				}
				if (parent->left == node) {
					parent->left = next;
				} else {
					parent->right = next;
				}
				if (next != nullptr) {
					next->parent = parent;
				}
				break;
			}

			Node *minNode = findMinNode(node->right);
			data = minNode->data;
			node->data = data;
			node = node->right;

		} else if (node->data > data) {
			parent = node;
			node = node->left;
		} else {
			parent = node;
			node = node->right;
		}
	}
	splay(parent); // Splaying for the parent of the node deleted.
}

void SPLAYTree::printInOrder() {
	printInOrder(root);
	std::cout << std::endl;
}

void SPLAYTree::printInOrder(Node *node) {
	if (node != nullptr) {
		printInOrder(node->left);
		std::cout << node->data << " ";
		printInOrder(node->right);
	}
}

int main() {
	SPLAYTree *tree = new SPLAYTree();
	tree->insert(5);
	tree->insert(4);
	tree->insert(6);
	tree->insert(3);
	tree->insert(2);
	tree->insert(1);
	tree->insert(3);
	tree->printTree();

	std::cout << "Value 2 found: " << tree->find(2) << std::endl;
	tree->remove(2);
	tree->remove(5);
	tree->printTree();

	delete tree;
}

/*
 R:3
 L:2
 |  L:1
 R:6
 L:4
 |  R:5

 Value 2 found: true
 R:4
 L:3
 |  L:1
 R:6
 */
