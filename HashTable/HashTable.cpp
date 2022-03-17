#include "HashTable.h"

HashTable::HashTable(int tSize) {
	tableSize = tSize;
	Key = std::vector<int>(tSize + 1);
	Value = std::vector<int>(tSize + 1);
	Flag = std::vector<int>(tSize + 1, EMPTY_NODE);
}

int HashTable::computeHash(int key) {
	return key % tableSize;
}

int HashTable::resolverFun(int index) {
	return index;
}

bool HashTable::add(int key, int value) {
	int hashValue = computeHash(key);
	for (int i = 0; i < tableSize; i++) {
		if (Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED) {
			Key[hashValue] = key;
			Value[hashValue] = value;
			Flag[hashValue] = FILLED_NODE;
			return true;
		}
		hashValue += resolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

bool HashTable::add(int value) {
	int key = value;
	return add(key, value);
}

bool HashTable::find(int key) {
	int hashValue = computeHash(key);
	for (int i = 0; i < tableSize; i++) {
		if (Flag[hashValue] == EMPTY_NODE)
			return false;

		if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key)
			return true;

		hashValue += resolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

int HashTable::get(int key) {
	int hashValue = computeHash(key);
	for (int i = 0; i < tableSize; i++) {
		if (Flag[hashValue] == EMPTY_NODE)
			return -1;

		if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key)
			return Value[hashValue];

		hashValue += resolverFun(i);
		hashValue %= tableSize;
	}
	return -1;
}

bool HashTable::remove(int key) {
	int hashValue = computeHash(key);
	for (int i = 0; i < tableSize; i++) {
		if (Flag[hashValue] == EMPTY_NODE)
			return false;

		if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key) {
			Flag[hashValue] = LAZY_DELETED;
			return true;
		}
		hashValue += resolverFun(i);
		hashValue %= tableSize;
	}
	return false;
}

void HashTable::print() {
	std::cout << "HashTable contains :: ";
	for (int i = 0; i < tableSize; i++) {
		if (Flag[i] == FILLED_NODE)
			std::cout << "(" << i << " => " << Value[i] << ") ";
	}
	std::cout << std::endl;
}

int main() {
	HashTable ht(1000);
	ht.add(1, 10);
	ht.add(2, 20);
	ht.add(3, 30);
	ht.print();

	std::cout << "Find key 2 : " << ht.find(2) << std::endl;
	std::cout << "Value at key 2 : " << ht.get(2) << std::endl;

	ht.remove(2);
	std::cout << "After deleting node with key 2.." << std::endl;
	std::cout << "Find key 2 : " << ht.find(2) << std::endl;
	return 0;
}
/*
 HashTable contains :: (1 => 10) (2 => 20) (3 => 30)
 Find key 2 : 1
 Value at key 2 : 20
 After deleting node with key 2..
 Find key 2 : 0
 */
