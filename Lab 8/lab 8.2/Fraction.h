#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int search_NOK(int a, int b);
int search_NOD(int& a, int& b);

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction();
	fraction(int numerator, int denominator);
	fraction(fraction& frac);
	~fraction();

	int get_numerator() { return numerator; };
	int get_denominator() { return denominator; };

	void set_numerator(int numerator) { this->numerator = numerator; };
	void set_denominator(int denominator) { this->denominator = denominator; };

	void print();
	void standart();

	fraction operator +(fraction& slag);
	fraction operator -(fraction& slag);
	fraction operator *(fraction& slag);
	fraction operator /(fraction& slag);

	bool operator ==(fraction& second);
	bool operator > (fraction& second);
	bool operator < (fraction& second);
};

ostream& operator <<(ostream& out, fraction& frac);
istream& operator >>(istream& in, fraction& frac);

void comparison(fraction& first, fraction& second);