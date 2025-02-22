#include "main.h"
#include "BigInt.hpp"
//#define Debug


int main()
{

	BigInt i  = "1001204907898561904732";
	BigInt i2 = i;
	BigInt i3 = "99999123999";
	BigInt i4 = "99999999";
	//i2 = i;
	std::cout << (i3+i4) << std::endl;
	i3 += i4;
	std::cout << i3 << std::endl;

	BigInt i7 = "123";
	BigInt i8 = "456";
	BigInt i6 = i7*i8;
	std:: cout << i6 << std::endl;
	i6 *= i7;
	std:: cout << i6 << std::endl;
	std::cout << i7 << " " << i8 << std::endl;
	std::cout << (i7==i8);
	std::cout << (i7>i8);
	std::cout << (i7<i8);
	std::cout << (i7!=i8);


	BigInt i9;
	//std::cin >> i9;
	//std::cout << i9;
	//i3 += i4;
	//std::cout<< i3;
	//std::cin>>i3;
	//std::cout<<i3;


	//BigInt inp;
	// std::cin >> inp;

	// std::cout << inp;
	return 0;
}