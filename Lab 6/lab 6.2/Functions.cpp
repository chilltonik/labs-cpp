#include "Functions.h"

int Rand_even_size()
{
	int size = rand() % (max_count_rand - min_count_rand) + min_count_rand;
	if (size % 2 == 1)
	{
		size += 1;
	}
	return size;
}
int Generation_even_value()
{
	int number = rand() % (max_rand_generation - min_rand_generation) + min_rand_generation;
	if (number % 2 == 1)
	{
		number++;
	}
	return number;
}
int Generation_not_even_value()
{
	int number = rand() % (max_rand_generation - min_rand_generation) + min_rand_generation;
	if (number % 2 == 0)
	{
		number++;
	}
	return number;
}

void Showfile(ifstream& infile, string name)
{
	ifstream fin;
	fin.open(name, ios::binary);
	int value;
	fin.read(reinterpret_cast<char*>(&value), sizeof(int));
	while (!fin.eof())
	{
		cout << value << endl;
		fin.read(reinterpret_cast<char*>(&value), sizeof(int));
	}
	fin.close();
}

void Recording_in_file(bool FLAG_BIN, int& count_even, int& count_not_even, int max_even, int max_not_even, ofstream& fout)
{
	while (count_even < max_even && count_not_even < max_not_even)
	{
		int value = rand() % (max_count_rand - min_rand_generation) + min_count_rand;
		if (value % 2 == 0)
		{
			count_even++;
		}
		else
		{
			count_not_even++;
		}

		if (!FLAG_BIN)
		{
			fout << value << endl;
		}
		else
		{
			fout.write(reinterpret_cast<char*>(&value), sizeof(int));
		}
	}
}
void Recording_not_even_values(bool FLAG_BIN, int difference, ofstream& fout)
{
	for (int i = 0; i < difference; ++i)
	{
		int value = Generation_not_even_value();
		if (!FLAG_BIN)
		{
			fout << value << endl;
		}
		else
		{
			fout.write(reinterpret_cast<char*>(&value), sizeof(int));
		}
	}
}
void Recording_even_values(bool FLAG_BIN, int difference, ofstream& fout)
{
	for (int i = 0; i < abs(difference); ++i)
	{
		int value = Generation_even_value();
		if (!FLAG_BIN)
		{
			fout << value << endl;
		}
		else
		{
			fout.write(reinterpret_cast<char*>(&value), sizeof(int));
		}
	}
}

void Recording_in_fileG_even(ifstream& finF_even, string even, ofstream& foutG, int& count_even)
{
	while (getline(finF_even, even))
	{
		int value = stoi(even);
		if (value % 2 == 0)
		{
			foutG << value << endl;
			count_even++;
		}
		if (count_even == 1)
		{
			count_even = 0;
			break;
		}
	}
}
void Recording_in_fileG_not_even(ifstream& finF_not_even, string not_even, ofstream& foutG, int& count_not_even)
{
	while (getline(finF_not_even, not_even))
	{
		int value = stoi(not_even);
		if (value % 2 == 1)
		{
			foutG << value << endl;
			count_not_even++;
		}
		if (count_not_even == 1)
		{
			count_not_even = 0;
			break;
		}
	}
}

void Recording_in_fileBinG_even(ifstream& finBinF_even, int Bin_even, ofstream& foutBinG, int& Bin_count_even)
{
	while (finBinF_even.read(reinterpret_cast<char*>(&Bin_even), sizeof(int)))
	{
		if (Bin_even % 2 == 0)
		{
			foutBinG.write(reinterpret_cast<char*>(&Bin_even), sizeof(int));
			Bin_count_even++;
		}
		if (Bin_count_even == 1)
		{
			Bin_count_even = 0;
			break;
		}
	}
}
void Recording_in_fileBinG_not_even(ifstream& finBinF_not_even, int Bin_not_even, ofstream& foutBinG, int& Bin_count_not_even)
{
	while (finBinF_not_even.read(reinterpret_cast<char*>(&Bin_not_even), sizeof(int)))
	{
		if (Bin_not_even % 2 == 1)
		{
			foutBinG.write(reinterpret_cast<char*>(&Bin_not_even), sizeof(int));
			Bin_count_not_even++;
		}
		if (Bin_count_not_even == 1)
		{
			Bin_count_not_even = 0;
			break;
		}
	}
}