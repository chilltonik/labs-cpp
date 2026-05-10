#pragma once
#include "Game.h"

class Mobile : public Game
{
protected:
	unsigned int speed_X;
	unsigned int speed_Y;
	unsigned int speed_Z;

public:
	void set_speed_X(unsigned int speed_X);
	void set_speed_Y(unsigned int speed_Y);
	void set_speed_Z(unsigned int speed_Z);

	unsigned int get_speed_X();
	unsigned int get_speed_Y();
	unsigned int get_speed_Z();

	void fill();
	void print();

	Mobile();
	Mobile(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z);
	Mobile(Game& object_game, Mobile& object);
	~Mobile();
};