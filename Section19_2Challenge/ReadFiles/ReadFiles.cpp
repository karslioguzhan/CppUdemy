#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct student
{
	std::string name;
	std::string answers;
};

int calculateScore(std::string correctAnswers, std::string answers);

int main()
{

	std::fstream responsesFile;
	responsesFile.open("responses.txt");
	

	if (!responsesFile)
	{
		std::cerr << "Error: Cannot open File: responses.txt" << std::endl;
		return 1;
	}

	int numberReadedLines{ 1 };
	std::string tempLine;
	std::string correctAnswers;
	std::vector<student>  students;
	student tempStudent;
	// Read data from text file
	while (std::getline(responsesFile, tempLine))
	{
		if (numberReadedLines == 1)
		{
			correctAnswers = tempLine;
			numberReadedLines++;
			continue;
		}
		else if (numberReadedLines % 2 == 0)
		{
			tempStudent.name = tempLine;
			numberReadedLines++;
			continue;
		}
		else
		{
			tempStudent.answers = tempLine;
			numberReadedLines++;
		}
		students.push_back(tempStudent);
	}

	// Print data 
	std::cout << std::setw(15) << std::left << "Student";
	std::cout << std::setw(15) << std::right << "Score" << std::endl;
	std::cout << std::setw(30) << std::setfill('-') << "" << std::endl;
	int cummulativeScore{ 0 };
	for (auto studentIterator : students)
	{
		std::cout << std::setfill(' ') << std::setw(15) << std::left << studentIterator.name;
		int scoreStudent = calculateScore(correctAnswers, studentIterator.answers);
		cummulativeScore += scoreStudent;
		std::cout << std::setw(15) << std::right << scoreStudent << std::endl;
	}
	std::cout << std::setw(30) << std::left << std::setfill('-') << "" << std::endl;
	std::cout << std::setw(20) << std::setfill(' ') << "Average Score";
	std::cout << std::fixed << std::setprecision(1) << std::setw(10)
		<< std::right <<cummulativeScore / (static_cast<float>(students.size())) << std::endl;

	return 0;

}

int calculateScore(std::string correctAnswers, std::string answers)
{
	int tempResult{ 0 };
	for (int numChar{ 0 }; numChar < correctAnswers.length(); ++numChar)
	{
		if (correctAnswers.at(numChar) == answers.at(numChar))
		{
			tempResult++;
		}
	}
	return tempResult;
}
