#include <iostream>
#include <string>

void rotateString(std::string, int);

int main()
{

	std::string word{};
	int numOfRotations{};

	std::cout << "Type a word: ";
	std::cin >> word;

	std::cout << "Type a number of rotations: ";
	std::cin >> numOfRotations;

	rotateString(word, numOfRotations);

	return 0;

}

void rotateString(std::string word, int numOfRotations)
{
	char temp1{};
	char temp2{};
	int countTotalCombinations{ 0 };

	int count = word.size() - 1;

	std::cout << "Original Word: " << word << std::endl;

	while (count > 0)
	{

		if ((count - numOfRotations) < 0) // If the result is negative number, break the loop.
			break;

		else
		{
			temp1 = word.at(count);
			temp2 = word.at(count - numOfRotations);
			word.at(count) = temp2;
			word.at(count - numOfRotations) = temp1;
			countTotalCombinations++;

		}

		std::cout << "Word Combination # " << countTotalCombinations << " : " << word << std::endl;
		count -= numOfRotations;
	}
}