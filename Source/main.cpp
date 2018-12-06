#include <iostream>
#include "ReadFile.h"
#include "linkedListFunctions.h"
using namespace std;
int main() {
  BookClass *head = new BookClass;
  readFile r(head);
  if(!(r.readFileFunction())){
    cout << "Unable to read from file :/\n";
    return 0;
  }
  /*BookClass *tmp = head;
  do {
    tmp->printBookDetails();
    tmp = tmp->getNextPtr();
  }
  while(tmp != head);*/
}
