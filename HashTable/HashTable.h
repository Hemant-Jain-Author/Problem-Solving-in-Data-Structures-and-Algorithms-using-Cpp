
#include <string>
#include <vector>
#include <iostream>

class HashTable
{

private:
	static int EMPTY_NODE;
	static int LAZY_DELETED;
	static int FILLED_NODE;
	std::vector<int> Arr;
	std::vector<int> Flag;
	int tableSize = 0;
	virtual int ComputeHash(int key);
	virtual int ResolverFun(int index);

public:
	HashTable(int tSize);
	virtual bool Add(int value);
	virtual bool Find(int value);
	virtual bool Remove(int value);
	virtual void Print();
};
