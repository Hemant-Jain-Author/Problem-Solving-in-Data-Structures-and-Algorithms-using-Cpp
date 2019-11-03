#pragma once

class OuterClass
{
private:
	class NestedClass
	{
		// NestedClass fields and methods.
	};

	// OuterClass fields and methods.
};


#pragma once

class LinkedList
{

private:
	class Node
	{
	private:
		int value;
		Node *next;
		// Nested Class Node other fields and methods.

	};

private:
	Node *head;
	int size;
	// Outer Class LinkedList other fields and methods.
};



class Tree
{

private:
	class Node
	{
	private:
		int value = 0;
		Node *lChild;
		Node *rChild;
		// Nested Class Node other fields and methods.	
	};

private:
	Node *root;
	// Outer Class Tree other fields and methods.
};