#pragma once
#include "Fixed.h"

class Star : public Fixed
{
protected:
	unsigned int massa;
public:
	void set_massa(unsigned int massa);
	unsigned int get_massa();

	void input() override;
	void print() override;

	Star();
	Star(int x, int y, int z, int temperature, string name, string surface_type, unsigned int massa);
	Star(Fixed& object_fixed, Star& object);
	~Star();

	const char* get_Type() const override
	{
		return "Star";
	}
	Star* Clone() override
	{
		return new Star(*this);
	}

	void read(istream& in) override
	{
		Fixed::read(in);
		in >> massa;
	}
	void write(ostream& out) override
	{
		Fixed::write(out);

		out << massa << endl;
	}
};

void Star::set_massa(unsigned int massa) { this->massa = massa; };
unsigned int Star::get_massa() { return this->massa; };

void Star::input()
{
	Fixed::input();

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