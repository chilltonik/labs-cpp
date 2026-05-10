#pragma once
#include "Fixed.h"

class Planet : public Fixed
{
protected:
	bool life;
public:
	void set_life(bool life);
	bool get_life();

	void fill();
	void print();

	Planet();
	Planet(int x, int y, int z, int temperature, string name, string surface_type, bool life);
	Planet(Fixed& object_fixed, Planet& object);
	~Planet();
};