#include <iostream>
#include <string>
#include <cmath>
#include "ReadFile.h"
#include "linkedListFunctions.h"
using namespace std;

int printCommands();
void printBookList(BookClass *head);
void addNewBook(BookClass *head);

int main() {
  BookClass *head = new BookClass;
  readFile r(head);
  if(!(r.readFileFunction())){
    cout << "Unable to read from file :/\n";
    return 0;
  }
  int n;
  n = printCommands();
  while (1) {
    switch (n) {
      case 1:
        sort_l_bookname(head);
        printBookList(head);
        break;

      case 2:
        addNewBook(head);
        sort_l_bookname(head);
        break;

      case 3:

        break;

      case 4:

        break;

      case 5:

        break;

      case 6:
        cout << "\n\nBye ;))))\n\n";
        return 0;
    }
    n = printCommands();
  }
}

int printCommands(){
  int a;
  cout << "\t+====<< Commands >>====+\n"
        << "\t|1. Print Book list    |\n"
        << "\t|2. Add new Book       |\n"
        << "\t|3. Add new Customer   |\n"
        << "\t|4. Exit Customer      |\n"
        << "\t|5. Customer Management|\n"
        << "\t|6. Exit               |\n"
        << "\t+======================+\n\n"
        << "Enter your command number (1-6): ";
  cin >> a;
  while (a > 6 || a < 1){
    cout << "Wrong input;\nEnter it again : ";
    cin >> a;
  }
  return a;
}
void printBookList(BookClass *head){
  cout << "\n\n\n------------------------------> Book List <------------------------------\n";
  cout << " NO. |          Book  Name          |       Author       | Year | Price |\n";
  cout << "-------------------------------------------------------------------------\n";
  BookClass *tmp = head;
  int count = 1;
  string s;
  do {
    s = to_string(count);
    cout << " " << s;
    for(unsigned int i = 0; i < (4 - s.size()); i++)
      cout << " ";
    cout << "|";
    count++;
    tmp->printBookDetails();
    tmp = tmp->getNextPtr();
  }
  while(tmp != head);
  cout << "-------------------------------------------------------------------------\n\n\n";
}

void addNewBook(BookClass *head){
  BookClass *newBook = new BookClass;
  string s;
  cout << "\nEnter Book's Name : ";
  cin >> s;
  newBook->setBookName(s);
  cout << "Enter Book's Author Name : ";
  cin >> s;
  newBook->setWriter(s);
  int a;
  cout << "Enter Book's Publication Year : ";
  cin >> a;
  newBook->setPubYear(a);
  double d;
  cout << "Enter Book's Price ($): ";
  cin >> d;
  newBook->setPrice(d);
  add_l(head, newBook);
  cout << "\nYour Book Added Successfully.\n\n";
}
