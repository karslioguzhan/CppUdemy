#include "ChallengeFunctions.h"

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
	//std::vector<std::shared_ptr<Test>> vectorShared;
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();

}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num)
{
	for (int numElement{ 0 }; numElement < num; ++numElement)
	{
		std::cout << "Enter data point [" << numElement + 1 << "] : ";
		int inputNumber{ 0 };
		std::cin >> inputNumber;
		vec.push_back(std::make_shared<Test>(inputNumber));
		//vec.push_back(std::make_shared<Test>(Test(inputNumber)));
	}
}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{
	std::cout << "\nDisplaying vector data\n";
	std::cout << "=========================\n";
	for (auto &numElement:vec)
	{
		std::cout << numElement->get_data() << std::endl;
	}
	std::cout << "=========================\n";
}
