#include "DoublyLinkedList.h"
#include <exception>

int main()
{
    DoublyLinkedList *ll = new DoublyLinkedList();
    ll->addHead(1);
    ll->addHead(2);
    ll->addHead(3);
    ll->print();
        
    std::cout << "Size is :: " << ll->size() << std::endl;
    std::cout << "IsEmpty :: " << ll->isEmpty() << std::endl;
    std::cout << "Peek :: " << ll->peek() << std::endl;

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
Peek :: 3
3 2 1 4 
2 1 4 
Search List :: 0
Search List :: 1
*/

DoublyLinkedList::Node::Node(int v, Node *nxt, Node *prv)
{
    value = v;
    next = nxt;
    prev = prv;
}

DoublyLinkedList::Node::Node(int v)
{
    value = v;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
    length = 0;
}

int DoublyLinkedList::size()
{
    return length;
}

bool DoublyLinkedList::isEmpty()
{
    return length == 0;
}

int DoublyLinkedList::peek()
{
    if (isEmpty())
        throw ("EmptyListException");

    return head->value;
}

void DoublyLinkedList::addHead(int value)
{
    Node *newNode = new Node(value, nullptr, nullptr);
    if (length == 0)
    {
        tail = head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void DoublyLinkedList::addTail(int value)
{
    Node *newNode = new Node(value, nullptr, nullptr);
    if (length == 0)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

int DoublyLinkedList::removeHead()
{
    if (isEmpty())
        throw ("EmptyListException");
    Node* deleteMe;
    int value = head->value;
    deleteMe = head;
    head = head->next;

    if (head == nullptr)
    {
        tail = nullptr;
    }
    else
    {
        head->prev = nullptr;
    }
    delete deleteMe;
    length--;
    return value;
}

bool DoublyLinkedList::removeNode(int key)
{
    Node *curr = head;
    Node *deleteMe;
    if (curr == nullptr) // empty list
        return false;

    if (curr->value == key) // head is the node with value key.
    {
        deleteMe = curr;
        curr = curr->next;
        delete deleteMe;
        length--;
        if (curr != nullptr)
        {
            head = curr;
            head->prev = nullptr;
        }
        else
            tail = nullptr; // only one element in list.

        return true;
    }

    while (curr->next != nullptr)
    {
        if (curr->next->value == key)
        {
            deleteMe = curr->next;
            curr->next = curr->next->next;
            if (curr->next == nullptr) // last element case.
                tail = curr;
            else
                curr->next->prev = curr;
            delete deleteMe;
            length--;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool DoublyLinkedList::find(int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == key)
            return true;

        temp = temp->next;
    }
    return false;
}

void DoublyLinkedList::freeList()
{
    Node* curr = head;
    Node* next;
    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
    tail = head = nullptr;
    length = 0;
}

void DoublyLinkedList::print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value << std::string(" ");
        temp = temp->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::sortedInsert(int value)
{
    Node *temp = new Node(value);
    Node *curr = head;
    if (curr == nullptr) // first element
    {
        head = temp;
        tail = temp;
    }
    if (head->value <= value) // at the begining
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    while (curr->next != nullptr && curr->next->value > value) // treversal
    {
        curr = curr->next;
    }
    if (curr->next == nullptr) // at the end
    {
        tail = temp;
        temp->prev = curr;
        curr->next = temp;
    }
    else /// all other
    {
        temp->next = curr->next;
        temp->prev = curr;
        curr->next = temp;
        temp->next->prev = temp;
    }
}

void DoublyLinkedList::reverseList()
{
    Node *curr = head;
    Node *tempNode;
    while (curr != nullptr)
    {
        tempNode = curr->next;
        curr->next = curr->prev;
        curr->prev = tempNode;
        if (curr->prev == nullptr)
        {
            tail = head;
            head = curr;
            return;
        }
        curr = curr->prev;
    }
    return;
}

void DoublyLinkedList::removeDuplicate()
{
    Node *curr = head;
    Node *deleteMe;
    while (curr != nullptr)
    {
        if ((curr->next != nullptr) && curr->value == curr->next->value)
        {
            deleteMe = curr->next;
            curr->next = deleteMe->next;
            curr->next->prev = curr;
            if (deleteMe == tail)
            {
                tail = curr;
            }
            delete deleteMe;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void DoublyLinkedList::copyListReversed(DoublyLinkedList& dll)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        dll.addHead(curr->value);
        curr = curr->next;
    }
}

void DoublyLinkedList::copyList(DoublyLinkedList& dll)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        dll.addTail(curr->value);
        curr = curr->next;
    }
}
