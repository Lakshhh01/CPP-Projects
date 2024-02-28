//#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
#include<iostream>
#include<fstream>
#include "book.h"
using namespace std;



/////////////////////////////////////////////////<<--BOOK-->>///////////////////////////////////////////////////////////////////


int main() { 

	DoublyLinkedList<Book> l;                           
    
    int choice;
    do{
    	cout<<"\n\n";
		cout << "\t\t"<< CYAN << "+=====================================+" << RESET << "\n";
	    cout << "\t\t"<<"| "   << "       Library Management System    " << RESET << "|" << "\n";
	    cout << "\t\t"<< CYAN << "+=====================================+" << RESET <<  "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      1. Add New Book" << RESET << "                |" << "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      2. Delete Book Entry" << RESET << "           |" << "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      3. Display Library" << RESET << "             |" << "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      4. Search Book in Library" << RESET << "      |" << "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      5. Update Book in Library" << RESET << "      |" << "\n";
	    cout << "\t\t"<<"|" << YELLOW << "      6. Top 3 Books" << RESET << "                 |" << "\n";
	    cout << "\t\t"<<"|" << RED << "      7. Quit" << RESET << "                        |" << "\n";
	    cout << "\t\t"<< CYAN << "+=====================================+" << RESET << "\n";
	    cout << "\t\t" << YELLOW << "Enter your choice:" <<RESET;
    
	    cin >> choice;

			
		    switch (choice) {		
		        
		       case 1:{
		       	
		       		
		       		int id;
					char bname[30];
			       	double price;
			       	char author[30];
			       	int rating;
			       	cout << MINT << "\nEnter the id of book:" << RESET;
				    cin >> id;
				
				    cout << MINT << "\nEnter the Name of book:" << RESET;
				    fflush(stdin);
				    gets(bname);
				
				    cout << MINT << "\nEnter the author of book:" << RESET;
				    fflush(stdin);
				    gets(author);
				
				    cout << MINT << "\nEnter the price of book:" << RESET;
				    cin >> price;
				
				    cout << MINT << "\nEnter the ratings(out of 10):" << RESET;
				    cin >> rating;
			       	
			       	//---Create Object b---//
			       	Book b(bname,id,author,price,rating);
			       	
			       	if(l.insertEnd(b))	{
						
			       	//---Write to file---//
			       	ofstream out("BookData.bin",ios_base::binary | ios_base::app);
			       	out.write((char*)&b,sizeof(b));

					out.close();
					
					//--------------------//
					cout<<MAGENTA"\n Book entry inserted Successfully ^.^"<<RESET;
					}
			       	
			       	
			       	
					break;
			   }
			   case 2:{
			   	
			   		int pos;
			   		cout<<MINT<<"\n Enter the position you want to delete the Book entry node:";
			   		cin>>pos;
			   		l.deletePosition(pos);
			   		cout << "\n-------------------------------------------------------------------------------------------------\n";
	    			cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
	    			cout << "\n-------------------------------------------------------------------------------------------------\n";
  					l.display();
  					cout << "\n-------------------------------------------------------------------------------------------------\n";
					
					
					
					break;
			   }  
			   case 3:{
			   	
			   		cout << "\n-------------------------------------------------------------------------------------------------\n";
	    			cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
	    			cout << "\n-------------------------------------------------------------------------------------------------\n";
  		
			   		l.display();
			   		
			   		
			   		cout << "\n-------------------------------------------------------------------------------------------------\n";

			   		
					break;
			   }
			   case 4:{
			   
			   
					std::cout <<"\n" <<  "\t\t=====================================" <<  "\n";
				    std::cout <<"\t\t"<< "|      " << MAGENTA << "Search According to... " << RESET << "      |\n";
				    std::cout <<"\t\t"<< "|===================================|\n";
				    std::cout <<"\t\t"<< "| " << YELLOW << "1) ID     " << RESET << "                        |\n";
				    std::cout <<"\t\t"<< "| " << YELLOW << "2) Name " << RESET << "                          |\n";
				    std::cout <<"\t\t"<< "|===================================|\n";
				    std::cout <<"\t\t"<< " Your choice:   ";
					int c;
					cin>>c;
								
								//create a varibale of node* to save the address from p that matched the entry after traversing// 
					if(c==1){
						
						int id;
						cout<<"\n Enter id of book: ";
						cin>>id;
						
				//--create a node pointer (send it null) and it will be received by reference by the search func--//
				//--useful for further update  fucn--//
						Node<Book>* nodeptr=NULL;
						if(l.searchBook(id,nodeptr)){			// search(int,node*) will be called//
							cout << GREEN << "\n ^.^ Book found ^.^" << RESET;
						}else{
							cout<<DARKRED<<"\n Failed to search :("<<RESET;
						}
						
					}
					
					else if(c==2){
						
						char name[40];
						cout<<"\n Enter name: ";
						fflush(stdin);
						gets(name);
						Node<Book>* nodeptr;
						if(l.searchBook(name,nodeptr)){			// search(char*,node*) will be called//
							cout << GREEN << "\n ^.^ Book found... ^.^" << RESET;
						}else{
							cout<<DARKRED<<"\n Failed to search.. :("<<RESET;
						}
						
					}
					else{
						cout<<DARKRED<<"\n Enter valid choice !"	<<RESET;
					}
					
					break;
			   }
			   case 5:{
			   	
		
					
					l.updateBook();
    				
					cout << "\n-------------------------------------------------------------------------------------------------\n";
	    			cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
	    			cout << "\n-------------------------------------------------------------------------------------------------\n";
  		
					l.display();
					cout << "\n-------------------------------------------------------------------------------------------------\n";

				
					/*
					//---Write to file---//
				
					ofstream out("BookData.bin",ios_base::binary );	//binary bhi chahiye aur append bhi karna hai to bitwise or use karo'|'
					
					out.write((char*)&b,sizeof(b));
	
					out.close();
					
					//------------------//
					*/
						
					break;
			   }
			   case 6:{
				   	cout<<MAGENTA<<"\n Loading..."<<RESET;
				   	l.top3();
				   	
					break;
			   }
			   case 7:{
				   	cout<<DARKRED<<"\n Quiting.."<<RESET;
					break;
			   }	
		        default:
		            cout<<DARKRED<<"\n\n\t\tPlease enter valid choice!!\n"<<RESET;
		    }
    	}while(choice!=7);		

	return 0;
}




