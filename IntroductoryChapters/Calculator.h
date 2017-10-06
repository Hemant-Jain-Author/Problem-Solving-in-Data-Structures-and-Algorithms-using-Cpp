#pragma once

class Calculator
{
private:
	int value = 0;

public:
	Calculator();

	Calculator(int arr);

	virtual void reset();

	virtual int getValue();

	virtual void add(int data);

	virtual void increment();

	virtual void subtract(int data);

	virtual void decrement();
};