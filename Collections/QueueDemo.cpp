#include <string>
#include <iostream>

#include <vector>
#include <deque>
#include <queue>

int main1()
{
	std::queue<int> que;
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto i : arr)
	{
		que.push(i);
	}

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		std::cout << que.front() << " ";
		que.pop();
	}
	std::cout << std::endl;

	return 0;
}


int main()
{
	std::deque<int> que;
	std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (auto i : arr)
	{
		que.push_back(i);
	}

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		// cout << que.front() << " ";
		// que.pop_front();  //queue behaviour.

		std::cout << que.back() << " ";
		que.pop_back();  //stack behaviour.
	}
	std::cout << std::endl;

	return 0;
}

