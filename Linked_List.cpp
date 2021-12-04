//
//  Linked_List.cpp
//  Program 4
//
//  Created by Nils Streedain on 12/1/21.
//

#include "Linked_List.h"

Linked_List::Linked_List() {
	length = 0;
	head = NULL;
}

Node* Linked_List::nodeAt(unsigned int index) {
	Node *currNode = head;
	for (int i = 0; i < index; i++)
		currNode = currNode->next;
	return currNode;
}

Node* Linked_List::findMiddle(Node *currHead) {
	Node *toMiddle = currHead;
	Node *toRight = currHead->next;
	
	while (toRight != NULL) {
		toRight = toRight->next;
		if (toRight != NULL) {
			toRight = toRight->next;
			toMiddle = toMiddle->next;
		}
	}
	
	return toMiddle;
}

void Linked_List::split(Node *currHead, Node **leftList, Node **rightList) {
	Node *mid = findMiddle(currHead);
	
	*leftList = currHead;
	*rightList = mid->next;
	mid->next = NULL;
}

void Linked_List::swapNode(Node **to, Node **from) {
	Node* node = *from;
	if (node == NULL)
		throw std::out_of_range("Index out of bounds.");
	
	*from = node->next;
	node->next = *to;
	*to = node;
}

Node* Linked_List::merge(Node *leftList, Node *rightList) {
	// Recursive merge function
//	Node* sortedList = NULL;
//
//	if (leftList == NULL)
//		return rightList;
//	else if (rightList == NULL)
//		return leftList;
//
//	if (leftList->val <= rightList->val) {
//		sortedList = leftList;
//		sortedList->next = merge(leftList->next, rightList);
//	} else {
//		sortedList = rightList;
//		sortedList->next = merge(leftList, rightList->next);
//	}
//	return sortedList;
	
	// Non-recursive merge function
	Node sortedList(0, NULL);
	Node* currHead = &sortedList;

	while (true) {
		if (leftList == NULL) {
			currHead->next = rightList;
			break;
		} else if (rightList == NULL) {
			currHead->next = leftList;
			break;
		}
		if (leftList->val <= rightList->val)
			swapNode(&(currHead->next), &leftList);
		else
			swapNode(&(currHead->next), &rightList);
		currHead = currHead->next;
	}
	return sortedList.next;
}

void Linked_List::mergesort(Node **start) {
	Node* currHead = *start;
	if (currHead == NULL || currHead->next == NULL)
		return;
	
	Node* leftList;
	Node* rightList;
	
	split(currHead, &leftList, &rightList);
	
	mergesort(&leftList);
	mergesort(&rightList);
	
	*start = merge(leftList, rightList);
}

bool Linked_List::isPrime(int x) {
	// Remove case where 1 returns true
	if (x < 2)
		return false;
	
	for (int i = 2; i <= x / 2; i++)
		if (x%i == 0)
			return false;
	return true;
}

int Linked_List::get_length() {
	return length;
}

void Linked_List::print() {
	Node *currNode = head;
	for (int i = 0; i < length; i++) {
		std::cout << currNode->val << " ";
		currNode = currNode->next;
	}
	std::cout << std::endl;
}

void Linked_List::clear() {
	Node *currNode;
	for (int i = 0; i < length; i++) {
		currNode = head;
		head = head->next;
		delete currNode;
	}
	
	length = 0;
}

unsigned int Linked_List::push_front(int val) {
	head = new Node(val, head);
	return ++length;
}

unsigned int Linked_List::push_back(int val) {
	if (length == 0)
		return push_front(val);
	nodeAt(length - 1)->next = new Node(val, NULL);
	return ++length;
}

unsigned int Linked_List::insert(int val, unsigned int index) {
	if (index > length)
		throw std::out_of_range("Index out of bounds.");
	if (index == 0)
		return push_front(val);
	
	Node *nodeAtIndex = nodeAt(index - 1);
	nodeAtIndex->next = new Node(val, nodeAtIndex->next);
	return ++length;
}

void Linked_List::sort_ascending() {
	mergesort(&head);
}

void Linked_List::sort_descending() {
	
}

int Linked_List::getNumPrimes() {
	Node *currNode = head;
	int numPrimes = 0;
	for (int i = 0; i < length; i++) {
		if (isPrime(currNode->val))
			numPrimes++;
		currNode = currNode->next;
	}
	
	return numPrimes;
}
