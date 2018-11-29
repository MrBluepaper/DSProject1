
class Book{
  string bookName;
  string writer;
  int pubYear;
  double price;
  Book *nextPtr;

public:
  string getBookName();
  string getWriter();
  int getPubYear();
  double getPrice();
  Book *getNextPtr();
  void setBookName(string s);
  void setWriter(string s);
  void setPubYear(int i);
  void setPrice(double d);
  void setNextPtr(Book *b);
};
string Book::getBookName(){return bookName;}
string Book::getWriter(){return writer;}
int Book::getPubYear(){return pubYear;}
double Book::getPrice(){return price;}
Book *Book::getNextPtr(){return nextPtr;}
void Book::setBookName(string s){bookName = s;}
void Book::setWriter(string s){writer = s;}
void Book::setPubYear(int i){pubYear = i;}
void Book::setPrice(double d){price = d;}
void setNextPtr(Book *b){nextPtr = b;}
