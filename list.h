#include <string>
using namespace std;

class List {

//  classic linked list struct
private:
  struct lnode {
    string word;
    int dupCount; //counts the number of times the word is found in the text
    lineListPtr lineCount; //keeps track of the lines that contain the word
    struct lnode *next;
  };
  typedef struct lnode *ListPtr;
  // This declares a member that is the pointer to the linked list 
  ListPtr listptr;

public:
  // prototypes for member functions
  List ();
  void insert(string newWord, int lineCount);
  void printList(); //prints the linked list showing the word, it's dupCount and lineCount
};    //end class List
