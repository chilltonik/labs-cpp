/*
3. Дано n – натуральное число. Среди простых чисел <= n, найти такое, в двоич-
ной записи которого максимальное количество нулей.
*/
#include<iostream> 
using namespace std;

int main()
{
	unsigned int n;

	cout << "Enter the n: ";
	cin >> n;

	int maxOf_0 = 0;
	int result = -1;

	for (int m = 2; m <= n; m++)               // перебор чисел
	{
		bool flag = true;
		
		for (int i = 2; i <= sqrt(m); i++)     // простота
		{
			if (m % i == 0)
			{
				flag = false;
				break;
			}
		}
		
		if (flag)                               
		{
			int simple = m;
			cout << "Simple = " << simple << endl;
			
			int iter = 0;

			while (simple >= 1)                  // количество единиц
			{
				int ostsimple = simple % 2;
				simple /= 2;

				if (ostsimple == 0)
				{
					iter++;
				}
				else
				{
					continue;
				}				
			}

			if (iter >= maxOf_0)                  // Результат
			{
				maxOf_0 = iter;
				result = m;
			}

			cout << "\tAmount of 0 in the binary cod: " << iter << endl;
		}
	}

	cout << "\nResult number is: " << result << "\nAmount of nulls in this number is: " << maxOf_0 << endl;
	
	return 0;
}