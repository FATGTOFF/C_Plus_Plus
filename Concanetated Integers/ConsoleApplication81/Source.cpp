/* How to concatenate an integer array into a single int variable
*/

#include <iostream>
using namespace std;


int main()
{
    const int numOfElements{ 4 };
    int arr[numOfElements]{1, 2, 3, 4};
    int concatenated{ 0 };

    int userChoiceElements{ 0 };
    cout << "How many elements do you want to combine into one int variable?>>>";
    cin >> userChoiceElements;
    while (userChoiceElements < 0 || userChoiceElements > numOfElements)
    {
	   cout << "Your input [" << userChoiceElements << "] is incorrect\n";
	   cout << "How many elements do you want to combine into one int variable?>>>";
	   cin >> userChoiceElements;
    }

    for (int count = 0; count < userChoiceElements; count++)
	   concatenated = concatenated * 10 + arr[count];

    cout << concatenated << endl;

    return 0;
}