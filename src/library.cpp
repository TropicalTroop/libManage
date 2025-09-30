#include "library.h"

Library::Library() {
    // Initialize empty vectors
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

Book* Library::findBookCopies(const Book& target){
    for(int i = 0; i < catalogue.size(); i++){
        if(target.getISBN() == catalogue[i].getISBN() && catalogue[i].getAvailability() != false){
            return &catalogue[i];
        }
    }

    return nullptr;
}

bool Library::getBookStatus(const Book b1) const{
    return b1.getAvailability();
}

void Library::bookDetails(const Book b1) const{
    b1.printBook();
}

void Library::addBook(const Book b1){
    catalogue.push_back(b1);
}

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

void Library::addUser(const User& u1){
    userList.push_back(u1);
}

void Library::removeUser(const User& target){
    for(int i = 0; i < userList.size(); i++){
        if(target.getID() == userList[i].getID()){
            userList.erase(userList.begin() + i);
        }
    }
}

