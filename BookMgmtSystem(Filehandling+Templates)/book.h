#include<iostream>

#include<iomanip>
#include<fstream>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef BOOK_H
#define BOOK_H

#define MINT    "\033[38;2;152;255;152m" // Mint color code
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[37m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define DARKRED     "\033[0;31m" // Dark red color code


//using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//template <class T>
class Book {
	
    char bname[30];
    int id;
    char author[20];
    double pr;
    int rating;
 
    public:
//-------------------------/////////////////Constructors///////////////-------------------------------//

    Book() ;
    
    Book(char* nm, int i, char* auth, double p, int r);

   
//--------------------------------------------Mutators/setters----------------------------------------------//

    void setId(int i) ;
    
    void setName(char* nm) ;

    void setPrice(double p) ;

    void setRating(int r) ;

    void setAuthor(char* an);
    
//---------------------------------------getters/accesssors---------------------------------------------------//
    int getId() ;

    char* getName() ;

    double getPrice();

    int getRating() ;

    char* getAuthor() ;
    
//--------------------------/////////////////Member Methods///////////////----------------------------//

    
	void update();	
	void display();
};

//--------------------------/////////////////Non Member Methods///////////////----------------------------//

//void store(Book* , int* ) ;
//void add_Book(Book* , int* );
//void search_Book(Book* , int ) ;
//void top_ratings(Book* , int );
//void remove_Book(Book* , int* ) ;
#endif
