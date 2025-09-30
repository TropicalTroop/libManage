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

        int getBookCount() const;

        Book* bookAddress(int) const;

        void printAccount() const;

        int getID() const;
    private:
        std::vector<Book*> myBooks;  // list of books user has borrowed
        std::string name;            // name of user
        int age;                     // age of user
        int ID;                      // id of user
};

#endif