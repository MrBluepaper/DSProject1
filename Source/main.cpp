#include <iostream>
#include <string>
#include "ReadFile.h"
#include "linkedListFunctions.h"
#include "QueueClass.h"
using namespace std;

int printCommands();
void printBookList(BookClass *head, int i);
BookClass *addNewBook(BookClass *head);
BookClass *addCustomer(QueueClass *males, QueueClass *females, BookClass *head);
BookClass *addBookToCustomer(BookClass* head, QueueClass *tmp);
void printCustomers(QueueClass *males, QueueClass *females, int i);

int main() {
  BookClass *head = new BookClass;
  QueueClass *maleHead = new QueueClass;
  QueueClass *femaleHead = new QueueClass;
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
        cout << "Print Book List Sorted by 1.Name or 2.Date ? (1 or 2) : ";
        int n;
        cin >> n;
        printBookList(head, n%2);
        break;

      case 2:
        head = addNewBook(head);
        sort_l_bookname(head);
        break;

      case 3:
        head = addCustomer(maleHead, femaleHead, head);
        break;

      case 4:{
        if(maleHead->getNextPtr() == nullptr && femaleHead->getNextPtr() == nullptr){
          cout << "No Customer to Exit...\n\n";
          break;
        }
        printCustomers(maleHead, femaleHead, 1);
        cout << "Enter - 1 - to Exit a Customer or - 0 - to return previous menu : ";
        int u,i = 1;
        cin >> u;
        while (u == 1) {
          QueueClass *males_tt = maleHead->getNextPtr();
          QueueClass *females_tt = femaleHead->getNextPtr();
          if(males_tt && females_tt){
            if(i % 2){
              cout << "Customer Name : " << males_tt->getName()
                    << "\nBill :\n";
              males_tt->printBill();
              QueueClass *tmp = males_tt->getNextPtr();
              delete males_tt;
              maleHead->setNextPtr(tmp);
              males_tt = males_tt->getNextPtr();
              i++;
            }
            else{
              cout << "Customer Name : " << females_tt->getName()
                    << "\nBill :\n";
              females_tt->printBill();
              QueueClass *tmp = females_tt->getNextPtr();
              delete females_tt;
              femaleHead->setNextPtr(tmp);
              females_tt = females_tt->getNextPtr();
              i++;
            }
          }
          else if(males_tt){
            cout << "Customer Name : " << males_tt->getName()
                  << "\nBill :\n";
            males_tt->printBill();
            QueueClass *tmp = males_tt->getNextPtr();
            delete males_tt;
            maleHead->setNextPtr(tmp);
            males_tt = males_tt->getNextPtr();
            i++;
          }
          else if(females_tt){
            cout << "Customer Name : " << females_tt->getName()
                  << "\nBill :\n";
            females_tt->printBill();
            QueueClass *tmp = females_tt->getNextPtr();
            delete females_tt;
            femaleHead->setNextPtr(tmp);
            females_tt = females_tt->getNextPtr();
            i++;
          }
          printCustomers(maleHead, femaleHead, i);
          if(maleHead->getNextPtr() == nullptr && femaleHead->getNextPtr() == nullptr){
            cout << "No Customer to Exit...\n\n";
            break;
          }
          cout << "Enter - 1 - to Exit a Customer or - 0 - to return previous menu : ";
          cin >> u;
        }
        break;
      }
      case 5:
        if(maleHead->getNextPtr() == nullptr && femaleHead->getNextPtr() == nullptr){
          cout << "No Customers to show!\n\n";
          break;
        }
        printCustomers(maleHead, femaleHead, 1);
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
        << "\t|5. Customer Bills     |\n"
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
void printBookList(BookClass *head, int i){
  if(head == nullptr){
    cout << "No Book Available!\n\n";
    return;
  }
  if(i == 1)
    sort_l_bookname(head);
  else if(i == 0)
    sort_l_date(head);
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

BookClass *addNewBook(BookClass *head){
  BookClass *newBook = new BookClass;
  string s;
  cout << "\nEnter Book's Name : ";
  cin.ignore();
  getline(cin, s);
  newBook->setBookName(s);
  cout << "Enter Book's Author Name : ";
  getline(cin, s);
  newBook->setWriter(s);
  int a;
  cout << "Enter Book's Publication Year : ";
  cin >> a;
  newBook->setPubYear(a);
  double d;
  cout << "Enter Book's Price ($): ";
  cin >> d;
  newBook->setPrice(d);
  head = add_l(head, newBook);
  cout << "\nYour Book Added Successfully.\n\n";
  return head;
}
BookClass *addCustomer(QueueClass *males, QueueClass *females, BookClass *head){
  QueueClass *tmp = new QueueClass;
  QueueClass *tmpt;
  cout << "\nEnter your customer sex (1.male / 2.female) : ";
  int a;
  cin >> a;
  if(a == 1)
    tmpt = males;
  else if(a == 2)
    tmpt = females;
  while(tmpt->getNextPtr()){
    tmpt = tmpt->getNextPtr();
  }
  tmpt->setNextPtr(tmp);
  tmp->setSex(a-1);
  cout << "Enter your Customer name : ";
  string ss;
  cin >> ss;
  tmp->setName(ss);
  head = addBookToCustomer(head, tmp);
  return head;
}
BookClass *addBookToCustomer(BookClass* head, QueueClass *tmp){
  if(head == nullptr){
    cout << "\nNo Book Available!\n";
    return nullptr;
  }
  printBookList(head, 1);
  cout << "\nChoose your books number to add (end with -1) : \n";
  int y;
  cin >> y;
  if(y == -1) return head;
  BookClass *buy;
  do{
    buy = search_ln(head, y-1);
    if(buy == nullptr)
      cout << "\nBook not found!\n";
    else{
      tmp->getShop()->addBook(buy->getBookName());
      tmp->getShop()->setPrice(buy->getPrice());
      head = delete_l(head, buy->getBookName());
    }
    printBookList(head, 1);
    cin >> y;
  } while(y != -1);
  return head;
}

void printCustomers(QueueClass *males, QueueClass *females, int i){
  cout << "\n\n----)) Customers ((----\n";
  males = males->getNextPtr();
  females = females->getNextPtr();
  int j = 1;
  while(males && females){
    if(i % 2){
      cout << j << ". " << males->getName() << "   " << males->getShop()->getPrice() << " $" << endl;
      males = males->getNextPtr();
      j++;
      i++;
    }
    else{
      cout << j << ". " << females->getName() << "   " << females->getShop()->getPrice() << " $" << endl;
      females = females->getNextPtr();
      j++;
      i++;
    }
  }
  while(males){
    cout << j << ". " << males->getName() << "   " << males->getShop()->getPrice() << " $" << endl;
    males = males->getNextPtr();
    j++;
    i++;
  }
  while(females){
    cout << j << ". " << females->getName() << "   " << females->getShop()->getPrice() << " $" << endl;
    females = females->getNextPtr();
    j++;
    i++;
  }
  cout << endl << endl;
}
