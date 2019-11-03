#include "ArrayDemo.h"

int main()
{
	std::vector<int> arr(10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (auto  i = arr.begin();i != arr.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return 0;
}
