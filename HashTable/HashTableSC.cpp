#include "HashTableSC.h"

int main()
{
	HashTableSC *ht = new HashTableSC();
	for (int i = 1; i < 110; i++)
		ht->Add(i);

	std::cout << "Search 100 :: " << ht->Find(100) << std::endl;
	std::cout << "Remove 100 :: " << ht->Remove(100) << std::endl;
	std::cout << "Search 100 :: " << ht->Find(100) << std::endl;
	std::cout << "Remove 100 :: " << ht->Remove(100) << std::endl;
	ht->Print();
	return 0;
}


HashTableSC::Node::Node(int v, Node *n)
{
	value = v;
	next = n;
}

HashTableSC::HashTableSC()
{
	tableSize = 23;// some odd value
	listArray = std::vector<Node*>(tableSize);
	for (int i = 0; i < tableSize; i++)
	{
		listArray[i] = nullptr;
	}
}

int HashTableSC::ComputeHash(int key)
{
	int hashValue = 0;
	hashValue = key;
	return hashValue % tableSize;
}

void HashTableSC::Add(int value)
{
	int index = ComputeHash(value);
	listArray[index] = new Node(value, listArray[index]);
}

bool HashTableSC::Remove(int value)
{
	int index = ComputeHash(value);
	Node *nextNode, *head = listArray[index];
	Node *delMe;
	if (head != nullptr && head->value == value)
	{
		delMe = head;
		listArray[index] = head->next;
		delete(delMe);
		return true;
	}
	while (head != nullptr)
	{
		nextNode = head->next;
		if (nextNode != nullptr && nextNode->value == value)
		{
			delMe = head->next;
			head->next = nextNode->next;
			delete(delMe);
			return true;
		}
		else
		{
			head = nextNode;
		}
	}
	return false;
}

void HashTableSC::Print()
{
	for (int i = 0; i < tableSize; i++)
	{
		Node *head = listArray[i];
		if (head)
			std::cout << "\nPrinting for index value :: " << i << " List of value Printing :: ";

		while (head != nullptr)
		{
			std::cout << head->value << " ";
			head = head->next;
		}
	}
}

bool HashTableSC::Find(int value)
{
	int index = ComputeHash(value);
	Node *head = listArray[index];
	while (head != nullptr)
	{
		if (head->value == value)
			return true;

		head = head->next;
	}
	return false;
}