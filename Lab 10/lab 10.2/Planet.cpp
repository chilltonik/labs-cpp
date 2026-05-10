#include "Planet.h"

void Planet::set_life(bool life) { this->life = life; };
bool Planet::get_life() { return this->life; };

void Planet::fill()
{
	Fixed::fill();
	bool life = true;
	short solution = 0;
	bool flag = true;

	while (flag)
	{
		cout << "Choice the presence of life: " << endl
			<< "1. Presence. " << endl
			<< "2. Not presence." << endl;

		cout << "Your solution: ";
		enter(cin, solution);

		if (solution >= 1 && solution <= 2)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
			set_life(life);
			break;
		case 2:
			set_life(!life);
			break;
		default:
			cout << "Yoops, your choise isn't correct. Please try again..." << endl;
			break;
		}
	}
}
void Planet::print()
{
	cout << "\nPlanet:" << endl;
	Fixed::print();
	if (get_life())
	{
		cout << "Life: What luck! Life is here!" << endl;
	}
	else
	{
		cout << "Life: Hmm, it looks like there is no life here..." << endl;
	}
}

Planet::Planet() : Fixed()
{
	this->life = false;
}
Planet::Planet(int x, int y, int z, int temperature, string name, string surface_type, bool life) : Fixed(x, y, z, temperature, name, surface_type)
{
	this->life = life;
}
Planet::Planet(Fixed& object_fixed, Planet& object) : Fixed(object_fixed)
{
	this->life = object.get_life();
}
Planet::~Planet()
{
	//cout << "Planet destructor is here!" << endl;
}