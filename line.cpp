#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "list.h"
#include "line.h"

using namespace std;

/* List is a default constructor that initializes a newly
   created list to the empty list.                  */

LineList::LineList() {
  llPtr = NULL;
}

//Inserts the new word into the list, checking for duplicates
void LineList::insert(int lineCount) {
  LLPtr newPtr, previousPtr, currentPtr;

  newPtr = new llnode;
  newPtr->lineCount = lineCount;
  newPtr->next = NULL;
  
  previousPtr = NULL;
  currentPtr = llPtr;
  
	if(not_in_line_list(lineCount)){
		while(currentPtr != NULL){
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
		if(previousPtr == NULL){
			newPtr->next = llPtr;
			llPtr = newPtr;
		}
		else{
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
			}
		}
	else{
		return ;
		}
}

//Checks if the word exist already in the list
bool LineList::not_in_line_list(int lineCount){
	
	LLPtr currentPtr;
	currentPtr = llPtr;

	while(currentPtr != NULL && lineCount != currentPtr->lineCount){
		currentPtr = currentPtr->next;
	}
	if(currentPtr == NULL){
		cout << "No Item\n";
		return true;
	}
	else{
		cout<< "Item in list\n";
		return false;
	}
}

// function prints the current list members in order in five columns
void LineList::print_line_list(){
  LLPtr p;
  p = llPtr;

  while (p != NULL)
  {
      cout << p->lineCount << " , ";
      p = p->next;
  }
  cout << "End of List\n" ;
}
