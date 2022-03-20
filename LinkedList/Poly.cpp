#include <string>
#include <list>
#include <iostream>
#include <limits>

class Polynomial {
private:
	struct Node {
        int coeff;
        int pow;
        struct Node *next;
        Node(int c, int p);
	};
	Node *head;

public:
	Polynomial(int coeffs[], int pows[], int size);
	virtual void add(Polynomial& poly2);
    virtual void print();
};

Polynomial::Node::Node(int c, int p) {
    coeff = c;
    pow = p;
    next = nullptr;
}

Polynomial::Polynomial(int coeffs[], int pows[], int size){
    head = nullptr;
    Node *tail=nullptr, *temp=nullptr;
    for (int i=0; i < size; i++) {
        temp = new Node(coeffs[i], pows[i]);
        if(head == nullptr)
            head = tail = temp;
        else {
            tail->next = temp;
            tail=tail->next;
        }
    }
}

void Polynomial::add(Polynomial& poly2){
    Node* p1 = head;
    Node* p2 = poly2.head;
    Node* prev;
    Node* temp=nullptr;

    if(p2 == nullptr){
        return;
    } else if (p1 == nullptr || p1->pow < p2->pow) {
        temp = new Node(p2->coeff, p2->pow);
        temp->next = p1;
        head = temp;
        prev = temp;
        p2 = p2->next;
    } else if(p1->pow == p2->pow) {
        p1->coeff = p1->coeff + p2->coeff;
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    } else {
        prev = p1;
        p1 = p1->next;
    }

    while (p1 != nullptr || p2 != nullptr) {
        if (p1 == nullptr || p1->pow < p2->pow) {
            temp = new Node(p2->coeff, p2->pow);
            temp->next = p1;
            prev->next = temp;
            prev = temp;
            p2 = p2->next;
        } else if (p1->pow == p2->pow) {
            p1->coeff = p1->coeff + p2->coeff;
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            prev = p1;
            p1 = p1->next;
        } 
    }
}

void Polynomial::print() {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->coeff;
        if(curr->pow != 0)
            std::cout << "x^" << curr->pow;
        
        if (curr->next != nullptr)
            printf(" + ");
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    int c1[] = { 6, 5, 4 };
    int p1[] = { 2, 1, 0 };
    int s1 = 3;
    Polynomial first = Polynomial(c1, p1, s1);
    first.print();

    int c2[] = { 3, 2, 1 };
    int p2[] = { 3, 1, 0 };
    int s2 = 3;
    Polynomial second = Polynomial(c2, p2, s2);
    second.print();

    first.add(second);
    first.print();
    return 0;
}

/*
6x^2 + 5x^1 + 4
3x^3 + 2x^1 + 1
3x^3 + 6x^2 + 7x^1 + 5
*/