#include "stdafx.h"
#include "QueueLL.h"

int main()
{
	Queue q;
	for (int i = 1; i <= 100; i++)
		q.push(i);

	for (int i = 1; i <= 50; i++)
		q.pop();

	q.print();
	return 0;
}

Queue::Node::Node(int v, Node *n)
{
	value = v;
	next = n;
}

int Queue::size()
{
	return queue_size;
}

bool Queue::isEmpty()
{
	return queue_size == 0;
}

int Queue::peek()
{
	if (isEmpty())
		throw std::exception("QueueEmptyException");

	return head->value;
}

void Queue::push(int value)
{
	Node *temp = new Node(value, nullptr);

	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	queue_size++;
}

int Queue::pop()
{
	if (isEmpty())
		throw std::exception("QueueEmptyException");
	
	int value = head->value;
	Node* delMe = head;
	head = head->next;
	delete delMe;
	queue_size--;
	return value;
}

void Queue::print()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		std::wcout << temp->value << std::wstring(L" ");
		temp = temp->next;
	}
}