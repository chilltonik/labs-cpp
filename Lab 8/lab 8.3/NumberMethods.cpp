#include"Number.h"
int input_value(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter count: ";
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
void fill_arr(int*& arr, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % (2 - 0) + 0;
	}
}
void print_arr(int* arr, int size)
{
	cout << "Your arr:" << endl;
	for (int i = 0; i < size; ++i)
	{
		if (i != 0 && i % 64 == 0)
		{
			cout << endl;
		}
		if (i % 4 == 0)
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
}

string fill_degree(int osn, int degree)
{
	int arr[100];
	arr[0] = 1;
	arr[1] = 1;

	for (int p = 0; p < degree; ++p)
	{
		int b = 0;
		for (int i = 1; i <= arr[0]; ++i)
		{
			b += arr[i] * osn;
			arr[i] = b % 10;
			b /= 10;
		}

		if (b != 0)
		{
			arr[0]++;
			arr[arr[0]] = b;
		}
	}

	string result = "";
	for (int i = arr[0]; i >= 1; --i)
	{
		result.push_back(arr[i] + static_cast<int>('0'));
	}
	/*cout << "Degree_result:" << endl;
	cout << result << endl;*/

	/*cout << "Arr:" << endl;
	for (int i = arr[0]; i >= 1; --i)
	{
		cout << arr[i];
	}
	cout << endl;*/

	return result;
}

void sum(int* result, int* current, int size)
{
	int rank_count = current[0];
	//cout << "current[1]: "<< current[1] << endl;
	//cout << "rank_count_arr: " << rank_count << endl;
	for (int i = size - 1, j = 1; j <= rank_count; --i, ++j)
	{
		int value = result[i] + current[j];
		if (value >= 10)
		{
			int ii = i;
			int jj = j;
			while (result[ii] + current[jj] >= 10)
			{
				int ost = (result[ii] + current[jj]) % 10;
				result[ii] = ost;
				if (ii >= 1)
				{
					result[ii - 1]++;
				}
				--ii;
				++jj;
				if (ii < 0)
				{
					break;
				}
			}
		}
		else
		{
			result[i] = value;
		}
	}
}
void convert_to_string(string& result_str, int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i <= size - 1)
		{
			if (arr[i] != 0 || arr[i + 1] != 0)
			{
				result_str.push_back(arr[i] + static_cast<int>('0'));
			}
		}
	}
}

unsigned long long convert_dec_to_bin(int dec)
{
	unsigned long long sum = 1;
	int osn = 2;

	int current = dec;

	while (current)
	{
		int ost = current % osn;
		sum = sum * 10 + ost;
		current /= osn;
	}

	int temp = sum % 10;
	unsigned long long bin = 0;

	while (sum > 1)
	{
		temp = sum % 10;
		bin = bin * 10 + temp;
		sum /= 10;
	}

	return bin;
}
//Реализовать
string convert_dec_to_bin(string dec)
{
	string result = "";
	return result;
}

Number::Number()
{
	m_arr = new int[m_rank] {0};
}
Number::Number(int dec)
{
	m_arr = new int[m_rank];
	clear();
	unsigned long long bin = convert_dec_to_bin(dec);

	int i = 0;
	while (bin)
	{
		int value = bin % 10;
		m_arr[i] = value;
		bin /= 10;
		i++;
	}
}
Number::Number(string dec)
{
}
Number::Number(Number& odject)
{
	m_arr = new int[m_rank];
	for (int i = 0; i < m_rank; ++i)
	{
		m_arr[i] = odject.m_arr[i];
	}
}

Number::~Number()
{
	delete[] m_arr;
	m_arr = nullptr;
	//cout << "Destrustor is here!" << endl;
}

void Number::set_m_arr(int* arr, int size)
{
	clear();
	for (int i = 0; i < size; ++i)
	{
		m_arr[i] = arr[i];
	}
}
int* Number::get_m_arr()
{
	print();
	cout << "pointer: " << m_arr << endl;
	return m_arr;
}

void Number::fill()
{
	clear();

	string value = "";
	cout << "Enter your number in binary code: ";
	getline(cin, value);

	int rank_count = value.size();
	for (int i = 0; i < rank_count; ++i)
	{
		m_arr[i] = static_cast<int>(value[i]) - static_cast <int>('0');
	}
}
void Number::clear()
{
	for (int i = 0; i < m_rank; ++i)
	{
		m_arr[i] = 0;
	}
}

