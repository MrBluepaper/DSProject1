#include <iostream>
#include "ReadFile.h"
#include "linkedListFunctions.h"
using namespace std;

int printCommands();

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
  printCommands();
}

int printCommands(){
  int a;
  cout << "====<< Commands >>====\n"
        << "1. Print Book list\n"
        << "2. Add new Book\n"
        << "3. Add new Customer\n"
        << "4. Exit Customer\n"
        << "5. Customer Management\n"
        << "======================\n\n"
        << "Enter your command number (1-5): ";
  cin >> a;
  while (a > 5 || a < 1){
    cout << "Wrong input;\nEnter it again : ";
    cin >> a;
  }
  return a;
}
