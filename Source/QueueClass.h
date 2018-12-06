class QueueClass{
private:
  bool sex; //true --> male         false --> female
  int bookCount;

public:
  QueueClass(){bookCount = 0;};
  void setSex(bool a){sex = a;};
  void addBookCount(){bookCount++;}
  bool getSex(){return sex;}
  int getBookCount(){return bookCount;}
};
