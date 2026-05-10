#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct student;
string Simbols();
char Simbol();
template <class Type>
Type Integer(Type max)
{
	Type test = 0;
	bool flag = true;
	bool invite = false;
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your value: " << endl;
			cin >> test;
		}

		if (test >= 1 && test <= max)
		{
			flag = false;
		}
		else
		{
			flag = true;
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return test;
}
void Fill(student& person);
void Recording(bool flag_bin, student& person, ofstream& fout);
void Show(student& person);
void Recording_in_result(bool flag_bin, ifstream& fin, ofstream& fout, student& person, char simbol);