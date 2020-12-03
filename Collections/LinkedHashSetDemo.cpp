#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

int main()
{
	// Create a hash set.
	std::unordered_set<std::string> hs;
	// Add elements to the hash set.
	hs.insert("India");
	hs.insert("USA");
	hs.insert("Brazile");
	hs.insert("Canada");
	hs.insert("UK");
	hs.insert("China");
	hs.insert("France");
	hs.insert("Spain");
	hs.insert("Italy");
	std::cout << "HashSet value:: ";
	for (auto i : hs)
		std::cout << i << " ";
	std::cout << std::endl;
}
