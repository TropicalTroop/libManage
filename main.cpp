/*
library management system
created by Atharva, Nikhil, Po
CS116 - Prof. Chenhansa
*/ 

#include <iostream>
#include <vector>
#include <string>
#include "src/book.h"
#include "src/library.h"
#include "src/user.h"
int main(){
	
	//get user name
	std::string userName;
	int userAge = 0;
	int userID = 0;
	std::cout << "Hi, please enter your name: ";
	std::cin >> userName;

	//get user age
	std::cout << "Please enter your age: ";
	while (!(std::cin >> userAge) || userAge <= 0) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input. Please enter a positive integer age: ";
	}

	userID = rand()%10000;

	
	//initialize the books
	int barcode = 1001;
	std::vector<Book> catalogue;
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 1", "J.K. Rowling", 353403, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 2", "J.K. Rowling", 353404, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 3", "J.K. Rowling", 353405, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 4", "J.K. Rowling", 353406, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 5", "J.K. Rowling", 353407, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){ 
		Book inputBook("Harry Potter 6", "J.K. Rowling", 353408, "Fantasy", barcode, true);
		catalogue.push_back(inputBook);
		barcode++;
	}
	for(int i = 0; i < 3; i++){
		Book inputBook("Harry Potter 7", "J.K. Rowling", 353409, "Fantasy", barcode, true); 
		catalogue.push_back(inputBook);
		barcode++;
	}
	
	// add books into library
	Library lib;
	for (int i = 0; i < static_cast<int>(catalogue.size()); ++i) {
		lib.addBook(catalogue[i]);
	}
	
	User currentUser(userName, userAge, userID);
	lib.addUser(currentUser);

	
	//use barcode to know the books which borrowed by user
	std::vector<int> borrowed;
	
	//user interface list
	bool execute = true;
	while(execute){
		std::cout << "Library Menu: " <<std::endl;
		std:: cout << "Hello, " << userName << " (ID " << userID << ") " << std::endl;
		std::cout << "1) Show catalogue\n";
		std::cout << "2) Checkout a  book (by barcode)\n";
		std::cout << "3) Return a book (by barcode)\n";
		std::cout << "4) Show my current books\n";
		std::cout << "0) Exit\n";
		std::cout << "Choose: ";
		
		//enter the choice and input validation
		int choice;
		if (!(std::cin >> choice)) {             
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input. Please enter 0-4.\n";
			continue;
		}
		if (choice < 0 || choice > 4) {          
			std::cout << "Invalid input. Please enter 0-4.\n";
			continue;
		}

		//show catalogue
		if (choice == 1){
			std::cout << "Catalogue: " << std::endl;
			for(int i = 0; i < static_cast<int>(catalogue.size()); i++){
				const Book& b = catalogue[i];
				bool available = lib.getBookStatus(b);
				std::cout << "Title: " << b.getTitle() << " Barcode: " << b.getBarcode();
				if(available){std::cout << "Available" << std::endl;}
				else{std::cout << "Checked out" << std::endl;}
			}
		}
		
		//checkout a book by barcode
		else if(choice == 2){
			std::cout << "Enter barcode to checkout: ";
			int code;
			if(!(std::cin >> code)){
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue;
			}
				
			int found = -1;
			for (int i = 0; i < static_cast<int>(catalogue.size()); i++) {
				if (catalogue[i].getBarcode() == code) { 
					found = i; 
					break; 
				}
			}
			if (found == -1) {
				std::cout << "No such barcode\n";
			} 
			else if (!lib.getBookStatus(catalogue[found])) {
				std::cout << "That copy is not available\n";
			} 
			else {
				lib.checkoutBook(catalogue[found], currentUser);
				borrowed.push_back(found);
				std::cout << "Checked out: " << catalogue[found].getTitle() << " Barcode: " << code << std::endl;
			}
		}
		
		//return a book by barcode
		else if (choice == 3) { 
			if (borrowed.empty()) {
				std::cout << "You have no books to return.\n";
			} else {
				std::cout << "Your borrowed books: " << std::endl;
				for (int i = 0; i < static_cast<int>(borrowed.size()); i++) {
					int index = borrowed[i];
					std::cout << "Title: " << catalogue[index].getTitle() << " Barcode: " << catalogue[index].getBarcode() << std::endl;
				}

				std::cout << "Enter barcode to return: ";
				int code;
				if (!(std::cin >> code)) {
					std::cin.clear(); 
					std::cin.ignore(10000, '\n'); 
					continue;
				}

				int pos = -1;
				for (int i = 0; i < static_cast<int>(borrowed.size()); i++) {
					if (catalogue[borrowed[i]].getBarcode() == code) {
						pos = i;
						break;
					}
				}

				if (pos == -1) {
					std::cout << "You don’t have that book.\n";
				} 
				else {
					int index = borrowed[pos];
					lib.returnBook(catalogue[index]);
					std::cout << "Returned: " << catalogue[index].getTitle()<< " Barcode: " << code << std::endl;
					int n = static_cast<int>(borrowed.size());
					for(int i = pos; i < n - 1; i++){
						borrowed[i] = borrowed[i+1];
					}
					borrowed.pop_back();
				}
			}
		}
		
		//show my current books
		else if (choice == 4) {
			std::cout << "Books you have checked out: " << std::endl;
			if (borrowed.empty()) {
				std::cout << "None\n";
			} 
			else {
				for (int i = 0; i < static_cast<int>(borrowed.size()); i++) {
					int index = borrowed[i];
					std::cout << catalogue[index].getTitle() << " Barcode: " << catalogue[index].getBarcode() << std::endl;
				}
			}
		}
		
		//Exit
		else if (choice == 0) {
			execute = false;
			std::cout << "Goodbye, " << userName << "!\n";
		}		
	
	}
return 0;	
}

