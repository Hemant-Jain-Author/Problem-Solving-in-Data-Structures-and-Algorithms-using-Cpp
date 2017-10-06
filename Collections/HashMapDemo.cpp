#include "stdafx.h"
#include "HashMapDemo.h"
#include <iostream>

#include <map>

int main454()
{
	// Create a hash map.
	std::map<std::string, int> tm;

	// Put elements into the map
	tm["Mason"] = 55;
	tm["Jacob"] = 77;
	tm["William"] = 99;
	tm["Alexander"] = 80;
	tm["Michael"] = 50;
	tm["Emma"] = 65;
	tm["Olivia"] = 77;
	tm["Sophia"] = 88;
	tm["Emily"] = 99;
	tm["Isabella"] = 100;

	std::cout << "Total number of students in class :: " << tm.size() << std::endl;
	for (auto key : tm)
	{
		std::cout << key.first << " score marks :" << tm[key.first] << std::endl;
	}
	auto temp = tm.find("Emma") != tm.end();
	std::cout << "Emma present in class :: " << temp << std::endl;
	auto result = tm.find("John") != tm.end();
	std::cout << "John present in class :: " << result << std::endl;
	return 0;
}

#include <unordered_map>
int main()
{
	// Create a hash map.
	std::unordered_map<std::string, int> hm;

	// Put elements into the map
	hm["Mason"] = 55;
	hm["Jacob"] = 77;
	hm["William"] = 99;
	hm["Alexander"] = 80;
	hm["Michael"] = 50;
	hm["Emma"] = 65;
	hm["Olivia"] = 77;
	hm["Sophia"] = 88;
	hm["Emily"] = 99;
	hm["Isabella"] = 100;

	std::cout << "Total number of students in class :: " << hm.size() << std::endl;
	for (auto key : hm)
	{
		std::cout << key.first << (" score marks :") << hm[key.first] << std::endl;
	}
    auto temp = hm.find("Emma") != hm.end();
	std::cout << "Emma present in class :: " << temp << std::endl;
	auto result = hm.find("John") != hm.end();
	std::cout <<"John present in class :: " << result << std::endl;
	return 0;
}