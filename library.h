#include "bookClass.hpp"
#include <vector>

#ifndef LIBRARY_H
#define LIBRARY_H

class Library{
public:
   void checkoutBook(Book, User);
   void returnBook(Book, User);
   void holdBook(Book, User);
   bool getBookStatus(Book);
   std::string bookDetails(Book);
private:
   std::vector<Book> catalogue;


};
#endif
