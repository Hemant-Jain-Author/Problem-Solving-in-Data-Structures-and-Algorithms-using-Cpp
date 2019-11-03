#include "BulbInterface.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	Bulb *b = new Bulb();
	b->size = Bulb::BulbSize::MEDIUM;

	std::cout << "Bulb Size :" << (int)b->size << std::endl;

	std::cout << "bulb is on return : " << b->isOnFun() << std::endl;
	b->turnOn();
	std::cout << "bulb is on return : " << b->isOnFun() << std::endl;
	
	return 0;
}

