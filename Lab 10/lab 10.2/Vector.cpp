#include "Vector.h"

int Vector::get_size() { return this->m_size; };

void Vector::clear()
{
	for (int i = 0; i < this->get_size(); ++i)
	{
		this->m_arr[i] = nullptr;
	}
}
void Vector::fill()
{
	int members_count = 0;
	cout << "Enter members count: ";
	cin >> members_count;

	for (int i = 0; i < members_count; ++i)
	{
		push_back();
	}
}
void Vector::print()
{
	cout << "\nVirtual:" << endl;
	for (int i = 0; i < this->get_size(); ++i)
	{
		m_arr[i]->print();
	}
	cout << endl;
}

Vector::Vector()
{
	this->m_size = 0;
	this->m_arr = nullptr;
}
Vector::Vector(int size)
{
	this->m_arr = new Game * [size];
	clear();
}
Vector::Vector(Vector& obj)
{
	this->m_arr = new Game * [obj.get_size()];
	for (int i = 0; i < obj.get_size(); ++i)
	{
		this->m_arr[i] = new Game;
	}

	for (int i = 0; i < obj.get_size(); ++i)
	{
		this->m_arr[i] = obj.m_arr[i];
	}
}
Vector::~Vector()
{
	for (int i = 0; i < get_size(); ++i)
	{
		delete m_arr[i];
	}
	delete[] m_arr;
	m_arr = nullptr;
}

void Vector::push_back()
{
	Star *star;
	Planet *planet;
	Asteroid *asteroid;
	Spaceship *spaceship;
	Rocket *rocket;

	Game** new_arr = new Game * [this->get_size() + 1];
	for (int i = 0; i < this->get_size() + 1; ++i)
	{
		new_arr[i] = new Game;
	}
	for (int i = 0; i < this->get_size(); ++i)
	{
		new_arr[i] = this->m_arr[i];
	}

	cout << "\nChoice the new object: " << endl
		<< "1. Star." << endl
		<< "2. Planet." << endl
		<< "3. Asteroid." << endl
		<< "4. Spaceship." << endl
		<< "5. Rocket." << endl;

	int solution = 0;
	bool flag = true;
	while (flag)
	{
		cout << "Your choice: ";
		cin >> solution;
		if (solution >= 1 && solution <= 5)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			cout << "\nStar!" << endl;
			star = new Star;
			star->fill();
			new_arr[this->get_size()] = star;
		}
		break;
		case 2:
		{
			cout << "\nPlanet!" << endl;
			planet = new Planet;
			planet->fill();
			new_arr[this->get_size()] = planet;
		}
		break;
		case 3:
		{
			cout << "\nAsteroid!" << endl;
			asteroid = new Asteroid;
			asteroid->fill();
			new_arr[this->get_size()] = asteroid;
		}
		break;
		case 4:
		{
			cout << "\nSpaceship!" << endl;
			spaceship = new Spaceship;
			spaceship->fill();
			new_arr[this->get_size()] = spaceship;
		}
		break;
		case 5:
		{
			cout << "\nRocket!" << endl;
			rocket = new Rocket;
			rocket->fill();
			new_arr[this->get_size()] = rocket;
		}
		break;
		}
	}

	delete[] m_arr;
	this->m_size++;
	this->m_arr = new_arr;
}
void Vector::pop_back()
{
	Game** new_arr = new Game * [this->get_size() - 1];
	for (int i = 0; i < this->get_size() - 1; ++i)
	{
		new_arr[i] = new Game;
	}
	for (int i = 0; i < this->get_size() - 1; ++i)
	{
		new_arr[i] = this->m_arr[i];
	}

	delete[] m_arr;
	this->m_size--;
	this->m_arr = new_arr;
}