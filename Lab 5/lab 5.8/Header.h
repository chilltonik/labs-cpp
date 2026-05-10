#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#define RAND 1.156
#define length 30
#define minlength 5
#define ascii_start 65
#define ascii_finish 90

using namespace std;

void Null(char** arr_strings, const int count_of_strings, const int len);
void Fill_arr_strings_yourself(char** arr_strings, const int count_of_strings, const int len);
void Fill_arr_strings_random(char** arr_strings, const int count_of_strings, const int len);
void Show_arr_strings(char** arr_strings, const int count_of_strings, const int len);
void Menu(char** arr_strings, const int count_of_strings);
void Delete(char** arr_strings, const int count_of_strings);

void Comparison(char** arr, const int size, int firstpoze, int secondpoze, bool& flag);

template <class T>
void FillArray(T* Arr, const int size)
{
	int min = 0;
	int max = 0;

	bool flag = true;

	while (flag)
	{
		cout << "\nEnter the MAX value for generation: ";
		cin >> max;
		cout << "Enter the MIN value for generation: ";
		cin >> min;

		if (max >= min)
		{
			flag = false;
		}
		else
		{
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}


	for (int i = 0; i < size; ++i)
	{
		Arr[i] = RAND * ((rand() % (max - 1 - min)) + min);
	}
}

template <class T>
void ShowArray(T* Arr, const int size)
{
	cout << "\nYour array: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << Arr[i] << "\t";
	}
}

template <class T>
void Comparison(T* arr, const int size, int FirstPoze, int SecondPoze, bool& flag)
{
	if (FirstPoze > size || SecondPoze > size)
	{
		cout << "Error!" << endl;
		exit(0);
	}

	if (arr[FirstPoze] < arr[SecondPoze])
	{
		flag = true;
	}
}

template <class T>
void Merg(T arr[], const int size, int begin, int end)
{
	int i = begin;
	int mid = begin + (end - begin) / 2;
	int j = mid + 1;
	int k = 0;
	T* d = new T[size];

	while (i <= mid && j <= end)
	{
		bool flag = false;
		Comparison(arr, size, i, j, flag);

		if (flag)
		{
			d[k] = arr[i];
			++i;
		}
		else
		{
			d[k] = arr[j];
			++j;
		}
		++k;
	}

	while (i <= mid)
	{
		d[k] = arr[i];
		++i;
		++k;
	}

	while (j <= end)
	{
		d[k] = arr[j];
		++j;
		++k;
	}

	for (int i = 0; i < k; ++i)
	{
		arr[begin + i] = d[i];
	}

	delete[] d;
}
template <class T>
void MergSort(T* arr, const int size, int left, int right)
{
	if (left < right)
	{
		if (right - left == 1)
		{
			bool flag = false;
			Comparison(arr, size, right, left, flag);

			if (flag)
			{
				swap(arr[left], arr[right]);
			}
		}
		else
		{
			MergSort(arr, size, left, left + (right - left) / 2);
			MergSort(arr, size, left + (right - left) / 2 + 1, right);
			Merg(arr, size, left, right);
		}
	}
}