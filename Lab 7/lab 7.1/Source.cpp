/*
* Выполнить задание, используя динамическое выделение памяти для одномерного массива.
Дано (в текстовом файле) n>10^9 натуральных чисел (каждое число <=10^4). 
Ограничение на объем используемой памяти 1 Мб. Получить массив за один просмотр элементов файла:

3. образованный из натуральных чисел <=10^4, не встречающихся в исходном файле, по возрастанию;
*/
#include "Functions.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	string file_text = "file_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "Ошибка открытия файла file_text для записи" << endl;
		return -1;
	}
	cout << "Файл file_text открыт для записи" << endl;

	int size = 0;
	cout << "Enter size: ";
	cin >> size;

	Recording_in_file(fout_text, size);

	cout << "Файл file_text закрыт для записи" << endl;
	fout_text.close();

	ifstream fin_text;
	fin_text.open(file_text);
	if (!fin_text.is_open())
	{
		cout << "Ошибка открытия файла fin_text для чтения" << endl;
		return -1;
	}
	cout << "Файл file_text открыт для чтения" << endl;

	const int bool_size = 10000;
	int array_size = 0;
	cout << "Enter array_size: ";
	array_size = Integer();

	int* arr = new int[array_size];
	bool bool_arr[bool_size];

	while (!fin_text.eof())
	{
		Fill_array(fin_text, arr, array_size, bool_arr, bool_size);
	}
	
	Show_array(arr, array_size);

	delete[] arr;
	cout << "Файл file_text закрыт для чтения" << endl;
	fin_text.close();

	return 0;
}