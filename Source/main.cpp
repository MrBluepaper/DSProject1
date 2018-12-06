#include <iostream>
#include "BookClass.h"
#include "ReadFile.h"
using namespace std;
int main() {
  BookClass *head = new BookClass;
  readFile r(head);
  while(head->getNextPtr())
    head->printBookDetails();
}
