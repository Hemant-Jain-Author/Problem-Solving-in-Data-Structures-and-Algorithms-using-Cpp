#pragma once
#include <string>
#include <iostream>

class DoublyLinkedList
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

    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList();
    virtual int size();
    virtual bool isEmpty();
    virtual void addHead(int value);
    virtual int removeHead();
    // Other methods.

    virtual int peek();
    virtual void addTail(int value);
    virtual bool removeNode(int key);
    virtual bool find(int key);
    virtual void freeList();
    virtual void print();
    virtual void sortedInsert(int value);
    virtual void reverseList();
    virtual void removeDuplicate();
    virtual void copyListReversed(DoublyLinkedList&);
    virtual void copyList(DoublyLinkedList&);
};
