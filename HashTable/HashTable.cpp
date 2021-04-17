#include "HashTable.h"
 
HashTable::HashTable(int tSize)
{
    tableSize = tSize;
    Key = std::vector<int>(tSize + 1);
    Value = std::vector<int>(tSize + 1);
    Flag = std::vector<int>(tSize + 1, EMPTY_NODE);
}

int HashTable::computeHash(int key)
{
    return key % tableSize;
}

int HashTable::resolverFun(int index)
{
    return index;
}

bool HashTable::add(int key, int value)
{
    int hashValue = computeHash(key);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED)
        {
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

bool HashTable::add(int value)
{
    int key = value;
    return add(key, value);
}

bool HashTable::find(int key)
{
    int hashValue = computeHash(key);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
        {
            return false;
        }

        if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key)
        {
            return true;
        }

        hashValue += resolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

int HashTable::get(int key)
{
    int hashValue = computeHash(key);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
        {
            return -1;
        }

        if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key)
        {
            return Value[hashValue];
        }

        hashValue += resolverFun(i);
        hashValue %= tableSize;
    }
    return -1;
}

bool HashTable::remove(int key)
{
    int hashValue = computeHash(key);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
            return false;

        if (Flag[hashValue] == FILLED_NODE && Key[hashValue] == key)
        {
            Flag[hashValue] = LAZY_DELETED;
            return true;
        }
        hashValue += resolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

void HashTable::print()
{
    std::cout << "Values Stored in HashTable are::" << std::endl;
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[i] == FILLED_NODE)
            std::cout << "Node at index [" << i << " ] :: " << Value[i] << std::endl;
    }
}

int main1()
{
    HashTable ht = HashTable(1000);
    ht.add(89, 89);
    ht.add(18, 18);
    ht.add(49);
    ht.add(58);
    ht.add(69);
    ht.print();

    ht.remove(89);
    ht.remove(18);
    ht.remove(49);
    ht.remove(58);
    ht.remove(69);
    ht.print();
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

int main()
{
    HashTable ht = HashTable(1000);
    ht.add(1, 10);
    ht.add(2, 10);
    ht.add(3, 30);
    ht.print();

    std::cout<< "find key 2 : " << ht.find(2) << std::endl;
    std::cout<< "Value at key 2 : " << ht.get(2) << std::endl;

    ht.remove(2);
    std::cout<< "\nAfter deleting node with key 2.." << std::endl;
    std::cout<< "find key 2 : " << ht.find(2) << std::endl;
    return 0;
}
/*
Values Stored in HashTable are::
Node at index [1 ] :: 10
Node at index [2 ] :: 10
Node at index [3 ] :: 30
find key 2 : 1
Value at key 2 : 10

After deleting node with key 2..
find key 2 : 0

*/
