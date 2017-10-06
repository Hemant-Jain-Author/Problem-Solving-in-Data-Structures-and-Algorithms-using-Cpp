#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

const std::string text = "Hello, World!";
const double PI = 3.141592653589793;

int main100()
{
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	for (auto n : numbers)
	{
		sum += n;
	}
	std::cout << "Sum is :: " << sum << std::endl;
	return 0;
}

int main200()
{
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	std::cout << "Sum is :: " << sum << std::endl;
	return 0;
}

int main300()
{
	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	int i = 0;
	while (i < numbers.size())
	{
		sum += numbers[i];
		i++;
	}
	std::cout << "Sum is :: " << sum << std::endl;
	return 0;
}

int main400()
{
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = 0;
	int i = 0;
	do {
		sum += numbers[i];
		i++;
	} while (i < numbers.size());
	std::cout << "Sum is :: " << sum << std::endl;
	return 0;
}