/*
* Вычислить корень уравнения 0) ( =x f на отрезке [a; b] с точностью  =10–6,
используя заданный метод (М = 1 – метод половинного деления, М = 2 – метод
касательных, М = 3 – метод хорд) для заданных функций. Вычисление корня
уравнения оформить в виде функции с функциональным параметром, параметры
a, b, , s – в виде аргументов по умолчанию.
Результат представить в виде таблицы (s – значение параметра, х – вычис-
ленный корень уравнения, f(x) – значение функции в найденной точке х, k_iter – ко-
личество итераций цикла для получения корня с заданной точностью):
*/
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>

using namespace std;

enum WidthValues 
{
	widthS = 7,
	widthX = 12,
	widthY = 16,
	widthK = 5,

	widthLine = 37,
};

void draw_line()
{
	for (int i = 0; i < widthLine; ++i)
	{
		cout << "-";
	}
	cout << endl;
}

double znach_func_A(double x)
{
	return (x - 1) * (x - 1) - 3;
}

double znach_func_B(double x, double s)
{
	return pow(M_E, (x - s)) - sqrt(x + 1);
}

void root_A(double (*F_A)(double), double a = 1, double b = 4, double eps = 1e-6)
{
	double x = 0;
	double fa = F_A(a);
	double f = F_A(x);

	do
	{
		x = (a + b) / 2;
		f = F_A(x);
		fa = F_A(a);

		if (f * fa <= 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}

	} while (abs(a - b) > eps || abs(f) > eps);


	cout.width(15); cout << left << x;
	cout.width(15); cout << left << F_A(x) << endl;
}

void root_B(double (*F_B)(double, double), double x, double s, double a = 0, double b = 2, double eps = 1e-6)
{
	int k = 0;
	do
	{
		k++;
		x = (a + b) / 2;
		if (F_B(x, s) * F_B(a, s) <= 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}

	} while (abs(a - b) > eps || F_B(x, s) > eps);

	cout.width(widthS); cout << left << s;
	cout.width(widthX); cout << left << x;
	cout.width(widthY); cout << left << F_B(x, s);
	cout.width(widthK); cout << left << k << endl;
}

int main() 
{
	double a = 1;
	double b = 4;
	double eps = 1e-6;

	cout << "a)" << endl;
	draw_line();
	cout.width(15); cout << left << "x";
	cout.width(15); cout << left << "y" << endl;
	draw_line();

	root_A(znach_func_A);

	draw_line();
	cout << endl;
	cout << "b)" << endl;
	draw_line();
	cout.width(widthS); cout << left << "s";
	cout.width(widthX); cout << left << "x";
	cout.width(widthY); cout << left << "y";
	cout.width(widthK); cout << left << "k" << endl;
	draw_line();

	const double s0 = 0.3;
	const double sn = 0.7;
	const double ds = 0.1;

	double s = s0;

	do
	{
		double x = (a + b) / 2;
		root_B(znach_func_B, x, s);
		s += ds;

	} while (s < sn + ds / 2);

	draw_line();

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}