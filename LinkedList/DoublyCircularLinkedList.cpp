#include "stdafx.h"
#include "DoublyCircularLinkedList.h"
#include <exception>

int main()
{
	DoublyCircularLinkedList *ll;
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	return 0;
}

DoublyCircularLinkedList::Node::Node(int v, Node *nxt, Node *prv)
{
	value = v;
	next = nxt;
	prev = prv;
}

DoublyCircularLinkedList::Node::Node(int v)
{
	value = v;
	next = this;
	prev = this;
}

DoublyCircularLinkedList::DoublyCircularLinkedList()
{
	list_size = 0;
}

int DoublyCircularLinkedList::size()
{
	return list_size;
}

bool DoublyCircularLinkedList::isEmpty()
{
	return list_size == 0;
}

int DoublyCircularLinkedList::peekHead()
{
	if (isEmpty())
	{
		throw std::exception("EmptyListException");
	}
	return head->value;
}

void DoublyCircularLinkedList::addHead(int value)
{
	Node *newNode = new Node(value);
	if (list_size == 0)
	{
		tail = head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev = newNode;
		newNode->prev->next = newNode;
		head = newNode;
	}
	list_size++;
}

void DoublyCircularLinkedList::addTail(int value)
{
	Node *newNode = new Node(value, nullptr, nullptr);
	if (list_size == 0)
	{
		head = tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->next = tail->next;
		newNode->prev = tail;
		tail->next = newNode;
		newNode->next->prev = newNode;
		tail = newNode;
	}
	list_size++;
}

int DoublyCircularLinkedList::removeHead()
{
	if (list_size == 0)
		throw std::exception("EmptyListException");

	int value = head->value;
	list_size--;

	if (list_size == 0)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return value;
	}

	Node *next = head->next;
	next->prev = tail;
	tail->next = next;
	delete head;
	head = next;
	return value;
}

int DoublyCircularLinkedList::removeTail()
{
	if (list_size == 0)
		throw std::exception("EmptyListException");

	int value = tail->value;
	list_size--;

	if (list_size == 0)
	{
		delete tail;
		head = tail = nullptr;
		return value;
	}

	Node *prev = tail->prev;
	prev->next = head;
	head->prev = prev;
	delete tail;
	tail = prev;
	return value;
}

bool DoublyCircularLinkedList::isPresent(int key)
{
	Node *temp = head;
	if (head == nullptr)
		return false;

	do
	{
		if (temp->value == key)
		{
			return true;
		}
		temp = temp->next;
	} while (temp != head);

	return false;
}

void DoublyCircularLinkedList::freeList()
{
	if (head == nullptr)
		return;

	Node* curr = head->next;
	Node* next;
	while (curr != head)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}

void DoublyCircularLinkedList::print()
{
	if (isEmpty())
		return;

	Node *temp = head;
	do
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	} while (temp != nullptr);
}