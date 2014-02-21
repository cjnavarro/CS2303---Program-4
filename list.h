
#include <string>

using namespace std;

class List {

//Self referential linked-list structure
private:
  struct lnode {
    string word;
	int count;
	string lineCount;
    struct lnode *next;
  };
  typedef struct lnode *ListPtr;

  ListPtr listPtr;

public:
  // prototypes for member functions
  List ();
  void insert(string word, int lineNum);
  void print_list();
  bool not_in_list(string word);
}; 

