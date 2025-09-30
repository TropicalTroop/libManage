/* Book Class Definition
Atharva, Nikhil, Po
09/23/25 */
#include <string>
#include <iostream>

#ifndef BOOK_H
#define BOOK_H

// Class Definition for Book
class Book{
public:
   /*Default constructor for Book
   @param none */
   Book(); 
   
   /* Overloaded constructor for Book
   @param Title (string), Author (string) ISBN (int) Genre (string) Barcode (int)*/
   Book(std::string, std::string, int, std::string, int, bool);
   
   /* Returns the title of the book
   @param none
   @return std::string*/
   std::string getTitle() const;
   
   /* Returns author of the book
   @param none
   @return std::string*/
   std::string getAuthor() const;

   /* Returns genre of the book
   @param none
   @return std::string*/
   std::string getGenre() const;

   /* Returns availability of the book
   @param none
   @return bool*/
   bool getAvailability() const;
   
   /* Returns Barcode of the book
   @param none
   @return int*/
   int getBarcode() const;
   
   /* Returns the ISBN of the book
   @param none
   @return integer*/
   int getISBN() const;

   /* Sets availability of the book
   @param bool
   @return none*/
   void setAvailability(bool);

   /* Prints all traits of book
   @param none
   @return none*/
   void printBook() const;
   
private:
   std::string title; //Stores the title as std::string
   std::string author; //stores the author as std::string
   int ISBN; //stores ISBN as integer
   std::string genre; //stores genre as std::string
   bool availability; //stores availability as bool
   int barcode; //stores barcode as integer
};

#endif
