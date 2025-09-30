#include "library.h"

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
void Library::checkoutBook(Book b1, User u1){
    if(b1.getAvailability() == false){
        b1 = findBookCopies(b1);
    }
    b1.setAvailability(false);
    u1.addBook(&b1);
    
}

void Library::returnBook(Book b1){
    for(int i = 0; i < userList.size(); i++){
        for(int j = 0; j < userList[i].getBookCount(); j++){
            if(b1.getISBN() == userList[i].bookAddress(j)->getISBN()){
                userList[i].removeBook(userList[i].bookAddress(j));
                b1.setAvailability(true);
            }
        }
    }
}

Book Library::findBookCopies(Book target){
    for(int i = 0; i < catalogue.size(); i++){
        if(target.getISBN() == catalogue[i].getISBN() && catalogue[i].getAvailability() != false){
            return catalogue[i];
        }
    }
}

bool Library::getBookStatus(Book b1){
    return b1.getAvailability();
}

void Library::bookDetails(Book b1){
    b1.printBook();
}

void Library::addBook(Book b1){
    catalogue.push_back(b1);
}

void Library::removeBook(Book target){
    for(int i = 0; i < catalogue.size(); i++){
        if(target.getBarcode() == catalogue[i].getBarcode()){
            if(catalogue[i].getAvailability() != true){
                returnBook(target);
            }
            catalogue.erase(catalogue.begin() + i);
        }
    }
}

void Library::addUser(User u1){
    userList.push_back(u1);
}

void Library::removeUser(User target){
    for(int i = 0; i < userList.size(); i++){
        if(target.getID() == userList[i].getID()){
            userList.erase(userList.begin() + i);
        }
    }
}

