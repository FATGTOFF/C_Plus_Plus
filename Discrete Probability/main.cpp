#include <iostream>
#include <random>


int main()
{
    enum class Animal { RABBIT, FOX, DEER, BEAR, MOOSE, TOTALOFANIMALS };
    unsigned int count[static_cast<unsigned int>(Animal::TOTALOFANIMALS)]{ 0 };

    /* The player could encounter a rabbit, a fox, a deer, a bear or a moose, with the following
       probabilities:
            - rabbit: 50%
            - fox:    25%
            - deer:   15%
            - bear:    7%
            - moose:   5%
    */
    std::discrete_distribution<> dist({ 50.0, 25.0, 13.0, 7.0, 5.0});
    std::mt19937 eng(std::random_device{}());

    for (int i = 0; i < 100; ++i)
    {

        switch (dist(eng))
        {
            case static_cast<unsigned int>(Animal::RABBIT):
                ++count[static_cast<unsigned int>(Animal::RABBIT)];
                break;
            case static_cast<unsigned int>(Animal::FOX):
                ++count[static_cast<unsigned int>(Animal::FOX)];
                break;
            case static_cast<unsigned int>(Animal::DEER):
                ++count[static_cast<unsigned int>(Animal::DEER)];
                break;
            case static_cast<unsigned int>(Animal::BEAR):
                ++count[static_cast<unsigned int>(Animal::BEAR)];
                break;
            case static_cast<unsigned int>(Animal::MOOSE):
                ++count[static_cast<unsigned int>(Animal::MOOSE)];
                break;
        }
    }

    std::cout << "Total of Rabbits: " << count[static_cast<unsigned int>(Animal::RABBIT)] << std::endl;
    std::cout << "Total of Fox:     " << count[static_cast<unsigned int>(Animal::FOX)] << std::endl;
    std::cout << "Total of Deer:    " << count[static_cast<unsigned int>(Animal::DEER)] << std::endl;
    std::cout << "Total of Bear:    " << count[static_cast<unsigned int>(Animal::BEAR)] << std::endl;
    std::cout << "Total of Moose:   " << count[static_cast<unsigned int>(Animal::MOOSE)] << std::endl;

}