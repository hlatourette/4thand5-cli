#include <iostream>
#include <string>

#include "util.h"

using namespace fourthandfive;

int main()
{
    std::string question;
    std::cout << "What would you like to know?" << std::endl;
    std::cin >> question;
    std::cout << meaningOfLifeTheUniverseAndEverything(question) << std::endl;
    return 0;
}

