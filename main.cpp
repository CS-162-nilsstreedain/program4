//
//  main.cpp
//  Program 4
//
//  Created by Nils Streedain on 12/1/21.
//

#include <iostream>
#include "Linked_List.h"

int main(int argc, const char * argv[]) {
	Linked_List listOne;
	Linked_List listTwo;

	listOne.push_front(5);
	listOne.push_front(4);
	listOne.push_front(3);
	listOne.push_front(2);
	listOne.push_front(1);
	listOne.print();
	std::cout << listOne.get_length() << std::endl;

	listOne.push_back(6);
	listOne.push_back(7);
	listOne.push_back(8);
	listOne.push_back(9);
	listOne.push_back(10);
	listOne.print();
	std::cout << listOne.get_length() << std::endl;

	listTwo.insert(1, 0);
	listTwo.insert(2, 1);
	listTwo.insert(3, 2);
	listTwo.insert(7, 3);
	listTwo.insert(6, 4);
	listTwo.insert(5, 5);
	listTwo.insert(4, 6);
	listTwo.print();
	listTwo.sort_ascending();
	listTwo.print();
	std::cout << listTwo.get_length() << std::endl;
	
	return 0;
}
