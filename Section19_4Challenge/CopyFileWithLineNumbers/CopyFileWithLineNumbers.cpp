#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	inputFile.open("romeoandjuliet.txt");

	if (!inputFile)
	{
		std::cerr << "Cannot find or open file!\n";
		return 1;
	}

	outputFile.open("formattedRomeoandjuliet.txt");
	if (!outputFile)
	{
		std::cerr << "Cannot create file to write\n";
		return 2;
	}

	std::string readedLine;
	int numLine{ 1 };
	while (std::getline(inputFile, readedLine))
	{
		if (readedLine.empty())
		{
			outputFile << readedLine << std::endl;
		}
		else
		{
			outputFile << std::left << std::setw(6) << numLine << "\t" << readedLine << std::endl;
			numLine++;
		}
	}
	std::cout << "Formatting and copy was successful!\n";

	inputFile.close();
	outputFile.close();
	return 0;

}
