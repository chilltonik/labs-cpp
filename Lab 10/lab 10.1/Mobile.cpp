#include "Mobile.h"

void Mobile::set_speed_X(unsigned int speed_X) { this->speed_X = speed_X; };
void Mobile::set_speed_Y(unsigned int speed_Y) { this->speed_Y = speed_Y; };
void Mobile::set_speed_Z(unsigned int speed_Z) { this->speed_Z = speed_Z; };

unsigned int Mobile::get_speed_X() { return this->speed_X; };
unsigned int Mobile::get_speed_Y() { return this->speed_Y; };
unsigned int Mobile::get_speed_Z() { return this->speed_Z; };

void Mobile::fill()
{
	Game::fill();

	unsigned int speed_X = 0;
	unsigned int speed_Y = 0;
	unsigned int speed_Z = 0;

	cout << "Enter the speed X: ";
	enter(cin, speed_X);
	cout << "Enter the speed Y: ";
	enter(cin, speed_Y);
	cout << "Enter the speed Z: ";
	enter(cin, speed_Z);

	set_speed_X(speed_X);
	set_speed_Y(speed_Y);
	set_speed_Z(speed_Z);
}
void Mobile::print()
{
	Game::print();

	cout << "Speed X: " << get_speed_X() << " mil/h." << endl;
	cout << "Speed Y: " << get_speed_Y() << " mil/h." << endl;
	cout << "Speed Z: " << get_speed_Z() << " mil/h." << endl;
}

Mobile::Mobile() : Game()
{
	this->speed_X = 0;
	this->speed_Y = 0;
	this->speed_Z = 0;
}
Mobile::Mobile(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z ) : Game(x, y, z)
{
	this->speed_X = speed_X;
	this->speed_Y = speed_Y;
	this->speed_Z = speed_Z;
}
Mobile::Mobile(Game& object_game, Mobile& object) : Game(object_game)
{
	this->speed_X = object.get_speed_X();
	this->speed_Y = object.get_speed_Y();
	this->speed_Z = object.get_speed_Z();
}
Mobile::~Mobile()
{
	//cout << "Mobile destructor is here!" << endl;
}