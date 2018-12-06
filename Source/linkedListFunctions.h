void sort_l_bookname(BookClass *head){
  for(BookClass *tmp = head; tmp->getNextPtr() != head; tmp = tmp->getNextPtr())
    for(BookClass *tmp2 = tmp->getNextPtr(); tmp2 != head; tmp2 = tmp2->getNextPtr())
      if(tmp->getBookName() > tmp2->getBookName()){
        string o;
        int l;
        double d;
        o = tmp->getBookName();
        tmp->setBookName(tmp2->getBookName());
        tmp2->setBookName(o);
        o = tmp->getWriter();
        tmp->setWriter(tmp2->getWriter());
        tmp2->setWriter(o);
        l = tmp->getPubYear();
        tmp->setPubYear(tmp2->getPubYear());
        tmp2->setPubYear(l);
        d = tmp->getPrice();
        tmp->setPrice(tmp2->getPrice());
        tmp2->setPrice(d);
      }
}

void sort_l_date(BookClass *head){
  for(BookClass *tmp = head; tmp->getNextPtr() != head; tmp = tmp->getNextPtr())
    for(BookClass *tmp2 = tmp->getNextPtr(); tmp2 != head; tmp2 = tmp2->getNextPtr())
      if(tmp->getPubYear() > tmp2->getPubYear()){
        string o;
        int l;
        double d;
        o = tmp->getBookName();
        tmp->setBookName(tmp2->getBookName());
        tmp2->setBookName(o);
        o = tmp->getWriter();
        tmp->setWriter(tmp2->getWriter());
        tmp2->setWriter(o);
        l = tmp->getPubYear();
        tmp->setPubYear(tmp2->getPubYear());
        tmp2->setPubYear(l);
        d = tmp->getPrice();
        tmp->setPrice(tmp2->getPrice());
        tmp2->setPrice(d);
      }
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
    if(tmp->getBookName() == bookName){
      BookClass *y = tmp->getNextPtr();
      BookClass *x = tmp;
      while(x->getNextPtr() != tmp)
        x = x->getNextPtr();
      x->setNextPtr(y);
      delete tmp;
      return y;
    }
    do {
      if(tmp->getNextPtr()->getBookName() == bookName){
        BookClass *y = tmp->getNextPtr()->getNextPtr();
        delete tmp->getNextPtr();
        tmp->setNextPtr(y);
        return head;
      }
      tmp = tmp->getNextPtr();
    } while(head != tmp->getNextPtr());
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
BookClass *search_ln(BookClass *head, int n){
  if(head != nullptr){
    BookClass *tmp = head;
    for(int i = 0; i < n; i++){
      tmp = tmp->getNextPtr();
      if((i < n-1) && head == tmp){
        cout << "Book not found!\n";
        return nullptr;
      }
    }
    //cout << "\n\n" << tmp->getBookName() << endl;
    return tmp;
  }
  else
    return nullptr;
}
