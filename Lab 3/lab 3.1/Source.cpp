/*
Дан массив целых чисел, содержащий n элементов. Для тестирования преду-
смотреть возможность задавать элементы массива различным образом: при
описании с инициализацией, присвоением значений (в том числе случайных), или
вводом необходимых значений.

3. Получить за один просмотр массив С(К), упорядоченный по возрастанию,
путем слияния массивов A(N) и B(M), упорядоченных по возрастанию
(K = N + M).
*/
#include<iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int A = 10;
	const int B = 10;

	int N = 10;
	int M = 10;

	int arr_A[A] = { -13, -7, -3, 0, 1, 2, 6, 11, 36, 56 };
	int arr_B[B] = { -17, -5, -4, 0, 2, 3, 8, 17, 22, 45 };

	cout << "Выберите способ задания массивов А(N) и В(M):\n" << endl;
	cout << "1.Массив А(N) и В(M) уже проинициализированы при описании." << endl
		<< "2.Массивы А(N) и В(M) задаются вручную пользователем." << endl
		<< "3.Массивы А(N) и В(M) заполняются случайными числами." << endl;

	int solution;
	
	cout << "\nВаш вариант: ";
	cin >> solution;
	
	switch (solution)
	{
		case 1:
		{
			int fixSize = 10;
			cout << "\n1.Массив А(N) и В(M) уже проинициализированы при описании (N и M равны 10):" << endl;			

			cout << "\n\tA" << endl;

			for (int i = 0; i < fixSize; i++)
			{
				cout << "| " << "arr_A[" << i << "] = " << arr_A[i] << endl;
			}

			cout << "\n\tB" << endl;

			for (int i = 0; i < fixSize; i++)
			{
				cout << "| " << "arr_B[" << i << "] = " << arr_B[i] << endl;
			}
		}
		break;

		case 2:
		{
			cout << "\n2.Массивы А(N) и В(M) задаются вручную пользователем:" << endl;

			cout << "\nВведите размер массива А (от 0 до 10): ";
			cin >> N;

			cout << "\n\tA" << endl;

			for (int i = 0; i < N; i++)
			{
				cout << "|" << "arr_A[" << i << "] = ";
				cin >> arr_A[i];
			}

			cout << "\nВведите размер массива B (от 0 до 10): ";
			cin >> M;

			cout << "\n\tB" << endl;

			for (int i = 0; i < M; i++)
			{
				cout << "|" << "arr_B[" << i << "] = ";
				cin >> arr_B[i];
			}
		}
		break;

		case 3:
		{
			cout << "\n3.Массивы А(N) и В(M) заполняются случайными числами:" << endl;
			
			cout << "\nВведите размер массива А (от 0 до 10): ";
			cin >> N;

			cout << "\n\tA" << endl;

			for (int i = 0; i < N; i++)
			{
				arr_A[i] = rand() % 50;
				cout << "|" << "arr_A[" << i << "] = "<< arr_A[i] << endl;
			}

			int box1; 

			for (int i = 0; i < N - 1; i++) 
			{
				for (int j = 0; j < N - i - 1; j++)
				{
					if (arr_A[j] > arr_A[j + 1]) 
					{
						box1 = arr_A[j];
						arr_A[j] = arr_A[j + 1];
						arr_A[j + 1] = box1;
					}
				}
			}

			cout << "\n\tA^" << endl;

			for (int i = 0; i < N; i++) 
			{
				cout << "|" << "arr_A^[" << i << "] = " << arr_A[i] << endl;
			}

			cout << "\nВведите размер массива B (от 0 до 10): ";
			cin >> M;

			cout << "\n\tB" << endl;

			for (int i = 0; i < M; i++)
			{
				arr_B[i] = rand() % 50;
				cout << "|" << "arr_B[" << i << "] = " << arr_B[i] << endl;
			}

			int box2; 

			for (int i = 0; i < M - 1; i++) 
			{
				for (int j = 0; j < M - i - 1; j++)
				{
					if (arr_B[j] > arr_B[j + 1]) 
					{
						box2 = arr_B[j];
						arr_B[j] = arr_B[j + 1];
						arr_B[j + 1] = box2;
					}
				}
			}

			cout << "\n\tB^" << endl;

			for (int i = 0; i < M; i++) 
			{
				cout << "|" << "arr_B^[" << i << "] = " << arr_B[i] << endl;
			}

		}
		break;

		default:
		{
			cout << "\nВ следующий раз введите значение согласно инструкции!" << endl;
		}
		break;

	}

	int arr_C[A + B] = { 0 };

	if (solution == 1 ||
		solution == 2 ||
		solution == 3)
	{
		for (int i = 0, j = 0, k = 0; k < N + M; k++)
		{
			// если А закончился раньше
			if (i >= N && j < M) 
			{
				arr_C[k] = arr_B[j];
				j++;
			}
			// если Б закончился раньше
			if (j >= M && i < N) 
			{
				arr_C[k] = arr_A[i];
				i++;
			}
			// пока одинаковы
			if (i < N && j < M) 
			{
				if (arr_A[i] < arr_B[j])
				{
					arr_C[k] = arr_A[i];
					i++;
				}
				else
				{
					arr_C[k] = arr_B[j];
					j++;
				}
			}
		}

		cout << "\n\tС" << endl;

		for (int k = 0; k < N + M; k++)
		{
			cout << "|" << "arr_C[" << k << "] = " << arr_C[k] << endl;
		}
	}
	return 0;
}