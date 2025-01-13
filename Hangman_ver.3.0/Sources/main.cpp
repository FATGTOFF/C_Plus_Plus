#include "Hangman.h"


#ifdef DEBUG_HANGMAN
int numOfHeapAllocations = 0;
int numOfDeletes = 0;

void* operator new(size_t size)
{
	++numOfHeapAllocations;

	return malloc(size);
}

void operator delete(void* ptr)
{
	++numOfDeletes;

	return free(ptr);
}
#endif

int main()
{

	Hangman hangman{};

#ifdef DEBUG_HANGMAN
	std::cout << "Allocated: " << numOfHeapAllocations << " times\n";
	std::cout << "Freed: " << numOfDeletes << " times\n";
#endif

	bool keepLooping{ true };

	while (keepLooping)
	{
		keepLooping = hangman.play();
	}
}