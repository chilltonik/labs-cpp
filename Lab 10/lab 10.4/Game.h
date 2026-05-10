#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game
{
protected:
	int x;
	int y;
	int z;

public:
	void set_x(int x);
	void set_y(int y);
	void set_z(int z);

	int get_x();
	int get_y();
	int get_z();

	void fill();
	virtual void print();

	template <class T>
	void enter(istream& in, T& data)
	{
		while (true)
		{

			in >> data;

			if (in.fail())
			{
				in.clear();
				in.ignore(INT_MAX, '\n');

				cout << "An incorrect value. Please try again:" << endl;

				continue;
			}
			else
			{
				break;
			}
		}
	}

	Game();
	Game(int x, int y, int z);
	Game(Game& object);
	~Game();
};