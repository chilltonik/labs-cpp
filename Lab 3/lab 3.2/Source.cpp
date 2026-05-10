/*
Pолучить квадратную матрицу B пор€дка n, каждый элемент bij которой
равен максимуму из элементов исходной квадратной матрицы ј пор€дка n, рас-
положенных в закрашенной области (включа€ границы), определ€емой соот-
ветствующими индексами i, j по рисунку.
*/
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	const int ROW = 5;
	const int COL = 5;

	int arr_A[ROW][COL];

	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++)
	//	{
	//		arr_A[i][j] = rand() % 50;
	//	}
	//}

	int x = 1;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr_A[i][j] = x++;
		}

	}
 
	cout << "\t\tarr_A:\n\n";

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr_A[i][j] << "\t";
		}
		cout << endl << endl;
	}

	int arr_B[ROW][COL];

	int k, l, max = 0; // k - i, l - j

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			max = arr_A[i][j];

			for (k = i; k < ROW; k++)
			{
				for (l = 0; l <= j; l++)
				{
					if (arr_A[k][l] > max)
					{
						max = arr_A[k][l];
					}
				}
			}
			arr_B[i][j] = max;
		}
	}

	cout << "\n\t\tarr_B:\n\n";

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr_B[i][j] << "\t";
		}
		cout << endl << endl;
	}

	return 0;
}
