#include <iostream>
#include "ReadFile.h"
using namespace std;
int main() {
  BookClass *head = new BookClass;
  readFile r(head);
  r.readFileFunction();
  BookClass *tmp = head;
  while(tmp){
    head->printBookDetails();
    tmp = tmp->getNextPtr();
  }
}
