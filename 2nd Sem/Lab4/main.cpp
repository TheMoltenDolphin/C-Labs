#include "main.h"
#include "BigInt.hpp"
//#define Debug




int main()
{

	BigInt i  = "1001204907898561904732";
	BigInt i2 = i;
	BigInt i3;

	i3 = i2;

	//std::cin>>i3;
	std::cout<<i3;

	
	BigInt inp;
	std::cin >> inp;

	std::cout << inp;
	return 0;
}