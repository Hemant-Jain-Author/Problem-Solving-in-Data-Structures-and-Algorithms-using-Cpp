
#include <algorithm>
#include <iostream>
#include <set>

int main()
{
    // Create a tree set.
    std::set<std::string> ts;

    // Add elements to the ttee set.
    ts.insert("India");
    ts.insert("USA");
    ts.insert("Brazile");
    ts.insert("India");

    for (auto var : ts)
    {
        std::cout << var << " ";
    }
    std::cout << std::endl;

    std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) << std::endl;
    std::cout << "Hash Table contains Russia : " << (std::find(ts.begin(), ts.end(), "Russia") != ts.end()) << std::endl;

    ts.erase("USA");
    for (auto var : ts)
    {
        std::cout << var << " ";
    }
    std::cout << std::endl;
    std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) << std::endl;
    return 0;
}

/*
Brazile India USA 
Hash Table contains USA : 1
Hash Table contains Russia : 0
Brazile India 
Hash Table contains USA : 0
*/

#include <unordered_set>

int main2()
{
    // Create a hash set.
    std::unordered_set<std::string> hs;

    // Add elements to the hash set.
    hs.insert("India");
    hs.insert("USA");
    hs.insert("Brazile");
    hs.insert("India");

    for (auto var : hs)
    {
        std::cout << var<< " ";
    }
    std::cout << std::endl;

    std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end()) << std::endl;
    std::cout << "Hash Table contains Russia : "<< (std::find(hs.begin(), hs.end(), "Russia") != hs.end()) << std::endl;

    hs.erase("USA");
    for (auto var : hs)
    {
        std::cout << var<<" ";
    }
    std::cout << std::endl;
    std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end() )<< std::endl;
    return 0;
}

/*
USA Brazile India 
Hash Table contains USA : 1
Hash Table contains Russia : 0
Brazile India 
Hash Table contains USA : 0
*/