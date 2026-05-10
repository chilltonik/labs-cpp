#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x = -4;
	double y1 = 0,
		slag = 1,
		y2 = 1,
		deg = x,
		fact = 1;
	double const EPS = 1e-6;
	int i = 0;

	for (x; x <= 6; x += 0.5)
	{
		int j = 0;
		deg = x;

		while (abs(slag) >= EPS)
		{
			fact *= (i + 1);
			slag = deg / fact;
			deg *= x;
			i++;			
			j++;

			y2 += slag;
		}

		 /*double sum = 0;
		double number = 1;
		short degree = 0;
		while (abs(number) >= EPS)
		{
			double chislitel = 1;
			for (i = 1; i <= degree; i++)
			{
				chislitel *= x;
			}

			double znam = 1;
			for (i = 1; i <= degree; i++)
			{
				znam *= i;
			}

			number = chislitel / znam;
			sum += number;
			++degree;
		}*/

		cout << "x: " << x << "\t\ty2: " << y2 - 1 << "\tIterations: " << j << endl;
		
		i = 0;
		fact = 1;
		slag = 1;
		y2 = 1;

		y1 = exp(x) - 1;
		cout << "x: " << x << "\t\ty1: " << y1 << endl << endl;
	}

	return 0;
}