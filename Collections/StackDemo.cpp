#include <string>
#include <iostream>
#include <vector>
#include <stack>

int main()
{
	std::stack<int> stk;
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto i : arr)
	{
		stk.push(i);
	}

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;

	return 0;
}