


class LineList {

//  classic linked list struct
private:
  struct lineList{
    int lineNum;
    struct lineList *next
  };
  typedef struct lineList *LineListPtr;
  
  LineListPtr llPtr
  
  public:
  //Prototypes
  void insert(int lineValue);
  void print_linelist(LineListPtr currentPtr);

};
