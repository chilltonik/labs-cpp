/*
3. Вводится последовательность целых чисел. Определить количество элемен-
тов в наиболее длинной подпоследовательности подряд идущих чисел, образую-
щих арифметическую прогрессию.
*/
#include <iostream>
using namespace std;

void main()
{
	int size;
	cout << "Enter the size: ";
	cin >> size;

	int n;

	cout << "\nEnter n1: ";
	cin >> n;

	int prevN = n;

	cout << "\nEnter n2: ";
	cin >> n;

	int curN = n;

	int prevDif = curN - prevN;

	int curAmound = 2;
	int AmoundMax = 2;

	for (int i = 0; i < size - 2; i++)
	{
		prevN = curN;

		cout << "\nEnter n" << i + 3 << ": ";
		cin >> curN;

		int curDif = curN - prevN;

		if (curDif == prevDif)
		{
			++curAmound;
		}
		else
		{
			if (curAmound > AmoundMax)
			{
				AmoundMax = curAmound;
			}
			curAmound = 2;
		}

		prevDif = curDif;
	}

	if (AmoundMax < curAmound)
	{
		AmoundMax = curAmound;
	}

	cout << "\nThe answer: " << AmoundMax << endl;
}
