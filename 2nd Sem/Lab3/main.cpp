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
			//std::cout << "parallelepiped created" << std::endl;
		}
		~parallelepiped()
		{
			//std::cout << "parallelepiped destroyed" << std::endl;
		}
		double GetVolume()
		{
			return a * b * c;
		}
		double GetArea()
		{
			return a*b;
		}
		double GetDiagonal()
		{
			return sqrt(a*a + b*b + c*c);
		}
};


int main()
{

	double a, b, c;
	std::cout << "Enter a, b, c: ";
	std::cin >> a >> b >> c;
	parallelepiped figure1(a, b, c);

	double a1, b1, c1;
	std::cout << "Enter a, b, c: ";
	std::cin >> a1 >> b1 >> c1;
	parallelepiped figure2(a1, b1, c1);

	std::cout << "volume 1 " << (figure1.GetVolume() < figure2.GetVolume() ? "<" : (figure1.GetVolume() > figure2.GetVolume() ? ">" : "=")) << " volume 2" << std::endl; 
	std::cout << "area 1  " << (figure1.GetArea() < figure2.GetArea() ? "<" : (figure1.GetArea() > figure2.GetArea() ? ">" : "=")) << " area 2" << std::endl; 
	std::cout << "diagonal 1 " << (figure1.GetDiagonal() < figure2.GetDiagonal() ? "<" : (figure1.GetDiagonal() > figure2.GetDiagonal() ? ">" : "=")) << " diagonal 2" << std::endl; 

	return 0;	
}