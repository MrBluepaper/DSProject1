#include "BookClass.h"

BookClass *sort_l(BookClass *head){

}

BookClass *delete_l(BookClass *head, string bookName){

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
