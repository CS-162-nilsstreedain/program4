/******************************************************
** Program: application.cpp
** Author: Nils Streedain
** Date: 12/1/2021
** Description: Main driver file for Program 4
** Input: User console interaction
** Output: Program will output to the command line.
******************************************************/

#include <iostream>
#include "Linked_List.h"

template <typename T>

/*********************************************************************
 ** Function: getUserInput()
 ** Description: Generic function to ask user a question and get an input
 ** Parameters: std::string question
 ** Pre-Conditions: question must be provided
 ** Post-Conditions: the user input will be returned
 *********************************************************************/
T getUserInput(std::string question) {
	T output;
	std::cout << question << " ";
	std::cin >> output;
	std::cin.clear();
	return output;
}

/*********************************************************************
 ** Function: boolFromUser()
 ** Description: Function to return a boolian from user input when user types trueChar, true is returned, when user types falseChar, false is returned, otherwise, the user is asked again.
 ** Parameters: std::string question, char trueChar, char falseChar
 ** Pre-Conditions: question, trueChar, & falseChar must be provided
 ** Post-Conditions: a bool based on the user input will be returned
 *********************************************************************/
bool boolFromUser(std::string question, char trueChar, char falseChar) {
	char ch = getUserInput<char>(question);
	if (ch == trueChar)
		return true;
	if (ch == falseChar)
		return false;
	return boolFromUser(question, trueChar, falseChar);
}

/*********************************************************************
 ** Function: main()
 ** Description: Main driver function for hunt the wumpus
 ** Parameters: command line arguments for size and debugMode
 ** Pre-Conditions: size & debugMode must be provided
 ** Post-Conditions: The function will create a cave and start a game, then ask the user what to do when the game has ended.
 *********************************************************************/
int main(int argc, const char * argv[]) {
	bool doAgain = true;
	while (doAgain) {
		std::cout << "\x1B[2J\x1B[H";
		Linked_List list;

		// Populate list based on user input
		bool addAnother = true;
		while (addAnother) {
			list.push_back(getUserInput<int>("Please enter a number:"));
			addAnother = boolFromUser("Do you want another num (y or n):", 'y', 'n');
		}

		// Sort list based on user input
		if (boolFromUser("Sort ascending or descending (a or d)?", 'a', 'd'))
			list.sort_ascending();
		else
			list.sort_descending();
		std::cout << "Your linked list is: ";
		list.print();

		// Get & print count of prime nums in list
		int numPrimes = list.getNumPrimes();
		std::cout << "You have " << numPrimes << " prime number(s) in your list." << std::endl;

		// Do again? based on user input
		doAgain = boolFromUser("Do you want to do this again (y or n)?", 'y', 'n');
	}
	std::cout << "\x1B[2J\x1B[H";
	
	return 0;
}
