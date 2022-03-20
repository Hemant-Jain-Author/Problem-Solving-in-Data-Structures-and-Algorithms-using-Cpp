#include "LinkedList.h"
#include <exception>

LinkedList::Node::Node(int v, Node *n) {
	value = v;
	next = n;
}

LinkedList::LinkedList(){
	head = nullptr;
	length = 0;
}

int LinkedList::size() {
	return length;
}

bool LinkedList::isEmpty() {
	return length == 0;
}

int LinkedList::peekHead() {
	if (isEmpty()) {
		throw("EmptyListException");
	}
	return head->value;
}

void LinkedList::addHead(int value) {
	head = new Node(value, head);
	length++;
}

void LinkedList::addTail(int value) {
	Node *newNode = new Node(value);
	Node *curr = head;

	if (head == nullptr)
		head = newNode;

	while (curr->next != nullptr)
		curr = curr->next;

	curr->next = newNode;
}

void LinkedList::print() {
	Node *temp = head;
	while (temp != nullptr) {
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

int LinkedList::removeHead() {
	if (isEmpty()) {
		throw("EmptyListException");
	}
	Node *deleteMe = head;
	int value = head->value;
	head = head->next;
	length--;
	delete deleteMe;
	return value;
}

bool LinkedList::find(int data) {
	Node *temp = head;
	while (temp != nullptr) {
		if (temp->value == data) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool LinkedList::deleteNode(int delValue) {
	Node *temp = head;
	Node *deleteMe;
	if (isEmpty())
		throw("EmptyListException");

	if (delValue == head->value) {
		deleteMe = head;
		head = head->next;
		length--;
		delete deleteMe;
		return true;
	}

	while (temp->next != nullptr) {
		if (temp->next->value == delValue) {
			deleteMe = temp->next;
			temp->next = temp->next->next;
			length--;
			delete deleteMe;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void LinkedList::deleteNodes(int delValue) {
	Node *currNode = head;
	Node *nextNode;
	Node *deleteMe;
	while (currNode != nullptr && currNode->value == delValue) // first node
	{
		deleteMe = head;
		head = currNode->next;
		currNode = head;
		delete deleteMe;
	}

	while (currNode != nullptr) {
		nextNode = currNode->next;
		if (nextNode != nullptr && nextNode->value == delValue) {
			deleteMe = currNode->next;
			currNode->next = nextNode->next;
			delete deleteMe;
		} else
			currNode = nextNode;
	}
}

LinkedList::Node* LinkedList::reverseRecurseUtil(Node *currentNode,
		Node *nextNode) {
	Node *ret;
	if (currentNode == nullptr) {
		return nullptr;
	}
	if (currentNode->next == nullptr) {
		currentNode->next = nextNode;
		return currentNode;
	}

	ret = reverseRecurseUtil(currentNode->next, currentNode);
	currentNode->next = nextNode;
	return ret;
}

void LinkedList::reverseRecurse() {
	head = reverseRecurseUtil(head, nullptr);
}

void LinkedList::reverse() {
	Node *curr = head;
	Node *prev = nullptr;
	Node *next = nullptr;
	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

LinkedList* LinkedList::copyListReversed() {
	Node *tempNode = nullptr;
	Node *tempNode2 = nullptr;
	Node *curr = head;
	while (curr != nullptr) {
		tempNode2 = new Node(curr->value, tempNode);
		curr = curr->next;
		tempNode = tempNode2;
	}
	LinkedList *ll2 = new LinkedList();
	ll2->head = tempNode;
	return ll2;
}

LinkedList* LinkedList::copyList() {
	Node *headNode = nullptr;
	Node *tailNode = nullptr;
	Node *tempNode = nullptr;
	Node *curr = head;

	if (curr == nullptr) {
		LinkedList *ll2 = new LinkedList();
		ll2->head = nullptr;
		return ll2;
	}

	headNode = new Node(curr->value);
	tailNode = headNode;
	curr = curr->next;

	while (curr != nullptr) {
		tempNode = new Node(curr->value);
		tailNode->next = tempNode;
		tailNode = tempNode;
		curr = curr->next;
	}
	LinkedList *ll2 = new LinkedList();
	ll2->head = headNode;
	return ll2;
}

bool LinkedList::compareList(LinkedList *ll) {
	return compareList(head, ll->head);
}

bool LinkedList::compareList(Node *head1, Node *head2) {
	if (head1 == nullptr && head2 == nullptr) {
		return true;
	} else if ((head1 == nullptr) || (head2 == nullptr)
			|| (head1->value != head2->value)) {
		return false;
	} else {
		return compareList(head1->next, head2->next);
	}
}

bool LinkedList::compareList2(LinkedList *ll) {
	return compareList2(head, ll->head);
}

bool LinkedList::compareList2(Node *head1, Node *head2) {
	while (head1 != nullptr && head2 != nullptr) {
		if (head1->value != head2->value)
			return false;

		head1 = head1->next;
		head2 = head2->next;
	}
	if (head1 == nullptr && head2 == nullptr) {
		return true;
	}
	return false;
}

int LinkedList::findLength() {
	Node *curr = head;
	int count = 0;
	while (curr != nullptr) {
		count++;
		curr = curr->next;
	}
	return count;
}

int LinkedList::nthNodeFromBegining(int index) {
	if (index > size() || index < 1) {
		throw("TooFewNodes");
	}
	int count = 0;
	Node *curr = head;
	while (curr != nullptr && count < index - 1) {
		count++;
		curr = curr->next;
	}
	return curr->value;
}

int LinkedList::nthNodeFromEnd(int index) {
	int size = findLength();
	int startIndex;
	if (size != 0 && size < index) {
		throw("TooFewNodes");
	}
	startIndex = size - index + 1;
	return nthNodeFromBegining(startIndex);
}

int LinkedList::nthNodeFromEnd2(int index) {
	int count = 1;
	Node *forward = head;
	Node *curr = head;
	while (forward != nullptr && count <= index) {
		count++;
		forward = forward->next;
	}

	if (forward == nullptr) {
		throw("TooFewNodes");
	}

	while (forward != nullptr) {
		forward = forward->next;
		curr = curr->next;
	}
	return curr->value;
}

LinkedList::Node* LinkedList::findIntersection(Node *head, Node *head2) {
	int l1 = 0;
	int l2 = 0;
	Node *tempHead = head;
	Node *tempHead2 = head2;
	while (tempHead != nullptr) {
		l1++;
		tempHead = tempHead->next;
	}
	while (tempHead2 != nullptr) {
		l2++;
		tempHead2 = tempHead2->next;
	}

	int diff;
	if (l1 < 12) {
		Node *temp = head;
		head = head2;
		head2 = temp;
		diff = l2 - l1;
	} else {
		diff = l1 - l2;
	}

	for (; diff > 0; diff--) {
		head = head->next;
	}
	while (head != head2) {
		head = head->next;
		head2 = head2->next;
	}

	return head;
}

void LinkedList::freeList() {
	Node *curr = head;
	Node *next;
	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	head = nullptr;
	length = 0;
}

void LinkedList::sortedInsert(int value) {
	Node *newNode = new Node(value);
	Node *curr = head;

	if (curr == nullptr || curr->value > value) {
		newNode->next = head;
		head = newNode;
		return;
	}
	while (curr->next != nullptr && curr->next->value < value) {
		curr = curr->next;
	}

	newNode->next = curr->next;
	curr->next = newNode;
}

void LinkedList::removeDuplicate() {
	Node *curr = head;
	Node *deleteMe;
	while (curr != nullptr) {
		if (curr->next != nullptr && curr->value == curr->next->value) {
			deleteMe = curr->next;
			curr->next = curr->next->next;
			delete deleteMe;
		} else {
			curr = curr->next;
		}
	}
}

void LinkedList::makeLoop() {
	Node *temp = head;
	while (temp != nullptr) {
		if (temp->next == nullptr) {
			temp->next = head;
			return;
		}
		temp = temp->next;
	}
}

bool LinkedList::loopDetect() {
	Node *slowPtr;
	Node *fastPtr;
	slowPtr = fastPtr = head;

	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr) {
			std::cout << "loop found" << std::endl;
			return true;
		}
	}
	std::cout << "loop not found" << std::endl;
	return false;
}

bool LinkedList::reverseListLoopDetect() {
	Node *tempHead = head;
	reverse();
	if (tempHead == head) {
		reverse();
		std::cout << "loop found" << std::endl;
		return true;
	} else {
		reverse();
		std::cout << "loop not found" << std::endl;
		return false;
	}
}

int LinkedList::loopTypeDetect() {
	Node *slowPtr;
	Node *fastPtr;
	slowPtr = fastPtr = head;

	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
		if (head == fastPtr->next || head == fastPtr->next->next) {
			std::cout << "circular list loop found" << std::endl;
			return 2;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr) {
			std::cout << "loop found" << std::endl;

			return 1;
		}
	}
	std::cout << "loop not found" << std::endl;
	return 0;
}

LinkedList::Node* LinkedList::loopPointDetect() {
	Node *slowPtr;
	Node *fastPtr;
	slowPtr = fastPtr = head;

	while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr) {
			return slowPtr;
		}
	}
	return nullptr;
}

void LinkedList::removeLoop() {
	Node *loopPoint = loopPointDetect();
	if (loopPoint == nullptr) {
		return;
	}

	Node *firstPtr = head;
	if (loopPoint == head) {
		while (firstPtr->next != head) {
			firstPtr = firstPtr->next;
		}
		firstPtr->next = nullptr;
		return;
	}

	Node *secondPtr = loopPoint;
	while (firstPtr->next != secondPtr->next) {
		firstPtr = firstPtr->next;
		secondPtr = secondPtr->next;
	}
	secondPtr->next = nullptr;
}

// Testing code.
int main1() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	std::cout << "size : " << ll->size() << std::endl;
 	std::cout << "isEmpty : " << ll->isEmpty() << std::endl;
 	std::cout << "peek : " << ll->peekHead() << std::endl;
	return 0;
}
/*
3 2 1 
size : 3
isEmpty : 0
peek : 3
 */

// Testing code.
int main2() {
	LinkedList *ll = new LinkedList();
	ll->sortedInsert(2);
	ll->sortedInsert(1);
	ll->sortedInsert(3);
	ll->print();
	return 0;
}
/*
1 2 3 
 */

// Testing code.
int main3() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	std::cout << "Find : " << ll->find(4) << std::endl;
	std::cout << "Find : " << ll->find(2) << std::endl;
	return 0;
}

/*
Find : 0
Find : 1
*/

// Testing code.
int main4() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
	ll->print();
	ll->deleteNode(3);
	ll->print();
	return 0;
}

