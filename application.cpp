//
//  application.cpp
//  Program 4
//
//  Created by Nils Streedain on 12/1/21.
//

#include <iostream>
#include "Linked_List.h"

int insertNumber() {
	int num;
	std::cout << "Please enter a number: ";
	std::cin >> num;
	std::cin.clear();
	return num;
}

bool boolFromUser(std::string question) {
	char ch;
	std::cout << question << " ";
	std::cin >> ch;
	std::cin.clear();
	if (ch == 'y')
		return true;
	else if (ch == 'n')
		return false;
	else
		return boolFromUser(question);
}

void sort(Linked_List *list) {
	char ch;
	std::cout << "Sort ascending or descending (a or d)? ";
	std::cin >> ch;
	std::cin.clear();
	if (ch == 'a')
		list->sort_ascending();
	else if (ch == 'b')
		list->sort_descending();
	else
		sort(list);
}


int main(int argc, const char * argv[]) {
	bool doAgain = true;
	while (doAgain) {
		Linked_List list;

		// Populate list based on user input
		bool addAnother = true;
		while (addAnother) {
			list.push_back(insertNumber());
			addAnother = boolFromUser("Do you want another num (y or n):");
		}

		// Sort list based on user input
		sort(&list);
		std::cout << "Your linked list is: ";
		list.print();

		// Get & print count of prime nums in list
		int numPrimes = list.getNumPrimes();
		std::cout << "You have " << numPrimes << " prime number(s) in your list." << std::endl;
		
		// Do again? based on user input
		doAgain = boolFromUser("Do you want to do this again (y or n)? ");
	}
	
	return 0;
}
