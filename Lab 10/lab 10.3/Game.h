#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define GAME "Game"
#define FIXED "Fixed"
#define MOBILE "Mobile"
#define STAR "Star"
#define PLANET "Planet"
#define ASTEROID "Asteroid"
#define SPACESHIP "Spasechip"
#define ROCKET "Rocket"

enum Identifiers
{
	STAR_ID = 1,
	PLANET_ID = 2,
	ASTEROID_ID = 3,
	SPACESHIP_ID = 4,
	ROCKET_ID = 5,
};

class Game
{
protected:
	int x;
	int y;
	int z;

	friend ostream& operator<<(ostream& out, Game& obj);

public:
	void set_x(int x);
	void set_y(int y);
	void set_z(int z);

	int get_x();
	int get_y();
	int get_z();

	virtual void input();
	virtual void print();

	template <class T>
	void enter(istream& in, T& data)
	{
		while (true)
		{

			in >> data;

			if (in.fail())
			{
				in.clear();
				in.ignore(INT_MAX, '\n');

				cout << "An incorrect value. Please try again:" << endl;

				continue;
			}
			else
			{
				break;
			}
		}
	}

	Game();
	Game(int x, int y, int z);
	Game(Game& object);
	~Game();

	virtual const char* get_Type() const
	{
		return "Game";
	}
	virtual Game* Clone()
	{
		return new Game(*this);
	}

	virtual void read(istream& in)
	{
		in >> x;
		in >> y;
		in >> z;
	}
	virtual void write(ostream& out)
	{
		out << get_Type() << endl;
		out << x << endl;
		out << y << endl;
		out << z << endl;
	}
};

ostream& operator<<(ostream& out, Game& obj)
{
	if (&out == &cout)
	{
		obj.print();
	}
	else
	{
		obj.write(out);
	}

	return out;
}

void Game::set_x(int x) { this->x = x; };
void Game::set_y(int y) { this->y = y; };
void Game::set_z(int z) { this->z = z; };

int Game::get_x() { return this->x; };
int Game::get_y() { return this->y; };
int Game::get_z() { return this->z; };

void Game::input()
{
	int x = 0;
	int y = 0;
	int z = 0;

	cout << "Enter coordinates: " << endl;
	cout << "Enter x: ";
	enter(cin, x);

	cout << "Enter y: ";
	enter(cin, y);

	cout << "Enter z: ";
	enter(cin, z);

	set_x(x);
	set_y(y);
	set_z(z);
}
void Game::print()
{
	cout << "X: " << get_x() << endl;
	cout << "Y: " << get_y() << endl;
	cout << "Z: " << get_z() << endl;
}

Game::Game()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
Game::Game(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Game::Game(Game& object)
{
	this->x = object.get_x();
	this->y = object.get_y();
	this->z = object.get_z();
}
Game::~Game()
{
	//cout << "Game destructor is here!" << endl;
}