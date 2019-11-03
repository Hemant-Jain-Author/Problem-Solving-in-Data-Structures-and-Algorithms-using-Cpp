#include "BulbInterface.h"


int Bulb::TotalBulbCount = 0;

Bulb::Bulb()
{
	size = BulbSize::SMALL;
	isOn = false;
	TotalBulbCount++;
}

int Bulb::getBulbCount()
{
	return TotalBulbCount;
}

void Bulb::turnOn()
{
	isOn = true;
}

void Bulb::turnOff()
{
	isOn = false;
}

bool Bulb::isOnFun()
{
	return isOn;
}

AdvanceBulb::AdvanceBulb()
{
	intensity = 0;
}
void AdvanceBulb::setIntersity(int i)
{
	intensity = i;
}
int AdvanceBulb::getIntersity()
{
	return intensity;
}

int main()
{
	Bulb b;
	
	b.setBulbSize(BulbSize::MEDIUM);

	std::cout << "Bulb Size :" << (int)b.getBulfSize() << std::endl;

	std::cout << "bulb is on return : " << b.isOnFun() << std::endl;
	b.turnOn();
	std::cout << "bulb is on return : " << b.isOnFun() << std::endl;

	return 0;
}