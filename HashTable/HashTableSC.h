#include <string>
#include <vector>
#include <iostream>

class HashTableSC
{
private:
	struct Node
	{
		int value;
		Node *next;
		Node(int v, Node *n);
	};

	int tableSize;
	std::vector<Node*> listArray;

	int ComputeHash(int key); // division method

public:	
	HashTableSC();	
	virtual void Add(int value);
	virtual bool Remove(int value);
	virtual void Print();
	virtual bool Find(int value);
};