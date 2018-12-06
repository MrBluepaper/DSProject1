#include <iostream>
#include <fstream>
#include <string>
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
    while (s >> word) {
      cout << word << endl;
    }
  }
}
