#include"Functions.h"

int Input_value(int max)
{
	int test = 0;
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

void fill_vector(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand() % (max_value_for_generation - min_value_for_generation) + min_value_for_generation;
	}
}
void print_vector(vector<int>& arr)
{
	cout << "Your vector: " << endl;
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int calculate_result_vector(vector<int>& arr)
{
	int result = 0;
	int size = arr.size();

	for (int i = 0; i < arr.size() - 1; ++i)
	{
		result += arr[i] + arr[i + 1] + size * arr[size - 1];
		size--;
	}
	return result;
}

void fill_list(list<int>& lst)
{
	for (int i = 0; i < lst.size(); ++i)
	{
		int value = rand() % (max_value_for_generation - min_value_for_generation) + min_value_for_generation;
		lst.push_back(value);
		lst.pop_front();
	}
}
void print_list(list<int>& lst)
{
	list<int>::iterator current = lst.begin();

	cout << "Your list: " << endl;
	while (current != lst.end())
	{
		cout << *current << "  ";
		++current;
	}
	cout << endl;
}
int calculate_result_list(list<int>& lst)
{
	int result = 0;

	list<int>::iterator current_begin = lst.begin();
	list<int>::iterator current_end = --lst.end();
	int size = lst.size();

	while (current_begin != lst.end())
	{
		int slag1 = *current_begin;
		if (++current_begin == lst.end())
		{
			return result;
		}
		int slag2 = *(current_begin);
		int slag3 = size * (*(current_end--));
		result += slag1 + slag2 + slag3;

		size--;
	}
}
