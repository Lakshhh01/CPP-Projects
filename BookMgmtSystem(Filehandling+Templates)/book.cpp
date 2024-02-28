#include "book.h"
#include<iostream>
//#include<cstring>
using namespace std;

/////////////////////////////////////-------Constructors------------///////////////////////////////////////////

    Book::Book() {
        strcpy(this->bname, "not given");
        this->id = 0;
        strcpy(this->author, "not given");
        this->pr = 0.0;
        this->rating = 0;
    }

    Book::Book(char* nm, int i, char* auth, double p, int r) {
        this->id = i;
        strcpy(this->bname, nm);
        strcpy(this->author, auth);
        this->pr = p;
        this->rating = r;
    }

    
    
/////////////////////////////////////---------Setters-----------///////////////////////////////////////////


    void Book::setId(int i) {
        this->id = i;
    }

    void Book::setName(char* nm) {
        strncpy(this->bname, nm, sizeof(this->bname) - 1);
        this->bname[sizeof(this->bname) - 1] = '\0';
    }

    void Book::setPrice(double p) {
        this->pr = p;
    }

    void Book::setRating(int r) {
        this->rating = r;
    }

    void Book::setAuthor(char* an) {
        strncpy(this->author, an, sizeof(this->author) - 1);
        this->author[sizeof(this->author) - 1] = '\0';
    }


/////////////////////////////////////---------Getters-----------///////////////////////////////////////////

    int Book::getId() {
        return this->id;
    }

    char* Book::getName() {
        return this->bname;
    }

    double Book::getPrice() {
        return this->pr;
    }

    int Book::getRating() {
        return this->rating;
    }

    char* Book::getAuthor() {
        return this->author;
    }

	
//--------------------------------------------------Display()------------------------------------//
	
	void Book::display(){
															
	  	std::cout << WHITE << std::setw(4) << this->id << " | " << WHITE << std::setw(30) << this->bname << " | " 
        << WHITE << std::setw(20) << this->author << " | " << WHITE << std::setw(8) << std::fixed << std::setprecision(2) << this->pr << " | " 
        << WHITE << std::setw(6) << this->rating << " |" << "\n";
        
		
	}



////////////////////////////////////////////////////////////////////////////////////////////////////////////