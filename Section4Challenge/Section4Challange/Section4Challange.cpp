// Section4Challange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter your favorite number between 1 and 100: ";
    int favoriteNumberInput{ 0 };
    std::cin >> favoriteNumberInput;
    std::cout << "Amazing!! That's my favorite number too! \n";
    std::cout << "No really!! " << favoriteNumberInput << " is my favorite number! \n";
    
    return 0;
}
