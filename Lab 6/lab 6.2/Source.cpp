/*
* Выполнить задания для текстового и бинарного файлов. Задания выпол-
нить через функции. Размер файлов <= 64GiB.
3. Компоненты файла f – целые числа, четных чисел столько же, сколько нечет-
ных. Получить файл g из чисел исходного файла, в котором не было бы двух со-
седних чисел одинаковой четности.
*/
#include "Functions.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	bool FLAG_BIN = false;

	int size = Rand_even_size();

	int max_even = size / 2;
	int max_not_even = size / 2;

	int count_even = 0;
	int count_not_even = 0;

	string fileF = "FileF.txt";
	ofstream foutF;
	foutF.open(fileF);
	if (!foutF.is_open())
	{
		cout << "Ошибка открытия файла F для записи" << endl;
		return 1;
	}
	else
	{
		//cout << "файл F открыт для записи" << endl;
		Recording_in_file(FLAG_BIN, count_even, count_not_even, max_even, max_not_even, foutF);
		int difference = count_even - count_not_even;

		if (difference > 0)
		{
			Recording_not_even_values(FLAG_BIN, difference, foutF);
		}
		if (difference < 0)
		{
			Recording_even_values(FLAG_BIN, difference, foutF);
		}
	}
	//cout << "Файл F закрыт для записи" << endl;
	foutF.close();

	ifstream finF_even;
	ifstream finF_not_even;

	finF_even.open(fileF);
	finF_not_even.open(fileF);

	if (!finF_even.is_open() && finF_not_even.is_open())
	{
		cout << "Не удалось открыть файл F для чтения even и not_even" << endl;
		return 2;
	}
	else
	{
		//cout << "Файл F для чтения even и not_even открыт" << endl;
		string fileG = "FileG.txt";
		ofstream foutG;
		foutG.open(fileG);

		if (!foutG.is_open())
		{
			cout << "Ошибка открытия файла G для записи" << endl;
			return 3;
		}
		else
		{
			//cout << "Файл G открыт для записи" << endl;
			string even = "";
			string not_even = "";
			int count_even = 0;
			int count_not_even = 0;

			while (!finF_even.eof() && !finF_not_even.eof())
			{
				Recording_in_fileG_even(finF_even, even, foutG, count_even);
				Recording_in_fileG_not_even(finF_not_even, not_even, foutG, count_not_even);
			}
		}
		//cout << "Файл G закрыт для записи" << endl;
		foutG.close();
	}
	//cout << "Файл F even и not_even закрыт для чтения" << endl;
	finF_even.close();
	finF_not_even.close();

	//__________________________________________________________________________________________________________Bin
	count_even = 0;
	count_not_even = 0;

	FLAG_BIN = true;

	string fileBinF = "FileBinF.bin";
	ofstream foutBinF(fileBinF, ios::binary);
	if (!foutBinF.is_open())
	{
		cout << "ошибка открытия файла BinF для записи" << endl;
		return 1;
	}
	else
	{
		//cout << "Файл BinF открыт для записи" << endl;
		Recording_in_file(FLAG_BIN, count_even, count_not_even, max_even, max_not_even, foutBinF);
		int difference = count_even - count_not_even;

		if (difference > 0)
		{
			Recording_not_even_values(FLAG_BIN, difference, foutBinF);
		}
		if (difference < 0)
		{
			Recording_even_values(FLAG_BIN, difference, foutBinF);
		}
	}
	//cout << "Файл BinF закрыт для записи" << endl;
	foutBinF.close();

	string fileBinG = "FileBinG.bin";

	ifstream finBinF_even(fileBinF, ios::binary);
	ifstream finBinF_not_even(fileBinF, ios::binary);
	ifstream finBinG(fileBinG, ios::binary);
	ifstream finBinF(fileBinF, ios::binary);

	if (!finBinF_even.is_open() && !finBinF_not_even.is_open())
	{
		cout << "Ошибка открытия файлов finBinF_even и finBinF_not_even для чтения" << endl;
		return 2;
	}
	else
	{
		//cout << "Файлы finBinF_even и finBinF_not_even открыты для чтения" << endl;
		ofstream foutBinG(fileBinG, ios::binary);

		if (!foutBinG.is_open())
		{
			cout << "Ошибка открытия файла BinG для записи" << endl;
			return 3;
		}
		else
		{
			//cout << "Файл BinG открыт для записи" << endl;
			int Bin_even = 0;
			int Bin_not_even = 0;
			int Bin_count_even = 0;
			int Bin_count_not_even = 0;

			while (!finBinF_even.eof() && !finBinF_not_even.eof())
			{
				Recording_in_fileBinG_even(finBinF_even, Bin_even, foutBinG, Bin_count_even);
				Recording_in_fileBinG_not_even(finBinF_not_even, Bin_not_even, foutBinG, Bin_count_not_even);
			}
		}
		//cout << "Файл BinG закрыт для записи" << endl;
		foutBinG.close();
	}
	//cout << "Файлы finBinF_even и finBinF_not_even закрыты для чтения" << endl;
	finBinF_even.close();
	finBinF_not_even.close();

	cout << "fileBinF:" << endl;
	Showfile(finBinF, fileBinF);
	cout << "\nfileBinG:" << endl;
	Showfile(finBinG, fileBinG);
	
	return 0;
}