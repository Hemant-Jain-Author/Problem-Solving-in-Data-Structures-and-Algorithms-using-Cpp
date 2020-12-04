#include "CountMap.h"
#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <limits>

bool isAnagram(std::string &str1, std::string &str2)
{
    int size1 = str1.size();
    int size2 = str2.size();

    if (size1 != size2)
        return false;

    CountMap<char> *cm = new CountMap<char>();

    for (auto ch : str1)
        cm->add(ch);

    for (auto ch : str2)
        cm->remove(ch);

    return (cm->size() == 0);
}

void removeDuplicate(std::string &str)
{
    int index = 0;
    std::unordered_set<char> hs;

    for (auto ch : str)
    {
        if (hs.find(ch) == hs.end())
        {
            str[index++] = ch;
            hs.insert(ch);
        }
    }
    str[index] = '\0';
}

int findMissing(std::vector<int> &arr, int start, int end)
{
    std::unordered_set<int> hs;
    for (auto i : arr)
    {
        hs.insert(i);
    }

    for (int curr = start; curr <= end; curr++)
    {
        if (hs.find(curr) == hs.end())
        {
            return curr;
        }
    }
    return std::numeric_limits<int>::max();
}

void printRepeating(std::vector<int> &arr)
{
    std::unordered_set<int> hs;

    std::cout << "Repeating elements are:";
    for (auto val : arr)
    {
        if (hs.find(val) != hs.end())
        {
            std::cout << val << "  ";
        }
        else
        {
            hs.insert(val);
        }
    }
}

void printFirstRepeating(std::vector<int> &arr)
{
    int i;
    int size = arr.size();
    CountMap<int> *hs = new CountMap<int>();

    for (i = 0; i < size; i++)
    {
        hs->add(arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        hs->remove(arr[i]);
        if (hs->containsKey(arr[i]))
        {
            std::cout << "First Repeating number is : " << arr[i] << std::endl;
            return;
        }
    }
}

int hornerHash(std::vector<char> &key, int tableSize)
{
    int size = key.size();
    int h = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        h = (32 * h + key[i]) % tableSize;
    }
    return h;
}

int main()
{
    std::string var1 = "hello";
    std::string var2 = "elloh";
    std::string var3 = "world";

    std::cout << "isAnagram : " << isAnagram(var1, var2) << std::endl;
    std::cout << "isAnagram : " << isAnagram(var1, var3) << std::endl;

    removeDuplicate(var1);
    for (auto var : var1)
        std::cout << var;
    std::cout << std::endl;

    std::vector<int> arr = { 1, 2, 3, 5, 6, 7, 8, 9, 10 };
    std::cout << findMissing(arr, 1, 10) << std::endl;
    std::cout << std::endl;

    std::vector<int> arr1 = { 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 1 };
    printRepeating(arr1);
    std::cout << std::endl;

    printFirstRepeating(arr1);
    return 0;
}
