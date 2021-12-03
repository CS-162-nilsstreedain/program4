//
//  Node.h
//  Program 4
//
//  Created by Nils Streedain on 12/1/21.
//

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
