/*
Разработать класс «вектор», моделирующий математическое понятие «одномерный массив» произвольного размера с возможностью изменения числа элементов.

Реализовать три вида конструктора:
- без аргументов, +
- инициализации, +
- копирования, +
- деструктор.+

Определить методы:
- задания размерности вектора,+
- определения количества элементов заданного вектора;+
- заполнения элементов вектора случайными числами.+

Реализовать:
- перегрузку операторов индексирования [], возвращающие изменяемое значение элемента (L-value) и не изменяемое (R-value) 
с контролем выхода за пределы размерности вектора (для получения элемента вектора по заданному индексу, занесения значения элемента вектора по заданному индексу),+
- перегрузку операторов ввода/вывода значений элементов вектора.+

Разместить описание класса в заголовочном файле, а определения методов и главную функцию программы – в отдельных файлах.
Используя объекты описанного класса «Вектор», реализовать алгоритм своего варианта задания 7.1.

Выполнить задание, используя динамическое выделение памяти для одномерного массива. 
Дано (в текстовом файле) n>10^9 натуральных чисел (каждое число <10^4). 
Ограничение на объем используемой памяти 1 Мб. Получить массив за один просмотр элементов файла:

3. образованный из натуральных чисел <10^4, не встречающихся в исходном файле, по возрастанию;

*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

#define max_for_int 10000
#define min_for_int 0

using namespace std;

template<class Type>
class MyVector
{
private:
	int size;
	Type* vector;
public:
	MyVector();
	MyVector(int size);
	MyVector(MyVector& vector);

	~MyVector();

	int get_size() { return size; };
	void set_size(int count); //реализовать

	Type& operator[](const int index);
	Type operator[](const int index) const;

	void fill();
	void print();
};

template<class Type>
ostream& operator <<(ostream& out, MyVector<Type>& vector)
{
	cout << "Your vector:" << endl;
	for (int i = 0; i < vector.get_size(); ++i)
	{
		out << vector[i] << "  ";
	}
	cout << endl;

	return out;
}

template<class Type>
istream& operator >>(istream& in, MyVector<Type>& vect)
{
	for (int i = 0; i < vect.size; i++)
	{
		in >> vect.vector[i];
	}
	cout << endl;
	return in;
}

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
void Recording_in_file(ofstream& fout, int size)
{
	for (int i = 0; i < size; ++i)
	{
		fout << rand() % (max_for_int - min_for_int) + min_for_int << endl;
	}
}

int calculate_size(ifstream& fin, MyVector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0; i < bool_arr.get_size(); ++i)
	{
		bool_arr[i] = false;
	}

	while (fin >> value)
	{
		bool_arr[value] = true;
	}

	int j = 0;
	for (int i = 0; i < bool_arr.get_size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			j++;
		}
	}

	return j;
}

template<class Type>
void Fill_array(ifstream& fin, MyVector<Type>& arr, MyVector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0, j = 0; i < bool_arr.get_size() && j < arr.get_size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			arr[j] = i;
			j++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	string file_text = "File_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "Ошибка открытия файла file_text для записи" << endl;
		return -1;
	}
	cout << "Файл file_text открыт для записи" << endl;
	int size = 10000;/////////////////////////////////////

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
	MyVector<bool> bool_arr(bool_size);

	int array_size = calculate_size(fin_text, bool_arr);
	cout << "array_size: " << array_size << endl;
	MyVector<int> arr(array_size);
	
	Fill_array(fin_text, arr, bool_arr);
	cout << arr << endl;

	cout << "Файл file_text закрыт для чтения" << endl;
	fin_text.close();

	return 0;
}

template<class Type>
MyVector<Type>::MyVector()
{
	size = 0;
	vector = nullptr;
}

template<class Type>
MyVector<Type>::MyVector(int size)
{
	this->size = size;
	vector = new Type[size];
}

template<class Type>
MyVector<Type>::MyVector(MyVector& vec)
{	
	size = vec.size;
	vector = new Type[size];
	for (int i = 0; i < size; ++i)
	{
		vector[i] = vec.vector[i];
	}
}

template<class Type>
MyVector<Type>::~MyVector()
{
	if (vector)
	{
		//cout << "Deconstructor" << endl;
		delete[] vector;
	}
	size = 0;
}

template<class Type>
void MyVector<Type>::set_size(int count)
{
	size = count;
}

template<class Type>
Type& MyVector<Type>::operator[](const int index)
{
	if (index < size && index >= 0)
	{
		return vector[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}
}

template<class Type>
Type MyVector<Type>::operator[](const int index) const
{
	if (index < size)
	{
		return vector[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}

}

template<class Type>
void MyVector<Type>::fill()
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		vector[i] = rand() % (max_for_int - min_for_int) + min_for_int;
	}
}

template<class Type>
void MyVector<Type>::print()
{
	cout << "Your vector:" << endl;
	for (int i = 0; i < get_size(); ++i)
	{
		cout << vector[i] << "  ";
	}
	cout << endl;
}