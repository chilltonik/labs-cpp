/*
 9.1. ВЕКТОРЫ

 1. Реализовать задание 7.1, используя объявление и методы соответствующего параметризированного класса vector из стандартной библиотеки шаблонов STL.

 7.1+
 Выполнить задание, используя динамическое выделение памяти для одно-мерного массива.
 Дано (в текстовом файле) n>10^9 натуральных чисел (каждое число <10^4).
 Ограничение на объем используемой памяти 1 Мб. Получить массив за один просмотр элементов файла:

 3. образованный из натуральных чисел <10^4, не встречающихся в исходном файле, по возрастанию;

*/
#include"Functions.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	string file_text = "File_text.txt";  
	ofstream fout_text;

	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "Ошибка открытия файла file_text для записи" << endl;
		return -1;
	}
	//cout << "Файл file_text открыт для записи" << endl;

	int size = 10000;/////////////////////////////////////

	Recording_in_file(fout_text, size);
	//cout << "Файл file_text закрыт для записи" << endl;

	fout_text.close();
	ifstream fin_text;

	fin_text.open(file_text);
	if (!fin_text.is_open())
	{
		cout << "Ошибка открытия файла fin_text для чтения" << endl;
		return -1;
	}
	//cout << "Файл file_text открыт для чтения" << endl;

	const int bool_size = 10000;//////////////////////

	vector<bool> bool_arr(bool_size);
	int array_size = calculate_size(fin_text, bool_arr);

	//cout << "array_size: " << array_size << endl;
	vector<int> arr(array_size);

	Fill_array(fin_text, arr, bool_arr);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "  ";
	}

	//cout << "Файл file_text закрыт для чтения" << endl;
	fin_text.close();

	return 0;
}