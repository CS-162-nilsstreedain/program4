# Program 4 - Basic Linked List Application

This is a basic linked list application implementation by [Nils Streedain](https://github.com/nilsstreedain) which interprets user command line input to create a populated linked list. The list is then sorted and printed to the CLI along with other list info.

## Usage

When first run, the program will prompt the user to enter a number with "Please enter a number:". If anything other than a valid number is input, the user will be asked again.

Once a valid number has been input, the user will be asked if they'd like to add another number to the list with "Do you want another num (y or n):". To which they must
respond with 'y' or 'n'. If any other input is selected, the user will be asked again.

These steps are repeated until the user selects 'n', indicating the list is complete. The user will then be asked which sorting function they would like to be utilized with "Sort ascending or descending (a or d)?".

Typing 'a' will sort the list in an ascending pattern using a recursive merge sort function, and typing 'd' will alternatively sort the list in a descending pattern, using a recursive selection sort function.

Finally, the sorted list is printed to the command line, along with the count of prime numbers in the list. After printing, the user is prompted to see if the program should repeat from the beginning with "Do you want to do this again (y or n)?" Then the program ends and returns to the basic CLI.

## Implementations

### Recursive Merge Sort
As noted above, when sorting in an ascending pattern by the sort_ascending() function, a recursive merge sort function is used. This process consists of six functions:

#### sort_ascending()
Recursive driver function, calls mergesort() on the list's head node.

#### mergesort()
Recursive merge sort function. Utilizes split() to divide the list into two sublists, recursively calls mergesort() on each sublist, then calls merge() to combine the sublists back together in order from least to greatest. When the base case is reached (head or head's next node being NULL) the function is returned.

#### split()
Divides a list defined by a given head node, using findMiddle() to get the middle node of the list. The first list is defined by the given head node, with the next node of middle set to NULL to end the list. The second list is set to middle's next node, effectively splitting the head node into two sublists, each defined by a Node.

#### findMiddle()
This function find the middle of a Node defined list with a given head node. First we set two node pointers, one to the given head, and one to given head's next node. If we then iterate both node pointers through the list, one twice as often as the other, we can effectively find the middle node with the pointer moving at half the frequency of the other.

#### merge()
This function takes two lists defined by head nodes and combines them in ascending order. I have written both a recursive & non-recursive version of this function but ultimately chose the non-recursive version for simplicity.

This function works by creating a new node defined list, then repeatedly looks at the front node value of each given list and swaps (using swapHeadNode()) the lower of the two nodes to the new list until nodes from both lists have been added to the new list.

#### swapHeadNode()
This function takes two node pointers and moves the head of the first list to the head of the second list while maintaining the rest of the nodes in the list. Example below:

Before: to = {1, 2, 3}, from = {4, 5, 6}

After:  to = {4, 1, 2, 3}, from = {5, 6}

### Recursive Selection Sort
As noted above, when sorting in a descending pattern by the sort_descending() function, a recursive selection sort function is used. This process consists of three functions:

#### sort_descending()
Recursive driver function, calls selectionSort() on head and then sets head equal to the Node returned.

#### selectionSort()
Recursive selection sort function. To sort the list, this function first iterates through every node, starting at the given head, keeping track of the max element found. Once every element has been checked, if the max is not the given head, the max and given head are swapped using swapNode(). Finally, selection sort is called again on the given head's next node

#### swapNode()
This function swaps the location of two nodes in a head defined node list by switching the pointers of given nodes.

## Extra Credit

### sort_descending() Selection Sort
Selection sort for the sort_descending() function is defined by both the selectionSort() & swapNode() functions in the Linked_List.cpp/.h files.