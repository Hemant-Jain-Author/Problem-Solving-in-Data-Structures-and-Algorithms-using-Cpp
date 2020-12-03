#include <iostream>

class BulbInterface
{
public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual bool isOnFun() = 0;
};

enum class BulbSize
{
	SMALL,
	MEDIUM,
	LARGE
};

// implements BulbInterface
class Bulb : public BulbInterface
{
private:
	// Class Variables
	static int TotalBulbCount;

	// Instance Variables
	bool isOn;

public:
	// Constructor
	Bulb();

	// Class Method
	static int getBulbCount();

	// Instance Method
	virtual void turnOn();

	// Instance Method
	virtual void turnOff();

	// Instance Method
	virtual bool isOnFun();

private:
	// Instance Variables
	BulbSize size;
public:
	// Instance Method
	BulbSize getBulfSize()
	{
		return size;
	}

	// Instance Method
	void setBulbSize(BulbSize s)
	{
		size = s;
	}
};

class AdvanceBulb : public Bulb
{
private:
	// Instance Variables
	int intensity;

public:
	AdvanceBulb();

	// Instance Method
	virtual void setIntersity(int i);

	// Instance Method
	virtual int getIntersity();
};

class Bulb2
{
private:
	// Instance Variables
	bool isOn;

public:
	// Constructor
	Bulb2();

	// Instance Method
	virtual void turnOn();

	// Instance Method
	virtual void turnOff();

	// Instance Method
	virtual bool isOnFun();
};