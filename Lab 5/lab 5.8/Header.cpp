#include "Header.h"

void Null(char** arr_strings, const int count_of_strings, const int len)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			arr_strings[i][j] = '\0';
		}
	}
}
void Fill_arr_strings_yourself(char** arr_strings, const int count_of_strings, const int len)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			cin >> arr_strings[i][j];
			if (arr_strings[i][j] == '*')
			{
				break;
			}
		}
	}
}
void Fill_arr_strings_random(char** arr_strings, const int count_of_strings, const int len)
{
	for (int i = 0; i < count_of_strings; ++i)
	{
		int n = rand() % (length - 1 - minlength) + minlength;
		for (int j = 0; j < n; ++j)
		{
			arr_strings[i][j] = rand() % (ascii_finish - ascii_start) + ascii_start;
		}
		arr_strings[i][n] = '*';
	}
}
void Show_arr_strings(char** arr_strings, const int count_of_strings, const int len)
{
	cout << "\narr_cstrings:" << endl;
	for (int i = 0; i < count_of_strings; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			if (arr_strings[i][j] != '*')
			{
				cout << arr_strings[i][j];
			}
			else
			{
				break;
			}

		}
		cout << endl;
	}
	cout << endl;
}
void Menu(char** arr_strings, const int count_of_strings)
{
	cout << "\nchoice the filling method:" << endl <<
		"1. yourself.(in the finish of the everyone of your strings put '*' please.)" << endl <<
		"2. random." << endl;

	int solution = 0;
	bool flag = true;

	while (flag)
	{
		cout << "your choice: ";
		cin >> solution;

		if (solution == 1 || solution == 2)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			Fill_arr_strings_yourself(arr_strings, count_of_strings, length);
		}
		break;
		case 2:
		{
			Fill_arr_strings_random(arr_strings, count_of_strings, length);
		}
		break;
		default:
		{
			cout << "error. please try again..." << endl;
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

void Comparison(char** arr, const int size, int firstpoze, int secondpoze, bool& flag)
{
	if (firstpoze > size || secondpoze > size)
	{
		cout << "error!" << endl;
		exit(0);
	}

	if (*arr[firstpoze] < *arr[secondpoze])
	{
		flag = true;
	}
}