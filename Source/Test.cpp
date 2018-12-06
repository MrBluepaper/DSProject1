#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  ifstream bookFile("bookList.txt");
  if(!bookFile.is_open()){
    cerr << "Unable to open file :" << '\n';
    return false;
  }
  string line, word;
  while (getline(bookFile,line)) {
    stringstream s(line);
    while (s >> word) {
      cout << word << " ";
    }
    cout << endl;
  }
}
