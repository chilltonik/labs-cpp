#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"

using namespace std;

class Vector
{
private:
	int m_size;
	Game** m_arr;
public:

	Vector();
	Vector(int size);
	Vector(Vector& obj);
	~Vector();

	void push_back();
	void pop_back();

	int get_size();

	void clear();
	void fill();
	void print();
};