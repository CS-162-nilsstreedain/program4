/******************************************************
** Program: Node.h
** Author: Nils Streedain
** Date: 12/1/2021
** Description: Node object header file
** Input: N/A
** Output: N/A
******************************************************/

#ifndef Node_h
#define Node_h

#include <iostream>

class Node {
public:
	int val;
	Node *next;
	
	Node(int, Node*);
};

#endif /* Node_h */
