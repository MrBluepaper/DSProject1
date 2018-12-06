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
  BookClass *pre, *head_tmp = head;
  while (getline(bookFile,line)) {

    size_t pos = line.find("-");
    string word = line.substr(0, pos);
    head->setPubYear(atoi(word.c_str()));

    size_t pos2 = line.find("-", pos+1);
    word = line.substr(pos+1, pos2 - pos - 1);
    head->setBookName(word);

    pos = line.find("-", (pos2)+1);
    word = line.substr(pos2+1, pos - pos2 - 1);
    head->setWriter(word);

    pos2 = line.find("-", pos+1);
    word = line.substr(pos+1, pos2 - pos - 1);
    head->setPrice(atoi(word.c_str()));

    pre = head;
    BookClass *tmp = new BookClass;
    head->setNextPtr(tmp);
    head = tmp;
  }
  delete head;
  pre->setNextPtr(head_tmp);
  return true;
}
