
#include <string>
#include <vector>
#include <iostream>

enum FLAGS 
{   EMPTY_NODE = 0, 
    LAZY_DELETED = 1, 
    FILLED_NODE = 2
};

class HashTable
{
private:
    std::vector<int> Key;
    std::vector<int> Value;
    std::vector<int> Flag;
    int tableSize = 0;
    virtual int computeHash(int key);
    virtual int resolverFun(int index);

public:
    HashTable(int tSize);
    virtual bool add(int key, int value);
    virtual bool add(int value);
    virtual bool find(int key);
    virtual int get(int key);
    virtual bool remove(int key);
    virtual void print();
};
