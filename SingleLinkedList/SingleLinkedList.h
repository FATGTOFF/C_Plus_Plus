//header file for the UnsortedList class

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>


//class definition
template <class T>
class LinkedList
{
private:
	struct ListNode		//node structure
	{
		ListNode *next;	//next node pointer
		T value;	//node value
	};

	ListNode *head;	//head or beginning of list
	ListNode *currentPos;	//current position in the list
	int enqueueCounter;
	int dequeueCounter;
	int length;

public:
	//constructors
	LinkedList();
	LinkedList(const LinkedList &);

	// destructors
	~LinkedList();

	// accessors and mutators
	void insertNode(T);
	void appendNode(T);
	void pop(T& t);
	void deleteNode(T);
	void makeEmpty();
	void print() const;
	void reverse();
	void resetCount();
	void resetList();
	T getNext(bool &hasMore);
	int search(T);
	int getLength() const;
	int getEnqueueCount() const;
	int getDequeueCount() const;
	int getTotalCount() const;

	void operator =(const LinkedList<T> &copyList);
};

//************************************************
//constructor                                    *
//************************************************
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;	//initializes the head pointer to nullptr - end of the list; in this case 
					//the list is empty.
					
	currentPos = nullptr;
	enqueueCounter = 0;
	dequeueCounter = 0;
	length = 0;
}

//***********************************************
//copy constructor                              *
//***********************************************
template <class T>
LinkedList<T>::LinkedList(const LinkedList &copyList)
{
	head = nullptr;

	ListNode *copyNodePtr;	//pointer to copy node
	copyNodePtr = copyList.head;
	length = copyList.length;

	while (copyNodePtr)	//loop the copy nodes until end
	{
		appendNode(copyNodePtr->value);	//add nodes with new values
		copyNodePtr = copyNodePtr->next;	//move to the next copy node
	}
}

//*************************************************************
//destructor                                                  *
//deletes all nodes in the list from beginning to end         *
//*************************************************************
template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;	//pointer to current node
	ListNode *nextNodePtr;	//pointer to next node
	nodePtr = head;	//sets the pointer to beginning

	while(nodePtr)			
	{
		nextNodePtr = nodePtr->next;	//pointer on next node
		delete nodePtr;					//delete the node (the pointer is already on next)
		nodePtr = nextNodePtr;			//set current node pointer to the first one in the list
	}
}

//************************************************************
//insertNode function                                        *
// inserts a node in the list in ascending order             *
//************************************************************
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *nodePtr;	//pointer to current node
	ListNode *newNodePtr;	//pointer to new node that is inserted
	ListNode *previousNodePtr;	//pointer to previous node

	newNodePtr = new ListNode;	//creates a new node and pointer
	newNodePtr->value = newValue;	//set value to the new node

	enqueueCounter++;  //compare against head

	if (!head)	//check if the list is empty
	{
		enqueueCounter++;  //reasign head
		head = newNodePtr;

		enqueueCounter++;  //reassigns node
		newNodePtr->next = nullptr;

		length++;

		return;
	}
	else
	{
		nodePtr = head;	//set pointer to beginning of the list
		previousNodePtr = nullptr;

		while (nodePtr != nullptr && nodePtr->value < newValue)	//check end of list and the value
		{
			previousNodePtr = nodePtr;	//set previous node pointer to current
			nodePtr = nodePtr->next;	//set the node pointer to next
		}
	}

	if (!previousNodePtr)
	{
		enqueueCounter++;
		newNodePtr->next = nodePtr;	//set new node pointer to first node
		enqueueCounter++; 
		head = newNodePtr;	//make the newNodePtr the head of the list
	}
	else
	{
		enqueueCounter++; 
		previousNodePtr->next = newNodePtr;	 //relink the pointer to new pointer
		enqueueCounter++;
		newNodePtr->next = nodePtr;	//set new node pointer to the next node
	}

	length++;
}

//***************************************************************
//appendsNode function                                          *       
//-appends a node to the end of the list                        *
//***************************************************************
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	ListNode *nodePtr;	//pointer to current node
	ListNode *newNodePtr;	//pointer to the new node that should be appended

	newNodePtr = new ListNode;	//creates a new node, sets pointer
	newNodePtr->value = newValue;	//set value to the new node
	newNodePtr->next = nullptr;	//sets the next value to nullptr, because it is the last node (tail)

	if(!head)	//check to see if the list is empty
	{
		head = newNodePtr;
		currentPos = head;
		length = 1;
	}
	else
	{
		nodePtr = head;	//set pointer to beginning of list

		while(nodePtr->next)	//check if the pointer is pointing to the last node
		{
			nodePtr = nodePtr->next;	//moves the pointer to the next node
		}

		nodePtr->next = newNodePtr;	//set pointer of last node to the new appending node (last one)
	}

	length++;
}

//****************************************************
//pop function                                       *
//removes the item on top of the stack               *
//****************************************************
template <class T>
void LinkedList<T>::pop(T& t)
{
	if (head != nullptr)
	{
		dequeueCounter++;

		t = head->value;
		head = head->next;
		length--;
	}
}

