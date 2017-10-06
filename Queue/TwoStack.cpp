#include "stdafx.h"
#include "TwoStack.h"

int main()
{
	TwoStack st;
	for (int i = 0; i < 10; i++)
		st.StackPush1(i);
	
	for (int j = 0; j < 10; j++)
		st.StackPush2(j + 10);
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << "stack one pop value is : " << st.StackPop1() << std::endl;
		std::cout << "stack two pop value is : " << st.StackPop2() << std::endl;
	}
	return 0;
}

TwoStack::TwoStack()
{
	top1 = -1;
	top2 = MAX_SIZE;
}

void TwoStack::StackPush1(int value)
{
	if (top1 < top2 - 1)
	{
		data[++top1] = value;
	}
	else
	{
		throw std::exception("StackFullException");
	}
}

void TwoStack::StackPush2(int value)
{
	if (top1 < top2 - 1)
	{
		data[--top2] = value;
	}
	else
	{
		throw std::exception("StackFullException");
	}
}

int TwoStack::StackPop1()
{
	if (top1 >= 0)
	{
		int value = data[top1--];
		return value;
	}
	else
	{
		throw std::exception("StackEmptyException");
	}
}

int TwoStack::StackPop2()
{
	if (top2 < MAX_SIZE)
	{
		int value = data[top2++];
		return value;
	}
	else
	{
		throw std::exception("StackEmptyException");
	}
}