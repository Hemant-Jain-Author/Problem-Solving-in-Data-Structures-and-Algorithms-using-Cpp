#include "DoublyCircularLinkedList.h"
#include <exception>

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
    length = 0;
}

int DoublyCircularLinkedList::size()
{
    return length;
}

bool DoublyCircularLinkedList::isEmpty()
{
    return length == 0;
}

int DoublyCircularLinkedList::peekHead()
{
    if (isEmpty())
    {
        throw ("EmptyListException");
    }
    return head->value;
}

void DoublyCircularLinkedList::addHead(int value)
{
    Node *newNode = new Node(value);
    if (length == 0)
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
    length++;
}

void DoublyCircularLinkedList::addTail(int value)
{
    Node *newNode = new Node(value, nullptr, nullptr);
    if (length == 0)
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
    length++;
}

int DoublyCircularLinkedList::removeHead()
{
    if (length == 0)
        throw ("EmptyListException");

    int value = head->value;
    length--;

    if (length == 0)
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
    if (length == 0)
        throw ("EmptyListException");

    int value = tail->value;
    length--;

    if (length == 0)
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

bool DoublyCircularLinkedList::find(int key)
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
    }
    while (temp != head);

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
    length = 0;
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
    }
    while (temp != head);
    std::cout << std::endl;
}


int main()
{
    DoublyCircularLinkedList *ll = new DoublyCircularLinkedList();;
    ll->addHead(1);
    ll->addHead(2);
    ll->addHead(3);
    ll->print();
        
    std::cout << "Size is :: " << ll->size() << std::endl;
    std::cout << "IsEmpty :: " << ll->isEmpty() << std::endl;
    std::cout << "Peek head :: " << ll->peekHead() << std::endl;

    ll->addTail(4);
    ll->print();
    ll->removeHead();
    ll->print();
    std::cout << "Search List :: " << ll->find(5) << std::endl;
    std::cout << "Search List :: " << ll->find(1) << std::endl;
    ll->freeList();
    ll->print();
    
    return 0;
}

/*
3 2 1 
Size is :: 3
IsEmpty :: 0
Peek head :: 3
3 2 1 4 
2 1 4 
Search List :: 0
Search List :: 1
*/