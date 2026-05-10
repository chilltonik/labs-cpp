#include "Header.h"

pos::pos()
{
	x = 0;
	y = 0;
	mdiagonal = 0;
	pdiagonal = 17;
}
pos::pos(int x, int y)
{
	this->x = x;
	this->y = y;
	mdiagonal = x + y;
	pdiagonal = x - y;
}
void pos::print()
{
	cout << (char)(x + 96) << y;
}

parr::parr()
{
	n = 0;
	for (auto& i : a)
	{
		i = pos();
	}
}
pos& parr::operator[] (const int i)
{
	return a[i];
}
bool parr::free_vertical(int& y)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i].x == y)
		{
			return 0;
		}
	}
	return 1;
}
bool parr::free_horizontal(int& x)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i].y == x)
		{
			return 0;
		}
	}
	return 1;
}
bool parr::free_diagonals(pos& p)
{
	for (int i = 0; i < n; ++i)
	{
		if ((a[i].mdiagonal == p.mdiagonal) || (a[i].pdiagonal == p.pdiagonal))
		{
			return 0;
		}
	}
	return 1;
}
void parr::print()
{
	for (auto& i : a)
	{
		i.print();
		cout << ' ';
	}
	cout << endl;
}

bool foo(int& m, int& n, parr& arr)
{
	for (int j = 1; j < 9; ++j)
	{
		if (arr.free_horizontal(j))
		{
			pos p(arr.n + 1, j);
			if (arr.free_diagonals(p))
			{
				arr[arr.n] = p;
				arr.n++;
				if (arr.n == 8)
				{
					n++;
					cout << setw(2) << n << ' ';
					arr.print();
				}
				else if (foo(m, n, arr))
				{
					return 1;
				}
				arr.n--;
				arr[arr.n] = pos();
			}
		}
	}

	return n == m;
}

void find_pos(int m)
{
	if (m <= 0)
	{
		return;
	}
	parr arr = parr();
	int n = 0;
	foo(m, n, arr);
}