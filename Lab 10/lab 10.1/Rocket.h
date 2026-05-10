#pragma once
#include"Mobile.h"

class Rocket : public Mobile
{
protected:
	unsigned int power;
	unsigned int time;

public:
	void set_power(unsigned int power);
	void set_time(unsigned int time);

	unsigned int get_power();
	unsigned int get_time();

	void fill();
	void print();

	Rocket();
	Rocket(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, unsigned int power, unsigned int time);
	Rocket(Mobile& object_mobile, Rocket& object);
	~Rocket();
};