/*
4 3 2 1 
4 2 1 
*/

// Testing code.
int main5() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(1);
	ll->addHead(1);
	ll->addHead(3);
	ll->print();
	ll->deleteNodes(1);
	ll->print();
	return 0;
}

// Testing code.
int main6() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	ll->reverse();
 	ll->print();
 	ll->reverseRecurse();
 	ll->print();
	return 0;
}

/*
3 2 1 
1 2 3 
3 2 1 
*/

// Testing code.
int main7() {
	LinkedList *ll = new LinkedList();
	for(int i =1;i<5;i++) {
		ll->sortedInsert(i);
		ll->sortedInsert(i);
	}
	ll->print();
	ll->removeDuplicate();
	ll->print();
	return 0;
}

/*
1 1 2 2 3 3 4 4 
1 2 3 4 
*/

// Testing code.
int main8() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->print();
	LinkedList *ll2 = ll->copyListReversed();
 	ll2->print();
	LinkedList *ll3 = ll->copyList();
 	ll3->print();
	return 0;
}

/*
3 2 1 
1 2 3 
3 2 1 
*/

// Testing code.
int main9() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);	
	LinkedList *ll2 = ll->copyList();
 	std::cout << "Compare list :: " << ll->compareList(ll2)<<std::endl;
	return 0;
}

