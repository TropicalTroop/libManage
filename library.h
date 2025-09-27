/* Library Class Definition
Atharva, Nikhil, Po, 9/26/25 */
#include "bookClass.hpp"
#include <vector>

#ifndef LIBRARY_H
#define LIBRARY_H

class Library{
public:
   //Default constructor, initializes catalogue and userList vectors
   Library();

   //Overloaded constructor, takes in two vectors and assigns them to private data members
   Library(std::vector<Book>, std::vector<User>);

   //Assigns a book to a user, makes book unavailable, "checking it out"
   void checkoutBook(Book, User);

   //Removes book from user, makes it available, "returns it"
   void returnBook(Book, User);

   // Returns whether a book is available or unavailable as bool
   bool getBookStatus(Book);

   // Returns title, ISBN, genre, author, availability, and barcode of book
   std::string bookDetails(Book);

   // Adds a book to the catalogue
   void addBook(Book);

   // Removes a book from the catalogue
   void removeBook(Book);

   // Adds user to list of Users (userList)
   void addUser(User);

   //Removes user from list of users (userList)
   void removeUser(User);
private:
   // Vector containing all books within the library
   std::vector<Book> catalogue;

   // Vector containing all users within the library
   std::vector<User> userList;
};
#endif
