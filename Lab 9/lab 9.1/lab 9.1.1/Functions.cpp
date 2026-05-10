#include"Functions.h"

void Recording_in_file(ofstream& fout, int size)
{
	for (int i = 0; i < size; ++i)
	{
		fout << rand() % (max_for_int - min_for_int) + min_for_int << endl;
	}
}
void Fill_array(ifstream& fin, vector<int>& arr, vector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0, j = 0; i < bool_arr.size() && j < arr.size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			arr[j] = i;
			j++;
		}
	}
}
int calculate_size(ifstream& fin, vector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0; i < bool_arr.size(); ++i)
	{
		bool_arr[i] = false;
	}

	while (fin >> value)
	{
		bool_arr[value] = true;
	}

	int j = 0;
	for (int i = 0; i < bool_arr.size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			j++;
		}
	}

	return j;
}