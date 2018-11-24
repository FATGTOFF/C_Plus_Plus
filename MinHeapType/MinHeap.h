//header file for the MinHeap type

#ifndef MINHEAPTYPE_H
#define MINHEAPTYPE_H


template<class T>
struct HeapType		//heapType structure array implementation
{  
	T* elements;
	int enqueCount;
	int dequeCount;
	void ReheapUp(int, int);
	void ReheapDown(int, int);
};


//*************************************************************
//reheapUp function   - for enqueue                           *
//minimum heap ; elements - parent > than elements-bottom     *                           *
//*************************************************************
template<class T>
void HeapType<T>::ReheapUp(int head, int bottom) 
{
	int parent{};

	if (bottom > head)
	{
		parent = (bottom - 1) / 2; //compare parent and bottom

		enqueCount++;  

		if (elements[parent] > elements[bottom]) 
		{
			swapHeapUp(elements[parent], elements[bottom], enqueCount);
			ReheapUp(head, parent);
		}
	}
}

//*************************************************************
//swapHeapUp function                                         *
//swaps the elements in the array during enqueue              *
//and counts the swaps                                        *
//*************************************************************
template <class T>
void swapHeapUp(T& firstSwap, T& secondSwap, int& countSwaps)
{
	T temp;
	//first swap
	countSwaps++;
	temp = firstSwap;
	//second swap
	countSwaps++;
	firstSwap = secondSwap;
	//third swap
	countSwaps++;
	secondSwap = temp;
}

//*************************************************************
//reheapUp function   - for dequeue                           *
//min heap ; elements - parent > than elements-bottom         *                        
//*************************************************************
template<class T>
void HeapType<T>::ReheapDown(int head, int bottom)
{
	int minChild{};
	int rightChild{};
	int leftChild{};

	leftChild = head * 2 + 1;
	rightChild = head * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)  //last node is the only node
		{
			minChild = leftChild;
		}
		else
		{
			dequeCount++;  

			//compare the children
			if (elements[leftChild] >= elements[rightChild]) 
			{
				minChild = rightChild;
			}
			else
			{
				minChild = leftChild;
			}
		}

		dequeCount++;  //operation to compare root to minChild

		if (elements[head] > elements[minChild])
		{
			swapHeapDown(elements[head], elements[minChild], dequeCount);
			ReheapDown(minChild, bottom);
		}
	}
}

//*************************************************************
//swapHeapDown function                                       *
//swaps the elements in the array during dequeue              *
//and counts the swaps                                        *
//*************************************************************
template <class T>
void swapHeapDown(T& firstSwap, T& secondSwap, int& countSwaps)
{
	T temp;
  //first swap
	countSwaps++;
	temp = firstSwap;
  //second swap
	countSwaps++;
	firstSwap = secondSwap;
  //third swap
	countSwaps++;
	secondSwap = temp;
}  

#endif