#include <string>
#include <vector>
#include <iostream>

class Stack {
private:
	static const int MIN_CAPACITY = 100;
	int *data;
	int stack_top = -1;
	int capacity;

public:
	Stack(int capacity  = MIN_CAPACITY);
	~Stack();
	virtual int size();
	virtual bool isEmpty();
	virtual int top();
	virtual void push(int value);
	virtual int pop();
	virtual void dynamicPush(int value); // Self growing stack capacity.
	virtual int dynamicPop(); // Self reducing stack capacity.
	virtual void print();
};
