#include "DeckOfCards.h"

int DeckOfCards::randomNumber(int min, int max)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(min, max);

	const int random = distrib(rng);

	return random;
}

void DeckOfCards::shuffleCards(int firstCard, int lastCard)
{
	int ranNum{};
	bool found = false;
	int counter{ 0 };

	
	for (int cardNum = 0; cardNum < TOTALNUMOFCARDS; cardNum++)
	{
		ranNum = randomNumber(firstCard, lastCard);
		cardsToBeShuffled[cardNum] = ranNum;
		arrOfCardScoresShuffled[cardNum] = arrOfCardScores[ranNum];
		counter = 0;
		for (int y = 0; y < cardNum + 1; y++)
		{
			if (found)
			{
				ranNum = randomNumber(firstCard, lastCard);
				cardsToBeShuffled[cardNum] = ranNum;
				arrOfCardScoresShuffled[cardNum] = arrOfCardScores[ranNum];
				y = 0;
				counter = 0;
				found = false;
			}

			if (cardsToBeShuffled[y] == ranNum)
			{
				counter++;
			}

			if (counter == 1)
			{
				found = false;
			}

			else if (counter > 1)
			{
				found = true;
				y = 0;
				counter = 0;
			}

		}

		//std::cout << cardsToBeShuffled[cardNum] + 1 << std::endl;
	}
	cardsAreShuffle = true;
}

void DeckOfCards::displayCards(bool cardsAreShuffle)
{
	int cardValues{};
	for (int count = 0; count < TOTALNUMOFCARDS; count++)
	{
		if (cardsAreShuffle)
		{
			cardValues = cardsToBeShuffled[count];
		}
		else
		{
			cardValues = newCards[count];
		}

		switch (cardValues)
		{
			// Spades
			case ACE_OF_SPADES: nameOfCardsShuffled[count] = "Ace of Spades"; break;
			case TWO_OF_SPADES: nameOfCardsShuffled[count] = "Two of Spades"; break;
			case THREE_OF_SPADES: nameOfCardsShuffled[count] = "Three of Spades"; break;
			case FOUR_OF_SPADES: nameOfCardsShuffled[count] = "Four of Spades"; break;
			case FIVE_OF_SPADES: nameOfCardsShuffled[count] = "Five of Spades"; break;
			case SIX_OF_SPADES: nameOfCardsShuffled[count] = "Six of Spades"; break;
			case SEVEN_OF_SPADES: nameOfCardsShuffled[count] = "Seven of Spades"; break;
			case EIGHT_OF_SPADES: nameOfCardsShuffled[count] = "Eight of Spades"; break;
			case NINE_OF_SPADES: nameOfCardsShuffled[count] = "Nine of Spades"; break;
			case TEN_OF_SPADES: nameOfCardsShuffled[count] = "Ten of Spades"; break;
			case JACK_OF_SPADES: nameOfCardsShuffled[count] = "Jack of Spades"; break;
			case QUEEN_OF_SPADES: nameOfCardsShuffled[count] = "Queen of Spades"; break;
			case KING_OF_SPADES: nameOfCardsShuffled[count] = "King of Spades"; break;

			// Clubs
			case ACE_OF_CLUBS: nameOfCardsShuffled[count] = "Ace of Clubs"; break;
			case TWO_OF_CLUBS: nameOfCardsShuffled[count] = "Two of Clubs"; break;
			case THREE_OF_CLUBS: nameOfCardsShuffled[count] = "Three of Clubs"; break;
			case FOUR_OF_CLUBS: nameOfCardsShuffled[count] = "Four of Clubs"; break;
			case FIVE_OF_CLUBS: nameOfCardsShuffled[count] = "Five of Clubs"; break;
			case SIX_OF_CLUBS: nameOfCardsShuffled[count] = "Six of Clubs"; break;
			case SEVEN_OF_CLUBS: nameOfCardsShuffled[count] = "Seven of Clubs"; break;
			case EIGHT_OF_CLUBS: nameOfCardsShuffled[count] = "Eight of Clubs"; break;
			case NINE_OF_CLUBS: nameOfCardsShuffled[count] = "Nine of Clubs"; break;
			case TEN_OF_CLUBS: nameOfCardsShuffled[count] = "Ten of Clubs"; break;
			case JACK_OF_CLUBS: nameOfCardsShuffled[count] = "Jack of Clubs"; break;
			case QUEEN_OF_CLUBS: nameOfCardsShuffled[count] = "Queen of Clubs"; break;
			case KING_OF_CLUBS: nameOfCardsShuffled[count] = "King of Clubs"; break;

			//Hearts
			case ACE_OF_HEARTS: nameOfCardsShuffled[count] = "Ace of Hearts"; break;
			case TWO_OF_HEARTS: nameOfCardsShuffled[count] = "Two of Hearts"; break;
			case THREE_OF_HEARTS: nameOfCardsShuffled[count] = "Three of Hearts"; break;
			case FOUR_OF_HEARTS: nameOfCardsShuffled[count] = "Four of Hearts"; break;
			case FIVE_OF_HEARTS: nameOfCardsShuffled[count] = "Five of Hearts"; break;
			case SIX_OF_HEARTS: nameOfCardsShuffled[count] = "Six of Hearts"; break;
			case SEVEN_OF_HEARTS: nameOfCardsShuffled[count] = "Seven of Hearts"; break;
			case EIGHT_OF_HEARTS: nameOfCardsShuffled[count] = "Eight of Hearts"; break;
			case NINE_OF_HEARTS: nameOfCardsShuffled[count] = "Nine of Hearts"; break;
			case TEN_OF_HEARTS: nameOfCardsShuffled[count] = "Ten of Hearts"; break;
			case JACK_OF_HEARTS: nameOfCardsShuffled[count] = "Jack of Hearts"; break;
			case QUEEN_OF_HEARTS: nameOfCardsShuffled[count] = "Queen of Hearts"; break;
			case KING_OF_HEARTS: nameOfCardsShuffled[count] = "King of Hearts"; break;

			//Diamonds
			case ACE_OF_DIAMONDS: nameOfCardsShuffled[count] = "Ace of Diamonds"; break;
			case TWO_OF_DIAMONDS: nameOfCardsShuffled[count] = "Two of Diamonds"; break;
			case THREE_OF_DIAMONDS: nameOfCardsShuffled[count] = "Three of Diamonds"; break;
			case FOUR_OF_DIAMONDS: nameOfCardsShuffled[count] = "Four of Diamonds"; break;
			case FIVE_OF_DIAMONDS: nameOfCardsShuffled[count] = "Five of Diamonds"; break;
			case SIX_OF_DIAMONDS: nameOfCardsShuffled[count] = "Six of Diamonds"; break;
			case SEVEN_OF_DIAMONDS: nameOfCardsShuffled[count] = "Seven of Diamonds"; break;
			case EIGHT_OF_DIAMONDS: nameOfCardsShuffled[count] = "Eight of Diamonds"; break;
			case NINE_OF_DIAMONDS: nameOfCardsShuffled[count] = "Nine of Diamonds"; break;
			case TEN_OF_DIAMONDS: nameOfCardsShuffled[count] = "Ten of Diamonds"; break;
			case JACK_OF_DIAMONDS: nameOfCardsShuffled[count] = "Jack of Diamonds"; break;
			case QUEEN_OF_DIAMONDS: nameOfCardsShuffled[count] = "Queen of Diamonds"; break;
			case KING_OF_DIAMONDS: nameOfCardsShuffled[count] = "King of Diamonds"; break;

			default: std::cout << "ERROR!-It should not reach here\n";
		}

		if (DEBUG)
		{
			std::cerr << std::right << std::setw(2) << count + 1 << std::left << ": "
				<< std::setw(20) << nameOfCardsShuffled[count] << std::setw(60)
				<< arrOfCardScoresShuffled[count] << std::endl;
		}


	}
}

