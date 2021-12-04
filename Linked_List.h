/******************************************************
** Program: Linked_List.h
** Author: Nils Streedain
** Date: 12/1/2021
** Description: Cave object header file
** Input: N/A
** Output: N/A
******************************************************/

#ifndef Linked_List_h
#define Linked_List_h

#include <iostream>
#include <stdexcept>
#include "Node.h"

class Linked_List {
private:
//public:
	unsigned int length; // the number of nodes contained in the list
	Node *head; // a pointer to the first node in the list
	
	Node* nodeAt(unsigned int index); // returns node at specified index
	
	Node* findMiddle(Node*); // return node at middle of list
	void split(Node*, Node**, Node**); // split list into sublists
	void swapHeadNode(Node**, Node**); // swap node to other list
	Node* merge(Node*, Node*); // merge method to combine lists
	void mergesort(Node**); // recursive mergesort method

	void swapNode(Node**, Node*, Node*, Node*);
	Node* selectionSort(Node*);
	
	bool isPrime(int); // returns true if int is prime
public:
	Linked_List(); // Linked_List constructor
	~Linked_List(); // Linked_List destructor
	
	int get_length(); // returns length
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list
	unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
	unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
	unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
	void sort_ascending(); // sort the nodes in ascending order.
	void sort_descending(); // sort the nodes in descending order
	
	int getNumPrimes(); // returns number of primes in list
};

#endif /* Linked_List_h */
