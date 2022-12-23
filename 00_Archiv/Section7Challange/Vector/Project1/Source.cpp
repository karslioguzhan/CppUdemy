#include <iostream>
#include <vector>

int main()
{
	// First task
	std::vector <int> vector1, vector2;

	// Second task
	vector1.push_back(10);
	vector1.push_back(20);
	std::cout << "vector1\n";
	std::cout << "\tFirst Element: " << vector1.at(0) << "\n\tSecond Element: "
		<< vector1.at(1) << "\n";
	std::cout << "\tSize of the vector1: " << vector1.size() << "\n";

	// Third task
	std::cout << "vector2\n";
	vector2.push_back(100);
	vector2.push_back(200);
	std::cout << "\tFirst Element: " << vector2.at(0) << "\n\tSecond Element: "
		<< vector2.at(1) << "\n";
	std::cout << "\tSize of the vector2: " << vector2.size() << "\n";

	// 4.th task
	std::vector <std::vector <int>> vector_2d;
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);
	std::cout << "2D Vector\n";
	std::cout << "\tFirst Row of vector_2d: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << "\n";
	std::cout << "\tSecond Row of vector_2d: " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << "\n";

	// 5.th task
	vector1.at(0) = 1000;

	// 6.th task
	std::cout << "2D Vector\n";
	std::cout << "\tFirst Row of vector_2d: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << "\n";
	std::cout << "\tSecond Row of vector_2d: " << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << "\n";

	// 7.th task
	std::cout << "vector1\n";
	std::cout << "\tFirst Element: " << vector1.at(0) << "\n\tSecond Element: "
		<< vector1.at(1) << "\n";
	std::cout << "\tSize of the vector1: " << vector1.size() << "\n";
}