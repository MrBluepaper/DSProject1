#include "ReadFile.h"
readFile::readFile(BookClass *head){
  this->head = head;
}
bool readFile::readFileFunction(){
  ifstream bookFile("bookList.txt");
  if(!bookFile.is_open()){
    cerr << "Unable to open file :" << '\n';
    return false;
  }
  string line, word;
  BookClass *pre;
  while (getline(bookFile,line)) {
    stringstream s(line);
    s >> word;
    head->setPubYear(atoi(word.c_str()));
    s >> word;
    head->setBookName(word);
    s >> word;
    head->setWriter(word);
    s >> word;
    head->setPrice(atoi(word.c_str()));
    pre = head;
    BookClass *tmp = new BookClass;
    head->setNextPtr(tmp);
    head = tmp;
  }
  delete head;
  pre->setNextPtr(nullptr);
  return true;
}
