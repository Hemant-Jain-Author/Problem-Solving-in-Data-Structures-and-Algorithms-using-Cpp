#include <string>
#include <vector>
#include <iostream>

class HashTableSC
{
private:
    struct Node
    {
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
