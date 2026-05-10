#include"Tree.h"

int input_value(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter count: ";
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter value: ";
			cin >> test;
		}

		if (test >= 1 && test <= max)
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
void fill_arr(int*& arr, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		int value = 0;
		bool isHere = true;

		while (isHere == true)
		{
			value = rand() % (100 - 0) + 0;
			isHere = false;

			for (int j = 0; j < i; ++j)
			{
				if (value == arr[j])
				{
					isHere = true;
					break;
				}
			}
		}

		arr[i] = value;
	}
}
void print_arr(int* arr, int size)
{
	cout << "Your arr:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}