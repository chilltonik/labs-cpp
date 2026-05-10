/*
Определить объединение с битовыми полями для представления заданной информации. Описать функцию вывода полей на экран. Сгенерировать случайный
массив таких структур. Отсортировать элементы массива стандартной функцией std::sort. Найти повторяющиеся элементы и вывести их на экран:

3.Объединяющий тип unsigned short для хранения положения стрелок часов, битовые поля: час (0..11), минута (0..59), секунда (0..59).
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using namespace std;

union Clock
{
	unsigned short Time;
	struct
	{
		unsigned short sec : 6;
		unsigned short min : 6;
		unsigned short hrs : 4;
	};
};

void showdata(Clock T)
{
	cout << T.hrs << "." << T.min << "." << T.sec << endl;
}

void getdata(Clock** arr, int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		(*arr)[i].Time = rand();
	}
}

bool comparing(const Clock& time1, const Clock& time2)
{
	return (time1.Time < time2.Time);
}

int main()
{
	setlocale(LC_ALL, "rus");

	int num = 0;
	cout << "Введите размер массива: ";
	cin >> num;

	Clock* arr = new Clock[num];

	getdata(&arr, num);

	cout << "Исходный массив:\n";
	for (int i = 0; i < num; i++)
	{
		showdata(arr[i]);
	}

	sort(&arr[0], &arr[num], comparing);
	cout << endl;

	cout << "Отсортированный массив:\n";
	for (int i = 0; i < num; i++)
	{
		showdata(arr[i]);
	}

	return 0;
}
