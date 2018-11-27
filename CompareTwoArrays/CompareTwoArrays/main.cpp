#include <iostream>
#include <string>

int main()
{
	//int arrNum1[]{ 1,2,3,4,5 };
	//int arrNum2[]{ 5,99,12,3,1, 4,55,66 };
	//int temp{};
	//const int sizeOfArray1 = sizeof(arrNum1) / sizeof(int);
	//const int sizeOfArray2 = sizeof(arrNum2) / sizeof(int);

	//int countMatches{ 0 };

	//for (int countA = 0; countA < sizeOfArray1; countA++)
	//{
	//	temp = arrNum1[countA];
	//	for (int countB = 0; countB < sizeOfArray2; countB++)
	//	{
	//		if (arrNum2[countB] == temp)
	//			countMatches++;
	//	}
	//}
	//std::cout << countMatches << std::endl;

	char sex[5]{};
	std::string name[5]{};
	std::string phoneNum[5]{};
	int numInterest[5]{ 5 };
	std::string listOfInterest[5]{};
	std::string match[10]{};
	bool matches[5]{};

	////First Client.
	//sex[0] = 'M';
	//name[0] = "Carlos";
	//phoneNum[0] = "875-1234";
	//numInterest[0] = 3;
	//listOfInterest[0] = {"Fishing", "Baseball", "Badmington", "Birding", "Ceramics" };

	std::string arrNum1[]{ "Fishing", "Baseball", "Badmington", "Birding", "Ceramics"};
	std::string arrNum2[]{ "Crafts" , "Darts" ,"Dominoes" , "Cosplay" ,"Birding", "Chess","Badmington","Fishing" };
	std::string temp{};
	const int sizeOfArray1 = sizeof(arrNum1) / sizeof(std::string);
	const int sizeOfArray2 = sizeof(arrNum2) / sizeof(std::string);

	int countMatches{ 0 };

	for (int countA = 0; countA < sizeOfArray1; countA++)
	{
		temp = arrNum1[countA];
		for (int countB = 0; countB < sizeOfArray2; countB++)
		{
			if (arrNum2[countB] == temp)
				countMatches++;
		}
	}
	std::cout << countMatches << std::endl;

	return 0;

}