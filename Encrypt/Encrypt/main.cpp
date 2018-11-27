#include <iostream>
#include <string>
#include <cctype> // For toupper function.
using namespace std;

//Function Prototypes.
void cipherTextLetter(int&);

enum Alphabet { A, B, C, D, E, F, G, 
	H, I, J, K, L, M, N, O, P, Q, R, 
	S, T, U, V, W, X, Y, Z, SPACE};

int main()
{
	int alpha{ 0 };

	string word;
	int key{ 3 };
	int result{ 0 };
	cout << "Enter a word and I will Encrypt it.\n";
	getline(cin, word);

	for (int count = 0; count < word.length(); count++)
	{

		if (word[count] == (' '))
		{
			result = SPACE;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('A') || word[count] == toupper('a'))
		{
			result = A + key;
			
			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('B') || word[count] == toupper('b'))
		{
			result = B + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('C') || word[count] == toupper('c'))
		{
			result = C + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('D') || word[count] == toupper('d'))
		{
			result = D + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('E') || word[count] == toupper('e'))
		{
			result = E + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('F') || word[count] == toupper('f'))
		{
			result = F + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('G') || word[count] == toupper('g'))
		{
			result = G + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('H') || word[count] == toupper('h'))
		{
			result = H + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('I') || word[count] == toupper('i'))
		{
			result = I + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('J') || word[count] == toupper('j'))
		{
			result = J + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('K') || word[count] == toupper('k'))
		{
			result = K + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('L') || word[count] == toupper('l'))
		{
			result = L + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('M') || word[count] == toupper('m'))
		{
			result = M + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('N') || word[count] == toupper('n'))
		{
			result = N + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('O') || word[count] == toupper('o'))
		{
			result = O + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('P') || word[count] == toupper('P'))
		{
			result = P + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('Q') || word[count] == toupper('q'))
		{
			result = Q + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('R') || word[count] == toupper('r'))
		{
			result = R + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('S') || word[count] == toupper('s'))
		{
			result = S + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('T') || word[count] == toupper('t'))
		{
			result = T + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('U') || word[count] == toupper('u'))
		{
			result = U + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('V') || word[count] == toupper('v'))
		{
			result = V + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('W') || word[count] == toupper('w'))
		{
			result = W + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('X') || word[count] == toupper('x'))
		{
			result = X + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('Y') || word[count] == toupper('y'))
		{
			result = Y + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

		if (word[count] == tolower('Z') || word[count] == toupper('z'))
		{
			result = Z + key;

			if (result >= 26)
				result = result - 26;
			cipherTextLetter(result);
		}

	}

	cout << endl;
	
	return 0;
}

void cipherTextLetter(int& result)
{

	switch (result)
	{
	case A: cout << 'A';
		break;

	case B: cout << 'B';
		break;

	case C: cout << 'C';
		break;

	case D: cout << 'D';
		break;

	case E: cout << 'E';
		break;

	case F: cout << 'F';
		break;

	case G: cout << 'G';
		break;

	case H: cout << 'H';
		break;

	case I: cout << 'I';
		break;

	case J: cout << 'J';
		break;

	case K: cout << 'K';
		break;

	case L: cout << 'L';
		break;

	case M: cout << 'M';
		break;

	case N: cout << 'N';
		break;

	case O: cout << 'O';
		break;

	case P: cout << 'P';
		break;

	case Q: cout << 'Q';
		break;

	case R: cout << 'R';
		break;

	case S: cout << 'S';
		break;

	case T: cout << 'T';
		break;

	case U: cout << 'U';
		break;

	case V: cout << 'V';
		break;

	case W: cout << 'W';
		break;

	case X: cout << 'X';
		break;

	case Y: cout << 'Y';
		break;

	case Z: cout << 'Z';
		break;

	case SPACE: cout << ' ';
		break;
	}
}