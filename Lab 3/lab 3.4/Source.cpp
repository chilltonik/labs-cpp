/*
Дана действительная матрица порядка n× m. Перебор строк/столбцов мат-
рицы осуществить с использованием указателей. Обосновать выбор метода
сортировки.
3. Упорядочить строки по возрастанию первых элементов.
*/
#include <iostream> 
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	const int A = 100;
	const int B = 100;

	int arr[A][B];

	int ROWS, COLLS;

	cout << "Enter ROWS: ";
	cin >> ROWS;

	cout << "Enter COLLS: ";
	cin >> COLLS;

	//cin - cout arr
	cout << "\t\tarr_A\n\n";

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLLS; ++j)
		{
			arr[i][j] = rand() % 50 - 20;
			cout << arr[i][j] << "\t";
		}
		cout << "\n\n";
	}
	
	// Выбор
	for (int i = 0; i < ROWS - 1; ++i)
	{
		int iMin = i; // iMin - это индекс строки, на место которой прилетит наименьшая на данный момент строка

		for (int j = i + 1; j < ROWS; ++j)
		{
			if (*arr[j] < *arr[iMin])
			{
				iMin = j;
			}
		}

		swap(arr[iMin], arr[i]);
	}

	//cout arr
	cout << endl;
	cout << "arr^:" << endl;

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLLS; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}

	return 0;
}