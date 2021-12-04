/******************************************************
** Program: Linked_List.cpp
** Author: Nils Streedain
** Date: 12/1/2021
** Description: Linked_List class implementation file
** Input: N/A
** Output: N/A
******************************************************/

#include "Linked_List.h"

/*********************************************************************
 ** Function: Linked_List()
 ** Description: Constructor for the Linked_List class
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: An empty linked list will be created.
 *********************************************************************/
Linked_List::Linked_List() {
	length = 0;
	head = NULL;
}

Linked_List::~Linked_List() {
	clear();
}

/*********************************************************************
 ** Function: nodeAt()
 ** Description: Returns the Node pointer at a specified index
 ** Parameters: unsigned int index
 ** Pre-Conditions: index must be provided
 ** Post-Conditions: The Node at index will be returned
 *********************************************************************/
Node* Linked_List::nodeAt(unsigned int index) {
	Node *currNode = head;
	for (int i = 0; i < index; i++)
		currNode = currNode->next;
	return currNode;
}

/*********************************************************************
 ** Function: findMiddle()
 ** Description: Returns the Node pointer at the middle of the list
 ** Parameters: Node *currHead
 ** Pre-Conditions: currHead must be provided
 ** Post-Conditions: The middle Node pointer will be returned
 *********************************************************************/
Node* Linked_List::findMiddle(Node *currHead) {
	Node *toMiddle = currHead;
	Node *toRight = currHead->next;
	
	while (toRight) {
		toRight = toRight->next;
		if (toRight) {
			toRight = toRight->next;
			toMiddle = toMiddle->next;
		}
	}
	
	return toMiddle;
}

/*********************************************************************
 ** Function: split()
 ** Description: Splits the currHead list and puts each half in the leftList and rightList
 ** Parameters: Node *currHead, Node **leftList, Node **rightList
 ** Pre-Conditions: currHead, leftList, & rightList must be provided
 ** Post-Conditions: The currHead list will be split in half between leftList & rightList
 *********************************************************************/
void Linked_List::split(Node *currHead, Node **leftList, Node **rightList) {
	Node *mid = findMiddle(currHead);
	
	*leftList = currHead;
	*rightList = mid->next;
	mid->next = NULL;
}

/*********************************************************************
 ** Function: swapHeadNode()
 ** Description: Swaps the Node at the front of from with the node at the front of to, while all to Nodes follow the new to front Node
 * Ex. 	Before:	to = {1, 2, 3}, from = {4, 5, 6}
 * 		After:		to = {4, 1, 2, 3}, from = {5, 6}
 ** Parameters: Node **to, Node **from
 ** Pre-Conditions: currHead, leftList, & rightList must be provided
 ** Post-Conditions: The currHead list will be split in half between leftList & rightList
 *********************************************************************/
// Ex. 	Before: to = {1, 2, 3}, from = {4, 5, 6}
//		After:  to = (4, 1, 2, 3}, from = {5, 6}
void Linked_List::swapHeadNode(Node **to, Node **from) {
	Node* node = *from;
	if (!node)
		throw std::out_of_range("Index out of bounds.");
	
	*from = node->next;
	node->next = *to;
	*to = node;
}

/*********************************************************************
 ** Function: merge()
 ** Description: Merges leftList with rightList, prioritizing by value, and returns final list
 ** Parameters: Node *leftList, Node *rightList
 ** Pre-Conditions: leftList & rightList must be provided
 ** Post-Conditions: A merged leftList & rightList will be returned
 *********************************************************************/
Node* Linked_List::merge(Node *leftList, Node *rightList) {
	// Recursive merge function
//	Node* sortedList = NULL;
//
//	if (!leftList)
//		return rightList;
//	else if (!rightList)
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
		if (!leftList) {
			currHead->next = rightList;
			break;
		} else if (!rightList) {
			currHead->next = leftList;
			break;
		}
		if (leftList->val <= rightList->val)
			swapHeadNode(&(currHead->next), &leftList);
		else
			swapHeadNode(&(currHead->next), &rightList);
		currHead = currHead->next;
	}
	return sortedList.next;
}

/*********************************************************************
 ** Function: mergesort()
 ** Description: Recursive mergesort function for a list from a given Node pointer
 ** Parameters: Node **start
 ** Pre-Conditions: start must be provided
 ** Post-Conditions: The list starting at start will be sorted recursively
 *********************************************************************/
void Linked_List::mergesort(Node **start) {
	Node* currHead = *start;
	if (!currHead || !(currHead->next))
		return;
	
	// Sublists for currHead to be split into
	Node* leftList;
	Node* rightList;
	
	// Splits currHead into left & right
	split(currHead, &leftList, &rightList);
	
	// Sorts left & right seprately
	mergesort(&leftList);
	mergesort(&rightList);
	
	// combines left & right back to start pointer
	*start = merge(leftList, rightList);
}

/*********************************************************************
 ** Function: swapNode()
 ** Description: Function for swapping nodes in a linked list using pointers
 ** Parameters: Node **currHead, Node *one, Node *two, Node* twoPrev
 ** Pre-Conditions: currHead, one, two & twoPrev must be provided
 ** Post-Conditions: The nodes one & two will be swapped in the linked list
 *********************************************************************/
