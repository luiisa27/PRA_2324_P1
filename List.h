#include <iostream>
#ifndef LIST_H
#define LIST_H
using namespace std;

template<typename T>

class List {
	public:
		virtual void insert(int pos, T e)=0; //inserta e en pos
		virtual void append(T e)=0;//inserta e al principio de la lista
		virtual void prepend(T e)=0;//inserta e al final de la lista
		virtual T remove(int pos)=0; //elimina e en pos y lo devuelve 
		virtual T get(int pos)=0;//devuelve el elemento situado en pos
		virtual bool empty()=0; //lista vacia true or false
		virtual int size()=0;//numero de elementos de la lista
};

#endif

