//header file for the Circular Linked List class
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>* next;
};

/* Assumption:  ItemType is a type for which the operators
"<" and "==" are defined—either an appropriate built-in type or a class that overloads these operators. */

template <class ItemType>
class UnsortedType
{
private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;

public:
	// Class constructor, destructor, and copy constructor
	UnsortedType();
	~UnsortedType();
	UnsortedType(const UnsortedType<ItemType>&);

	void operator=(UnsortedType<ItemType>);

	bool IsFull() const;
	// Determines whether list is full.
	// Post: Function value = (list is full)

	int  GetLength() const;
	// Determines the number of elements in list.
	// Post: Function value = number of elements in list.

	void RetrieveItem(ItemType& item, bool& found);
	// Retrieves list element whose key matches item's key 
	// (if present).
	// Pre:  Key member of item is initialized.
	// Post: If there is an element someItem whose key matches  
	//     item's key, then found = true and item is a copy of
	//     someItem; otherwise found = false and item is 
	//     unchanged.
	//     List is unchanged.

	void InsertItem(ItemType item);
	// Adds item to list.
	// Pre:  List is not full.
	//       item is not in list. 
	// Post: item is in list.

	void DeleteItem(ItemType item);
	// Deletes the element whose key matches item's key.
	// Pre:  Key member of item is initialized.
	//       One and only one element in list has a key matching 
	//       item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Initializes current position for an iteration through the 
	// list.   
	// Post: Current position is prior to list.

	void GetNextItem(ItemType& item);
	// Gets the next element in list.
	// Pre:  Current position is defined.
	//       Element at current position is not last in list.
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.

	void displayList() const;
	//Displays the list
};
#endif

//constructor
template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
	length = 0;
	listData = nullptr;
	currentPos = nullptr;
}

//destructor
template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
	NodeType<ItemType> *tempPtr;
	NodeType<ItemType> *predLoc;
	predLoc = listData;

	for (int count = length; count > 0; count--)
	{
		tempPtr = predLoc->next;
		predLoc->next = (predLoc->next)->next;
		delete tempPtr; // delete node.
		tempPtr = nullptr;
		predLoc = predLoc->next;
		length = count - 1;
	}
}

//copy constructor
template<class ItemType>
UnsortedType<ItemType>::UnsortedType(const UnsortedType<ItemType>& anotherItem)
{
	*this = anotherItem; //copy the list
}
 
//overloading the = operator
template<class ItemType>
void UnsortedType<ItemType>::operator=(UnsortedType<ItemType> right)
{
listData = right.listData;
length = right.length;
currentPos = right.currentPos;

}

//function for full list, throw exception
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
{
	NodeType<ItemType>* location;

	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

//function to get length of the list
template<class ItemType>
int UnsortedType<ItemType>::GetLength() const
{
	return length;
}

//function to search for an item
template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType & item, bool & found)
{
	NodeType<ItemType> *tempPtr;
	tempPtr = listData;

	for (int count = 0; count < length; count++)
	{
		if (tempPtr->info == item)
		{
			found = true;	//if found, return true
			return;			//and stop looping
		}
		tempPtr = tempPtr->next;	//go to next item
	}
	found = false;
}

//fuction to insert an item
template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
	NodeType<ItemType>* newNode; 
	newNode = new NodeType<ItemType>;
	NodeType<ItemType>* predLoc;
	//bool found;

	newNode->info = item;
	predLoc = listData; 

	if (predLoc == nullptr)	//if list is empty
	{
		listData = newNode; //if list is empty, assign a new tail to the list
		newNode->next = listData;	//new tail points to the head
	}
	else
	{
		//as long as the predloc->next is not equal to the head
		while (predLoc->next != listData)
		{
			predLoc = predLoc->next;	//move to another note, if there is one
		}
		predLoc->next = newNode; //point the predLoc to the newNode
		newNode->next = listData;	//point the newNode->next at the head
	}
	currentPos = listData;

	length++;
}

//delete an item from the list
template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
	NodeType<ItemType>* location;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* followUp; //follows behind the pointer PredLoc
	bool found;

	if (length == 0)
	{
		std::cout << "List is empty\n";
		return; //stops when list is empty
	}
	
	RetrieveItem(item, found);
	if (!found)
	{
		std::cout << "Value not found in the list\n";
		return; //stop when not found
	}

	predLoc = listData; 
	followUp = predLoc;

	if (listData == predLoc->next) //if there is only one element in the list
	{
		if (predLoc->info == item)
		{
			listData = nullptr;	//head must be reset if there is only one element
			delete followUp;
			return;
		}
	}

	for (int count = 0; count < length; count++)
	{
		if ((predLoc->next)->info == item) //(predLoc->next)->info
		{
			location = predLoc->next;	//was predloc
			predLoc->next = (predLoc->next)->next;
			delete location;
			location = nullptr;
			if (location == nullptr)
			{
				currentPos = predLoc->next;
				listData = currentPos;
			}
		}
		else
		{
			predLoc = predLoc->next;
		}
	}

	length--;
}

//function to reset the list
template<class ItemType>
void UnsortedType<ItemType>::ResetList()
{
	currentPos = listData;
}

//fuction to get the next item
template<class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType &item)
{

	NodeType<ItemType> *tempPtr;
	tempPtr = currentPos;

	item = (tempPtr->next)->info;
}

//function to display the list
template<class ItemType>
void UnsortedType<ItemType>::displayList() const
{
	NodeType<ItemType> *nodePtr;	//to move through the list

	nodePtr = listData; //point the node at the head

	for (int count = 0; count < length; count++)
	{
		//display the value in the node
		std::cout << nodePtr->info;
		nodePtr = nodePtr->next;
	}
}