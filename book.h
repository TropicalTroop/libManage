/* Book Class Definition
Atharva, Nikhil, Po
09/23/25 */
#include <string>

#ifndef BOOK_H
#define BOOK_H

// Class Definition for Book
class Book{
public:
   Book(); //Default Constructor
   
   Book(std::string, std::string, int, std::string, int);
   //Takes in Title, Author, ISBN, genre, and barcode into overloaded constructor.
   
   std::string getTitle() const;
   //Returns the book's title as std::string.
   
   std::string getAuthor() const;
   //returns book's author as std::string.
   
   std::string getGenre() const;
   //returns book's genre as std::string.
   
   bool getAvailability() const;
   //returns book's availability as true or false bool.
   
   int getBarcode() const;
   //returns the book's barcode as an integer
   
   int getISBN() const;
   //returns book's ISBN as an integer.
   
private:
   std::string title; //Stores the title as std::string
   std::string author; //stores the author as std::string
   int ISBN; //stores ISBN as integer
   std::string genre; //stores genre as std::string
   bool availability; //stores availability as bool
   int barcode; //stores barcode as integer
};

#endif
