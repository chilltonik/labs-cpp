/*
3. Дано n – натуральное число. Среди простых чисел <= n, найти такое, в двоич-
ной записи которого максимальное количество нулей.
*/

#include<iostream>
using namespace std;

int main()
{
	const int N = 1000;
	int prime_check[N];

	int n;

	cout << "Enter n: ";
	cin >> n;

	for (int i = 2; i <= n; ++i) 
	{
		prime_check[i] = true;
	}

	//вычеркиваем (обнуляем) кратные числа
	for (int i = 2; i <= sqrt(double(n)); ++i)
	{
		if (prime_check[i])
		{
			for (int j = i * 2; j <= n; j += i)
			{
				prime_check[j] = false;
			}
		}
	}

	//проверка на простое и вывод

	int max_of_0 = 0;
	int result = 0;

	for (int i = 2; i <= n; ++i)
	{
		if (prime_check[i]) 
		{
			cout << "\nSimple: " << i << endl;

			int simple = i;
			int ost = 0;
			int iter = 0;

			while (simple)
			{
				ost = simple % 2;
				simple /= 2;

				if (ost == 0)
				{
					iter++;
				}
			}

			if (iter >= max_of_0)
			{
				max_of_0 = iter;
				result = i;
			}
			cout << "Amount of nulls in this number is: " << max_of_0 << endl;
		}
	}

	cout << "\n\nResult number is: " << result << "\nAmount of nulls in this number is: " << max_of_0 << endl;

	return 0;
}