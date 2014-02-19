
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

/* List is a default constructor that initializes a newly
   created list to the empty list.                  */

List::List() {
  listptr = NULL;
}

/* insertAfter(oldvalue, newvalue) searches for the first occurrence
   of the value 'oldvalue' in the list and inserts a new node with
   value 'newvalue' following the node containing 'oldvalue".     */

void List::insertAfter(int oldvalue, int newvalue) {
  ListPtr p, q;

  // traverse the list looking for the correct place to insertAfter
  for (p = listptr; p != NULL && p->info != oldvalue; p = p->next)
    ;

  // mistake oldvalue is not in list
  if (p == NULL)
     error("ERROR: value is not on the list.");

  // allocate a new lnode and fix pointers
  q = new lnode;
  q->info = newvalue;
  q->next = p->next;
  p->next = q;
}

// function prints the current list members in order in five columns
void List::printList(){
  ListPtr p;
  int count = 1;
  p = listptr;

  while (p != NULL)
  {
    if (count % COL)
      cout << "list[" << count << "] = " << p->info << ", " ;
    else
      cout << "list[" << count << "] = " << p->info << endl ;
    count++;
    p = p->next;
  }
  cout << "End of List\n" ;
}

// push(newvalue) adds a new node with a given newvalue to the front of the list.
void List::push(int newvalue) {
  ListPtr p;

  p = new lnode;
  p->info = newvalue;
  p->next = listptr;
  listptr = p;
}

// delete(oldvalue) deletes the first node containing the value oldvalue from the list.

void List::deleteList(int oldvalue) {
  ListPtr p, q;

  // search the list for 'oldvalue'
  for (q=0, p=listptr; p != NULL && p->info != oldvalue; q=p, p=p->next)
    ;

  // 'oldvalue' was not found in the list
  if (p == NULL)
    error("ERROR: value to be deleted is not on the list.");

  // either 'oldvalue' is at the front of list
  if (q == NULL)
    listptr = p->next;
  // or somewhere else
  else
    q->next = p->next;

  // either way, delete the node
  delete p;
}
