#include "DoublyLinkedList.h"
#include "book.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//////////////////////////////////////<<--Constructor-->>//////////////////////////////////////////////////

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
		
	this->start=NULL;
	
	//--read the existing data from file--//
	ifstream in("BookData.bin", ios_base::binary | ios_base::app);

	// Check if the file is empty
	if (in.peek() == EOF) {
	    cout << MINT << "\n\t\t^.^ Empty Book Shelf..Want to Add books? ^.^\n" << RESET;
	} 
	else{
	
		Book bookentry;				//create an object varibale of book to store each entry from file
		 
		//--1)read from file--//			
		while(in.read((char*)&bookentry,sizeof(bookentry))){
							
		//--2,3)create and insert each node created for each book entry--//
			insertEnd(bookentry);

		}

	}
		
}




///////////////////////////////////////////////<<--Destructor-->>/////////////////////////////////////////

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	cout<<"\n Destructor called\n";

	if(start!=NULL){
		
		Node <T>*p=start;		
			
		ofstream out("BookData.bin",ios_base::binary );	//dont use append mode so that you can overwrite
		
		
		while(start!=NULL){			 //until start does not get value null into it
		
			start=p->getNext();		 //traverse start 
			
			//--store the current node data into a book object variable--//
			Book booknodedata=p->getData();
			
//			booknodedata.display();

			//--write that object into the file--//
			out.write((char*)&booknodedata,sizeof(booknodedata));
			
			//--delete the node--//
			delete  p;
			p=start;				
		}
		
        out.close();		

	}
	else{
		cout<<DARKRED<<"\n NO Nodes"<<RESET	;
	}	
	
					
	
}

	
//////////////////////////////////////<<--Insertion-->>/////////////////////////////////////////////////////

template <class T>
bool DoublyLinkedList<T>::insertEnd(T& b){
	Node<T>* temp=new Node<T>(b);
	if(start==NULL){
		start=temp;
		return true;
	}
	Node<T> *p=start;
	while(p->getNext()!=NULL){
		p=p->getNext();
		
	}
	temp->setPrev(p);
	p->setNext(temp);
	return true;
	
}



//
//bool DoublyLinkedList::insertPosition(Book& b,int pos){
//	Node* temp=new Node(b);
//	if(start==NULL){
//		start=temp;
//		return true;
//	}
//	if(pos==1){
//		temp->setNext(start);
//		start->setPrev(temp);
//		start=temp;
//		return true;
//	}
//	int i=1;
//	Node* p=start;
//	while(i<pos-1 && p->getNext()!=NULL){	//position linked list mei agar nahi hogi, to list k end m node ko add krdiya jayega
//		p=p->getNext();						
//		i++;
//	}
//	
//	temp->setNext(p->getNext());
//	temp->setPrev(p);
//	p->setNext(temp);
//	//this condition is checking for both scenarios:
//	//for temp to insert into middle, aur else if node is being added at last;
//	//then temp ke next mei null ko replace nahi karna hai isliye, temp->getNext me null nahi chahiye!!
//	if(temp->getNext()!=NULL){
//		temp->getNext()->setPrev(temp);
//		
//	}
//	return true;
//		
//}

/////////////////////////////////////////////<<--Deletion-->>///////////////////////////////////////////////

template <class T>
void DoublyLinkedList<T>::deletePosition(int position){
	
	//if your list is empty
	if(start==NULL){
		cout<<DARKRED<<"\n NO NODES TO DELETE..."<<RESET;
		return;
	}
	else{
		
		Node<T>* p=start; //keep first the address in p(100)
		
		//if there is only one node
		if(position==1){
			start=start->getNext();	
			cout<<RED<<"----------------------------------------------------------------------------------\n"<<RESET;
			p->getData().display();
			cout<<RED<<"----------------------------------------------------------------------------------\n\n"<<RESET;

			cout<<DARKRED<<"\n  is being deleted...! \n"<<RESET;
			cout<<"\n  Updated list... \n";
			delete p;
			return;
		}
		//for multiple nodes:
		int i=1;
		
		while(i<position-1 && p->getNext()!=NULL){		//run i until,position -1 and also check for last node condition
			p=p->getNext();
			i++;
		}
		
		//i will be on position-1 now
		if(i==position-1 && p->getNext()!=NULL){
			
			//take a new node pointer that will store the address of position node
			Node<T>* q=p->getNext();
					
			// if the node being deleted is last node of list
			if(q->getNext()==NULL){
				p->setNext(NULL);
			}
			
			// if the node being deleted is in middle somewhere of list
			if(q->getNext()!=NULL){
				q->getNext()->setPrev(p);
			}
			
			p->setNext(q->getNext());
			cout<<"\n";
			
			cout<<RED<<"-----------------------------------------------------------------------------------\n"<<RESET;
			q->getData().display();
			cout<<RED<<"-----------------------------------------------------------------------------------\n\n"<<RESET;
			cout<<DARKRED<<"\n  is being deleted...! \n"<<RESET;
			cout<<"\n Updated List...\n";
			
			delete q;
			return ;
		}
		else{
			cout<<DARKRED<<"\n Invalid"<<RESET;
		}
			
	}
	 // Write the updated list to the file after deletion
        ofstream out("BookData.bin", ios_base::binary);
        Node<T>* temp = start;

        while (temp != NULL) {
            Book bookData = temp->getData();
            out.write((char*)&bookData, sizeof(bookData));
            temp = temp->getNext();
        }

        out.close();
}



