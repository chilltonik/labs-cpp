#include <iostream>
#define TAB 8
#define Rand 1.35
#define delta 10

using namespace std;

void FillArray(int* arr, const int size)
{
	cout << "\nChoose the filling method (1 or 2 or 3): " << endl;
	cout << "1. Random." << endl
		<< "2. Increase." << endl
		<< "3. Waning." << endl;

	int solution = 0;

	bool flag = true;

	while (flag)
	{
		cout << "Your choise: ";
		cin >> solution;

		if (solution == 1 || solution == 2 || solution == 3)
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
			int max = 0;
			cout << "Enter max value for generation: ";
			cin >> max;

			if (max == 0)
			{
				max = 1;
			}

			arr[0] = rand() % max;
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] + rand() % max;
			}

		}
		break;
		case 3:
		{
			int max = 0;
			cout << "Enter max value for generation: ";
			cin >> max;

			if (max == 0)
			{
				max = 1;
			}

			arr[0] = rand() % max;
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] - rand() % max;
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
void FillArray(char* arr, const int size)
{
	cout << "\nChoose the filling method (1 or 2 or 3): " << endl;
	cout << "1. Random." << endl
		<< "2. Increase." << endl
		<< "3. Waning." << endl;

	int solution = 0;

	bool flag = true;

	while (flag)
	{
		cout << "Your choise: ";
		cin >> solution;

		if (solution == 1 || solution == 2 || solution == 3)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1://Rand
		{
			int max = 241;
			int min = 32;

			for (int i = 0; i < size; ++i)
			{
				arr[i] = char(rand() % (max - min) + min);
			}
		}
		break;
		case 2://Increase
		{
			int max = 241;
			int min = 32;

			arr[0] = char(rand() % (max - min) + min);
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] + rand() % delta;
			}
		}
		break;
		case 3: //Waning
		{
			int max = 241;
			int min = 32;

			arr[0] = char(rand() % (max - min) + min);
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] - rand() % delta;
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
void FillArray(double* arr, const int size)
{
	cout << "\nChoose the filling method (1 or 2 or 3): " << endl;
	cout << "1. Random." << endl
		<< "2. Increase." << endl
		<< "3. Waning." << endl;

	int solution = 0;

	bool flag = true;

	while (flag)
	{
		cout << "Your choise: ";
		cin >> solution;

		if (solution == 1 || solution == 2 || solution == 3)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1: // Rand
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
				arr[i] = (rand() % (max - min) * Rand + min);
			}
		}
		break;
		case 2: //Increase
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

			arr[0] = (rand() % (max - min) * Rand + min);
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] + (rand() % (max - min) * Rand + min);
			}
		}
		break;
		case 3: //Waning
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

			arr[0] = (rand() % (max - min) * Rand + min);
			for (int i = 1; i < size; ++i)
			{
				arr[i] = arr[i - 1] - (rand() % (max - min) * Rand + min);
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

//template<class TT>
//void ShowArray(TT* arr, const int size)
//{
//	cout << "\nYour array: " << endl;
//	for (int i = 0; i < size; ++i)
//	{
//		cout << arr[i] << "\t";
//	}
//
//	cout << endl;
//
//	for (int i = 0; i < size * TAB; ++i)
//	{
//		cout << "_";
//	}
//	cout << endl;
//}

//template <class T1>
//void ChoiceIncrease(T1* arr, const int size, int& comparison, int& moving) //Возрастание
//{
//	cout << "\nSorting by choiceIncrease:" << endl;
//
//	comparison = 0;
//	moving = 0;
//
//	for (int i = 0; i < size - 1; ++i)
//	{
//		int iMin = i;                  //Поиск минимального элемента
//		for (int j = i + 1; j < size; ++j)
//		{
//			comparison++;
//			if (arr[j] < arr[iMin])
//			{
//				moving++;
//				iMin = j;
//			}
//		}
//
//		T1 temp = arr[iMin];              //Обмен элементов местами
//		arr[iMin] = arr[i];
//		arr[i] = temp;
//	}
//	//cout << "Comparisons: " << comparison << endl;
//	//cout << "Movings: " << moving << endl;
//}
//template <class T2>
//void ChoiceWaning(T2* arr, const int size, int& comparison, int& moving) // Убывание
//{
//	cout << "\nSorting by choiceWaning:" << endl;
//
//	comparison = 0;
//	moving = 0;
//
//	for (int i = 0; i < size - 1; ++i)
//	{
//		int iMin = i;                  //Поиск минимального элемента
//		for (int j = i + 1; j < size; ++j)
//		{
//			comparison++;
//			if (arr[j] > arr[iMin])
//			{
//				moving++;
//				iMin = j;
//			}
//		}
//
//		T2 temp = arr[iMin];              //Обмен элементов местами
//		arr[iMin] = arr[i];
//		arr[i] = temp;
//	}
//	/*cout << "Comparisons: " << comparison << endl;
//	cout << "Movings: " << moving << endl;*/
//}
//
//template <class T3>
//void BubbleIncrease(T3* arr, const int size, int& comparison, int& moving)
//{
//	cout << "\nSorting by BubbleIncrease:" << endl;
//
//	comparison = 0;
//	moving = 0;
//
//	for (int k = size - 1; k >= 1; --k)
//	{
//		bool flag = false;
//		for (int i = 0; i < k; ++i)
//		{
//			comparison++;
//			if (arr[i] > arr[i + 1])
//			{
//				moving++;
//				T3 temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//
//				flag = true;
//			}
//		}
//
//		if (!flag)
//		{
//			break;
//		}
//	}
//	/*cout << "Comparisons: " << comparison << endl;
//	cout << "Movings: " << moving << endl;*/
//}
//template <class T4>
//void BubbleWaning(T4* arr, const int size, int& comparison, int& moving)
//{
//	cout << "\nSorting by BubbleWaning:" << endl;
//
//	comparison = 0;
//	moving = 0;
//
//	for (int k = size - 1; k >= 1; --k)
//	{
//		bool flag = false;
//		for (int i = 0; i < k; ++i)
//		{
//			comparison++;
//			if (arr[i] < arr[i + 1])
//			{
//				moving++;
//				T4 temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//
//				flag = true;
//			}
//		}
//
//		if (!flag)
//		{
//			break;
//		}
//	}
//	/*cout << "Comparisons: " << comparison << endl;
//	cout << "Movings: " << moving << endl;*/
//}
