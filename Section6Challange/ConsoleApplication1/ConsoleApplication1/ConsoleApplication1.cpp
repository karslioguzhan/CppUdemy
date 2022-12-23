// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    const double priceSmallRoom{ 25 }, priceLargeRoom{35}, taxRate{.06};
    const int expireDays{ 30 };
    
    // Introduction
    std::cout << "Oguzhan's Carpet Cleaning Service\n";
    std::cout << "Charges\n\t$" << priceSmallRoom << " per small room \n\t$" 
        << priceLargeRoom << " per large rooms\n";
    std::cout << "Sales tax rate is 6%\n";
    std::cout << "Estimates are valid for " << expireDays << "days\n\n";

    // Get user input
    std::cout << "Estimate for carpet cleaning service\n";
    int numberOfSmallRooms{ 0 }, numberOfLargeRooms{0};
    std::cout << "Number of small rooms: ";
    std::cin >> numberOfSmallRooms;
    std::cout << "Number of larger rooms: ";
    std::cin >> numberOfLargeRooms;

    // Calculation of prices
    double calcSmallRooms = numberOfSmallRooms * priceSmallRoom;
    double calcLargeRooms = numberOfLargeRooms * priceLargeRoom;
    double sumPrice = calcSmallRooms + calcLargeRooms;
    double calcTaxes = sumPrice * taxRate;
    double totalEstimate = sumPrice + calcTaxes;
    
    // Output calculations
    std::cout << "Cost: $" << sumPrice;
    std::cout << "\nTax: $" << calcTaxes;
    std::cout << "\n====================================\n";
    std::cout << "Total estimate: $" << totalEstimate;
    std::cout << "\nThis estimate is valid for " << expireDays << " days\n";

}

