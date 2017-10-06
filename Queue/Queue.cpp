#include "stdafx.h"
#include "Queue.h"

int main()
{
	Queue que;

	for (int i = 0; i < 20; i++)
		que.add(i);
	
	for (int i = 0; i < 20; i++)
		std::cout << que.remove() << std::endl;
	
	return 0;
}

Queue::Queue()
{
	queue_size = 0;
	data = new int[100];
}

bool Queue::add(int value)
{
	if (queue_size >= Capacity)
	{
		throw std::exception("QueueFullException");
		return false;
	}
	else
	{
		queue_size++;
		data[back] = value;
		back = (++back) % (Capacity - 1);
	}
	return true;
}

int Queue::remove()
{
	int value;
	if (queue_size <= 0)
	{
		throw std::exception("QueueEmptyException");
	}
	else
	{
		queue_size--;
		value = data[front];
		front = (++front) % (Capacity - 1);
	}
	return value;
}

bool Queue::isEmpty()
{
	return queue_size == 0;
}

int Queue::size()
{
	return queue_size;
}