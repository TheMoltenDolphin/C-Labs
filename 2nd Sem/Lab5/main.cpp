#include "main.h"
#include "MyVector.hpp"

int main()
{
	MyVector vec1;
	vec1.reserve(2000);

	vec1.push_back(1);
	vec1.push_back(6);
	vec1.push_back(2);
	vec1.insert(2, 3, 777);
	
	for (int i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i] << std::endl;
	}

	std::cout << std::endl;

	vec1.erase(2);
	vec1.front() = 100;
	vec1.back() = 200;
	vec1.resize(10, 0);

	for (int i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i] << std::endl;
	}
	
	return 0;

}	