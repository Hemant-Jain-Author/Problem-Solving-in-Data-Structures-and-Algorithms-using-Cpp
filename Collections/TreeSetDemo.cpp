#include <string>
#include <vector>
#include <set>
#include <iostream>

int main()
{
    // Create a tree set.
    std::set<std::string> ts;
    // Add elements to the tree set.
    ts.insert("India");
    ts.insert("USA");
    ts.insert("Brazile");
    ts.insert("Canada");
    ts.insert("UK");
    ts.insert("China");
    ts.insert("France");
    ts.insert("Spain");
    ts.insert("Italy");
    for (auto i : ts)
        std::cout << i << std::endl;
}
