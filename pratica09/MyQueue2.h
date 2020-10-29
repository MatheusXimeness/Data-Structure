#ifndef MyQueue2_H__
#define MyQueue2_H__

#include "MyStack.h"
#include <iostream>
using namespace std;

template<class T>
class MyQueue2 {
public:
	MyQueue2() {} 

	void push(const T&el);
	const T front() ; //Nesta implementacao vamos permitir retorno por copia...
	void pop() ;

	bool empty() ;
	int size() ;

private:
	MyStack<T> pilha1; //nao mude nada nessa interface!!!
	MyStack<T> pilha2; //nao mude nada nessa interface!!!
};


/* Faca sua implementacao abaixo desta linha...*/
/* Faca sua implementacao abaixo desta linha...*/
/* Faca sua implementacao abaixo desta linha...*/
/* Faca sua implementacao abaixo desta linha...*/








#endif