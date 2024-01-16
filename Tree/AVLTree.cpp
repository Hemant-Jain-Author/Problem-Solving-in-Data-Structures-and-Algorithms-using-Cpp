#include "AVLTree.h"

AVLTree::Node::Node(int d, Node *l, Node *r) {
	data = d;
	left = l;
	right = r;
	height = 0;
}

AVLTree::Node::~Node() {
	delete left;
	delete right;
}

AVLTree::AVLTree() {
	root = nullptr;
}

AVLTree::~AVLTree() {
	delete root;
}

int AVLTree::height(Node *n) {
	if (n == nullptr) {
		return -1;
	}
	return n->height;
}

int AVLTree::getBalance(Node *node) {
	return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

void AVLTree::insert(int data) {
	root = insert(root, data);
}

AVLTree::Node* AVLTree::insert(Node *node, int data) {
	if (node == nullptr) {
		return new Node(data, nullptr, nullptr);
	}

	if (node->data > data) {
		node->left = insert(node->left, data);
	} else if (node->data < data) {
		node->right = insert(node->right, data);
	} else { // Duplicate data not allowed
		return node;
	}

	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1) {
		if (data < node->left->data) // Left Left Case
				{
			return rightRotate(node);
		}
		if (data > node->left->data) // Left Right Case
				{
			return leftRightRotate(node);
		}
	}

	if (balance < -1) {
		if (data > node->right->data) // Right Right Case
				{
			return leftRotate(node);
		}
		if (data < node->right->data) // Right Left Case
				{
			return rightLeftRotate(node);
		}
	}
	return node;
}

AVLTree::Node* AVLTree::rightRotate(Node *x) {
	Node *y = x->left;
	Node *T = y->right;

	// Rotation
	y->right = x;
	x->left = T;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

AVLTree::Node* AVLTree::leftRotate(Node *x) {
	Node *y = x->right;
	Node *T = y->left;

	// Rotation
	y->left = x;
	x->right = T;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

AVLTree::Node* AVLTree::rightLeftRotate(Node *x) {
	x->right = rightRotate(x->right);
	return leftRotate(x);
}

AVLTree::Node* AVLTree::leftRightRotate(Node *x) {
	x->left = leftRotate(x->left);
	return rightRotate(x);
}

void AVLTree::deleteNode(int data) {
	root = deleteNode(root, data);
}

AVLTree::Node* AVLTree::deleteNode(Node *node, int data) {
	if (node == nullptr) {
		return nullptr;
	}

	if (node->data == data) {
		if (node->left == nullptr && node->right == nullptr) {
			return nullptr;
		} else if (node->left == nullptr) {
			return node->right; // no need to modify height
		} else if (node->right == nullptr) {
			return node->left; // no need to modify height
		} else {
			Node *minNode = findMin(node->right);
			node->data = minNode->data;
			node->right = deleteNode(node->right, minNode->data);
		}
	} else {
		if (node->data > data) {
			node->left = deleteNode(node->left, data);
		} else {
			node->right = deleteNode(node->right, data);
		}
	}

	node->height = max(height(node->left), height(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1) {
		if (data >= node->left->data) // Left Left Case
				{
			return rightRotate(node);
		}
		if (data < node->left->data) // Left Right Case
				{
			return leftRightRotate(node);
		}
	}

	if (balance < -1) {
		if (data <= node->right->data) // Right Right Case
				{
			return leftRotate(node);
		}
		if (data > node->right->data) // Right Left Case
				{
			return rightLeftRotate(node);
		}
	}
	return node;
}

AVLTree::Node* AVLTree::findMin(Node *curr) {
	Node *node = curr;
	if (node == nullptr) {
		return nullptr;
	}

	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

void AVLTree::printTree() {
	std::string str = "";
	printTree(root, str, false);
	std::cout << std::endl;
}

void AVLTree::printTree(Node *node, std::string indent, bool isLeft) {
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

	std::cout << node->data << "(" << node->height << ")" << std::endl;
	printTree(node->left, indent, true);
	printTree(node->right, indent, false);
}

int AVLTree::max(int a, int b) {
	return (a > b) ? a : b;
}

// Testing code.
int main() {
	AVLTree *t = new AVLTree();
	t->insert(1);
	t->insert(2);
	t->insert(3);
	t->insert(4);
	t->insert(5);
	t->insert(6);
	t->insert(7);
	t->insert(8);
	t->printTree();

	t->deleteNode(5);
	t->printTree();

	t->deleteNode(1);
	t->printTree();

	t->deleteNode(2);
	t->printTree();

	delete t;
}

/*
 R:4(3)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:6(2)
      L:5(0)
      R:7(1)
         R:8(0)

R:4(2)
   L:2(1)
   |  L:1(0)
   |  R:3(0)
   R:7(1)
      L:6(0)
      R:8(0)

R:4(2)
   L:2(1)
   |  R:3(0)
   R:7(1)
      L:6(0)
      R:8(0)

R:4(2)
   L:3(0)
   R:7(1)
      L:6(0)
      R:8(0)
 */
