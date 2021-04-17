#include "HashTableSC.h"

int main()
{
    HashTableSC ht = HashTableSC();
    ht.add(1, 10);
    ht.add(2, 10);
    ht.add(3, 30);
    ht.print();

    std::cout<< "find key 2 : " << ht.find(2) << std::endl;
    std::cout<< "Value at key 2 : " << ht.get(2) << std::endl;

    ht.remove(2);
    std::cout<< "After deleting node with key 2." << std::endl;
    std::cout<< "find key 2 : " << ht.find(2) << std::endl;
    return 0;
}

/*
Printing for index [ 1 ] are :: (1,10) 
Printing for index [ 2 ] are :: (2,10) 
Printing for index [ 3 ] are :: (3,30) 
find key 2 : 1
Value at key 2 : 10
After deleting node with key 2.
find key 2 : 0
*/

HashTableSC::Node::Node(int k, int v)
{
    key = k;
    value = v;
}

HashTableSC::HashTableSC()
{
    tableSize = 23;// some odd value
    listArray = std::vector<std::vector<Node>>(tableSize);
}

int HashTableSC::computeHash(int key)
{
    int hashValue = key;
    return hashValue % tableSize;
}

void HashTableSC::add(int value)
{
    add(value, value);
}

void HashTableSC::add(int key, int value)
{
    int index = computeHash(key);
    listArray[index].push_back(Node(key, value));
    // find and replace.
}

bool HashTableSC::remove(int key)
{
    int hash = computeHash(key);
    std::vector<Node> &lst = listArray[hash];

    for(auto it=lst.begin(); it != lst.end() ; it++)
    {
        if(it->key == key)
        {
            lst.erase(it);
            return true;
        }
    }
    return false;

}

void HashTableSC::print()
{
    for (int i = 0; i < tableSize; i++)
    {
        std::vector<Node> lst = listArray[i];
        if(lst.size() > 0)
        {
            std::cout << "Printing for index [ " << i << " ] are :: ";
            for(auto iter : lst)
            {
                std::cout <<"("<< iter.key <<","<< iter.value << ") ";
            }
            std::cout<< std::endl;
        }
    }

}

bool HashTableSC::find(int key)
{
    int hash = computeHash(key);
    std::vector<Node> lst = listArray[hash];

    for(auto iter : lst)
    {
        if(iter.key == key)
            return true;
    }
    return false;
}

int HashTableSC::get(int key)
{
    int hash = computeHash(key);
    std::vector<Node> lst = listArray[hash];

    for(auto iter : lst)
    {
        if(iter.key == key)
            return iter.value;
    }
    return -1;
}
