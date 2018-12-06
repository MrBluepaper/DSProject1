class ShopClass{
private:
  string *books;
  double price;
  int size;
public:
  ShopClass(){size = 0; books = nullptr; price = 0;}
  void setSize(int a){size = a;}
  int getSize(){return size;}
  void addBook(string bookN){
    size++;
    if(books == nullptr){
      books = new string[1];
      books[0] = bookN;
      return;
    }
    else{
      string *tmp = new string[size];
      for(int i = 0; i < size - 1; i++)
        tmp[i] = books[i];
      tmp[size - 1] = bookN;
      delete[] books;
      books = tmp;
    }
  }
  string deleteBook(){
    if(books == nullptr){
      return "0";
    }
    size--;
    string *tmp = new string[size];
    for(int i = 0; i < size; i++)
      tmp[i] = books[i];
    string u = books[size];
    delete[] books;
    books = tmp;
    if(!size)
      books = nullptr;
    return u;
  }
  string *getBooks(){return books;}
  void setPrice(double d){
    price += d;
  }
  double getPrice(){return price;}
};