DeckOfCards::DeckOfCards()
{
	newCards = nullptr;
	newCards = new int[TOTALNUMOFCARDS];
	cardsToBeShuffled = nullptr;
	cardsToBeShuffled = new int[TOTALNUMOFCARDS];
	nameOfCardsShuffled = nullptr;
	nameOfCardsShuffled = new std::string[TOTALNUMOFCARDS];
	dealtCards = nullptr;
	dealtCards = new int[TOTALNUMOFCARDS];

	for (int count = ACE_OF_SPADES; count < TOTALNUMOFCARDS; count++)
	{
		newCards[count] = count;
		cardsToBeShuffled[count] = count;
		nameOfCardsShuffled[count] = "None";
		dealtCards[count] = count;

	}

	cardsAreShuffle = false;

	std::fstream CardsValue("List of Cards Scores.txt", std::ios::in);
	arrOfCardScores = nullptr;
	arrOfCardScores = new int[TOTALNUMOFCARDS];
	for (int count = 0; count < TOTALNUMOFCARDS; count++)
	{
		CardsValue >> arrOfCardScores[count];
		//std::cout << arrOfCardScores[count] << std::endl;
	}

	CardsValue.close();

	arrOfCardScoresShuffled = nullptr;
	arrOfCardScoresShuffled = new int[TOTALNUMOFCARDS];
	for (int count = 0; count < TOTALNUMOFCARDS; count++)
	{
		arrOfCardScoresShuffled[count] = 0;
	}

}

DeckOfCards::~DeckOfCards()
{
	if (newCards != nullptr)
	{
		delete[] newCards;
		newCards = nullptr;
	}

	if (cardsToBeShuffled != nullptr)
	{
		delete[] cardsToBeShuffled;
		cardsToBeShuffled = nullptr;
	}

	if (nameOfCardsShuffled != nullptr)
	{
		delete[] nameOfCardsShuffled;
		nameOfCardsShuffled = nullptr;
	}
	
	if (dealtCards != nullptr)
	{
		delete[] dealtCards;
		dealtCards = nullptr;
	}

	if (arrOfCardScores != nullptr)
	{
		delete[] arrOfCardScores;
		arrOfCardScores = nullptr;
	}

	if (arrOfCardScoresShuffled != nullptr)
	{
		delete[] arrOfCardScoresShuffled;
		arrOfCardScoresShuffled = nullptr;
	}
}

void DeckOfCards::shuffleCards()
{
	shuffleCards(ACE_OF_SPADES, KING_OF_DIAMONDS);
}

void DeckOfCards::displayCards()
{
	displayCards(cardsAreShuffle);
}
