#pragma once
#include <math.h>
// суммируем высоты
void Sum(double a, double b, double h, double(*F)(double, double, double), double s, double t, double& S)
{
	double x = a,
		sum = 0;

	while (x < b)
	{
		sum += (*F)(x, s, t);
		x += h;
	}
	S = sum * h;
}
// вычисление интеграла
void Vych_Int(double a, double b, double eps, double s, double t, double(*F)(double, double, double), double& I, int& k)
{
	int n = 10;
	double h = (b - a) / n,
		S1 = 0, S2 = 0;

	Sum(a, b, h, F, s, t, S1);
	k = 0;

	do
	{
		S2 = S1;
		n *= 2;

		h = (b - a) / n;

		Sum(a, b, h, F, s, t, S1);
		k++;
	} while (fabs(S1 - S2) > eps);

	I = S1;
}
