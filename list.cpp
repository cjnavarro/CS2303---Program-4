#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "list.h"
#include "line.h"

using namespace std;

/* List is a default constructor that initializes a newly
   created list to the empty list.                  */

List::List() {
  listPtr = NULL;
}

//Inserts the new word into the list, checking for duplicates
void List::insert(string word, int lineNum) {
  ListPtr newPtr, previousPtr, currentPtr;

  newPtr = new lnode;
  newPtr->word = word;
  newPtr->count = 1;
  //newPtr->list = (newPtr->llist).insert(lineNum);
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
		//currentPtr->llist = (newPtr->&llist).insert(lineNum);
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
      cout << "Word: " << p->word << " | Word Count: " << p->count << "\n";
      p = p->next;
  }
  cout << "End of List\n" ;
}


