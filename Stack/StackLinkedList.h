
#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Stack
{
private:
    struct Node
    {
        int value = 0;
        Node *next;
        Node(int v, Node *n);
    };
    Node *head = nullptr;
    int stack_size = 0;
public:
    // Stack class API/methods .

    virtual int size();
    virtual bool isEmpty();
    virtual int peek();
    virtual void push(int value);
    virtual int pop();
    virtual void insertAtBottom(int value);
    virtual void print();
};
