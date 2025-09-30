#include "book.h"

/*Default constructor for Book
@param none */
Book::Book(){
    title = "";
    author = "";
    ISBN = 0;
    genre = "";
    availability = true;
    barcode = 0;        
}

/* Overloaded constructor for Book
@param Title (string), Author (string) ISBN (int) Genre (string) Barcode (int)*/
Book::Book(std::string title, std::string author, int ISBN, std::string genre, int barcode, bool availability){
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->genre = genre;
    this->barcode = barcode;
    this->availability = availability;
}

/* Returns the title of the book
@param none
@return std::string*/
std::string Book::getTitle() const{
    return title;
}

/* Returns author of the book
@param none
@return std::string*/
std::string Book::getAuthor() const{
    return author;
}

/* Returns genre of the book
@param none
@return std::string*/
std::string Book::getGenre() const{
    return genre;
}

/* Returns the ISBN of the book
@param none
@return integer*/
int Book::getISBN() const{
    return ISBN;
}

/* Returns availability of the book
@param none
@return bool*/
bool Book::getAvailability() const{
    return availability;
}

/* Returns Barcode of the book
@param none
@return int*/
int Book::getBarcode() const{
    return barcode;
}

/* Sets availability of the book
@param bool
@return none*/
void Book::setAvailability(bool updateAvailability){
    availability = updateAvailability;
}

/* Pritns all traits of book
@param none
@return none*/
void Book::printBook() const{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    if(getAvailability() == true){
        std::cout << "This book is available" << std::endl;
    }
    else{
        std::cout << "This book is unavailable" << std::endl;
    }
}