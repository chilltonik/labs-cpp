#include"Functions.h"

string Input_name()
{
	string test = "";
	bool flag = true;
	bool invite = false;
	//getline(cin, test);
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your string: " << endl;
			//getline(cin, test);
			cin >> test;
		}

		int length = test.length();

		for (int i = 0; i < length; ++i)
		{
			if (test[i] >= 'A' && test[i] <= 'Z' || test[i] >= 'a' && test[i] <= 'z')
			{
				flag = false;
			}
			else
			{
				flag = true;
				invite = true;
				cout << "Your enter is not correct. Please try again..." << endl;
				break;
			}
		}
	}

	return test;
}
char Input_simbol()
{
	char simbol;
	bool flag = true;
	bool invite = false;
	cout << "Enter your simbol: ";
	cin >> simbol;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your simbol: ";
			cin >> simbol;
		}

		if (simbol >= 'A' && simbol <= 'Z' || simbol >= 'a' && simbol <= 'z')
		{
			flag = false;
		}
		else
		{
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return simbol;
}

Data create_persone()
{
	Data persone;

	cout << "\nEnter surname: ";
	persone.surname = Input_name();
	cout << "Enter name: ";
	persone.name = Input_name();
	cout << "Enter fathername: ";
	persone.fathername = Input_name();

	cout << "Enter birthday day: ";
	persone.birthday.day = Input_value(30);
	cout << "Enter birthday month: ";
	persone.birthday.month = Input_value(12);
	cout << "Enter birthday year: ";
	persone.birthday.year = Input_value(2021);

	cout << "Enter course: ";
	persone.course = Input_value(5);
	cout << "Enter progress: ";
	persone.progress = Input_value(10.0);

	return persone;
}
void show_persone(Data persone)
{
	cout << "|Surname: " << persone.surname;
	cout << " | Name: " << persone.name;
	cout << " | Fathername: " << persone.fathername;
	cout << " | Birthday: " << persone.birthday.day;
	cout << "." << persone.birthday.month;
	cout << "." << persone.birthday.year;
	cout << " | Course: " << persone.course;
	cout << " | Progress: " << persone.progress << "|" << endl;
}

void create_list(list<Data>& lst, int members_count)
{
	for (int i = 0; i < members_count; ++i)
	{
		Data person = create_persone();
		lst.push_back(person);
	}
}
void show_list(list<Data> lst)
{
	cout << "Your list: " << endl;
	list<Data>::iterator p;
	p = lst.begin();
	while (p != lst.end())
	{
		show_persone(*p);	
		++p;
	}
}

void create_result_list(list<Data>& lst, list<Data>& result, char simbol)
{
	list<Data> ::iterator current;
	current = lst.begin();
	while (current != lst.end())
	{
		if (current->surname[0] == simbol)
		{
			result.push_back(*current);
			//lst.erase(current);
			current = lst.erase(current);
		}
		++current;
	}
}