#include "Functions.h"

int Integer()
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your value: " << endl;
			cin >> test;
		}

		if (test >= 1 && test <= max_for_array)
		{
			flag = false;
		}
		else
		{
			flag = true;
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return test;
}
void Show_array(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << endl;
	}
}
void Fill_array(ifstream& fin, int* arr, int size, bool* bool_arr, int bool_size)
{
	int value = 0;

	for (int i = 0; i < bool_size; ++i)
	{
		bool_arr[i] = false;
	}

	while (fin >> value)
	{
		bool_arr[value] = true;
	}

	for (int i = 0, j = 0; i < bool_size, j < size; ++i)
	{
		if (bool_arr[i] == false)
		{
			arr[j] = i;
			j++;
		}
	}

}
void Recording_in_file(ofstream& fout, int size)
{
	for (int i = 0; i < size; ++i)
	{
		fout << rand() % (max_value_for_genertion - min_value_for_genertion) + min_value_for_genertion << endl;
	}
}