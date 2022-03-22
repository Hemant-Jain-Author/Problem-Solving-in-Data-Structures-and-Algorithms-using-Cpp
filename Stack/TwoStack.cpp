#include "TwoStack.h"

// Testing code.
int main() {
	TwoStack st;
	st.push1(1);
	st.push1(2);
	st.push2(3);
	st.push2(4);
	std::cout << "stack 1 pop value is : " << st.pop1() << std::endl;
	std::cout << "stack 2 pop value is : " << st.pop2() << std::endl;
	return 0;
}

/*
stack 1 pop value is : 2
stack 2 pop value is : 4
*/

TwoStack::TwoStack() {
	top1 = -1;
	top2 = MAX_SIZE;
}

void TwoStack::push1(int value) {
	if (top1 < top2 - 1) {
		data[++top1] = value;
	} else {
		throw("StackFullException");
	}
}

void TwoStack::push2(int value) {
	if (top1 < top2 - 1) {
		data[--top2] = value;
	} else {
		throw("StackFullException");
	}
}

int TwoStack::pop1() {
	if (top1 >= 0) {
		int value = data[top1--];
		return value;
	} else {
		throw("StackEmptyException");
	}
}

int TwoStack::pop2() {
	if (top2 < MAX_SIZE) {
		int value = data[top2++];
		return value;
	} else {
		throw("StackEmptyException");
	}
}
