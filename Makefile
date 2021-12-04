# Program 4 Makefile
CC = g++ -std=c++11
exe_file = application
$(exe_file): Node.o Linked_List.o application.o
	$(CC) Node.o Linked_List.o application.o -o $(exe_file)
Node.o: Node.cpp
	$(CC) -c Node.cpp
Linked_List.o: Linked_List.cpp
	$(CC) -c Linked_List.cpp
application.o: application.cpp
	$(CC) -c application.cpp

clean:
	rm -f *.out *.o $(exe_file)

