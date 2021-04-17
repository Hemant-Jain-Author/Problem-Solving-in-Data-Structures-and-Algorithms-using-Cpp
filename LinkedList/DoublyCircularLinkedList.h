#pragma once

#include <string>
#include <iostream>

class DoublyCircularLinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
        Node *prev;
        Node(int v, Node *nxt, Node *prv);
        Node(int v);
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

public:
    DoublyCircularLinkedList();
    virtual int size();
    virtual bool isEmpty();
    virtual void addHead(int value);
    virtual int removeHead();
    // Other Methods.

    virtual int peekHead();
    virtual void addTail(int value);
    virtual int removeTail();
    virtual bool find(int key);
    virtual void freeList();
    virtual void print();
};
