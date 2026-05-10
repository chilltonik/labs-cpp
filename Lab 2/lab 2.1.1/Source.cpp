/*
3. Дано натуральное n. Определить, является ли это число палиндромом.
*/
#include <iostream>
using namespace std;

int main()
{	
	int value1, value2 = 0; 

	cout << "Enter value1: ";
	cin >> value1;

	int copyValue1 = value1;

	while (value1)
	{
		int ost = value1 % 10;
		value1 /= 10;
		value2 = value2 * 10 + ost;
	}
	cout << "value2 = " << value2 << '\n';

 	(copyValue1 == value2) ? (cout << "Palindrom") : (cout << "Not Palindrom");

	return 0;
}