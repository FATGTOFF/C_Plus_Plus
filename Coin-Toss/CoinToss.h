#ifndef COINTOSS_H
#define COINTOSS_H
#include <string>
#include <random>


class CoinToss
{
private:

    std::mt19937 generator;
    int timesToFlipCoin;
    int coinFlip;
    std::string heads;
    std::string tails;
    int countHeads;
    int countTails;
    double percentageHeads;
    double percentageTails;

public:
    //Default Constructor.
    CoinToss();

    std::string displayTossCoin();
    void displayCountFlip();
    void displayCountPercentage();
    void displayGraphicsComparison(double);
    void setTimesToFlipCoin();
    void InputNumber(int&);
    void resetCount();
    int getTimesToFlipCoin();

};
#endif