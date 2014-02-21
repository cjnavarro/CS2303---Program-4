#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include "list.h"

using namespace std;

/* List is a default constructor that initializes a newly
   created list to the empty list.                  */

List::List() {
  listPtr = NULL;
}

//Inserts the new word into the list, checking for duplicates
void List::insert(string word, int lineNum) {
  ListPtr newPtr, previousPtr, currentPtr;

  std::stringstream ss;
  ss << lineNum;
  
  string lineString = ss.str();

  
  newPtr = new lnode;
  newPtr->word = word;
  newPtr->count = 1;
  newPtr->lineCount = lineString;
  newPtr->next = NULL;
  
  
  previousPtr = NULL;
  currentPtr = listPtr;
  
	if(not_in_list(word)){
		while(currentPtr != NULL && word.compare(currentPtr->word) > 0){
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}

		if(previousPtr == NULL){
			newPtr->next = listPtr;
			listPtr = newPtr;
			
		}
		else{
				previousPtr->next = newPtr;
				newPtr->next = currentPtr;
			}
		}
	else{
		while(currentPtr != NULL && word != currentPtr->word){
			currentPtr = currentPtr->next;
		}
		(currentPtr->count)++;
		(currentPtr->lineCount) += ", ";
		(currentPtr->lineCount) += lineString; 
	}
}

//Checks if the word exist already in the list
bool List::not_in_list(string word){
	
	ListPtr currentPtr;
	currentPtr = listPtr;

	while(currentPtr != NULL && word != currentPtr->word){
		currentPtr = currentPtr->next;
	}
	if(currentPtr == NULL){
		return true;
	}
	else{
		return false;
	}
}

// function prints the current list members in order in five columns
void List::print_list(){
  ListPtr p;
  p = listPtr;

  while (p != NULL)
  {
      cout << "Word: " << p->word << " | Word Count: " << p->count << " | Line Count: " 
			<< p->lineCount << "\n";
      p = p->next;
  }
  cout << "End of List\n" ;
}


