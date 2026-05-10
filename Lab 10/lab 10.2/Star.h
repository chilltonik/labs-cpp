#pragma once
#include "Fixed.h"

class Star : public Fixed
{
protected:
	unsigned int massa;
public:
	void set_massa(unsigned int massa);
	unsigned int get_massa();

	void fill();
	void print();

	Star();
	Star(int x, int y, int z, int temperature, string name, string surface_type, unsigned int massa);
	Star(Fixed& object_fixed, Star& object);
	~Star();
};