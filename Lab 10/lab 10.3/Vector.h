#pragma once
#include <map>
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Star.h"
#include "Planet.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"
#include "ObjectFactory.h"

class Vector
{
private:
	int size;
	Game** arr;

	map<string, int> types;//список классов с их номерами, чтобы использовать switch

	friend ostream& operator<<(ostream& file, const Vector& vctr);

public:
	Vector();
	Vector(int size);
	Vector(const Vector& vctr);
	Vector(Vector&& vctr);

	~Vector();

	Game*& operator[](int index);
	Game*& operator[](int index) const;
	Vector& operator=(const Vector& vctr);
	Vector& operator=(Vector&& vctr);

	void input(int size);
	void read(istream& in);

	void push_back(Game* data);
	void pushAt(int index, Game* obj);
	void deleteAt(int index);
	void clear();

	void setSize(int size);
	int getSize() const;
};

Vector::Vector()
{
	size = 0;
	arr = new Game * [size];

	int i = 1;
	types.try_emplace(STAR, STAR_ID);
	types.try_emplace(PLANET, PLANET_ID);
	types.try_emplace(ASTEROID, ASTEROID_ID);
	types.try_emplace(SPACESHIP, SPACESHIP_ID);
	types.try_emplace(ROCKET, ROCKET_ID);
}
Vector::Vector(int size)
{
	try
	{
		if (size < 0)
		{
			throw size;
		}
	}
	catch (int)
	{
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	this->size = size;
	arr = new Game * [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = nullptr;
	}

	int i = 1;
	types.try_emplace(STAR, STAR_ID);
	types.try_emplace(PLANET, PLANET_ID);
	types.try_emplace(ASTEROID, ASTEROID_ID);
	types.try_emplace(SPACESHIP, SPACESHIP_ID);
	types.try_emplace(ROCKET, ROCKET_ID);
}
Vector::Vector(const Vector& vctr)
{
	size = vctr.size;
	arr = new Game * [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = vctr.arr[i];
	}
}
Vector::Vector(Vector&& vctr)//Конструктор перемещения передается ссылка на временный объект rvalue ссылка
{
	size = vctr.size;
	arr = new Game * [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = vctr.arr[i];
	}
	vctr.size = 0;
	vctr.arr = nullptr;
}
Vector::~Vector()
{
	clear();
}

ostream& operator<<(ostream& out, const Vector& vctr)//перегрузка опереатора вывода
{
	for (int i = 0; i < vctr.size; ++i)
	{
		if (vctr.arr[i])
		{
			out << *vctr.arr[i] << endl;
		}
	}

	return out;
}

Game*& Vector::operator[](int index)
{
	try
	{
		if (index < 0 || index >= size)
		{
			throw index;
		}
	}
	catch (int)
	{
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return arr[index];
}
Game*& Vector::operator[](int index) const
{
	try
	{
		if (index < 0 || index >= size)
		{
			throw index;
		}
	}
	catch (int)
	{
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return arr[index];
}
Vector& Vector::operator=(const Vector& vctr)//оператор копирования
{
	if (this == &vctr)
	{
		return *this;
	}

	clear();
	size = vctr.size;
	arr = new Game * [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = vctr.arr[i];
	}

	return *this;
}
Vector& Vector::operator=(Vector&& vctr)//оператор перемещения
{
	if (this == &vctr)
	{
		return *this;
	}

	swap(size, vctr.size);
	swap(arr, vctr.arr);

	return *this;
}

void Vector::input(int size)
{
	setSize(size);
	for (int i = 0; i < size; ++i)
	{
		cout << "Enter the type of the object " << i + 1 << ":" << endl;
		cout << " " << STAR_ID << ". " << STAR << endl;
		cout << " " << PLANET_ID << ". " << PLANET << endl;
		cout << " " << ASTEROID_ID << ". " << ASTEROID << endl;
		cout << " " << SPACESHIP_ID << ". " << SPACESHIP << endl;
		cout << " " << ROCKET_ID << ". " << ROCKET << endl;

		int option = 0;
		cin >> option;

		ObjectFactory factory;

		switch (option)
		{
		case STAR_ID:
			arr[i] = factory.create(STAR);
			break;
		case PLANET_ID:
			arr[i] = factory.create(PLANET);
			break;
		case ASTEROID_ID:
			arr[i] = factory.create(ASTEROID);
			break;
		case SPACESHIP_ID:
			arr[i] = factory.create(SPACESHIP);
			break;
		case ROCKET_ID:
			arr[i] = factory.create(ROCKET);
			break;
		default:
			break;
		}
		arr[i]->input();
		cout << endl;
	}
}
void Vector::read(istream& in)//функция, которая записывает данные из файла в массив
{
	int size = 0;
	while (!in.eof())//идем пока не закончится файл
	{
		string currentLine;//создаем буферную строку
		currentLine.clear();

		getline(in, currentLine);//заполняем текущую строку (первой) строкой файла

		if (currentLine.empty())//если строка пустая, то пропускаем ее
		{
			continue;
		}

		ObjectFactory factory;

		map<string, int>::iterator it = types.find(currentLine);//итератор, который по строке определяет какой объект
		if (it != types.end())//если найден элемент то заходим в if
		{
			switch (it->second)//смотрим номер нашего объекта и записываем в массив нужные данные
			{
			case STAR_ID:
				setSize(size + 1);//создаем нужный размер
				arr[size] = factory.create(STAR);//заполняем наш массив нужными данными
				arr[size++]->read(in);//заполнем каждое поле массива данными из файла
				break;
			case PLANET_ID:
				setSize(size + 1);
				arr[size] = factory.create(PLANET);
				arr[size++]->read(in);
				break;
			case ASTEROID_ID:
				setSize(size + 1);
				arr[size] = factory.create(ASTEROID);
				arr[size++]->read(in);
				break;
			case SPACESHIP_ID:
				setSize(size + 1);
				arr[size] = factory.create(SPACESHIP);
				arr[size++]->read(in);
				break;
			case ROCKET_ID:
				setSize(size + 1);
				arr[size] = factory.create(ROCKET);
				arr[size++]->read(in);
				break;
			default:
				break;
			}
		}
	}
}

void Vector::push_back(Game* obj)
{
	setSize(size + 1);
	arr[size - 1] = obj;
}
void Vector::pushAt(int index, Game* obj)
{
	try
	{
		if (index < 0 || index > size)
		{
			throw index;
		}
	}
	catch (int)
	{
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	setSize(size + 1);
	if (index != size - 1)
	{
		for (int i = size - 1; i > index; --i)
		{
			arr[i] = arr[i - 1];
		}
	}
	arr[index] = obj;
}

void Vector::deleteAt(int index)
{
	try
	{
		if (index < 0 || index >= size)
		{
			throw index;
		}
	}
	catch (int)
	{
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	for (int i = index; i < size - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}
	setSize(size - 1);
}
void Vector::clear()
{
	if (arr)
	{
		size = 0;
		delete[] arr;
		arr = nullptr;
	}
}

void Vector::setSize(int size)//перезаписываем массив делая его нужного размера
{
	try//обрабатываем исключения
	{
		if (size < 0)
		{
			throw size;
		}
	}
	catch (int)
	{
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	Game** newArr = new Game * [size];
	for (int i = 0; i < size; ++i)//все элементы старого массива копируем и по необходимости добавляем новые 0
	{
		if (i < this->size)
		{
			newArr[i] = arr[i];
		}
		else
		{
			newArr[i] = nullptr;
		}
	}

	delete[] arr;
	this->size = size;
	arr = newArr;
}
int Vector::getSize() const
{
	return size;
}