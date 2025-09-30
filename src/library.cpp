#include "library.h"

/* Default Constructor
@param none
@return none*/
Library::Library() {
    catalogue = std::vector<Book>();
    userList = std::vector<User>();
}

/* Overloaded constructor
@param std::vector<Book>, std::vector<User>
@return none*/
Library::Library(std::vector<Book> inputCatalogue, std::vector<User> inputList){
    catalogue = inputCatalogue;
    userList = inputList;
}

/* Book check out function
@param Book, User
@return none*/
void Library::checkoutBook(const Book& b1, User& u1){
    Book* availableCopy = findBookCopies(b1);
    if (availableCopy != nullptr) {
        availableCopy->setAvailability(false);
        u1.addBook(availableCopy);
        return;
    }

    for(int i = 0; i < catalogue.size(); i++){
        if(catalogue[i].getISBN() == b1.getISBN()){
            if(catalogue[i].getAvailability() == true){
                catalogue[i].setAvailability(false);
                u1.addBook(&catalogue[i]);
                return;
            }
        }
    }

}

/* Function to return books
@param address of Book object
@return void*/
void Library::returnBook(const Book& b1){
    for(int i = 0; i < userList.size(); i++){
        for(int j = 0; j < userList[i].getBookCount(); j++){
            if(b1.getISBN() == userList[i].bookAddress(j)->getISBN()){
                userList[i].removeBook(userList[i].bookAddress(j));
                return;
            }
        }
    }
}

/* Function to return pointer to available copy of book
@param address of Book Object
@return pointer to book object*/
Book* Library::findBookCopies(const Book& target){
    for(int i = 0; i < catalogue.size(); i++){
        if(target.getISBN() == catalogue[i].getISBN() && catalogue[i].getAvailability() != false){
            return &catalogue[i];
        }
    }

    return nullptr;
}

/* Function to return availability of book
@param Book object
@return boolean*/
bool Library::getBookStatus(const Book b1) const{
    return b1.getAvailability();
}

/* Function to print all details of book
@param book object
@return boolean*/
void Library::bookDetails(const Book b1) const{
    b1.printBook();
}

/*Function to add a book to the end of catalogue
@param book
@return void*/
void Library::addBook(const Book b1){
    catalogue.push_back(b1);
}

/*Function to remove a book from the catalogue
@param address of Book object
@return void*/
void Library::removeBook(const Book& target){
    for(int i = 0; i < catalogue.size(); i++){
        if(target.getBarcode() == catalogue[i].getBarcode()){
            if(catalogue[i].getAvailability() != true){
                returnBook(target);
            }
            catalogue.erase(catalogue.begin() + i);
        }
    }
}

/* Function to add a user to the list of users
@param address of user object
@return void*/
void Library::addUser(const User& u1){
    userList.push_back(u1);
}

/* Function to remove a user from the list of users
@param address of the user
@return void*/
void Library::removeUser(const User& target){
    for(int i = 0; i < userList.size(); i++){
        if(target.getID() == userList[i].getID()){
            userList.erase(userList.begin() + i);
        }
    }
}

