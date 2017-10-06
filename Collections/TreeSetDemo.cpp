#include "TreeSetDemo.h"

void TreeSetDemo::main(std::vector<std::wstring> &args)
{
	// Create a tree set.
	std::set<std::wstring> ts;
	// Add elements to the tree set.
	ts.insert(L"India");
	ts.insert(L"USA");
	ts.insert(L"Brazile");
	ts.insert(L"Canada");
	ts.insert(L"UK");
	ts.insert(L"China");
	ts.insert(L"France");
	ts.insert(L"Spain");
	ts.insert(L"Italy");
	std::wcout << ts << std::endl;
}
