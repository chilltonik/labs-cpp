#include "functions.h"

void input(char* list, int* p, int n)
{
	int i = 0;

	enter(list[i]);
	p[i] = i + 1;
	i = p[i];

	while (i < n)
	{
		enter(list[i]);
		p[i] = i + 1;
		i = p[i];
	}

	p[n - 1] = 0;
}
void output(char* list, int* p)
{
	int i = 0;
	int current = p[i];

	while (current)
	{
		cout << list[i] << " ";
		current = p[i];
		i = p[i];
	}
}
bool repeat(char* list1, char* list2, int* p1, int* p2, char symbol)
{
	bool flag = true;

	int k = 0;

	int i = 0;
	int current = p1[i];

	while (current)
	{
		if (symbol == list1[i])
		{
			k++;
		}

		current = p1[i];
		i = p1[i];
	}

	if (k != 2)
	{
		flag = false;
	}
	else
	{
		i = 0;
		current = p2[i];

		while (current)
		{
			if (symbol == list2[i]) 
			{
				flag = false;
				break;
			}

			current = p2[i];
			i = p2[i];
		}
	}

	return flag;
}
void createList(char* list1, char* list2, int* p1, int* p2) 
{
	int i = 0;
	int j = 0;

	int current = p1[i];

	while (current)
	{
		if (repeat(list1, list2, p1, p2, list1[i]))
		{
			list2[j] = list1[i];

			p2[j] = j + 1;
			j = p2[j];
			p2[j] = 0;
		}

		current = p1[i];
		i = p1[i];
	}

	p2[j - 1] = 0;
}