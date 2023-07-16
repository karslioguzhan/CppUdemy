#include "Test.h"

Test::Test():
	data{0}
{
	std::cout << "\tTest constructor (" << data << ")\n";
}

Test::Test(int data):
	data{data}
{
	std::cout << "\tTest constructor (" << data << ")\n";
}

int Test::get_data() const
{
	return data;
}

Test::~Test()
{
	std::cout << "\nTest destructor (" << data << ")";
}
