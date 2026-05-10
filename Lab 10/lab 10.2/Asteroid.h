#pragma once
#include"Mobile.h"

class Asteroid : public Mobile
{
protected:
	unsigned int diameter;
	bool water;
public:
	void set_diameter(unsigned int diameter);
	void set_water(bool water);

	unsigned int get_diameter();
	bool get_water();

	void fill();
	void print();

	Asteroid();
	Asteroid(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, unsigned int diameter, bool water);
	Asteroid(Mobile& object_mobile, Asteroid& object);
	~Asteroid();
};