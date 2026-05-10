/*
	Определить k-ую цифру в последовательности степеней двоек.
*/
#include <iostream>
using namespace std;

void main()
{
	int k;

	cout << "Enter k: ";
	cin >> k;                                                         

	int iter = 0;
	int degree_Of_Two = 1;
	int Copy_degree_Of_Two = 1;
	int inverted_Degree_Of_Two = 0;
	int ost = 0;

	while (k != iter)
	{
		Copy_degree_Of_Two = degree_Of_Two;

		while (Copy_degree_Of_Two)                                           //переворот                              
		{
			ost = Copy_degree_Of_Two % 10;
			Copy_degree_Of_Two /= 10;
			inverted_Degree_Of_Two = inverted_Degree_Of_Two * 10 + ost;
		}

		Copy_degree_Of_Two = degree_Of_Two;

		while (inverted_Degree_Of_Two)                                        //остатки
		{
			int ost = inverted_Degree_Of_Two % 10;
			inverted_Degree_Of_Two /= 10;

			iter++;

			if (k == iter)                                                    //проверка
			{
				cout << "m: " << ost;
				break;
			}
			else
			{
				continue;
			}
		}
		degree_Of_Two *= 2;
	}
}