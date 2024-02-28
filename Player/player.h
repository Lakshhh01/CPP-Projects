#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>

using namespace std;

class Player {
//---------------------------------------------------------state:---------------------------------------------------------//

    char pname[30];		
    int jersey_no;			
    int runs;	
    int wickets;			
    int matches;
  
  	public:
//----------------------------//----------------constructors:-------------------------//-----------------------------//
    Player() ;
    Player(char* , int , int , int , int ) ;


//---------------------------------//----------------------setters--------------------//-----------------------------//
    void setjersey_no(int ) ;
    void setName(char* );
    void setRuns(int );
    void setWickets(int );
    void setMatches(int ) ;
//-------------------------------//----------------------getters-----------------------//------------------------------//
    int getjersey_no() ;
    char* getName() ;
    int getRuns();
    int getWickets();
    int getMatches();
    
//member-functions//
	void update();
	void display();
  
};


void store(Player* , int* ) ;
void add_Player(Player* , int* );
void search_Player(Player* , int );
void remove_Player(Player* , int* );
void top_ratings(Player* b, int n) ;