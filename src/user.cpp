#include "user.h"
#include <iostream>

/* Default Constructor
@param none*/
User::User(){
    name = "";
    age = 0;
    ID = 0;
}
/* Overloaded constructor called during creation
@param name is name of user
@param age is age of user
@param ID is id of user*/
User::User(std::string name, int age, int ID){
    this->name = name;
    this->age = age;
    this->ID = ID;
}

/* Adds a book to the user's list
@param pointer to a book object
@return void*/
void User::addBook(Book* book){
    myBooks.push_back(book);
}

/*Removes a book from the user's list
@param pointer to a book object
@return void*/
void User::removeBook(Book* book){
    for(int i = 0; i < myBooks.size(); i++){
        if(myBooks[i] == book){
            myBooks[i]->setAvailability(true);
            myBooks.erase(myBooks.begin() + i);
            
        }
    }
}

/* Prints all of the user's attributes
@param none*/
void User::printAccount() const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "ID #: " << ID << std::endl;
    std::cout << "Books currently on loan:" << std::endl;
    for(int i = 0; i < myBooks.size(); i++){
        std::cout << myBooks[i]->getTitle() << std::endl;;
    }
}

int User::getBookCount() const{
    return myBooks.size();
}

Book* User::bookAddress(int index) const{
    return myBooks[index];
}

int User::getID() const{
    return ID;
}