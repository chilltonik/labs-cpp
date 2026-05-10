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

	void input() override;
	void print() override;

	Rocket();
	Rocket(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, unsigned int power, unsigned int time);
	Rocket(Mobile& object_mobile, Rocket& object);
	~Rocket();

	const char* get_Type() const override
	{
		return "Rocket";
	}
	Rocket* Clone() override
	{
		return new Rocket(*this);
	}

	void read(istream& in) override
	{
		Mobile::read(in);
		in >> power;
		in >> time;
	}
	void write(ostream& out) override
	{
		Mobile::write(out);

		out << power << endl;
		out << time << endl;
	}
};

void Rocket::set_power(unsigned int power) { this->power = power; };
void Rocket::set_time(unsigned int time) { this->time = time; };

unsigned int Rocket::get_power() { return this->power; };
unsigned int Rocket::get_time() { return this->time; };

void Rocket::input()
{
	Mobile::input();

	unsigned int power = 0;
	cout << "Enter power: ";
	enter(cin, power);

	unsigned int time = 0;
	cout << "Enter time: ";
	enter(cin, time);

	set_power(power);
	set_time(time);
}
void Rocket::print()
{
	Mobile::print();

	cout << "Power: " << get_power() << " * 10^6 kal/g" << endl;
	cout << "Time: " << get_time() << " s" << endl;
}

Rocket::Rocket() : Mobile()
{
	this->power = 0;
	this->time = 0;
}
Rocket::Rocket(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, unsigned int power, unsigned int time) : Mobile(x, y, z, speed_X, speed_Y, speed_Z)
{
	this->power = power;
	this->time = time;
}
Rocket::Rocket(Mobile& object_mobile, Rocket& object) : Mobile(object_mobile)
{
	this->power = object.get_power();
	this->time = object.get_time();
}
Rocket::~Rocket()
{
	//cout << "Rocket destructor is here!" << endl;
}