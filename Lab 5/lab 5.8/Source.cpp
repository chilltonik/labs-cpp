/*
* 5.8. СОРТИРОВКА СЛИЯНИЕМ
Дан массив чисел произвольной длины. Отсортировать массив, используя сортировку слияниями.
Создать шаблоны функций для сортировок, заполнения массивов, вывода результатов. Сравнение элементов массива оформить отдельной функцией.
Перегрузить функцию сравнения элементов для массива С-строк.
Выполнить сортировки массивов для данных разных типов: целых, вещественных, символьных, С- строк, используя написанные функции.
*/

#include <iostream>
#include <cmath>
#include <ctime>
#define RAND 1.156
#define length 30
#define minlength 5
#define ascii_start 65
#define ascii_finish 90

using namespace std;

void Fill_arr_strings_yourself(char** arr_strings, const int count_of_strings)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		cin.getline(arr_strings[i], length);
	}
}
void Fill_arr_strings_random(char** arr_strings, const int count_of_strings)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		int n = rand() % (length - 1 - minlength) + minlength;
		for (int j = 0; j < n; ++j)
		{
			arr_strings[i][j] = rand() % (ascii_finish - ascii_start) + ascii_start;
		}
		arr_strings[i][n] = '\0';
	}
}
void Show_arr_strings(char** arr_strings, const int count_of_strings)
{
	cout << "\narr_cstrings:" << endl;
	for (int i = 0; i < count_of_strings; ++i)
	{
		cout << arr_strings[i] << endl;
	}
}
void Menu(char** arr_strings, const int count_of_strings)
{
	cout << "\nChoice the filling method:" << endl <<
		"1. Yourself." << endl <<
		"2. Random." << endl;

	int solution = 0;
	bool flag = true;

	while (flag)
	{
		cout << "Your choice: ";
		cin >> solution;

		if (solution == 1 || solution == 2)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			Fill_arr_strings_yourself(arr_strings, count_of_strings);
		}
		break;
		case 2:
		{
			Fill_arr_strings_random(arr_strings, count_of_strings);
		}
		break;
		default:
		{
			cout << "Error. Please try again..." << endl;
		}
		break;
		}
	}
}
void Delete(char** arr_strings, const int count_of_strings)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		delete[] arr_strings[i];
	}
	delete[] arr_strings;
}

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
bool Comparison(T* arr, int FirstPoze, int SecondPoze)
{
	return arr[FirstPoze] < arr[SecondPoze];
}
bool Comparison(char** arr, int FirstPoze, int SecondPoze)
{
	return strcmp(arr[FirstPoze], arr[SecondPoze]) <= 0;
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
		bool flag = Comparison(arr, i, j);

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
			bool flag = Comparison(arr, right, left);

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

int main()
{
	srand(time(NULL));

	int size = 0;
	cout << "Enter size: ";
	cin >> size;

	int* ArrInt = new int[size];
	cout << "ArrInt:" << endl;

	FillArray(ArrInt, size);
	ShowArray(ArrInt, size);

	int begin = 0;
	int end = size - 1;

	MergSort(ArrInt, size, begin, end);
	ShowArray(ArrInt, size);

	double* ArrDoub = new double[size];
	cout << "\nArrDoub:" << endl;

	FillArray(ArrDoub, size);
	ShowArray(ArrDoub, size);

	MergSort(ArrDoub, size, begin, end);
	ShowArray(ArrDoub, size);

	char* ArrChar = new char[size];
	cout << "\nArrChar:" << endl;

	FillArray(ArrChar, size);
	ShowArray(ArrChar, size);

	MergSort(ArrChar, size, begin, end);
	ShowArray(ArrChar, size);

	int count_of_strings = 0;
	cout << "\nEnter count of strings: ";
	cin >> count_of_strings;

	char** arr_strings = new char* [count_of_strings];
	for (int i = 0; i < count_of_strings; ++i)
	{
		arr_strings[i] = new char[length];
	}

	Menu(arr_strings, count_of_strings);
	Show_arr_strings(arr_strings, count_of_strings);

	begin = 0;
	end = count_of_strings - 1;

	MergSort(arr_strings, count_of_strings, begin, end);
	Show_arr_strings(arr_strings, count_of_strings);

	Delete(arr_strings, count_of_strings);
	delete[] ArrChar;
	delete[] ArrDoub;
	delete[] ArrInt;

	return 0;
}