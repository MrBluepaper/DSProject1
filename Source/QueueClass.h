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
  }
};
