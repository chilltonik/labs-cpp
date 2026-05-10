#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <string>
#include "Vector.h"

#define SPACING 12

using namespace std;

class Matrix
{
private:
	string m_name;
	static int m_count;

	vector<vector<double>> m_matrix;

	int m_rows;
	int m_cols;

	friend ostream& operator << (ostream& out, const Matrix& matrix_to_out);
	friend istream& operator >> (istream& in, Matrix& matrix_to_in);
public:

	Matrix();
	Matrix(int rows, int cols);
	Matrix(Matrix& another_matrix);
	~Matrix();

	vector <double>& operator[](int index);
	bool is_compatible_width(const Matrix& another_matrix);
	Matrix operator*(const Matrix& another_matrix);

	void fill_random();
	void fill_keyboard();
	void fill_identity();
	void print();

	int get_rows();
	int get_cols();
	Matrix get_transposed();
};