void Linked_List::swapNode(Node **currHead, Node *one, Node *two, Node* twoPrev) {
	*currHead = two;
	
	twoPrev->next = one;
	
	Node* temp = two->next;
	two->next = one->next;
	one->next = temp;
}

/*********************************************************************
 ** Function: selectionSort()
 ** Description: Recursive selectionsort function for a list from a given Node pointer
 ** Parameters: Node **currHead
 ** Pre-Conditions: currHead must be provided
 ** Post-Conditions: The list starting at currHead will be sorted recursively
 *********************************************************************/
Node* Linked_List::selectionSort(Node *currHead) {
	// When base case is reached, head is returned
	if (!(currHead->next))
		return currHead;
	
	// Set curMac minimum for this recursion
	Node* currMax = currHead;
	// Keeps track of pointer to currMax so it can be swapped later
	Node* maxPrev = NULL;
	
	// Iterate through the list to find max node
	Node* temp = currHead;
	while (temp->next) {
		if (temp->next->val > currMax->val) {
			currMax = temp->next;
			maxPrev = temp;
		}
		temp = temp->next;
	}
	
	// If the max is not the already sorted head, swap the head & max
	if (currMax != currHead)
		swapNode(&currHead, currHead, currMax, maxPrev);
	
	// Run again on next node
	currHead->next = selectionSort(currHead->next);
	
	return currHead;
}

/*********************************************************************
 ** Function: isPrime()
 ** Description: Returns true if x is prime, false otherwise
 ** Parameters: int x
 ** Pre-Conditions: x must be provided
 ** Post-Conditions: True will be returned if x is prime
 *********************************************************************/
bool Linked_List::isPrime(int x) {
	// Remove case where 1 returns true
	if (x < 2)
		return false;
	
	for (int i = 2; i <= x / 2; i++)
		if (x%i == 0)
			return false;
	return true;
}

/*********************************************************************
 ** Function: get_length()
 ** Description: Returns the length of the linked list
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The length will be returned
 *********************************************************************/
int Linked_List::get_length() {
	return length;
}

/*********************************************************************
 ** Function: print()
 ** Description: Prints the linked list to the command line
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The linked list will be printed to the command line
 *********************************************************************/
void Linked_List::print() {
	Node *currNode = head;
	for (int i = 0; i < length; i++) {
		std::cout << currNode->val << " ";
		currNode = currNode->next;
	}
	std::cout << std::endl;
}

/*********************************************************************
 ** Function: clear()
 ** Description: Deletes each node of the list, emptying the list
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The list will be cleared
 *********************************************************************/
void Linked_List::clear() {
	Node *currNode;
	for (int i = 0; i < length; i++) {
		currNode = head;
		head = head->next;
		delete currNode;
	}
	
	length = 0;
}

/*********************************************************************
 ** Function: push_front()
 ** Description: Adds a new node containing val to the front of the linked list & returns new length
 ** Parameters: int val
 ** Pre-Conditions: val must be provided
 ** Post-Conditions: A node containing val will be added to front of list and the new length will be returned
 *********************************************************************/
unsigned int Linked_List::push_front(int val) {
	head = new Node(val, head);
	return ++length;
}

/*********************************************************************
 ** Function: push_back()
 ** Description: Adds a new node containing val to the back of the linked list & returns new length
 ** Parameters: int val
 ** Pre-Conditions: val must be provided
 ** Post-Conditions: A node containing val will be added to back of list and the new length will be returned
 *********************************************************************/
unsigned int Linked_List::push_back(int val) {
	if (length == 0)
		return push_front(val);
	nodeAt(length - 1)->next = new Node(val, NULL);
	return ++length;
}

/*********************************************************************
 ** Function: push_back()
 ** Description: Adds a new node containing val to the inked list at index, index & returns new length
 ** Parameters: int val, unsigned int index
 ** Pre-Conditions: val & index must be provided
 ** Post-Conditions: A node containing val will be added to index, index of list and the new length will be returned
 *********************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index) {
	if (index > length)
		throw std::out_of_range("Index out of bounds.");
	if (index == 0)
		return push_front(val);
	
	Node *nodeAtIndex = nodeAt(index - 1);
	nodeAtIndex->next = new Node(val, nodeAtIndex->next);
	return ++length;
}

/*********************************************************************
 ** Function: sort_ascending()
 ** Description: Sorts the linked list in an ascending pattern with a recursive mergesort function
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The linked list will be sorted in ascending pattern
 *********************************************************************/
void Linked_List::sort_ascending() {
	mergesort(&head);
}

/*********************************************************************
 ** Function: sort_descending()
 ** Description: Sorts the linked list in an descending pattern
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The linked list will be sorted in descending pattern
 *********************************************************************/
void Linked_List::sort_descending() {
	if (!head)
		return;
	
	head = selectionSort(head);
}

/*********************************************************************
 ** Function: getNumPrimes()
 ** Description: Returns the number of prime numbers in the linked list
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: The number of prime number in the linked list will be returned
 *********************************************************************/
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
