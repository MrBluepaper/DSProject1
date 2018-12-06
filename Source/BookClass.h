#include <iostream>
#include <string>
using namespace std;
class BookClass{
private:
  string bookName;
  string writer;
  int pubYear;
  double price;
  BookClass *nextPtr;
public:
  BookClass();
  string getBookName();
  string getWriter();
  int getPubYear();
  double getPrice();
  BookClass *getNextPtr();
  void setBookName(string s);
  void setWriter(string s);
  void setPubYear(int i);
  void setPrice(double d);
  void setNextPtr(BookClass *b);
  void printBookDetails();
};
