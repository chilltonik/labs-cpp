#pragma once
#include "Game.h"

class Fixed : public Game
{
protected:
	int temperature;
	string name;
	string surface_type;

public:
	void set_temperature(int temperature);
	void set_name(string name);
	void set_surface_type(string type);

	int get_temperature();
	string get_name();
	string get_surface_type();

	void input() override;
	void print() override;

	Fixed();
	Fixed(int x, int y, int z, int temperature, string name, string surface_type);
	Fixed(Game& object_game, Fixed& object);
	~Fixed();

	const char* get_Type() const override
	{
		return "Fixed";
	}
	Fixed* Clone() override
	{
		return new Fixed(*this);
	}

	void read(istream& in) override
	{
		Game::read(in);
		in >> temperature;
		in >> name;
		in >> surface_type;
	}
	void write(ostream& out) override
	{
		Game::write(out);

		out << temperature << endl;
		out << name << endl;
		out << surface_type << endl;
	}
};

void Fixed::set_temperature(int temperature) { this->temperature = temperature; };
void Fixed::set_name(string name) { this->name = name; };
void Fixed::set_surface_type(string type) { this->surface_type = type; };

int Fixed::get_temperature() { return this->temperature; };
string Fixed::get_name() { return this->name; };
string Fixed::get_surface_type() { return this->surface_type; };

void Fixed::input()
{
	Game::input();

	int temperature = 0;

	string name = "";
	string surface_type = "";

	cout << "Enter temperature: ";
	enter(cin, temperature);

	cout << "Enter name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);

	cout << "Enter surface type: ";
	getline(cin, surface_type);

	set_temperature(temperature);
	set_name(name);
	set_surface_type(surface_type);
}
void Fixed::print()
{
	Game::print();

	cout << "Temperature: " << get_temperature() << endl;
	if (this->temperature >= 5000)
	{
		cout << "Hmm, it's too hot!" << endl;
	}
	cout << "Name: " << get_name() << endl;
	cout << "Surface type: " << get_surface_type() << endl;
}

Fixed::Fixed() : Game()
{
	this->temperature = 0;
	this->name = "No name";
	this->surface_type = "No type";
}
Fixed::Fixed(int x, int y, int z, int temperature, string name, string surface_type) : Game(x, y, z)
{
	this->temperature = temperature;
	this->name = name;
	this->surface_type = surface_type;
}
Fixed::Fixed(Game& object_game, Fixed& object) : Game(object_game)
{
	this->temperature = object.get_temperature();
	this->name = object.get_name();
	this->surface_type = object.get_surface_type();
}
Fixed::~Fixed()
{
	//cout << "Fixed destructor is here!" << endl;
}