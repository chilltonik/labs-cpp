#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

struct data_of_birth
{
	int day;
	int month;
	int year;
};
struct Data
{
	string surname = "";
	string name = "";
	string fathername = "";
	data_of_birth birthday;
	int course;
	float progress;
};

template<class Type>
Type Input_value(Type max)
{
	Type test = 0;
	bool flag = true;
	bool invite = false;
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter value: ";
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
string Input_name();
char Input_simbol();

Data create_persone();
void show_persone(Data persone);

void create_list(list<Data>& lst, int members_count);
void show_list(list<Data> lst);

void create_result_list(list<Data>& lst, list<Data>& result, char simbol);
