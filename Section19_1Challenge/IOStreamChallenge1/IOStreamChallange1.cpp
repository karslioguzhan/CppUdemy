#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <format>
#include <ios>

// Function declaration
void printVisualizationNumber(int maxRightSide);

struct City 
{
	std::string name;
	long population;
	double cost;
};

// Assume each country has at least 1 city
struct Country 
{
	std::string name;
	std::vector<City> cities;
};

struct Tours 
{
	std::string title;
	std::vector<Country> countries;
};

int main()
{
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", 
                {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", 
                {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", 
                {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
                },
        },
            { "Argentina", 
                {
                    { "Buenos Aires", 3010000, 723.77 }
                }
        },
        }
    };

    const int columnNumber{ 4 };
    const int columnWidth{ 25 };
    const int maxRightSide{ columnNumber * columnWidth };

    // Print numbers for visualization 
    printVisualizationNumber(maxRightSide);

    int numSpaceCenter{ static_cast<int>(std::round((static_cast<double>(maxRightSide) - tours.title.length()) / 2)) };
    ;
    std::cout << std::setfill('=') << std::setw(numSpaceCenter + tours.title.length())
        << std::right << tours.title << std::setw(maxRightSide - (numSpaceCenter + tours.title.length())) 
        << "" << std::endl;
}

// Print numbers for visualization its place
void printVisualizationNumber(int maxRightSide)
{
    int printNumber{ 1 };
    for (int numChar{ 0 }; numChar < maxRightSide; ++numChar)
    {
        if (printNumber > 9)
        {
            printNumber = 0;
        }
        std::cout << printNumber;
        ++printNumber;
    }
    std::cout << std::endl << std::endl;
}
