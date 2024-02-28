//#include<iostream>
//#include "book.h"
//using namespace std;

template <class T>

class Node{
	T data;
	Node<T>* next;
	Node<T>* prev;
	
	public:
		Node(T);
		
		void setData(T&);
		void setNext(Node<T>*);
		void setPrev(Node<T>*);
		T getData();
		Node<T>* getNext();
		Node<T>* getPrev();
		
//		void display();	
};