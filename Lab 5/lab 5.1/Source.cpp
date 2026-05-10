/*
* Выполнить задание, оформив его через функции. Передачу массивов в функции
организовать несколькими способами.
Получить квадратную матрицу порядка n, элементами которой являются за-
данные числа а1, ..., аnn, расположенные в ней по спирали (см. схему на рисунке).
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void FillArray1(int* ptr[], const int ROWS, const int COLS)
{
	int StartRow = 0;
	int EndRow = ROWS - 1;
	int StartCol = 0;
	int EndCol = COLS - 1;

	int count = 1;

	while (StartRow <= EndRow && StartCol <= EndCol)
	{
		for (int i = StartRow; i <= EndRow; ++i)
		{
			ptr[i][StartCol] = count;
			count++;
		}
		StartCol++;

		for (int j = StartCol; j <= EndCol; ++j)
		{
			ptr[EndRow][j] = count;
			count++;
		}
		EndRow--;

		for (int i = EndRow; i >= StartRow; i--)
		{
			ptr[i][EndCol] = count;
			count++;
		}
		EndCol--;

		for (int j = EndCol; j >= StartCol; j--)
		{
			ptr[StartRow][j] = count;
			count++;
		}
		StartRow++;
	}
}
void FillArray2(int Arr[20][20], const int ROWS, const int COLS)
{
	int StartRow = 0;
	int EndRow = ROWS - 1;
	int StartCol = 0;
	int EndCol = COLS - 1;

	int count = 1;

	while (StartRow <= EndRow && StartCol <= EndCol)
	{
		for (int i = StartRow; i <= EndRow; ++i)
		{
			Arr[i][StartCol] = count;
			count++;
		}
		StartCol++;

		for (int j = StartCol; j <= EndCol; ++j)
		{
			Arr[EndRow][j] = count;
			count++;
		}
		EndRow--;

		for (int i = EndRow; i >= StartRow; i--)
		{
			Arr[i][EndCol] = count;
			count++;
		}
		EndCol--;

		for (int j = EndCol; j >= StartCol; j--)
		{
			Arr[StartRow][j] = count;
			count++;
		}
		StartRow++;
	}
}
void ShowArray(int* ptr[], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			cout << ptr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	const int _ROWS_ = 20;
	const int _COLS_ = _ROWS_;

	int ROWS = 0;
	int COLS = 0;

	cout << "Enter matrix order: ";
	cin >> ROWS;

	COLS = ROWS;

	int Arr[_ROWS_][_COLS_];

	int* p[_ROWS_];//создаем массив указателей
	for (int i = 0; i < ROWS; ++i)
	{
		p[i] = Arr[i]; //присваиваем адрес каждой строки
	}

	FillArray1(p, ROWS, COLS);
	cout << "\nFillArray1:" << endl;
	ShowArray(p, ROWS, COLS);

	FillArray2(Arr, ROWS, COLS);
	cout << "\nFillArray2:" << endl;
	ShowArray(p, ROWS, COLS);

	return 0;
}