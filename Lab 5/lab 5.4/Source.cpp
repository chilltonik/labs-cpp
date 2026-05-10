/*
* 3. Напишите функцию, возвращающую ссылку на максимальное число, 
встречающееся в заданном массиве произвольного размера (аргумент функции) ровно 2 раза.
Если такого числа нет, то возвратить ссылку на любое из максимальных чисел массива. 
Замените этот элемент значением k.
*/

#include <iostream>
#include <ctime>
using namespace std;

void FillArray(int* arr, const int size)
{
	cout << "Choose the filling method (1 or 2): " << endl;
	cout << "1. Random." << endl
		<< "2. Yourself." << endl;

	int solution = 0;
	
	bool flag = true;

	while (flag)
	{
		cout << "Your choise: ";
		cin >> solution;

		if (solution == 1 || solution == 2)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			int max = 0;
			int min = 0;

			cout << "Enter max value for generation: ";
			cin >> max;

			cout << "Enter min value for generation: ";
			cin >> min;

			if (min == 0)
			{
				min = 1;
			}

			if (max == 0)
			{
				max = 1;
			}

			for (int i = 0; i < size; ++i)
			{
				arr[i] = rand() % max - rand() % min;
			}
		}
		break;
		case 2:
		{
			for (int i = 0; i < size; ++i)
			{
				cin >> arr[i];
			}
		}
		break;
		default:
		{
			cout << "Your choice is not corrected. Please, try one more time" << endl;
		}
		break;
		}
	}
}
void ShowArray(int* arr, const int size)
{
	cout << "Your array: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "\t";
	}
}
int& Count_Of_Values(int* arr, const int size, bool& flag)
{
	int box = -1;
	int boxi = -1;

	int boxMax = -1;
	int boxMaxi = -1;

	int BOX = 0;
	int BOXi = -1;
	int BOXMAX = 0;
	int BOXMAXi = -1;

	for (int i = 0; i < size; ++i)
	{
		int count = 0;
		for (int j = 0; j < size; ++j)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}

		if (count == 2)
		{
			box = arr[i];
			boxi = i;

			if (box > boxMax)
			{
				boxMax = box;
				boxMaxi = boxi;
			} 
		}

		BOX = arr[i];
		BOXi = i;

		if (BOX > BOXMAX)
		{
			BOXMAX = BOX;
			BOXMAXi = BOXi;
		}
	}

	if (boxMaxi != -1)
	{
		cout << "\ni: " << boxMaxi << " boxMax: " << boxMax;
		cout << "\nRef: " << &arr[boxMaxi] << endl;
		return arr[boxMaxi];
	}
	else
	{
		flag = true;
		cout << "\nBOXMAXi: " << BOXMAXi << " BOXMAX: " << BOXMAX;
		cout << "\nRefMax: " << &arr[BOXMAXi] << endl;
		return arr[BOXMAXi];
	}
}

int main()
{
	srand(time(NULL));
	int size = 0;

	cout << "Enter size of array: ";
	cin >> size;

	int* arr = new int[size];
	bool flag = false;

	FillArray(arr, size);
	ShowArray(arr, size);

	int& ref = Count_Of_Values(arr, size, flag);
	cout << "\nResultRef: " << &ref << endl;

	if (flag)
	{
		int k = 0;
		cout << "Enter k: ";
		cin >> k;

		ref = k;

		Count_Of_Values(arr, size, flag) = 0;

		ShowArray(arr, size);
	}

	delete[] arr;
	return 0;
}