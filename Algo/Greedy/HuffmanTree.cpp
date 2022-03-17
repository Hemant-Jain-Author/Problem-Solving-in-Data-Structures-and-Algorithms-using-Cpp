#include "HuffmanTree.h"

Node::Node(char ch, int fr, Node *l, Node *r) {
	c = ch;
	freq = fr;
	left = l;
	right = r;
}

Node::~Node() {
	delete left;
	delete right;
}

struct comparator {
	bool operator()(Node *n1, Node *n2) {
		return n1->freq > n2->freq;
	}
};

HuffmanTree::~HuffmanTree() {
	delete root;
}

HuffmanTree::HuffmanTree(std::vector<char> &arr, std::vector<int> &freq) {
	int n = arr.size();
	std::priority_queue<Node*, std::vector<Node*>, comparator> pq;
	for (int i = 0; i < n; i++) {
		Node *node = new Node(arr[i], freq[i], nullptr, nullptr);
		pq.push(node);
	}

	while (pq.size() > 1) {
		Node *lt = pq.top();
		pq.pop();
		Node *rt = pq.top();
		pq.pop();
		Node *nd = new Node('+', lt->freq + rt->freq, lt, rt);
		pq.push(nd);
	}
	root = pq.top();
	pq.pop();
}

void HuffmanTree::print(Node *root, const std::string &s) {
	if (root->left == nullptr && root->right == nullptr && root->c != '+') {
		std::cout << root->c << " = " << s << std::endl;
		return;
	}
	print(root->left, s + "0");
	print(root->right, s + "1");
}

void HuffmanTree::print() {
	std::cout << "Char = Huffman code" << std::endl;
	print(root, "");
}

int main() {
	std::vector<char> ar = { 'A', 'B', 'C', 'D', 'E' };
	std::vector<int> fr = { 30, 25, 21, 14, 10 };
	HuffmanTree hf(ar, fr);
	hf.print();
}

/*
 Char = Huffman code
 C = 00
 E = 010
 D = 011
 B = 10
 A = 11
 */
