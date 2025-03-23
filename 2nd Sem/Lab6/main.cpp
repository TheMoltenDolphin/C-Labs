#include "main.h"
#include "Matrix.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix<int, 2, 3> vec1;
	vec1.fill(1);
	Matrix<int, 3, 5> vec2;
	vec2.fill(3);
	Matrix<int, 2, 5> vec3;
	vec3 = vec1*vec2;


	Matrix<int, 5, 3> vec5;
	vec5.fill(2);
	Matrix<int, 5, 3> vec6;
	vec6.fill(4);

	Matrix<int, 5, 3> vec7;
	vec5 += vec6;


	std::cout << vec5 << std::endl;
	Matrix<int, 3, 3> vec4;
	std::cout << "111" << std::endl;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			std::cout << (vec3)[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << vec4.det() << std::endl;

	return 0;

}	