#include <iostream>
#include <vector>

using namespace std;

struct node{
	int value;
	int min;
};

class Stack{
private:
	vector<node> arr;
	int top;
	int count;
public:
	Stack()
	{
		top=-1;
		count=0;
	}

	void push(int value);
	bool pop(int& value);
	bool Min(int& min);
	void print()
	{

		for(int i=0;i<count;i++)
			cout << arr[i].value << arr[i].min << endl;
	}
};

void Stack::push(int value)
{
	int min;
	if(top == -1)
	{
		min=value;
	}
	else
	{
		min = (arr[top].min < value ) ? arr[top].min : value;
	}
	node n;
	n.value=value;
	n.min=min;

	arr.push_back(n);
	
	top++;
	count++;

	cout << "push value is " << value << endl;
}

bool Stack::pop(int& value)
{
	if(top == -1)
		return false;
	value = arr[top].value;

	top--;
	count--;
	
	cout<< "pop value is " << value << endl;
	return true;
}

bool Stack::Min(int& min)
{
	if(top == -1)
		return false;
	min = arr[top].min;
	cout<< "Min value is " << min << endl;
	return true;
}

int main9()
{
	Stack s;
	int value;

	s.push(100);
	s.push(101);
	s.Min(value);
	s.push(102);
	s.push(11);
	s.Min(value);
	s.push(100);
	s.push(10);
	s.Min(value);
	s.push(101);
	s.Min(value);
	s.push(102);
	s.pop(value);
	s.Min(value);
	s.pop(value);
	s.pop(value);
	s.pop(value);
	s.pop(value);
	s.Min(value);
	s.pop(value);
	s.pop(value);

	return 0;
}
