#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct pos
{
	unsigned x : 4;
	unsigned y : 4;
	unsigned mdiagonal : 8;
	signed pdiagonal : 8;
	pos();
	pos(int x, int y);
	void print();
};
struct parr
{
	pos a[8];
	short n;
	pos& operator[] (const int i);
	parr();
	bool free_vertical(int& y);
	bool free_horizontal(int& x);
	bool free_diagonals(pos& p);
	void print();
};

void find_pos(int n);
bool foo(int& m, int& n, parr& arr);