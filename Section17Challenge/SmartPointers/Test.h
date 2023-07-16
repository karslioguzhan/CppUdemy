#pragma once
#include <iostream>

class Test
{
private:
	int data;
public:
	Test();
	Test(int data);
	int get_data() const;
	~Test();
};

