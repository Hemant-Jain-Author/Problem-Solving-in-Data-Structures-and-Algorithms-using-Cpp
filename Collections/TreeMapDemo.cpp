#include "TreeMapDemo.h"

void TreeMapDemo::main(std::vector<std::wstring> &args)
{
	// Create a hash map.
	std::map<std::wstring, int> tm;

	// Put elements into the map
	tm[L"Mason"] = boost::optional<int>(55);
	tm[L"Jacob"] = boost::optional<int>(77);
	tm[L"William"] = boost::optional<int>(99);
	tm[L"Alexander"] = boost::optional<int>(80);
	tm[L"Michael"] = boost::optional<int>(50);
	tm[L"Emma"] = boost::optional<int>(65);
	tm[L"Olivia"] = boost::optional<int>(77);
	tm[L"Sophia"] = boost::optional<int>(88);
	tm[L"Emily"] = boost::optional<int>(99);
	tm[L"Isabella"] = boost::optional<int>(100);

	std::wcout << std::wstring(L"Total number of students in class :: ") << tm.size() << std::endl;
	for (auto key : tm)
	{
		std::wcout << key.first << std::wstring(L" score marks :") << tm[key.first] << std::endl;
	}

	std::wcout << std::wstring(L"Emma present in class :: ") << tm.find(L"Emma") != tm.end() << std::endl;
	std::wcout << std::wstring(L"John present in class :: ") << tm.find(L"John") != tm.end() << std::endl;
	tm.erase(L"Emma");
	std::wcout << std::wstring(L"Emma present in class :: ") << tm.find(L"Emma") != tm.end() << std::endl;

}
