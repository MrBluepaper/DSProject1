#include "ShopClass.h"
class QueueClass{
private:
  bool sex; //true --> male         false --> female
  ShopClass shopping;
  QueueClass *nextPtr;
public:
  QueueClass(){nextPtr = nullptr;}
  void setSex(bool a){sex = a;}
  bool getSex(){return sex;}
  ShopClass *getShop(){return &shopping;}
  QueueClass *getNextPtr(){return nextPtr;}
  void setNextPtr(QueueClass *n){nextPtr = n;}
  void printBill(){
  }
};
