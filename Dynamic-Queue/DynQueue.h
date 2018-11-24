//header file for DYNQUEUE, list type
#ifndef DYNQUEUE_H
#define DYNQUEUE_H

class DynQueue
{
private:
   // Structure for the queue nodes
   struct QueueNode
   {
      Employee value;  // pointer to value in a node
      QueueNode *next; // Pointer to the next node
   };

   QueueNode *front;  // The front of the queue
   QueueNode *rear;   // The rear of the queue
   int numItems;      // Number of items(employees) in the queue

public:
   // Constructor
   DynQueue();

   // Destructor
   ~DynQueue();

   // Queue operations
   void enqueue(Employee);
   void dequeue(Employee &);
   bool isEmpty() const;
   void clear();
   int GetLength() const;
};
#endif