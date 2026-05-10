#pragma once
#include"Mobile.h"

class Spaceship : public Mobile
{
protected:
	string name;
	unsigned int max_speed;
	unsigned int ammunition;

public:
	void set_name(string name);
	void set_max_speed(unsigned int max_speed);
	void set_ammunition(unsigned int ammunition);

	string get_name();
	unsigned int get_max_speed();
	unsigned int get_ammunition();

	void fill();
	void print();

	Spaceship();
	Spaceship(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, string name, unsigned int max_speed, unsigned int ammunition);
	Spaceship(Mobile& object_mobile, Spaceship& object);
	~Spaceship();
};