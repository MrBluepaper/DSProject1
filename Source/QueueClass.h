#include "ShopClass.h"
class QueueClass{
private:
  bool sex; //true --> male         false --> female
  string name;
  ShopClass shopping;
  QueueClass *nextPtr;
public:
  QueueClass(){nextPtr = nullptr;}
  void setName(string s){name = s;}
  string getName(){return name;}
  void setSex(bool a){sex = a;}
  bool getSex(){return sex;}
  ShopClass *getShop(){return &shopping;}
  QueueClass *getNextPtr(){return nextPtr;}
  void setNextPtr(QueueClass *n){nextPtr = n;}
  void printBill(){
    string t;
    t = shopping.deleteBook();
    while (t != "0"){
      cout << "- " << t << endl;
      t = shopping.deleteBook();
    }
    cout << "------------\n";
    cout << "Price : " << shopping.getPrice() << " $" << endl;
    cout << "\nOne Customer Exited...\n\n";
  }
};