/////////////////////////////////////////////////<<--Display-->>////////////////////////////////////////////////

template <class T>
void DoublyLinkedList<T>::display(){
	if(start==NULL){
		cout<<DARKRED<<"\n No Node to display"<<RESET;
		return ;	
	}
	Node<T>* p=start;
	while(p!=NULL){
		p->getData().display();
		cout<<"\n";
		p=p->getNext();
	}
	

}
	



/////////////////////////////////////////////<<--Search-->>////////////////////////////////////////////////////


//function for search by id:
template <class T>
bool DoublyLinkedList<T>::searchBook(int id,Node<T>* &nodeptr){ //recieve the pointer variable->nodeptr by reference
	
	if(start==NULL){
		cout<<DARKRED<<"\nCan't search into empty list."<<RESET;
		
		nodeptr=NULL;			
		return false;
	}
		int flag=0;
		//--create a pointer p to traverse through list--//
		Node<T>* p=start;		
		
		while(p!=NULL){
			if(id==p->getData().getId()){
				
				nodeptr=p;				//put the addredd in p of that book found into node_ptr 
				flag=1;
				break;
			}
			//if id not found yet, traverse further
			p=p->getNext();
		}
		
		
		if(flag==1){
			
			cout << MAGENTA << "\n SEARCHING...\n" << RESET;
			
			cout << "\n-------------------------------------------------------------------------------------------------\n";
			cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
			cout << "\n-------------------------------------------------------------------------------------------------\n";
			
			//nodeptr contains the address of the book found
			nodeptr->getData().display();
			cout << "\n-------------------------------------------------------------------------------------------------\n";					
			return true;		
		}
		
			return false;
		
		
}


//function for search by name:
template <class T>
bool DoublyLinkedList<T>::searchBook(const char* name,Node<T>* &nodeptr){	//recieve the pointer var. ->nodeptr by reference
	
	if(start==NULL){
		cout<<DARKRED<<"\nCan't search into empty list."<<RESET;
		
		nodeptr=NULL;			
		return false;
	}
		int flag=0;
		//--create a pointer p to traverse thru list--//
		Node<T>* p=start;		
		
		while(p!=NULL){
			if(stricmp(name,p->getData().getName())==0){
				
				nodeptr=p;				//put the addredd in p of that book found into node_ptr 
				flag=1;
				break;
			}
			//if id not found yet, traverse further
			p=p->getNext();
		}
		
		
		if(flag==1){
			
			cout << MAGENTA << "\n SEARCHING...\n" << RESET;
			
			cout << "\n-------------------------------------------------------------------------------------------------\n";
			cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
			cout << "\n-------------------------------------------------------------------------------------------------\n";
			
			//nodeptr contains the address of the book found
			nodeptr->getData().display();
			cout << "\n-------------------------------------------------------------------------------------------------\n";					
			return true;
						
		}
		
			
			return false;
		
		
}


////////////////////////////////////////////<<--Update-->>////////////////////////////////////////////////////

template <class T>
void DoublyLinkedList<T>::updateBook(){
	if(start==NULL){
		cout<<DARKRED<<"\n No Book Entries to update"<<RESET;
		return ;	
	}
	
	int flag=0;				//until book is found
	
	
	cout<<"\n Enter if you want to \n1)update by id\n2)update by name ";
	int c;
	cin>>c;
	Node<T>* nodeptr=NULL;

	if(c==1){
		int id;
		cout<<"\nEnter the id of book you want to update:";
		cin>>id;
		//--function call--//
		searchBook(id,nodeptr);	//nodeptr will not be null now, it will contain some address of the node found--//	
		
	}else if(c==2){
		char name[40];
		cout<<"\nEnter the name of book you want to update:";
		fflush(stdin);
		gets(name);
		//--function call--//
		searchBook(name,nodeptr);				
		
	}else{
		cout<<DARKRED<<"Invalid choice!"<<RESET;
		return;
	}


	if(nodeptr!=NULL){	 //means the nodeptr contains address of book found after search()--//
	
		
		int choice;
        cout <<MINT<< "What do you want to update?\n"<<RESET;
        cout <<MINT<< "1- Price.\n2- Ratings.\n"<<RESET;
        cout <<MINT<< "Enter your choice: "<<RESET;

        cin >> choice;

		switch(choice){
			case 1:{
				double pr;
				cout<<"\nEnter the updated price:" ;
				cin>>pr;
				cout << MAGENTA << "\n UPDATING...\n" << RESET;
				
				
				T b=nodeptr->getData();		//create a temp object variable  b
				b.setPrice(pr);					//update price for b					
				nodeptr->setData(b);			//assign that temp variable nodeptr					
				break;
			}	
			case 2:{
				int r;
				cout<<"\nEnter the updated ratings(out of 10):" ;
				cin>>r;
				cout << MAGENTA << "\nUPDATING...\n" << RESET;
				
				
				T b=nodeptr->getData();
				b.setRating(r);
				nodeptr->setData(b);
				break;
			}
			default:{
				cout<<DARKRED<<"\n Invalid choice!"<<RESET;

			}
		}
		cout <<CYAN<< "\n\nBOOK information updated successfully.\n"<<RESET;
		return;
	
	}
		cout<<DARKRED<<"\n Failed to Update...!!"<<RESET;
		
}