/*
Compare list :: 1
*/

// Testing code.
int main10() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
 	ll->print();
	std::cout << "nthNodeFromBegining :: " << ll->nthNodeFromBegining(2)<<std::endl;
 	std::cout << "nthNodeFromEnd :: " << ll->nthNodeFromEnd(2)<<std::endl;
 	std::cout << "nthNodeFromEnd2 :: " << ll->nthNodeFromEnd2(2)<<std::endl;
	return 0;
}

/*
4 3 2 1 
nthNodeFromBegining :: 3
nthNodeFromEnd :: 2
nthNodeFromEnd2 :: 2
*/

// Testing code.
int main11() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
 	ll->print();
	std::cout << "nthNodeFromBegining :: " << ll->nthNodeFromBegining(2)<<std::endl;
 	std::cout << "nthNodeFromEnd :: " << ll->nthNodeFromEnd(2)<<std::endl;
 	std::cout << "nthNodeFromEnd2 :: " << ll->nthNodeFromEnd2(2)<<std::endl;
	return 0;
}

/*
4 3 2 1 
nthNodeFromBegining :: 3
nthNodeFromEnd :: 2
nthNodeFromEnd2 :: 2
*/

// Testing code.
int main12() {
	LinkedList *ll = new LinkedList();
	ll->addHead(1);
	ll->addHead(2);
	ll->addHead(3);
	ll->addHead(4);
 	ll->print();
	ll->makeLoop();
	ll->loopDetect();
 	ll->reverseListLoopDetect();
 	ll->loopTypeDetect();
	ll->removeLoop();
	ll->print();
	return 0;
}

/*
4 3 2 1 
loop found
loop found
circular list loop found
4 3 2 1
*/

int main(){
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	main8();
	main9();
	main10();
	main11();
	main12();
	return 0;
}
