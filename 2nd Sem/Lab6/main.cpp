#include "main.h"
#include "Matrix.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix<int> vec1;
	Matrix<int> vec2(3, 3);
	vec1 = vec2;
	
	vec2 = vec2;
	vec2++;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			std::cout << vec2[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << vec2.det() << std::endl;
	std::cout << "111" << std::endl;

	return 0;

}	