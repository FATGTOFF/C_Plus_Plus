//header file for the PQHeap class

#ifndef PQHEAP_H
#define PQHEAP_H
#include "MinHeap.h"

//exceptions
class FullPQ{};		
class EmptyPQ{};

//class definition
template<class T>
class PQHeap
{
private:
	int length;
	HeapType<T> items;
	int maxItems;

public:
	//constructor and destructor
	PQHeap(int);
	~PQHeap();
	//priority queue functions
	void Enqueue(T newItem);
	void Dequeue(T& item);
	void MakeEmpty();
	void ResetCount();
	int GetLengthHeap() const;
	int GetEnqueueCount() const;
	int GetDequeueCount() const;
	int GetTotalCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
};

//********************************************
//constructor                                *
//********************************************
template<class T>
PQHeap<T>::PQHeap(int max)
{
	maxItems = max;
	items.elements = new T[max];
	length = 0;
	
	items.enqueCount = 0;
	items.dequeCount = 0;
}

//********************************************
//destructor                                 *
//********************************************
template<class T>
PQHeap<T>::~PQHeap()
{
	delete[] items.elements;
}

//********************************************
//enqueue function                           *
//enqueues item or throws expception         * 
//********************************************
template<class T>
void PQHeap<T>::Enqueue(T newItem)
{
	if (length == maxItems)
	{
		throw FullPQ();
	}
	else
	{
		length++;
		items.elements[length - 1] = newItem;
		items.ReheapUp(0, length - 1);
	}
}

//********************************************
//dequeue function                           *
//dequeues item or throws expception         * 
//********************************************
template<class T>
void PQHeap<T>::Dequeue(T& item)
{
	if (length == 0)
	{
		throw EmptyPQ();
	}
	else
	{
		item = items.elements[0];
		items.elements[0] = items.elements[length - 1];
		length--;
		items.ReheapDown(0, length - 1);
	}
}

//********************************************
//makeEmpty function                         *
//makes the PQ empty                         *
//********************************************
template<class T>
void PQHeap<T>::MakeEmpty()
{
	length = 0;
}

//********************************************
//ResetCount function                        *
//resets the enqueue and dequeue counter     *
//********************************************
template<class T>
void PQHeap<T>::ResetCount()
{
	items.enqueCount = 0;
	items.dequeCount = 0;
}


//********************************************
//GetLengthHeap function                     *
//returns the length                         *
//********************************************
template<class T>
int PQHeap<T>::GetLengthHeap() const
{
	return length;
}

//********************************************
//GetEnqueueCount                            *
//returns the enqueueCount                   *
//********************************************
template<class T>
int PQHeap<T>::GetEnqueueCount() const
{
	return items.enqueCount;
}

//********************************************
//GetDequeueCount                            *
//returns the dequeueCount                   *
//********************************************
template<class T>
int PQHeap<T>::GetDequeueCount() const
{
	return items.dequeCount;
}

//***********************************************
//GetTotalCount                                 *
//returns the sum of enqueue and dequeue count  *
//***********************************************
template<class T>
int PQHeap<T>::GetTotalCount() const
{
	return (items.enqueCount + items.dequeCount);
}

//********************************************
//IsEmpty function                           *
//returns true for empty                     *
//********************************************
template<class T>
bool PQHeap<T>::IsEmpty() const
{
	return length == 0;
}

//********************************************
//IsFull function                            *
//retuns true for full queue                 *
//********************************************
template<class T>
bool PQHeap<T>::IsFull() const
{
	return length == maxItems;
}

#endif