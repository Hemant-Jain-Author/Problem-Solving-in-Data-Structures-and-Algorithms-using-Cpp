#include "ArrayDemo.h"

void main()
{
	std::vector<int> arr(10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	std::wcout << arr << std::endl;
}
