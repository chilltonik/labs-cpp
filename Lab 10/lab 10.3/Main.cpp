#include <iostream>
#include <string>
#include <fstream>
#include "Vector.h"
#include "ObjectFactory.h"

using namespace std;

int main()
{
	const string file = "Game.txt";

	int size = 0;
	cout << "Enter size: ";
	cin >> size;

	Vector objects(size);
	objects.input(size);

	ofstream fout(file);
	fout << objects << endl;
	fout.close();

	cout << "----------------Vector----------------" << endl;
	ifstream fin(file);
	objects.clear();
	objects.read(fin);
	cout << endl << objects << endl;
	fin.close();

	Vector result(size);
	cout << "----------------RESULT----------------" << endl;
	ifstream fin_res(file);
	result.clear();
	result.read(fin_res);
	cout << endl << result << endl;
	fin_res.close();

	return 0;
}