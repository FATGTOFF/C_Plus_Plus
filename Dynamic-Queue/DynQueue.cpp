#include <iostream>
#include <string>
#include "DynQueue.h"


//********************************************
// The constructor creates an empty queue.   *
//********************************************

DynQueue::DynQueue()
{
   front = nullptr;
   rear = nullptr;
   numItems = 0;
}

//********************************************
// Destructor                                *
//********************************************

DynQueue::~DynQueue()
{
   clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************

void DynQueue::enqueue(Employee item)
{
   QueueNode *newNode = nullptr;

   // Create a new node and store num there.
   newNode = new QueueNode;
   newNode->value = item;
   newNode->next = nullptr;

   // Adjust front and rear as necessary.
   if (isEmpty())
   {
      front = newNode;
      rear = newNode;
   }
   else
   {
      rear->next = newNode;
      rear = newNode;
   }

   // Update numItems.
   numItems++;
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************

void DynQueue::dequeue(Employee &item)
{
   QueueNode *temp = nullptr;

   if (isEmpty())
   {
      std::cout << "The queue is empty.\n";
   }
   else
   {
      // Save the front node value in num.
      item = front->value;

      // Remove the front node and delete it.
      temp = front;
      front = front->next;
      delete temp;

      // Update numItems.
      numItems--;
   }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************

bool DynQueue::isEmpty() const
{
    bool status;

    if (numItems > 0)
       status = false;
    else
       status = true;
    return status;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************

void DynQueue::clear()
{
    Employee value;   // Dummy variable for dequeue

    while(!isEmpty())
       dequeue(value);
}

//********************************************
//GetLength function returns numItems,       *
//number of items in the list                *
//********************************************
int DynQueue::GetLength() const
{
	return numItems;
}
