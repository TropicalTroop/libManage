// Nikhil Aadapu, Atharva, Po
// 25 September 2025
// Defining class User

#include "book.h"
#include <vector>
#include <string>
   
#ifndef USER_H
#define USER_H

class User
{
    public:
        // Default Constructor
        // @param none
        // @return none
        User();
        // Overloaded constructor which is called when object is initialized with parameters of type string
        // and type int respectively
        // @param name is name of user
        // @param age is age of user
        User(std::string name, int age, int ID);

        // Adds a book pointer to the user's borrowed books list
        // @param book pointer to a Book the user is borrowing
        // @return void
        void addBook(Book* book);

        // Removes a book pointer from the user's borrowed books list
        // @param book pointer to the Book to be returned
        // @return void
        void removeBook(Book* book);

        /* Returns the amount of books in the user's list of books
        @param none
        @return integer*/
        int getBookCount() const;

        /* Returns a pointer to a book
        @param integer
        @return Book object pointer*/
        Book* bookAddress(int) const;
        
        /* Prints all of the user's attributes
        @param none*/
        void printAccount() const;

        /* Returns the ID of the user
        @param none
        @return integer*/
        int getID() const;
    private:
        std::vector<Book*> myBooks;  // list of books user has borrowed
        std::string name;            // name of user
        int age;                     // age of user
        int ID;                      // id of user
};

#endif