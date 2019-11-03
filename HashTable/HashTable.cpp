#include "HashTable.h"

int HashTable::EMPTY_NODE = -1;
int HashTable::LAZY_DELETED = -2;
int HashTable::FILLED_NODE = 0;

HashTable::HashTable(int tSize)
{
	tableSize = tSize;
	Arr = std::vector<int>(tSize + 1);
	Flag = std::vector<int>(tSize + 1, EMPTY_NODE);
}

int HashTable::ComputeHash(int key)
{
	return key % tableSize;
}

int HashTable::ResolverFun(int index)
{
	return index;
}

bool HashTable::Add(int value)
{
	int hashValue = ComputeHash(value);
	for (int i = 0; i < tableSize; i++)
	{
		if (Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED)
		{
			Arr[hashValue] = value;
			Flag[hashValue] = FILLED_NODE;
			return true;
		}
		hashValue += ResolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

bool HashTable::Find(int value)
{
	int hashValue = ComputeHash(value);
	for (int i = 0; i < tableSize; i++)
	{
		if (Flag[hashValue] == EMPTY_NODE)
		{
			return false;
		}

		if (Flag[hashValue] == FILLED_NODE && Arr[hashValue] == value)
		{
			return true;
		}

		hashValue += ResolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

bool HashTable::Remove(int value)
{
	int hashValue = ComputeHash(value);
	for (int i = 0; i < tableSize; i++)
	{
		if (Flag[hashValue] == EMPTY_NODE)
			return false;

		if (Flag[hashValue] == FILLED_NODE && Arr[hashValue] == value)
		{
			Flag[hashValue] = LAZY_DELETED;
			return true;
		}
		hashValue += ResolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

void HashTable::Print()
{
	std::cout << "\nValues Stored in HashTable are::" << std::endl;
	for (int i = 0; i < tableSize; i++)
	{
		if (Flag[i] == FILLED_NODE)
			std::cout << "Node at index [" << i << " ] :: " << Arr[i] << std::endl;
	}
}

int main()
{
	HashTable *ht = new HashTable(1000);
	ht->Add(89);	
	ht->Add(18);	
	ht->Add(49);	
	ht->Add(58);	
	ht->Add(69);
	ht->Add(89);	
	ht->Add(18);	
	ht->Add(49);	
	ht->Add(58);	
	ht->Add(69);
	ht->Print();

	ht->Remove(89);		
	ht->Remove(18);		
	ht->Remove(49);		
	ht->Remove(58);
	ht->Remove(69);
	ht->Print();
	return 0;
}

/*
Values Stored in HashTable are::
Node at index [18 ] :: 18
Node at index [19 ] :: 18
Node at index [49 ] :: 49
Node at index [50 ] :: 49
Node at index [58 ] :: 58
Node at index [59 ] :: 58
Node at index [69 ] :: 69
Node at index [70 ] :: 69
Node at index [89 ] :: 89
Node at index [90 ] :: 89

Values Stored in HashTable are::
Node at index [19 ] :: 18
Node at index [50 ] :: 49
Node at index [59 ] :: 58
Node at index [70 ] :: 69
Node at index [90 ] :: 89
*/