#include <iostream>
#include <vector>

int main()
{
	// First task
	std::vector <int> vector1, vector2;
	vector1.push_back(10);
	vector1.push_back(20);

	std::cout << "First value of vector1: " << vector1.at(0)
		<< "\n Second value of vector1: " << vector1.at(1) 
		<< "\n Size of vector1: " << vector1.size();
	vector2.push_back(100);
	vector2.push_back(200);
	std::cout << "\n\nFirst value of vector2: " << vector2.at(0)
		<< "\n Second value of vector2: " << vector2.at(1)
		<< "\n Size of vector2: " << vector2.size() << "\n";
	
	// Second task multidimensional vector
	std::vector <std::vector <int>> vector_2d;
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	std::cout << "First Value of vector_2d: " 
		<< vector_2d.at(0).at(0) << std::endl;

	vector1.at(0) = 1000;

	std::cout << "\nFirst Value of vector_2d: "
		<< vector_2d.at(0).at(0) << std::endl;
}
