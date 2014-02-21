/*
 * File: list.h
 * -------------
 * Header of list.cpp
 */
 
#include <string>

using namespace std;

class List {
public:
	/*
	 * Constructs an empty list
	 */
  List ();
  
  /*
   * Inserts an new word in to a list OR
   * Increments the counter of the word and appends a line number
   */
  void insert(string word, int lineNum);
  
  /*
   * Prints out the contents of the list
   */
  void print_list();
  
  /*
   * Returns true if a word is not in the list
   */
  bool not_in_list(string word);


/* Private section */

private:
  struct lnode {
    string word;
		int count;
		string lineCount;
    struct lnode *next;
  };
  
  typedef struct lnode *ListPtr;

  ListPtr listPtr;
}; 

