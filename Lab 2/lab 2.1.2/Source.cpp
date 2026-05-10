/*
3. Определить, равна ли сумма первых k цифр дробной части заданного поло-
жительного вещественного числа сумме n следующих цифр.
*/
#include <iostream>
using namespace std;

int main()
{
	double value;
	int k, n;

	cout << "Enter the value: " << endl;
	cin >> value;

	cout << "\nEnter the k: " << endl;
	cin >> k;

	cout << "\nEnter the n: " << endl;
	cin >> n;

	double drobvalue = value - int(value);
	double drobvalue1 = 0;

	int sumk = 0;

	for (int i = 0; i < k; i++)
	{
		drobvalue1 = int(drobvalue * 10);
		drobvalue = drobvalue*10  - int(drobvalue * 10);

		sumk += drobvalue1; 
	}

	cout << "\nYour sumk: " << sumk << endl;

	double drobvalue2 = 0;
	int sumn = 0;

	for (int j = 0; j < n; j++)
	{
		drobvalue2 = int(drobvalue * 10);
		drobvalue = drobvalue * 10 - int(drobvalue * 10);

		sumn += drobvalue2;
	}

	cout << "Your sumn: " << sumn << endl << endl;

	sumk == sumn ? cout << "Equality holds" : cout << "Equality Not holds" << endl;

	return 0;
}