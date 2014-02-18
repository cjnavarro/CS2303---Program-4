/* 
Author: Bob Kinicki

Member functions for linked list implementation
based Langsam et al textbook.      

Note - very concise for loops came from Langsam  */

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace std;

/* List is a default constructor that initializes a newly
   created list to the empty list.                  */

List::List() {
  listptr = NULL;
}

//~List is the destructor that traverses the nodes of a
// list, freeing them one by one.

List::~List() {
  // Use standard two pointer scheme to run down the list
  // deleting list nodes.
  ListPtr p, q;
  p = listptr;
  while (p != NULL) {
    q = p->next;
    delete p;
    p = q;
  }
}
