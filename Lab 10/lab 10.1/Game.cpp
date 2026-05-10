#include "Game.h"

void Game::set_x(int x) { this->x = x; };
void Game::set_y(int y) { this->y = y; };
void Game::set_z(int z) { this->z = z; };

int Game::get_x() { return this->x; };
int Game::get_y() { return this->y; };
int Game::get_z() { return this->z; };

void Game::fill()
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