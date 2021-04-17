// CircularLinkedList.cpp : Defines the entry point for the console application.
//

#include "CircularLinkedList.h"

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
    length = 0;
}

int CircularLinkedList::size()
{
    return length;
}

bool CircularLinkedList::isEmpty()
{
    return length == 0;
}

int CircularLinkedList::peek()
{
    if (isEmpty())
        throw "EmptyListException";

    return tail->next->value;
}

void CircularLinkedList::print()
{
    if (isEmpty())
    {
        std::cout<<"List is empty"<<std::endl;
        return;
    }    

    Node *temp = tail->next;
    while (temp != tail)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << temp->value << std::endl;
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
    length++;
}

int CircularLinkedList::removeHead()
{
    if (isEmpty())
    {
        throw ("EmptyListException");
    }
    int value = tail->next->value;
    Node* delMe = tail->next;

    if (tail == tail->next)
        tail = nullptr;
    else
        tail->next = tail->next->next;

    delete delMe;
    length--;
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
    length++;
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

bool CircularLinkedList::find(int data)
{
    Node *temp = tail;
    for (int i = 0; i < length; i++)
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
    length = 0;
}

int main()
{
    CircularLinkedList *ll = new CircularLinkedList();
    ll->addHead(1);
    ll->addHead(2);
    ll->addHead(3);
    ll->print();
    /*    
    std::cout << "Size is :: " << ll->size() << std::endl;
    std::cout << "IsEmpty :: " << ll->isEmpty() << std::endl;
    std::cout << "Peek :: " << ll->peek() << std::endl;
    /*ll->addTail(4);
    ll->print();
    ll->removeHead();
    ll->print();
    std::cout << "Search List :: " << ll->find(5) << std::endl;
    std::cout << "Search List :: " << ll->find(1) << std::endl;
    ll->removeNode(1);
    ll->print();
    ll->freeList();
    ll->print();
    */
    CircularLinkedList *cl1 = ll->copyList();
    CircularLinkedList *cl2 = ll->copyListReversed();
    cl1->print();
    cl2->print();
    return 0;
}

/*
3 2 1
Size is :: 3
IsEmpty :: 0
Peek :: 3
*/

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