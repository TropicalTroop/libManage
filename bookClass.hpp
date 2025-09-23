/* Book Class Definition
Atharva, Nikhil, Po
09/23/25 */
#include <string>

#ifndef BOOK_H
#define BOOK_H

// Class Definition for Book
class Book{
public:
   Book();
   Book(std::string, std::string, int, std::string, bool, int);
   std::string getTitle() const;
   std::string getAuthor() const;
   std::string getGenre() const;
   bool getAvailability() const;
   int getBarcode() const;
   int getISBN() const;
   
private:
   std::string title;
   std::string author;
   int ISBN;
   std::string genre;
   bool availability;
   int barcode;
};

/*
{ Book, bool, int
  Book, bool, int
|
|
V
}
*/
#endif
