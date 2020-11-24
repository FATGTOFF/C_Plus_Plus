#include <iostream>
#include <random>

void createPassword(char*, const int);
void replaceVowels(char*, const int);
int randomNumber(int, int);

int main()
{
    const int sizeOfPassword = 9; // Number of characters plus the null terminator
    char password[sizeOfPassword]{};
    char* pPassword = password;

    createPassword(pPassword, sizeOfPassword);
    replaceVowels(pPassword, sizeOfPassword);
}

void createPassword(char *pPassword, const int sizeOfPassword)
{
    char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *pAlpha = alpha;

    /*
    * Run a loop until 8 characters to obtain the random
    * characters from the alphabet into the password variable   
    */
    for (int count = 0; count < sizeOfPassword - 1; count++)
    {
        *(pPassword + count) = *(pAlpha + randomNumber(0, 25));
    }

    std::cout << "Random characters\n";
    std::cout << pPassword << std::endl;
}

void replaceVowels(char *pPassword, const int sizeOfPassword)
{
    for (int count = 0; count < sizeOfPassword - 1; count++)
    {
        if ('A' == *(pPassword + count))
        {
            *(pPassword + count) = '$';
        }

        else if ('E' == *(pPassword + count))
        {
            *(pPassword + count) = '%';
        }

        else if ('I' == *(pPassword + count))
        {
            *(pPassword + count) = '@';
        }

        else if ('O' == *(pPassword + count))
        {
            *(pPassword + count) = '#';
        }

        else if ('U' == *(pPassword + count))
        {
            *(pPassword + count) = '&';
        }

    }

    std::cout << "Vowels replaced\n";
    std::cout << pPassword << std::endl;
}


int randomNumber(int min, int max)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distrib(min, max);

    const int random = distrib(rng);

    return random;
}