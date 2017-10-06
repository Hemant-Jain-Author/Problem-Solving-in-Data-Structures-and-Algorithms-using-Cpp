#include "stdafx.h"
#include "BulbInterface.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, _TCHAR* argv[])
{
	Bulb *b = new Bulb();
	b->size = Bulb::BulbSize::MEDIUM;

	std::cout << "Bulb Size :" << (int)b->size << std::endl;

	std::cout << "bulb is on return : " << b->isOnFun() << std::endl;
	b->turnOn();
	std::cout << "bulb is on return : " << b->isOnFun() << std::endl;
	
	return 0;
}

