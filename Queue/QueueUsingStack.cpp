#include <string>
#include <stack>
#include <iostream>

class QueueUsingStack {
private:
	std::stack<int> stk1;
	std::stack<int> stk2;

public:
	virtual void add(int value);
	virtual int remove();
};

void QueueUsingStack::add(int value) {
	stk1.push(value);
}

int QueueUsingStack::remove() {
	int value;
	if (stk2.empty() == false) {
		value = stk2.top();
		stk2.pop();
		return value;
	}

	while (stk1.empty() == false) {
		value = stk1.top();
		stk1.pop();
		stk2.push(value);
	}

	value = stk2.top();
	stk2.pop();
	return value;
}

// Testing code.
int main() {
	QueueUsingStack que;
	que.add(1);
	que.add(2);
	que.add(3);
	std::cout << "Queue remove : " << que.remove() << std::endl;
	std::cout << "Queue remove : " << que.remove() << std::endl;
	return 0;
}

/*
Queue remove : 1
Queue remove : 2 
*/
