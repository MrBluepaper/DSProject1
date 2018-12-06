#include <iostream>
using namespace std;
class BookClass{
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
BookClass::BookClass(){nextPtr = nullptr;}
string BookClass::getBookName(){return bookName;}
string BookClass::getWriter(){return writer;}
int BookClass::getPubYear(){return pubYear;}
double BookClass::getPrice(){return price;}
BookClass *BookClass::getNextPtr(){return nextPtr;}
void BookClass::setBookName(string s){bookName = s;}
void BookClass::setWriter(string s){writer = s;}
void BookClass::setPubYear(int i){pubYear = i;}
void BookClass::setPrice(double d){price = d;}
void BookClass::setNextPtr(BookClass *b){nextPtr = b;}
void BookClass::printBookDetails(){
  cout << bookName << " , " << writer << " , " << getPubYear << " , " << price << "$" << endl;
}