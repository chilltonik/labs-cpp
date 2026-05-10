#include"Functions.h"

struct student
{
	string surname = "";
	string name = "";
	string fathername = "";
	int age = 0;
	string gender = "";
	int course = 0;
	double progress = 0;
};
string Simbols()
{
	string test = "";
	bool flag = true;
	bool invite = false;
	getline(cin, test);

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your string: " << endl;
			getline(cin, test);
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
char Simbol()
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
void Fill(student& person)
{
	cout << "Enter surname: " << endl;//Surname+
	cin.get();
	person.surname = Simbols();

	cout << "Enter name: " << endl;//Name+
	person.name = Simbols();

	cout << "Enter fathername: " << endl;//Fathername+
	person.fathername = Simbols();

	cout << "Enter age: " << endl;//Age+
	person.age = Integer(30);

	cout << "Enter gender: " << endl;//Gender+
	cin.get();
	person.gender = Simbols();

	cout << "Enter course: " << endl;//Course+
	person.course = Integer(5);

	cout << "Enter progress: " << endl;//Progress+
	person.progress = Integer(10.0);
}
void Recording(bool flag_bin, student& person, ofstream& fout)
{
	if (flag_bin == false)
	{
		fout << person.surname << " ";
		fout << person.name << " ";
		fout << person.fathername << " ";
		fout << person.age << " ";
		fout << person.gender << " ";
		fout << person.course << " ";
		fout << person.progress << endl;
	}
	else
	{
		cout << "Bin" << endl;
		fout.write(reinterpret_cast<char*>(&person.surname), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.name), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.fathername), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.age), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.gender), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.course), sizeof(student));
		fout.write(reinterpret_cast<char*>(&person.progress), sizeof(student));
	}

}
void Show(student& person)
{
	cout << "Surname: " << person.surname;
	cout << ". Name: " << person.name;
	cout << ". Fathername: " << person.fathername;
	cout << ". Age: " << person.age;
	cout << ". Gender: " << person.gender;
	cout << ". Course: " << person.course;
	cout << ". Progress: " << person.progress << "." << endl;
}
void Recording_in_result(bool flag_bin, ifstream& fin, ofstream& fout, student& person, char simbol)
{
	if (flag_bin == false)
	{
		fin >> person.surname;
		fin >> person.name;
		fin >> person.fathername;
		fin >> person.age;
		fin >> person.gender;
		fin >> person.course;
		fin >> person.progress;
	}
	else
	{
		cout << "Bin" << endl;
		fin.read(reinterpret_cast<char*>(&person.surname), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.name), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.fathername), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.age), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.gender), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.course), sizeof(student));
		fin.read(reinterpret_cast<char*>(&person.progress), sizeof(student));
	}

	bool flag = false;
	if (person.surname[0] == simbol)
	{
		flag = true;
	}

	if (flag_bin == false && flag)
	{
		fout << person.surname << " ";
		fout << person.name << " ";
		fout << person.fathername << " ";
		fout << person.age << " ";
		fout << person.gender << " ";
		fout << person.course << " ";
		fout << person.progress << endl;
	}
	else
	{
		if (flag)
		{
			cout << "Bin" << endl;
			fout.write(reinterpret_cast<char*>(&person.surname), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.name), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.fathername), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.age), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.gender), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.course), sizeof(student));
			fout.write(reinterpret_cast<char*>(&person.progress), sizeof(student));
		}
	}

}