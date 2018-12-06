#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BookClass.h"
using namespace std;

class readFile(){
  BookClass *head;
public:
  readFile(BookClass *head);
  bool readFileFunction();
}
readFile::readFile(BookClass *head){
  this->head = head;
}
bool readFile::readFileFunction(){
  ifstream bookFile("bookName.txt");
  if(!bookFile.is_open()){
    cerr << "Unable to open file :" << '\n';
    return false;
  }
  string line, word;
  while (getline(bookFile,line)) {
    stringstream s(line);
    s >> word;
    head->setPubYear(atoi(s.c_str());
    s >> word;
    head->setBookName(s);
    s >> word;
    head->setWriter(s);
    s >> word;
    head->setPrice(atoi(s.c_str());
    BookClass *tmp = new BookClass;
    head->setNextPtr(tmp);
    head = tmp;
  }
  return true;
}
