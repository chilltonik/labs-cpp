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

	void fill();
	void print();

	Fixed();
	Fixed(int x, int y, int z, int temperature, string name, string surface_type);
	Fixed(Game& object_game, Fixed& object);
	~Fixed();
};