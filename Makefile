
##Start of Makefile
main: main.o list.o line.o
	g++ -g -o main main.o list.o line.o
 
main.o: main.cpp list.h line.h
	g++ -g -Wall -c main.cpp 
 
list.o: list.cpp list.h line.h
	g++ -g -Wall -c list.cpp 
	
line.o: line.cpp list.h line.h
	g++ -g -Wall -c line.cpp
		
clean: 
	rm *.o
 ##End of Makefile
