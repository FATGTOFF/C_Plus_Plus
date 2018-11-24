//header file for the PQLinkedList class

#ifndef PQLINKEDLIST_H
#define PQLINKEDLIST_H
#include "SingleLinkedList.h"


//class definition
template <class T>
class PQLinkedList
{
private:
	LinkedList<T> list;

public:
	void Enqueue(T newItem);
	void Dequeue(T& item);
	void MakeEmpty();
	void ResetCount();
	int GetLengthList() const;
	int GetEnqueueCount() const;
	int GetDequeueCount() const;
	int GetTotalCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
};


//********************************************
//Enqueue function                           *
//inserts new item into queue                *
//********************************************
template <class T>
void PQLinkedList<T>::Enqueue(T newItem)
{
	list.insertNode(newItem);
}

//********************************************
//Dequeue functionnn                         *
//removes item from queue                    *
//********************************************
template <class T>
void PQLinkedList<T>::Dequeue(T& item)
{

	if (list.getLength() <= 0)	//head node is removed, because it is priority queue
	{
		throw EmptyPQ();
	}

	list.pop(item);
}

//*******************************************
//makeEmpty function                        *
//empties the list                          *
//*******************************************
template <class T>
void PQLinkedList<T>::MakeEmpty()
{
	list.makeEmpty();
}

//********************************************
//ResetCount function                        *
//resets the counter                         *
//********************************************
template <class T>
void PQLinkedList<T>::ResetCount()
{
	list.resetCount();
}

//********************************************
//GetLengthList function                     *
//returns the lenght                         *
//********************************************
template <class T>
int PQLinkedList<T>::GetLengthList() const
{
	return list.getLength();
}

//********************************************
//GetEnqueueCount function                   *
//returns the EnqueueCount                   *
//********************************************
template <class T>
int PQLinkedList<T>::GetEnqueueCount() const
{
	return list.getEnqueueCount();
}

//********************************************
//GetDequeueCount function                   *
//returns the dequeue count                  *
//********************************************
template <class T>
int PQLinkedList<T>::GetDequeueCount() const
{

	return list.getDequeueCount();
}

//********************************************
//GetTotalCount function                     *
//returns the totalCount                     *
//********************************************
template <class T>
int PQLinkedList<T>::GetTotalCount() const
{

	return list.getTotalCount();
}

//********************************************
//IsEmpty function                           *
//checks if the list is empty                *
//********************************************
template <class T>
bool PQLinkedList<T>::IsEmpty() const
{
	bool empty{};
	if (GetLength() == 0)
		empty = true;
	else
		empty = false;

	return empty;
}

//********************************************
//IsFull function                            *
//checks if the list is full                 *
//********************************************
template <class T>
bool PQLinkedList<T>::IsFull() const
{
	//not going to implment a check to see if system is out of memory
	return false ;
}

#endif

