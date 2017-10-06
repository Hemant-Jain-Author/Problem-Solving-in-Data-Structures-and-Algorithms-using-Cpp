#include "ArrayListDemo.h"

void ArrayListDemo::main(std::vector<std::wstring> &args)
{
	std::vector<int> al;

	al.push_back(1);
	al.push_back(2);
	al.push_back(3);
	al.push_back(4);
	std::wcout << std::wstring(L"Contents of Array: ") << al << std::endl;

	al.push_back(2, 9);
	al.push_back(5, 9);
	std::wcout << std::wstring(L"Contents of Array: ") << al << std::endl;

	std::wcout << std::wstring(L"Array Size: ") << al.size() << std::endl;

	std::wcout << std::wstring(L"Array IsEmpty: ") << al.empty() << std::endl;

	al.pop_back();

	std::wcout << std::wstring(L"Array Size: ") << al.size() << std::endl;
	al.removeAll(al);

	std::wcout << std::wstring(L"Array IsEmpty: ") << al.empty() << std::endl;
}
