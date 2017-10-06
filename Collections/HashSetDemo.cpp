#include "stdafx.h"
#include "HashSetDemo.h"
#include <unordered_set>
#include <set>

int main999()
{
	// Create a hash set.
	std::set<std::string> ts;

	// Add elements to the hash set.
	ts.insert("India");
	ts.insert("USA");
	ts.insert("Brazile");
	ts.insert("Canada");
	ts.insert("UK");
	ts.insert("China");
	ts.insert("France");
	ts.insert("Spain");
	ts.insert("Italy");

	for each (auto var in ts)
	{
		std::cout << var << " ";
	}
	std::cout << std::endl;

	std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) << std::endl;
	std::cout << "Hash Table contains Russia : " << (std::find(ts.begin(), ts.end(), "Russia") != ts.end()) << std::endl;

	ts.erase("USA");
	for each (auto var in ts)
	{
		std::cout << var << " ";
	}
	std::cout << std::endl;
	std::cout << "Hash Table contains USA : " << (std::find(ts.begin(), ts.end(), "USA") != ts.end()) << std::endl;
	return 0;
}

int main897()
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
	
	for each (auto var in hs)
	{
		std::cout << var<< " ";
	}
	std::cout << std::endl;

	std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end()) << std::endl;
	std::cout << "Hash Table contains Russia : "<< (std::find(hs.begin(), hs.end(), "Russia") != hs.end()) << std::endl;

	hs.erase("USA");
	for each (auto var in hs)
	{
		std::cout << var<<" ";
	}
	std::cout << std::endl;
	std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end() )<< std::endl;
	return 0;
}