/////////////////////////////////////////////<<--TOP3-->>/////////////////////////////////////////////////////

template <class T>
void DoublyLinkedList<T>::top3(){
	if(start==NULL){
		cout<<DARKRED<<"\n No Book entries to sort.."<<RESET;
		return;
	}
	Node<T>* p=start;
	
	T Top1book;		//fmax
	T Top2book;		//smax
	T Top3book;		//tmax
	
	std::cout <<"\n" << GREEN << "\t\t=====================================" << RESET << "\n";
    std::cout <<"\t\t"<< "|      " << GREEN << "Sort According to...   " << RESET << "      |\n";
    std::cout <<"\t\t"<< "|===================================|\n";
    std::cout <<"\t\t"<< "| " << YELLOW << "1) Ratings" << RESET << "                        |\n";
    std::cout <<"\t\t"<< "| " << YELLOW << "2) Price" << RESET << "                          |\n";
    std::cout <<"\t\t"<< "|===================================|\n";
    std::cout <<"\t\t"<< " Your choice:   ";
    
    
    
	int c;
	cin>>c;
	if(c==1){
	
	//--set all the three book object ratings min of all--//
	
	Top1book.setRating(-1);
	Top2book.setRating(-1);
	Top3book.setRating(-1);
	
	//--loop and take the concept of first 3 max nos in array--//
		while(p!=NULL){
			
			
			if(p->getData().getRating()>Top1book.getRating()){
				
				Top3book=Top2book;						//tmax=smax
				Top2book=Top1book;						//smax=fmax
				Top1book=p->getData();					//fmax=arr[i]
			}
			else if(p->getData().getRating()>Top2book.getRating()){
				
				Top3book=Top2book;						//tmax=smax
				Top2book=p->getData();					//smax=arr[i]
				
			}
			else if(p->getData().getRating()>Top3book.getRating()){		
				
				Top3book=p->getData();					//tmax=arr[i]
				
			}
			
			p=p->getNext();
		}
		
		cout<<MAGENTA<<"\n \t\t****Top3 Books According to Ratings****\n"<<RESET;
		cout << "\n-------------------------------------------------------------------------------------------------\n";
	    cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
	    cout <<"\n-------------------------------------------------------------------------------------------------\n";
  		
		if(Top1book.getRating()!=-1){
  			Top1book.display();
		}
		if(Top2book.getRating()!=-1){
  			Top2book.display();
		}
		if(Top3book.getRating()!=-1){
  			Top3book.display();
		}
		cout << "\n-------------------------------------------------------------------------------------------------\n";

		
	}
	else if(c==2){
		while(p!=NULL){
			if(p->getData().getPrice()>Top1book.getPrice()){
					
					Top3book=Top2book;						//tmax=smax
					Top2book=Top1book;						//smax=fmax
					Top1book=p->getData();					//fmax=arr[i]
				}
				else if(p->getData().getPrice()>Top2book.getPrice()){
					
					Top3book=Top2book;						//tmax=smax
					Top2book=p->getData();					//smax=arr[i]
					
				}
				else if(p->getData().getPrice()>Top3book.getPrice()){		
									
					Top3book=p->getData();					//tmax=arr[i]
					
				}
			
				
			p=p->getNext();
		}
		cout<<MAGENTA<<"\n \t\t****Top3 Books According to Price****\n"<<RESET;
		cout << "\n-------------------------------------------------------------------------------------------------\n";
	    cout << setw(4) << "ID" << " | " << setw(30) << "Book Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
	    cout << "\n-------------------------------------------------------------------------------------------------\n";
  		
  		if(Top1book.getPrice()){
  			Top1book.display();
		}
		if(Top2book.getPrice()){
  			Top2book.display();
		}
		if(Top3book.getPrice()){
  			Top3book.display();
		}
		
		cout <<"\n-------------------------------------------------------------------------------------------------\n";

	}
	else{
		cout<<DARKRED<<"\t\t"<<"\n Enter valid choice!"<<RESET;
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


