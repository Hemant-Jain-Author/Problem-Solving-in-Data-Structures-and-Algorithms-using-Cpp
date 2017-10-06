// CircularLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CircularLinkedList.h"

int main()
{
	CircularLinkedList *ll = new CircularLinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	return 0;
}

CircularLinkedList::Node::Node(int v, Node *n)
{
	value = v;
	next = n;
}

CircularLinkedList::Node::Node(int v)
{
	value = v;
	next = nullptr;
}

CircularLinkedList::CircularLinkedList()
{
	list_size = 0;
}

int CircularLinkedList::size()
{
	return list_size;
}

bool CircularLinkedList::isEmpty()
{
	return list_size == 0;
}

int CircularLinkedList::peek()
{
	if (isEmpty())
		throw std::exception("EmptyListException");

	return tail->next->value;
}


void CircularLinkedList::addHead(int value)
{
	Node *temp = new Node(value, nullptr);
	if (isEmpty())
	{
		tail = temp;
		temp->next = temp;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
	}
	list_size++;
}

int CircularLinkedList::removeHead()
{
	Node* delMe;
	if (isEmpty())
	{
		throw std::exception("EmptyListException");
	}
	int value = tail->next->value;
	delMe = tail->next;

	if (tail == tail->next)
		tail = nullptr;
	else
		tail->next = tail->next->next;

	delete delMe;
	list_size--;
	return value;
}

void CircularLinkedList::addTail(int value)
{
	Node *temp = new Node(value, nullptr);
	if (isEmpty())
	{
		tail = temp;
		temp->next = temp;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	list_size++;
}

bool CircularLinkedList::removeNode(int key)
{
	if (isEmpty())
		return false;

	Node *prev = tail;
	Node *curr = tail->next;
	Node *head = tail->next;

	if (curr->value == key) // head and single node case.
	{
		if (curr == curr->next) // single node case
		{
			tail = nullptr;
		}
		else // head case
		{
			tail->next = tail->next->next;
		}
		delete curr;
		return true;
	}

	prev = curr;
	curr = curr->next;

	while (curr != head)
	{
		if (curr->value == key)
		{
			if (curr == tail)
			{
				tail = prev;
			}
			prev->next = curr->next;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}

	return false;
}

CircularLinkedList* CircularLinkedList::copyListReversed()
{
	CircularLinkedList *cl = new CircularLinkedList();
	Node *curr = tail->next;
	Node *head = curr;

	if (curr != nullptr)
	{
		cl->addHead(curr->value);
		curr = curr->next;
	}
	while (curr != head)
	{
		cl->addHead(curr->value);
		curr = curr->next;
	}
	return cl;
}

CircularLinkedList* CircularLinkedList::copyList()
{
	CircularLinkedList *cl = new CircularLinkedList();
	Node *curr = tail->next;
	Node *head = curr;

	if (curr != nullptr)
	{
		cl->addTail(curr->value);
		curr = curr->next;
	}
	while (curr != head)
	{
		cl->addTail(curr->value);
		curr = curr->next;
	}
	return cl;
}

bool CircularLinkedList::isPresent(int data)
{
	Node *temp = tail;
	for (int i = 0; i < list_size; i++)
	{
		if (temp->value == data)
			return true;

		temp = temp->next;
	}
	return false;
}

void CircularLinkedList::freeList()
{
	if (tail == nullptr)
		return;

	Node* curr = tail->next;
	Node* next;
	while (curr != tail)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	delete tail;
	tail = nullptr;
	list_size = 0;
}

void CircularLinkedList::print()
{
	if (isEmpty())
		return;

	Node *temp = tail->next;
	while (temp != tail)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << temp->value;
}