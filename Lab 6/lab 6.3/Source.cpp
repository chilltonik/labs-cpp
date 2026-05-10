/*
* Написать программу для работы с базой данных, содержащей записи со сведениями о студентах:
ФИО, возраст, пол, курс, успеваемость, в которой должны выполняться следующие действия:
• создание файла
• просмотр файла
Выполнить задания для текстового и бинарного файлов.

3. По исходному файлу определить всех студентов, ФИО которых начинается на заданную букву. Сформировать файл из этих студентов.
*/
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

int main()
{
	setlocale(LC_ALL, "ru");

	bool flag_bin = false;

	string file_text = "file_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "Ошибка открытия файла file_text для записи" << endl;
		return -1;
	}
	cout << "Файл file_text открыт для записи" << endl;

	student person;
	int members = 0;
	cout << "Enter count of members: ";
	members = Integer(30);

	for (int i = 0; i < members; ++i)
	{
		cout << i + 1 << ") " << "Enter student: " << endl;
		Fill(person);
		Recording(flag_bin, person, fout_text);
	}
	cout << "Файл file_text закрыт для записи" << endl;
	fout_text.close();

	ifstream fin_file_text;
	fin_file_text.open(file_text);
	if (!fin_file_text.is_open())
	{
		cout << "Не удалось открыть файл file_text для чтения" << endl;
		return -1;
	}
	cout << "Файл file_text открыт для чтения" << endl;

	string file_text_result = "file_text_result.txt";
	ofstream fout_text_result;
	fout_text_result.open(file_text_result);

	if (!fout_text_result.is_open())
	{
		cout << "Не удалось открыть файл file_text_result для записи" << endl;
		return -1;
	}
	cout << "Файл file_text_result открыт для записи" << endl;

	char simbol;
	simbol = Simbol();
	cout << "simbol: " << simbol << endl;

	while (!fin_file_text.eof())
	{
		Recording_in_result(flag_bin, fin_file_text, fout_text_result, person, simbol);
	}
	cout << "Файл file_text_result закрыт для записи" << endl;
	fout_text_result.close();

	cout << "Файл file_text закрыт для чтения" << endl;
	fin_file_text.close();
	//______________________________________________________________________________________________Bin
	flag_bin = true;
	cout << "\n Bin_file" << endl << endl;
	string file_bin = "file_bin.bin";
	ofstream fout_bin(file_bin, ios::binary);
	if (!fout_bin.is_open())
	{
		cout << "Ошибка открытия файла file_bin для записи" << endl;
		return -1;
	}
	cout << "Файл file_bin открыт для записи" << endl;

	student person_bin;
	members = 0;
	cout << "Enter count of members: ";
	members = Integer(30);

	for (int i = 0; i < members; ++i)
	{
		cout << i + 1 << ") " << "Enter student: " << endl;
		Fill(person_bin);
		Recording(flag_bin, person_bin, fout_bin);
	}
	cout << "Файл file_bin закрыт для записи" << endl;
	fout_bin.close();

	ifstream fin_bin(file_bin);
	if (!fin_bin.is_open())
	{
		cout << "Ошибка открытия файла file_bin для чтения" << endl;
		return -1;
	}
	cout << "Файл file_bin открыт для чтения" << endl;

	string file_bin_result = "file_bin_result.bin";
	ofstream fout_bin_result(file_bin_result, ios::binary);
	if (!fout_bin_result.is_open())
	{
		cout << "Ошибка открытия файла file_bin_result для записи" << endl;
		return -1;
	}
	cout << "Файл file_bin_result открыт для записи" << endl;

	char simbol_bin;
	simbol_bin = Simbol();
	cout << "simbol: " << simbol_bin << endl;

	while (!fin_bin.eof())
	{
		Recording_in_result(flag_bin, fin_bin, fout_bin_result, person_bin, simbol_bin);
	}
	cout << "Файл file_bin_result закрыт для записи" << endl;
	fout_bin_result.close();
	cout << "Файл file_bin закрыт для чтения" << endl;
	fin_bin.close();

	return 0;
}