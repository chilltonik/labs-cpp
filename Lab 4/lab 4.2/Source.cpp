#include<iostream>
#include<string.h>

using namespace std;

int Strlen(char* str)
{
	int k = 0;
	while (str[k] != '\0')
	{
		k++;
	}
	return k;
}

int main()
{
	const int SIZE = 256;
	char str[SIZE];

	const int SizeOfMySimbols = 6;
	char MySimbols[SizeOfMySimbols] = "01.-+";

	cout << "Bin: ";
	cin.getline(str, SIZE);

	int len = Strlen(str);

	//Нулевой элемент Знак Минус 
	bool flagZnakMinus = false;

	if (str[0] == '-')
	{
		flagZnakMinus = true;
	}

	//Нулевой элемент Знак Плюс 
	bool flagZnakPlus = false;

	if (str[0] == '+')
	{
		flagZnakPlus = true;
	}

	//Нулевой элемент Ноль или единица
	bool flagNullOrOne = false;
	if (str[0] == '0' || str[0] == '1')
	{
		flagNullOrOne = true;
	}

	//Корректность ввода и точка
	bool flagPoint = false;
	int countPoint = 0;

	for (int i = 0; i < len; ++i)
	{
		if (str[i] != '0' && str[i] != '1' && !(flagZnakMinus || flagZnakPlus || flagNullOrOne))
		{
			cout << "You have a mistake!" << endl;
			exit(0);
		}

		countPoint++;
		if (str[i] == '.')
		{
			flagPoint = true;
			countPoint = i;
			break;
		}
	}

	double Dec = 0;

	//Целая часть, нули и единицы до точки +
	double wholePart = 0;
	double Degree2 = 1;

	if (flagZnakMinus == true || flagZnakPlus == true)
	{
		for (int i = countPoint - 1; i >= 1; --i)
		{
			int simbol = static_cast<int>(str[i]) - static_cast <int>('0');
			wholePart += (simbol * Degree2);

			Degree2 *= 2;
		}

		//cout << "Whole Part: " << wholePart << endl;
	}
	else
	{
		for (int i = countPoint - 1; i >= 0; --i)
		{
			int simbol = static_cast<int>(str[i]) - static_cast <int>('0');
			wholePart += (simbol * Degree2);

			Degree2 *= 2;
		}

		//cout << "Whole Part: " << wholePart << endl;
	}

	//Дробная часть, нули и единицы после точки+
	double fractionalPart = 0;
	double Degree_2 = 0.5;

	if (flagPoint)
	{
		for (int i = countPoint + 1; i < len; ++i)
		{
			int simbol = static_cast<int>(str[i]) - static_cast <int>('0');
			fractionalPart += (simbol * Degree_2);

			Degree_2 /= 2;
		}

		//cout << "fractionalPart: " << fractionalPart << endl;
	}

	//Dec+
	Dec = static_cast<double>(wholePart) + fractionalPart;

	//Znak+
	if (flagZnakMinus == true)
	{
		cout << "Dec: " << -Dec << endl;
	}
	else
	{
		cout << "Dec: " << Dec << endl;
	}

	return 0;
}