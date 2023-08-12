#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main()
{
    std::fstream romeoAndJuliaFile;
    romeoAndJuliaFile.open("romeoandjuliet.txt");
    
    // Check if file is open correctly
    if (!romeoAndJuliaFile)
    {
        std::cerr << "Error reading Romeo and Julia File\n";
        return 1;
    }

    std::vector<std::string> romeoAndJulia;
    std::string tempString;
    while (romeoAndJuliaFile >> tempString)
    {
        romeoAndJulia.push_back(tempString);
    }

    std::cout << "Enter the substring to search for: ";
    std::string searchedWord{};
    std::cin >> searchedWord;
    int equalWords{ 0 };
    for (std::string actualWord : romeoAndJulia)
    {
        if (boost::algorithm::contains(actualWord, searchedWord) == true)
        {
            equalWords++;
        }
    }
    std::cout << romeoAndJulia.size() << " words were searched...\n";
    std::cout << "The substring " << searchedWord << " was found " << equalWords << " times\n";


    romeoAndJuliaFile.close();
    return 0;

}
