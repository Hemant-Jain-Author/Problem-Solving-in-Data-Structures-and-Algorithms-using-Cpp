#include "StackLinkedList.h"
#include <exception>

Stack::Node::Node(int v, Node *n)
{
	value = v;
	next = n;
}

int Stack::size()
{
	return stack_size;
}

bool Stack::isEmpty()
{
	return stack_size == 0;
}

int Stack::peek()
{
	if (isEmpty())
		throw  std::exception("StackEmptyException");

	return head->value;
}

void Stack::push(int value)
{
	head = new Node(value, head);
	stack_size++;
}

int Stack::pop()
{
	if (isEmpty())
		throw  std::exception("StackEmptyException");

	int value = head->value;
	Node* delMe = head;
	head = head->next;
	delete delMe;
	stack_size--;
	return value;
}

void Stack::insertAtBottom(int value)
{
	if (isEmpty())
	{
		push(value);
	}
	else
	{
		int temp = pop();
		insertAtBottom(value);
		push(temp);
	}
}

void Stack::print()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
}

int main()
{
	Stack s;
	for (int i = 1; i <= 100; i++)
		s.push(i);
	
	for (int i = 1; i <= 50; i++)
		s.pop();
	
	s.print();
}