#include "LinkedHashSetDemo.h"

void LinkedHashSetDemo::main(std::vector<std::wstring> &args)
{
	// Create a hash set.
	std::unordered_set<std::string> hs;
	// Add elements to the hash set.
	hs.insert(L"India");
	hs.insert(L"USA");
	hs.insert(L"Brazile");
	hs.insert(L"Canada");
	hs.insert(L"UK");
	hs.insert(L"China");
	hs.insert(L"France");
	hs.insert(L"Spain");
	hs.insert(L"Italy");
	std::wcout << std::wstring(L"HashSet value:: ") << hs << std::endl;
}