void Number::print()
{
	int znach_rank = 0;
	for (int i = m_rank - 1; i >= 0; --i)
	{
		if (m_arr[i] == 1)
		{
			break;
		}
		++znach_rank;
	}

	cout << "Your number in binary: " << endl;
	for (int i = 0; i < m_rank - znach_rank; ++i)
	{
		if (i != 0 && i % 64 == 0)
		{
			cout << endl;
		}
		else
		{
			if (i != 0 && i % 4 == 0)
			{
				cout << " ";
			}
		}
		cout << m_arr[i];
	}
	cout << endl;
}
void Number::print_reverse()
{
	int znach_rank = 0;
	for (int i = m_rank - 1; i >= 0; --i)
	{
		if (m_arr[i] == 1)
		{
			break;
		}
		++znach_rank;
	}

	cout << "Your number in binary code REVERSE: " << endl;
	for (int i = m_rank - znach_rank - 1; i >= 0; --i)
	{
		if (i != 0 && i % 64 == 0)
		{
			cout << endl;
		}
		else
		{
			if (i != 0 && i % 4 == 0)
			{
				cout << " ";
			}
		}
		cout << m_arr[i];
	}
	cout << endl;
}

void Number::shift_left(int n)
{
	for (int i = 0; i < m_rank; ++i)
	{
		if (i >= n)
		{
			m_arr[i - n] = m_arr[i];
			m_arr[i] = 0;
		}
	}
}
void Number::shift_right(int n)
{
	for (int i = m_rank - 1; i >= 0; --i)
	{
		if ((i + n) < m_rank)
		{
			m_arr[i + n] = m_arr[i];
			m_arr[i] = 0;
		}
	}
}

void Number::operator>(int n)
{
	for (int i = 0; i < m_rank; ++i)
	{
		if (i >= n)
		{
			m_arr[i - n] = m_arr[i];
			m_arr[i] = 0;
		}
	}
}
void Number::operator<(int n)
{
	for (int i = m_rank - 1; i >= 0; --i)
	{
		if ((i + n) < m_rank)
		{
			m_arr[i + n] = m_arr[i];
			m_arr[i] = 0;
		}
	}
}

ostream& operator<<(ostream& out, Number& num)
{
	//REVERSE
	int znach_rank = 0;
	for (int i = num.m_rank - 1; i >= 0; --i)
	{
		if (num.m_arr[i] == 1)
		{
			break;
		}
		++znach_rank;
	}

	for (int i = num.m_rank - znach_rank - 1; i >= 0; --i)
	{
		if (i != 0 && i % 64 == 0)
		{
			cout << endl;
		}
		else
		{
			if (i != 0 && i % 4 == 0)
			{
				cout << " ";
			}
		}
		cout << num.m_arr[i];
	}

	return out;
}
istream& operator>>(istream& in, Number& num)
{
	num.clear();

	string value = "";
	getline(in, value);

	int rank_count = value.size();
	for (int i = 0; i < rank_count; ++i)
	{
		num.m_arr[i] = static_cast<int>(value[i]) - static_cast <int>('0');
	}

	return in;
}

int& Number::operator[](const int index)
{
	if (index < m_rank && index >= 0)
	{
		return m_arr[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}
}
int Number::operator[](const int index) const
{
	if (index < m_rank && index >= 0)
	{
		return m_arr[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}
}

string Number::convert_bin_to_dec()
{
	string buffer = "";
	for (int i = 0; i < m_rank; ++i)
	{
		buffer.push_back(static_cast<char>(m_arr[i]) + static_cast <int>('0'));
	}
	//cout << buffer << endl;

	int result[100] = { 0 };
	int current[100] = { 0 };
	current[0] = 1;
	current[1] = 1;

	int len = buffer.size();

	if (buffer[0] == '1')
	{
		result[100 - 1]++;
	}

	for (int p = 1; p < len; ++p)
	{
		int b = 0;
		for (int i = 1; i <= current[0]; ++i)
		{
			b += current[i] * 2;
			current[i] = b % 10;
			b /= 10;
		}
		if (b != 0)
		{
			current[0]++;
			current[current[0]] = b;
		}

		if (buffer[p] == '1')
		{
			sum(result, current, 100);
		}
	}

	/*if (buffer[0] == '1')
	{
		result[100 - 1]++;
	}*/

	/*cout << "Current:" << endl;
	for (int i = current[0]; i >= 1; --i)
	{
		cout << current[i] << " ";
	}
	cout << endl;*/

	/*cout << "Current:" << endl;
	print(current, 100);*/

	string result_str = "";
	convert_to_string(result_str, result, 100);
	//cout << "Result_str: " << endl;
	//cout << result_str << endl;

	return result_str;
}