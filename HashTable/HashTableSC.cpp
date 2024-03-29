#include <string>
#include <vector>
#include <iostream>

class HashTableSC {
private:
	struct Node {
		int key;
		int value;
		Node(int k, int v);
	};

	int tableSize;
	std::vector<std::vector<Node>> listArray;

	int computeHash(int key); // division method

public:
	HashTableSC();
	virtual void add(int value);
	virtual void add(int key, int value);
	virtual bool remove(int key);
	virtual void print();
	virtual bool find(int key);
	virtual int get(int key);
};

HashTableSC::Node::Node(int k, int v) {
	key = k;
	value = v;
}

HashTableSC::HashTableSC() {
	tableSize = 121; // some odd value
	listArray = std::vector < std::vector < Node >> (tableSize);
}

int HashTableSC::computeHash(int key) {
	int hashValue = key;
	return hashValue % tableSize;
}

void HashTableSC::add(int value) {
	add(value, value);
}

void HashTableSC::add(int key, int value) {
	int index = computeHash(key);
	listArray[index].push_back(Node(key, value));
	// find and replace.
}

bool HashTableSC::remove(int key) {
	int hash = computeHash(key);
	std::vector<Node> &lst = listArray[hash];

	for (auto it = lst.begin(); it != lst.end(); it++) {
		if (it->key == key) {
			lst.erase(it);
			return true;
		}
	}
	return false;

}

void HashTableSC::print() {
	std::cout << "HashTable contains :: ";
	for (int i = 0; i < tableSize; i++) {
		std::vector<Node> lst = listArray[i];
		if (lst.size() > 0) {
			for (auto iter : lst) {
				std::cout << "(" << iter.key << " => " << iter.value << ") ";
			}
		}
	}
	std::cout << std::endl;
}

bool HashTableSC::find(int key) {
	int hash = computeHash(key);
	std::vector<Node> lst = listArray[hash];

	for (auto iter : lst) {
		if (iter.key == key)
			return true;
	}
	return false;
}

int HashTableSC::get(int key) {
	int hash = computeHash(key);
	std::vector<Node> lst = listArray[hash];

	for (auto iter : lst) {
		if (iter.key == key)
			return iter.value;
	}
	return -1;
}

// Testing code.
int main() {
	HashTableSC ht = HashTableSC();
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
