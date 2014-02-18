
##Start of Makefile
main: main.o list.o
	g++ -g -o main main.o list.o
 
main.o: main.c list.h 
	g++ -g -Wall -c main.c 
 
list.o: list.c list.h 
	g++ -g -Wall -c list.c 
	
clean: 
	rm *.o
 ##End of Makefile
