#include "Star.h"

void Star::set_massa(unsigned int massa) { this->massa = massa; };
unsigned int Star::get_massa() { return this->massa; };

void Star::fill()
{
	Fixed::fill();

	unsigned int massa = 0;
	cout << "Enter massa: ";
	enter(cin, massa);

	set_massa(massa);
}
void Star::print()
{
	Fixed::print();
	cout << "Massa: " << get_massa() << " * 10^25 kg" << endl;
}

Star::Star() : Fixed()
{
	this->massa = 0;
}
Star::Star(int x, int y, int z, int temperature, string name, string surface_type, unsigned int massa) : Fixed(x, y, z, temperature, name, surface_type)
{
	this->massa = massa;
}
Star::Star(Fixed& object_fixed, Star& object) : Fixed(object_fixed)
{
	this->massa = object.get_massa();
}
Star::~Star()
{
	//cout << "Star destructor is here!" << endl;
}