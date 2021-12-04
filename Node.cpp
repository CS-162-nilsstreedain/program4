/******************************************************
** Program: Node.cpp
** Author: Nils Streedain
** Date: 12/1/2021
** Description: Node class implementation file
** Input: N/A
** Output: N/A
******************************************************/

#include "Node.h"

/*********************************************************************
 ** Function: Node()
 ** Description: Constructor for the Node class
 ** Parameters: int val, Node* next
 ** Pre-Conditions: val & next must be provided
 ** Post-Conditions: A node with the val and a next node of next will be created.
 *********************************************************************/
Node::Node(int val, Node* next) {
	this->val = val;
	this->next = next;
}
