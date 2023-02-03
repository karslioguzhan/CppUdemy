// Section9Challange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cctype>

// Function Prototypes
void printMenu();
char selectMenu();
void printNumbers(const std::vector<int>& userNumbers);
void calculateMean(std::vector<int> &userNumbers);
void addNumber(std::vector<int>& userNumbers);
void findNumber(std::vector<int> userNumbers, char searchType);

int main()
{
    char userInput{};
    std::vector <int> userNumbers{};
    do
    {
        printMenu();
        userInput = selectMenu();


        switch (userInput)
        {
        case 'P':
            printNumbers(userNumbers);
            break;
        case 'A':
            addNumber(userNumbers);
            break;
        case 'M':
            calculateMean(userNumbers);
            break;
        case 'Q':
            std::cout << "Goodbye\n";
            break;
        case 'S':
            findNumber(userNumbers, 's');
            break;
        case 'L':
            findNumber(userNumbers, 'L');
            break;
        default:
            std::cout << "Unknown selection, please try again\n\n";
        }

    } while (userInput != 'Q');

}

void printMenu()
{
    std::cout << "P - Print numbers\n";
    std::cout << "A - Add number\n";
    std::cout << "M - Display mean of the numbers\n";
    std::cout << "S - Display the smallest number\n";
    std::cout << "L - Display the largest number\n";
    std::cout << "Q - Quit\n\n";
    std::cout << "Enter your choice: ";
}

void printNumbers(const std::vector<int>& userNumbers)
{
    if (userNumbers.empty())
    {
        std::cout << "[] - the list is empty\n\n";
    }
    else
    {
        std::cout << "[ ";
        for (auto valVec : userNumbers)
        {
            std::cout << valVec << " ";
        }
        std::cout << "]\n\n";
    }
}

void calculateMean(std::vector<int> &userNumbers)
{
    if (userNumbers.empty())
    {
        std::cout << "Unable to calculate the mean - no data\n\n";
    }
    else
    {
        int sum{};
        double mean{};
        for (auto valVec : userNumbers)
        {
            sum += valVec;
        }
        mean = static_cast<double>(sum) / userNumbers.size();
        std::cout << "The mean is: " << mean << std::endl << std::endl;
    }
}

void findNumber(std::vector<int> userNumbers, char searchType)
{
    // smallest number
    if (searchType == 's')
    {
        if (userNumbers.empty())
        {
            std::cout << "Unable to determine the smallest number - list is empty\n\n";
        }
        else
        {
            int smallest{ userNumbers.at(0) };
            for (auto smallVal : userNumbers)
            {
                if (smallest >= smallVal)
                {
                    smallest = smallVal;
                }
            }
            std::cout << "The smallest number is " << smallest << "\n\n";
        }
    }
    // largest number
    else
    {
        if (userNumbers.empty())
        {
            std::cout << "Unable to determine the largest number - list is empty\n\n";
        }
        else
        {
            int largest{ userNumbers.at(0) };
            for (auto bigVal : userNumbers)
            {
                if (largest <= bigVal)
                {
                    largest = bigVal;
                }
            }
            std::cout << "The largest number is " << largest << "\n\n";
        }
    }
}

void addNumber(std::vector<int>& userNumbers)
{
    std::cout << "Enter an integer to add to the list: ";
    int addedNumber{};
    std::cin >> addedNumber;
    userNumbers.push_back(addedNumber);
    std::cout << userNumbers.at(userNumbers.size() - 1) << " added\n\n";
}

char selectMenu()
{
    char userInput{};
    std::cin >> userInput;
    return std::toupper(userInput);
}