#include "stdafx.h"

#include <string>
#include <iostream>
#include <list>


int main1()
{
	std::list<int> ll;

	ll.push_front(1);
	ll.push_back(11);
	ll.push_front(2);
	ll.push_back(21);
	ll.push_front(3);
	ll.push_back(31);

	std::cout << "Contents of Linked List: " << std::endl;
	for (auto var : ll)
		std::cout << var << " ";
	std::cout << std::endl;

	ll.pop_front();
	ll.pop_back();

	for (auto var : ll)
		std::cout << var << " ";
	std::cout << std::endl;

	return 0;
}