//*********************************************************************
//deleteNode function                                                 *
//deletes the search value and relinks the nodes around               *
//*********************************************************************
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode *nodePtr;	//pointer to node searched
	ListNode *previousNodePtr;	//pointer to previous node already searched

	if(!head)	//check if the list is empty
	{
		return;	//if empty, return
	}

	if(head->value == searchValue)	//check if the first value is the searched for value
	{
		nodePtr = head->next;	//set nodePtr to the first node (new one)
		delete head;	//delete the node from the beginning of the list
		head = nodePtr;	//reset the head to the new first node
		length--;
	}
	else
	{
		nodePtr = head;		//set pointer to beginning of list

		while(nodePtr !=nullptr && nodePtr->value != searchValue)	//check end of list and if it contains the value searched for
		{
			previousNodePtr = nodePtr;	//move previous node pointer to current node pointer
			nodePtr = nodePtr->next;	//move the node pointer to next node
		}

		if(nodePtr)		//check if node found and if not, make it a nullpointer
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
			length--;
		}
	}

	currentPos = head;
}

//******************************************************
//makeEmpty function                                   *
//empties the list                                     *
//******************************************************
template <class T>
void LinkedList<T>::makeEmpty()
{
	ListNode *nodePtr;	//pointer to current node
	ListNode *nextNodePtr;	//pointer to next node

	nodePtr = head;	//set current node to the head of the list

	while (nodePtr)
	{
		nextNodePtr = nodePtr->next;
		delete nodePtr;					//delete current node
		nodePtr = nextNodePtr;
	}

	length = 0;
}
//****************************************************
//print function                                     *
//****************************************************
template <class T>
void LinkedList<T>::print() const
{
	ListNode *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << endl;
}

//*******************************************************
//reverse function                                      *
//reverses the node order in the list                   *
//*******************************************************
template <class T>
void LinkedList<T>::reverse()
{
	ListNode *nodePtr;	//pointer to the current node
	ListNode *nextNodePtr;	//pointer to the next node
	ListNode *previousNodePtr;	//pointer to the previous node

	nodePtr = head;
	previousNodePtr = nullptr;

	while(nodePtr)
	{
		nextNodePtr = nodePtr->next;
		nodePtr->next = previousNodePtr;
		previousNodePtr = nodePtr;
		nodePtr = nextNodePtr;
	}

	head = previousNodePtr;
}

//****************************************************
//resetCount function                                *
//resets the counters fre enqueue and dequeue        *
//****************************************************
template <class T>
void LinkedList<T>::resetCount()
{
	enqueueCounter = 0;
	dequeueCounter = 0;
}

//*************************************************
//resetList function                              *
//*************************************************
template <class T>
void LinkedList<T>::resetList()
{
	currentPos = head;
}

//**************************************************
//getNext function                                 *
//**************************************************
template <class T>
T LinkedList<T>::getNext(bool &isValid)
{
	T temp;

	if (currentPos == nullptr)
	{
		isValid = false;
	}
	else
	{
		isValid = true;
		temp = currentPos->value;
		currentPos = currentPos->next;
	}
	return temp;
}

//*****************************************************************
//search fucntion                                                 *
//searches for the first value found coresponding to the value    *
//searched for                                                    *
//*****************************************************************
template <class T>
int LinkedList<T>::search(T searchValue)
{
	ListNode *nodePtr;
	int foundPos = -1;	//variable for position, set on -1 for false
	int pos = 0;	//variable for position, set on 0 as start

	nodePtr = head;	//set pointer to beginning of list

	while(nodePtr)	//loop as long as there are nodes
	{
		if(nodePtr->value == searchValue) //if found right away
		{
			foundPos = pos;	
			break;
		}

		pos++;	//increment position counter
		nodePtr = nodePtr->next;	//go to next node
	}

	return foundPos;
}

//****************************************
//getLenght function				     *
//returns the length                     *
//****************************************
template <class T>
int  LinkedList<T>::getLength() const
{
	return length;
}

//*********************************************
//getEnqueueCount                             *
//returns the enqueueCounter                  *
//*********************************************
template <class T>
int LinkedList<T>::getEnqueueCount() const
{
	return enqueueCounter;
}

//*********************************************
//getDequeueCount                             *
//returns the dequeueCounter                  *
//*********************************************
template <class T>
int LinkedList<T>::getDequeueCount() const
{
	return dequeueCounter;
}

//*********************************************
//getTotalCount                               *
//sums enqueueCounter and DequeueCounter      *
//*********************************************
template <class T>
int LinkedList<T>::getTotalCount() const
{
	return enqueueCounter + dequeueCounter;
}

//*****************************************************
//operator = overload                                 *
//*****************************************************
template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &copyList)
{
	ListNode *nodePtr;	//pointer to current node
	ListNode *nextNodePtr;	//pointer to next node
	length = copyList.length;

	nodePtr = head;				//sets pointer to beginning of list

	while(nodePtr)				//check to see if we are at the end of the list.. nullptr = past the last node
	{
		nextNodePtr = nodePtr->next;	//set pointer to the next node so we can hold a pointer to it.
		delete nodePtr;					//delete current node (first one in the list) because we have a pointer to the next one
		nodePtr = nextNodePtr;			//set the current node pointer to the first one in the list.
	}

	head = nullptr;				//sets this objects head to start..

	ListNode *copyNodePtr;		//pointer to copy node to walk through each node
	copyNodePtr = copyList.head;

	while(copyNodePtr)	//loop through each copy node until end
	{
		appendNode(copyNodePtr->value);		//create and append a new node with copied value
		copyNodePtr = copyNodePtr->next;	//move to the next copy node
	}
}
#endif












