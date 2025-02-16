#include "main.h"
#include "BigInt.hpp"
//#define Debug


std::string IntToStr(int* inp, int n)
{
	std::string out = "";
	for(int i = 0; i < n; i++)
	{
		out += std::to_string(inp[i]);
	}
	return out;
}

int main()
{

	BigInt i  = "1001204907898561904732";
	BigInt i2 = i;
	BigInt i3 = "99";
	BigInt i4 = "99";
	//i2 = i;
	//std:: cout << (i3+i4);
	BigInt i5 = i3+i4;
	std::cout << i5;
	i3 += i4;
	std::cout<< i3;
	//std::cin>>i3;
	//std::cout<<i3;


	//BigInt inp;
	// std::cin >> inp;

	// std::cout << inp;
	return 0;
}