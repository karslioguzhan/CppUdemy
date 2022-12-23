#include <iostream>

int main()
{
    std::cout << "Enter your favorite Number between 1 and 100: ";
    int favoriteNumber{0};
    std::cin >> favoriteNumber;
    std::cout << "Awesome " << favoriteNumber << " is my favorite too \n";
    return 0;
}

