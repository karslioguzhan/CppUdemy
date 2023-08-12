#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <format>
#include <ios>

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

// Function declaration
void printVisualizationNumber(int maxRightSide);
Tours createTour();
void printTitle(int maxRightSide, const Tours tours);
void printColumnName(const int columnWidth, const int columnNumber);


int main()
{
    Tours tours{ createTour() };


    const int columnNumber{ 4 };
    const int columnWidth{ 25 };
    const int maxRightSide{ columnNumber * columnWidth };

    // Print numbers for visualization 
    printVisualizationNumber(maxRightSide);
    // Print Title
    printTitle(maxRightSide, tours);
    // Print Column names
    printColumnName(columnWidth, columnNumber);
    
    // Printing Country with its data
    int numCountryIteration{ 1 };
    for (auto country : tours.countries)
    {
        std::cout << std::setw(columnWidth * columnNumber) << std::setfill('*') << "" << std::endl;
        // printing Country name
        std::cout << std::left << std::setfill(' ') << std::setw(columnWidth * numCountryIteration) << country.name;
        int numCityIterator{ 1 };
        for (auto cities : country.cities)
        {
            if (numCityIterator == 1)
            {
                // Printing City
                std::cout << std::setw(columnWidth) << std::left << std::setfill(' ') << cities.name;
                // Printing Population
                std::cout << std::setw(columnWidth) << std::right << std::setfill(' ') << cities.population;
                std::cout << std::setw(columnWidth) << std::right << std::setfill(' ') << cities.cost;
                std::cout << std::endl;
                numCityIterator++;
                continue;
            }
            std::cout << std::setw(columnWidth) << std::left << std::setfill(' ') << "";
            std::cout << std::setw(columnWidth) << std::left << cities.name;
            std::cout << std::setw(columnWidth) << std::right << std::setfill(' ') << cities.population;
            std::cout << std::setw(columnWidth) << std::right << std::setfill(' ') << std::fixed << std::setprecision(2) << cities.cost;
            std::cout << std::endl;
            numCityIterator++;
        }
    }
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

// Function for creating default tour
Tours createTour()
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
    return tours;
}

void printTitle(int maxRightSide, const Tours tours)
{
    int numSpaceCenter{ static_cast<int>(std::round((static_cast<double>(maxRightSide) - tours.title.length()) / 2)) };
    std::cout << std::setfill(' ') << std::setw(numSpaceCenter + tours.title.length())
        << std::right << tours.title << std::setw(maxRightSide - (numSpaceCenter + tours.title.length())) 
        << "" << std::endl;
}

void printColumnName(const int columnWidth, const int columnNumber)
{
    std::cout << std::left << std::setfill(' ') << std::setw(columnWidth) << "Country";
    std::cout << std::left << std::setfill(' ') << std::setw(columnWidth) << "City";
    std::cout << std::right << std::setfill(' ') << std::setw(columnWidth) << "Population";
    std::cout << std::right << std::setfill(' ') << std::setw(columnWidth) << "Price";
    std::cout << std::endl;
    std::cout << std::setw(columnWidth * columnNumber) << std::setfill('-') << "";
    std::cout << std::endl;
}
