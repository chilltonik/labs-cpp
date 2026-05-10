/*
3.Построить матрицу B такого же размера, как А, по правилу: в каждом столбце
матрицы А удалить одинаковые элементы, сдвинув элементы в столбце, а в конец
столбцов добавить нули.
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));

	const int A = 100;

	int arrA[A][A];

	int ROWS, COLLS;

	cout << "ROWS: ";
	cin >> ROWS;

	cout << "COLLS: ";
	cin >> COLLS;

	int n;
	cout << "Enter the diapazon from 0: ";
	cin >> n;

	//cin-cout arrA
	cout << "\narrA:\n" << endl;
	for (int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLLS; ++j)
		{
			arrA[i][j] = rand() % n;
			cout << setw(3) << arrA[i][j];
		}
		cout << endl << endl;
	}

	//Замена повторок
	for (int j = 0; j < COLLS; ++j)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int k = i + 1; k < ROWS; ++k)
			{
				if (arrA[i][j] == arrA[k][j])
				{
					arrA[k][j] = n + 1;
				}
			}
		}
	}

	//{
		////cout arrA^
		//cout << "arrA (n + 1):\n" << endl;
		//for (int i = 0; i < ROWS; ++i)
		//{
		//	for (int j = 0; j < COLLS; ++j)
		//	{
		//		cout << setw(3) << arrA[i][j];
		//	}
		//	cout << endl << endl;
		//}
	//}

	int repeat = 0;

	//cout repeat 
	for (int j = 0; j < COLLS ; ++j)
	{
		repeat = 0;

		for (int i = 0; i < ROWS; ++i)
		{
			if (arrA[i][j] == n + 1)
			{
				++repeat;
			}
		}
		cout << "R:" << repeat << setw(3);
	}
	cout << endl;

	{
		//for (int j = 0; j < COLLS; ++j)
		//{
		//	int count = 0;// занулять снизу вверх посчетику
		//	for (int i = 0; i < ROWS; ++i)
		//	{
		//		if (arrA[i][j] == n + 1) 
		//		{
		//			if (i == ROWS - 1)
		//			{
		//				arrA[i][j] = 0;
		//			}

		//			for (int k = i; k < ROWS; ++k)
		//			{
		//				arrA[k][j] = arrA[k + 1][j];	
		//			}
		//		}
		//	}
		//}
	}

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLLS; ++j)
		{
			while (arrA[i][j] == n + 1)
			{
				for (int j = 0; j < COLLS; ++j)
				{
					int count = 0;// занулять снизу вверх посчетику 

					for (int i = 0; i < ROWS; ++i)
					{
						if (arrA[i][j] == n + 1)
						{
							++count;
							if (i == ROWS - 1)
							{
								arrA[i][j] = 0;
							}

							for (int k = i; k < ROWS; ++k)
							{
								arrA[k][j] = arrA[k + 1][j];
							}
						}
					}
					for (int x = 0; x < count; ++x) 
					{
						arrA[ROWS - 1 - x][j] = 0;
					}
				}
			}
		}
	}

	cout << "\narrB:\n" << endl;
	for (int j = 0; j < COLLS; ++j)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			cout << setw(3) << arrA[j][i];
		}
		cout << endl << endl;
	}

	return 0;
}