#include <string>
#include <vector>
#include <iostream>

class Stack {
private:
	int minCapacity;
	int *data;
	int stktop = -1;
	int capacity;

public:
	Stack(int size  = 1000);
	~Stack();
	virtual void push(int value);
	virtual int pop();
	virtual void dynamicPush(int value); // Self growing stack capacity.
	virtual int dynamicPop(); // Self reducing stack capacity.
	
	/* Other methods */
	virtual int size();
	virtual bool isEmpty();
	virtual int top();
	virtual void print();
};
