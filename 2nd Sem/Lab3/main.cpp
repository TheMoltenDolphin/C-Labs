#include "main.h"

class parallelepiped
{
	private:
		double a;
		double b;
		double c;
	public:
		parallelepiped(double _a, double _b, double _c)
		{
			a = _a;
			b = _b;
			c = _c;
			std::cout << "parallelepiped created" << std::endl;
		}
		~parallelepiped()
		{
			std::cout << "parallelepiped destroyed" << std::endl;
		}
		double GetVolume()
		{
			return a * b * c;
		}
		double GetArea()
		{
			return a*b;
		}
		double diagonal()
		{
			return sqrt(a*a + b*b + c*c);
		}
};


int main()
{
	int a, b, c;
	std::cout << "Enter a, b, c: ";
	std::cin >> a >> b >> c;
	parallelepiped figure(a, b, c);
	std::cout << "Volume: " << figure.GetVolume() << std::endl;
	std::cout << "Area: " << figure.GetArea() << std::endl;
	std::cout << "Diagonal: " << figure.diagonal() << std::endl;
	return 0;	
}