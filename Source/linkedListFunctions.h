#include "BookClass.h"

BookClass *sort_l(BookClass *head){

}

void add_l(BookClass *head, BookClass *new_a){
  new_a->setNextPtr(head->getNextPtr());
  head->setNextPtr(new_a);
}

BookClass *delete_l(BookClass *head, string bookName){
  BookClass *tmp = head;
  if(head->getNextPtr() == head){
    if(head->getBookName() == bookName){
      delete head;
      return nullptr;
    }
    else{
      cout << "Book not found to delete!\n";
      return head;
    }
  }
  else{
    do {
      if(tmp->getNextPtr()->getBookName() == bookName){
        BookClass *y = tmp->getNextPtr()->getNextPtr();
        delete tmp->getNextPtr();
        tmp->setNextPtr(y);
        return head;
      }
      tmp = tmp->getNextPtr();
    } while(head != tmp);
    cout << "Book not found to delete!\n";
    return head;
  }
}

BookClass *search_l(BookClass *head, string bookName){
  if(head != nullptr){
    BookClass *tmp = head;
    do {
      if (bookName == tmp->getBookName())
        return tmp;
      tmp = tmp->getNextPtr();
    } while(head != tmp);
    cout << "Book not found!\n";
  }
  return nullptr;
}
