#include"Fraction.h"

int search_NOK(int a, int b)
{
	int max = b;
	for (int i = max; i > 0; ++i)
	{
		if ((i % a == 0) && (i % b == 0))
		{
			return i;
		}
	}
}
int search_NOD(int& a, int& b)
{
	if (a == 0)
	{
		return b;
	}

	if (b == 0)
	{
		return a;
	}

	if (a >= b)
	{
		int ost = a % b;
		return search_NOD(ost, b);
	}

	if (b >= a)
	{
		int ost = b % a;
		return search_NOD(a, ost);
	}
}

fraction::fraction()
{
	numerator = 0;
	denominator = 1;
}
fraction::fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}
fraction::fraction(fraction& frac)
{
	this->numerator = frac.numerator;
	this->denominator = frac.denominator;
}
fraction::~fraction()
{
	//cout << "Destructor" << endl;
}

void fraction::print()
{
	cout << "Your fraction:" << endl;
	cout << numerator << "/" << denominator << endl;
}
void fraction::standart()
{
	int a = get_numerator();
	int b = get_denominator();

	int NOD = search_NOD(a, b);

	int new_numerator = get_numerator() / NOD;
	int new_denominator = get_denominator() / NOD;

	set_numerator(new_numerator);
	set_denominator(new_denominator);
}

fraction fraction::operator+(fraction& slag)
{
	int NOK = search_NOK(get_denominator(), slag.get_denominator());

	int new_numerator = get_numerator() * (NOK / get_denominator()) + slag.get_numerator() * (NOK / slag.get_denominator());
	int new_denominator = NOK;

	fraction result(new_numerator, new_denominator);

	result.standart();
	return result;
}
fraction fraction::operator-(fraction& slag)
{
	int NOK = search_NOK(get_denominator(), slag.get_denominator());

	int new_numerator = get_numerator() * (NOK / get_denominator()) - slag.get_numerator() * (NOK / slag.get_denominator());
	int new_denominator = NOK;

	fraction result(new_numerator, new_denominator);

	result.standart();
	return result;
}
fraction fraction::operator*(fraction& slag)
{
	int new_numerator = get_numerator() * slag.get_numerator();
	int new_denominator = get_denominator() * slag.get_denominator();

	fraction result(new_numerator, new_denominator);

	result.standart();
	return result;
}
fraction fraction::operator/(fraction& slag)
{
	int new_numerator = get_numerator() * slag.get_denominator();
	int new_denominator = get_denominator() * slag.get_numerator();

	fraction result(new_numerator, new_denominator);

	result.standart();
	return result;
}

bool fraction::operator==(fraction& second)
{
	standart();
	second.standart();

	int NOK = search_NOK(get_denominator(), second.get_denominator());

	int first_numerator = NOK / get_denominator();
	int second_numerator = NOK / second.get_denominator();

	if (first_numerator == second_numerator)
	{
		cout << "The fractions are equal!" << endl;
		return true;
	}
	else
	{
		cout << "The fractions are not equal!" << endl;
		return false;
	}
}
bool fraction::operator>(fraction& second)
{
	standart();
	second.standart();

	int NOK = search_NOK(get_denominator(), second.get_denominator());

	int first_numerator = NOK / get_denominator();
	int second_numerator = NOK / second.get_denominator();

	if (first_numerator > second_numerator)
	{
		cout << "First fraction is more!" << endl;
		return true;
	}
	else
	{
		cout << "The first fraction is not more!" << endl;
		return false;
	}
}
bool fraction::operator<(fraction& second)
{
	standart();
	second.standart();

	int NOK = search_NOK(get_denominator(), second.get_denominator());

	int first_numerator = NOK / get_denominator();
	int second_numerator = NOK / second.get_denominator();

	if (first_numerator < second_numerator)
	{
		cout << "First fraction is less!" << endl;
		return true;
	}
	else
	{
		cout << "The first fraction is not less!" << endl;
		return false;
	}
}

ostream& operator <<(ostream& out, fraction& frac)
{
	frac.standart();
	cout << frac.get_numerator() << "/" << frac.get_denominator();
	return out;
}
istream& operator >>(istream& in, fraction& frac)
{
	int numerator = 0;
	int denominator = 1;

	cout << "Enter numerator: ";
	in >> numerator;
	frac.set_numerator(numerator);

	bool flag = true;
	while (flag)
	{
		cout << "Enter denominator: ";
		in >> denominator;

		if (denominator != 0)
		{
			flag = false;
		}
		else
		{
			cout << "Yoops, uncorrect enter. Please try again..." << endl;
		}
	}
	frac.set_denominator(denominator);

	return in;
}

void comparison(fraction& first, fraction& second)
{
	first.standart();
	second.standart();

	int NOK = search_NOK(first.get_denominator(), second.get_denominator());

	int first_numerator = NOK / first.get_denominator();
	int second_numerator = NOK / second.get_denominator();

	if (first_numerator > second_numerator)
	{
		cout << first << " > " << second << endl;
		cout << "First fraction is more!" << endl;
	}
	else
	{
		if (first_numerator == second_numerator)
		{
			cout << first << " = " << second << endl;
			cout << "The fractions are equal!" << endl;
		}
		else
		{
			cout << second << " > " << first << endl;
			cout << "Second fraction is more!" << endl;
		}
	}
}