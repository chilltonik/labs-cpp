/*
* 5.9. ПЕРЕБОР С ВОЗВРАТОМ
Написать функции для выполнения следующих заданий.

3. Дано натуральное число m. Получить m расстановок восьми ферзей на шахматной доске,
при которых ни один из ферзей не угрожает другому.
Если m больше общего числа таких расстановок, то получить все расстановки.
*/
#include <iostream>

using namespace std;

template<class T>
void enter(istream& in, T& data)
{
	while (true)
	{

		in >> data;

		if (in.fail())
		{
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else
		{
			break;
		}
	}
}

int is_safe(int rows[8], int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	for (int i = 0; i < y; ++i)
	{
		if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y + i)
		{
			return 0;
		}
	}
	return 1;
}
void out(int rows[8], int& count, int m)
{
	count++;

	if (count > m)
	{
		return;
	}
	cout << "\nSolution #" << count << ":\n--------------------\n";
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (x == rows[y])
			{
				cout << "| Q ";
			}
			else
			{
				cout << "| ";
			}
		}
		cout << "|\n--------------------\n";
	}
}
void eight_queen(int rows[8], int y, int& count, int m)
{
	for (int x = 0; x < 8; x++)
	{
		if (is_safe(rows, x, y))
		{
			rows[y] = x;
			if (y == 7)
			{
				out(rows, count, m);
			}
			else
			{
				eight_queen(rows, y + 1, count, m);
			}
		}
	}
}

int main()
{
	int m = 0;
	cout << "enter m: ";
	enter(cin, m);

	int rows[8];
	int count = 0;
	eight_queen(rows, 0, count, m);
}