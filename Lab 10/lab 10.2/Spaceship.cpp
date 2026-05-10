#include "Spaceship.h"

void Spaceship::set_name(string name) { this->name = name; };
void Spaceship::set_max_speed(unsigned int max_speed) { this->max_speed = max_speed; };
void Spaceship::set_ammunition(unsigned int ammunition) { this->ammunition = ammunition; };

string Spaceship::get_name() { return this->name; };
unsigned int Spaceship::get_max_speed() { return this->max_speed; };
unsigned int Spaceship::get_ammunition() { return this->ammunition; };

void Spaceship::fill()
{
	Mobile::fill();

	string name = "";
	cout << "Enter name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);

	unsigned int max_speed = 0;
	cout << "Enter max speed: ";
	enter(cin, max_speed);

	unsigned int ammunition = 0;
	cout << "Enter ammunition: ";
	enter(cin, ammunition);

	set_name(name);
	set_max_speed(max_speed);
	set_ammunition(ammunition);
}
void Spaceship::print()
{
	cout << "\nSpaceship:" << endl;
	Mobile::print();

	cout << "Name: " << get_name() << endl;
	cout << "Max speed: " << get_max_speed() << " mil/h" << endl;
	cout << "Ammunition: " << get_ammunition() << " bullets" << endl;
}

Spaceship::Spaceship() : Mobile()
{
	this->name = "No name";
	this->max_speed = 0;
	this->ammunition = 0;
}
Spaceship::Spaceship(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, string name, unsigned int speed, unsigned int ammunition) : Mobile(x, y, z, speed_X, speed_Y, speed_Z)
{
	this->name = name;
	this->max_speed = max_speed;
	this->ammunition = ammunition;
}
Spaceship::Spaceship(Mobile& object_mobile, Spaceship& object) : Mobile(object_mobile)
{
	this->name = object.get_name();
	this->max_speed = object.get_max_speed();
	this->ammunition = object.get_ammunition();
}
Spaceship::~Spaceship()
{
	//cout << "Spaceship destructor is here!" << endl;
}