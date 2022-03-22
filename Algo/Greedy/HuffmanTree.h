#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <queue>

struct Node {
	char c = '\0';
	int freq = 0;
	Node *left;
	Node *right;
	~Node();
	Node(char ch, int fr, Node *l, Node *r);
};

class HuffmanTree {
	Node *root = nullptr;
public:
	~HuffmanTree();
	HuffmanTree(std::vector<char> &arr, std::vector<int> &freq);
	virtual void print();
private:
	void print(Node *root, const std::string &s);
};
