/* Library Class Definition
Atharva, Nikhil, Po, 9/26/25 */
#include "book.h"
#include "user.h"
#include <vector>
#include <string>

#ifndef LIBRARY_H
#define LIBRARY_H

class Library{
public:
   //Default constructor, initializes catalogue and userList vectors
   //@param none
   //@return none
   Library();

   //Overloaded constructor, takes in two vectors and assigns them to private data members 
   //@param std::vector<Book>, std::vector<User>
   //@return none
   Library(std::vector<Book> , std::vector<User>);

   //Assigns a book to a user, makes book unavailable, "checking it out"
   //@param Book, User
   //@return none
   void checkoutBook(const Book&, User&);

   //Removes book from user, makes it available, "returns it"
   //@param address of Book object
   //@return void
   void returnBook(const Book& b1);

   // Returns whether a book is available or unavailable as bool
   // @param Book Object
   // @return boolean
   bool getBookStatus(const Book) const;

   // Returns title, ISBN, genre, author, availability, and barcode of book
   //@param Book object
   //@return none
   void bookDetails(const Book) const;

   // Adds a book to the catalogue
   //@param Book object
   //@return none
   void addBook(const Book);

   // Returns vector of copies of a book
   //@param address of Book object
   //@return pointer to a book object
   Book* findBookCopies(const Book&);

   // Removes a book from the catalogue
   //@param address of a book object
   //@return void
   void removeBook(const Book&);

   // Adds user to list of Users (userList)
   //@param address of user object
   //@return void
   void addUser(const User&);

   //Removes user from list of users (userList)
   //@param address of user object
   //@return void
   void removeUser(const User&);
   
private:
   // Vector containing all books within the library
   std::vector<Book> catalogue;

   // Vector containing all users within the library
   std::vector<User> userList;
};
#endif
