// Section10ChallangeAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    // get user inputstring
    std::string userString;
    do 
    {
        std::cout << "Enter desired string for generating pyramide: \n";
        std::getline(std::cin, userString);
        std::cout << "\n";
        if (userString.empty())
        {
            std::cout << "Cannot build a pyramide with empty String! \n\n";
        }
    } while (userString.empty());
    

    // initialize necessary variables
    size_t lengthUserString{ userString.length() };

    // create pyramide
    for (size_t numRow{ 0 }; numRow < lengthUserString; ++numRow)
    {
        // loop for empty spaces
        for (size_t numEmpty{ 0 }; numEmpty < (lengthUserString - numRow-1); ++numEmpty)
        {
            std::cout << " ";
        }
        // printing chars into row (left half)
        size_t reqChar{ numRow + 1 };
        size_t charNumLeft{};
        for (charNumLeft; charNumLeft < reqChar; ++charNumLeft)
        {
            std::cout << userString.at(charNumLeft);
        }
        // printing chars into row (right half)
        
        for (size_t charNumRight{ charNumLeft -1}; charNumRight > (reqChar - charNumLeft); --charNumRight)
        {
            std::cout << userString.at(charNumRight-1);
        }
        
        std::cout << "\n";
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
