#include "BookClass.h"
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
  cout << " " << bookName;
  for(unsigned int i = 0; i < 29 - bookName.size(); i++, cout << " ");
  cout << "| " << writer;
  for(unsigned int i = 0; i < 19 - writer.size(); i++, cout << " ");
  cout << "| " << pubYear << " | " << price << " $  |\n";
}
