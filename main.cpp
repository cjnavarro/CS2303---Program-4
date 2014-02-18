/* 
Author: Bob Kinicki

This program is a driver to test the linked list
implementation by Langsam et al. */

#include <stdlib.h>
#include <iostream>
#include <string>
#include "List.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

// define NULL just in case not in headers

#if !defined(NULL)
  #define NULL 0
#endif

int main()
{
  size_t i;

  //seed t_array with test numbers 
  int t_array[10] = {21, 32, 43, 54, 65, 16, 17, 18, 19, 100};
  List l_list;      // List objects defined in included header file

  // test push function
  l_list.push (t_array[0]);

  // test insertAfter using t_array
  for (i=1; i < 10; i++) {
    l_list.insertAfter(t_array[i-1], t_array[i]);
  }

  cout << "Linked List after push and insert" << endl;
  // print the List to check if two functions work properly
  l_list.printList();

  // try one more insert
  l_list.insertAfter(65, 40);

  cout << "Linked List after insert 40" << endl;
  // print to check again
  l_list.printList();

  // try another insert
  l_list.insertAfter(21, 7777);

  cout << "Linked List after insert 7777" << endl;
  // print to check again
  l_list.printList();

  // test three more operations
  l_list.deleteList(43);
  l_list.pop();
  l_list.push(999);

  cout << "Linked List after a delete 43, a pop and push 999" << endl;
  // final print
  l_list.printList();
  return 0;
}
