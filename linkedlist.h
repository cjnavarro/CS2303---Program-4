/* 
Author: Bob Kinicki

Linked list code taken from Langsam, Augenstein & Tenebaum pp. 246-248 */

// This is List.h
#include <string>
#define COL 5
using namespace std;

class List {

//  classic linked list struct
private:
  struct lnode {
    int info;
    struct lnode *next;
  };
  typedef struct lnode *ListPtr;
  // This declares a member that is the pointer to the linked list 
  ListPtr listptr;

public:
  // prototypes for member functions
  List ();
  ~List();
  int error (string error_message);
  void insertAfter(int oldvalue, int newvalue);
  void push(int newvalue);
  void deleteList(int oldvalue);
  int pop();
  void printList();
};    //end class List
