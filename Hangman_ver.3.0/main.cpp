#include "Hangman.h"

int main()
{
	Hangman hangman{};
	bool keepLooping{ true };

	while (keepLooping)
	{
		keepLooping = hangman.play();
	}

}