#pragma once
#include <iostream>
//#include <ctime>
#define TAB 8
//#define Rand 1.35
//#define delta 10

using namespace std;

void FillArray(int* arr, const int size);
void FillArray(char* arr, const int size);
void FillArray(double* arr, const int size);

template<class TT>
void ShowArray(TT* arr, const int size)
{
	cout << "\nYour array: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "\t";
	}

	cout << endl;

	for (int i = 0; i < size * TAB; ++i)
	{
		cout << "_";
	}
	cout << endl;
}

template <class T1>
void ChoiceIncrease(T1* arr, const int size, int& comparison, int& moving) //Возрастание
{
	cout << "\nSorting by choiceIncrease:" << endl;

	comparison = 0;
	moving = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		int iMin = i;                  //Поиск минимального элемента
		for (int j = i + 1; j < size; ++j)
		{
			comparison++;
			if (arr[j] < arr[iMin])
			{
				moving++;
				iMin = j;
			}
		}

		T1 temp = arr[iMin];              //Обмен элементов местами
		arr[iMin] = arr[i];
		arr[i] = temp;
	}
	//cout << "Comparisons: " << comparison << endl;
	//cout << "Movings: " << moving << endl;
}
template <class T2>
void ChoiceWaning(T2* arr, const int size, int& comparison, int& moving) // Убывание
{
	cout << "\nSorting by choiceWaning:" << endl;

	comparison = 0;
	moving = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		int iMin = i;                  //Поиск минимального элемента
		for (int j = i + 1; j < size; ++j)
		{
			comparison++;
			if (arr[j] > arr[iMin])
			{
				moving++;
				iMin = j;
			}
		}

		T2 temp = arr[iMin];              //Обмен элементов местами
		arr[iMin] = arr[i];
		arr[i] = temp;
	}
	/*cout << "Comparisons: " << comparison << endl;
	cout << "Movings: " << moving << endl;*/
}

template <class T3>
void BubbleIncrease(T3* arr, const int size, int& comparison, int& moving)
{
	cout << "\nSorting by BubbleIncrease:" << endl;

	comparison = 0;
	moving = 0;

	for (int k = size - 1; k >= 1; --k)
	{
		bool flag = false;
		for (int i = 0; i < k; ++i)
		{
			comparison++;
			if (arr[i] > arr[i + 1])
			{
				moving++;
				T3 temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				flag = true;
			}
		}

		if (!flag)
		{
			break;
		}
	}
	/*cout << "Comparisons: " << comparison << endl;
	cout << "Movings: " << moving << endl;*/
}
template <class T4>
void BubbleWaning(T4* arr, const int size, int& comparison, int& moving)
{
	cout << "\nSorting by BubbleWaning:" << endl;

	comparison = 0;
	moving = 0;

	for (int k = size - 1; k >= 1; --k)
	{
		bool flag = false;
		for (int i = 0; i < k; ++i)
		{
			comparison++;
			if (arr[i] < arr[i + 1])
			{
				moving++;
				T4 temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				flag = true;
			}
		}

		if (!flag)
		{
			break;
		}
	}
	/*cout << "Comparisons: " << comparison << endl;
	cout << "Movings: " << moving << endl;*/
}


