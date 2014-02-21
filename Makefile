##Start of Makefile
main: main.o list.o
	g++ -g -o main main.o list.o
 
main.o: main.cpp list.h
	g++ -g -Wall -c main.cpp 
 
list.o: list.cpp list.h
	g++ -g -Wall -c list.cpp 
	
clean: 
	rm *.o
 ##End of Makefile
