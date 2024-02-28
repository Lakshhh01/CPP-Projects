//#include "node.h"
#include "node.cpp"
#include<string.h>

template <class T>
class DoublyLinkedList{
	Node<T>* start;
	
	public:
		
	DoublyLinkedList();	//constructor
	~DoublyLinkedList();
	
	bool insertEnd(T&);
//	bool insertPosition(Book&,int); 
	void deletePosition(int);
	
	//--function overloading--//
	bool searchBook(int,Node<T>*&);
	bool searchBook(const char*,Node<T>*&);
	
	void updateBook();
	void top3();
	void display();

};
