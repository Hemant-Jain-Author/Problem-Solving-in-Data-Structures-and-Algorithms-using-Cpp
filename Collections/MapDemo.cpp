#include <iostream>
#include <map>

int main1() {
	// Create a tree map.
	std::map<std::string, int> tm;

	// Put elements into the map
	tm["Apple"] = 100;
	tm["Mango"] = 50;
	tm["Banana"] = 40;

	std::cout << "Total number of elements in map :: " << tm.size() << std::endl;
	
	std::cout << "Map : ";
	for (auto key : tm) {
		std::cout << "[" << key.first << " @ " << tm[key.first] << "] ";
	}
	std::cout << std::endl;

	auto temp = tm.find("Banana") != tm.end();
	std::cout << "Banana in fruits :: " << temp << std::endl;
	auto result = tm.find("Grapes") != tm.end();
	std::cout << "Grapes in furits :: " << result << std::endl;
	return 0;
}
/*
Total number of elements in map :: 3
Map : [Apple @ 100] [Banana @ 40] [Mango @ 50] 
Banana in fruits :: 1
Grapes in furits :: 0
 */

#include <unordered_map>
int main2() {
	// Create a hash map.
	std::unordered_map<std::string, int> hm;

	// Put elements into the map
	hm["Apple"] = 100;
	hm["Mango"] = 50;
	hm["Banana"] = 40;

	std::cout << "Total number of elements in map :: " << hm.size() << std::endl;

	std::cout << "Map : ";
	for (auto key : hm) {
		std::cout << "[" << key.first << " @ " << hm[key.first] << "] ";
	}
	std::cout << std::endl;

	auto temp = hm.find("Banana") != hm.end();
	std::cout << "Banana in fruits :: " << temp << std::endl;
	auto result = hm.find("Grapes") != hm.end();
	std::cout << "Grapes in furits :: " << result << std::endl;
	return 0;
}

/*
Total number of elements in map :: 3
Map : [Banana @ 40] [Mango @ 50] [Apple @ 100] 
Banana in fruits :: 1
Grapes in furits :: 0
*/

int main(){
	main1();
	main2();
	return 0;
}