#include "node.h"


/////////////////////////////////Constructor////////////////////////////////////////

template <class T>
Node<T>::Node(T b){
	this->data=b;
	this->next=nullptr;
	this->prev=nullptr;
}

/////////////////////////////////Setters////////////////////////////////////////


template <class T>
void Node<T>::setData(T& b){
	this->data=b;
}


template <class T>
void Node<T>::setNext(Node<T>* n){
	this->next=n;
}

template <class T>
void Node<T>::setPrev(Node<T>* p){
	this->prev=p;
}

/////////////////////////////////Getters////////////////////////////////////////
template <class T>
T Node<T>::getData(){
	return this->data;
}

template <class T>
Node<T>* Node<T>::getNext(){
	return this->next;
}

template <class T>
Node<T>* Node<T>::getPrev(){
	return this->prev;
}


/////////////////////////////////Display////////////////////////////////////////

//void Node::display(){
//	cout<<"\n Data: ";
//	this->getData().display();
//	cout<<"\n Address in Next:"<<this->getNext();
//	cout<<"\n Address in prev:"<<this->getPrev();
//}


