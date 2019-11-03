#include "Calculator.h"

Calculator::Calculator()
{
	value = 0;
}

Calculator::Calculator(int val)
{
	value = val;
}

void Calculator::reset()
{
	value = 0;
}

int Calculator::getValue()
{
	return value;
}

void Calculator::add(int data)
{
	value = value + data;
}

void Calculator::increment()
{
	value += 1;
}

void Calculator::subtract(int data)
{
	value = value - data;
}

void Calculator::decrement()
{
	value -= 1;
}