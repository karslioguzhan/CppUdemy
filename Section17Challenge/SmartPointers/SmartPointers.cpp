#include <iostream>
#include <memory>
#include <vector>
#include "Test.h"
#include "ChallengeFunctions.h"

int main()
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	int num{ 0 };
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);

	return 0;
}