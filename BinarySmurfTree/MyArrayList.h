#pragma once
#include "Node.h"


template<class T>
class MyArrayList
{
public:
	MyArrayList();
	void add(T aData);
	void addAt(T aData);
	void print();
	T popTail();
	T popHead();

	int getSize();
	T at(int index);


	void sort();


private:
	int _size = 0;

	LLNode<T>* _head;
	LLNode<T>* _tail;
};

