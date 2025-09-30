#include "book.h"


Book::Book(){
    title = "";
    author = "";
    ISBN = 0;
    genre = "";
    availability = true;
    barcode = 0;        
}

Book::Book(std::string title, std::string author, int ISBN, std::string genre, int barcode, bool availability){
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->genre = genre;
    this->barcode = barcode;
    this->availability = availability;
}


std::string Book::getTitle() const{
    return title;
}


std::string Book::getAuthor() const{
    return author;
}


std::string Book::getGenre() const{
    return genre;
}


int Book::getISBN() const{
    return ISBN;
}


bool Book::getAvailability() const{
    return availability;
}


int Book::getBarcode() const{
    return barcode;
}


void Book::setAvailability(bool updateAvailability){
    availability = updateAvailability;
}

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