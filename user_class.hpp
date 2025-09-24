#include "book_class.hpp"
#include "library_class.hpp"

#ifndef USER_H
#define USER_H

class User{
public:
   User();
   User(std::string, int);
   
private:
   std::vector<Book> loans;
   std::vector<Book> holds;
   std::string name;
   int age;
   double overdraft;
};

#endif
