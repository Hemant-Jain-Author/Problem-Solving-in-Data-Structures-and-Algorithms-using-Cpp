#include <algorithm>
#include <iostream>
#include <set>

int main1() {
	// Create a tree set.
	std::set < std::string > ts;

	// Add elements to the tree set.
	ts.insert("Banana");
	ts.insert("Apple");
	ts.insert("Mango");

	std::cout << "Set : ";
	for (auto var : ts)
		std::cout << var << " ";
	std::cout << std::endl;

	std::cout << "Apple present : " << (ts.find("Apple") != ts.end()) << std::endl;
	std::cout << "Grapes present : " << (ts.find("Grapes") != ts.end()) << std::endl;

	ts.erase("Apple");
	std::cout << "Apple present : " << (ts.find("Apple") != ts.end()) << std::endl;
	return 0;
}

/*
Set : Apple Banana Mango 
Apple present : 1
Grapes present : 0
Apple present : 0
*/

#include <unordered_set>

int main2() {
	// Create a hash set.
	std::unordered_set < std::string > hs;

	// Add elements to the hash set.
	hs.insert("Banana");
	hs.insert("Apple");
	hs.insert("Mango");

	std::cout << "Set : ";
	for (auto var : hs)
		std::cout << var << " ";
	std::cout << std::endl;

	std::cout << "Apple present : " << (hs.find("Apple") != hs.end()) << std::endl;
	std::cout << "Grapes present : " << (hs.find("Grapes") != hs.end()) << std::endl;

	hs.erase("Apple");
	std::cout << "Apple present : " << (hs.find("Apple") != hs.end()) << std::endl;
	return 0;
}

/*
Set : Mango Apple Banana 
Apple present : 1
Grapes present : 0
Apple present : 0
*/

int main(){
	main1();
	main2();
	return 0;
}
