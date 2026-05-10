#include "Matrix.h"

int Matrix::m_count = 1;

Matrix::Matrix()
{
	this->m_name = "Matrix " + to_string(m_count++);
	this->m_rows = 0;
	this->m_cols = 0;
}
Matrix::Matrix(int rows, int cols)
{
	try
	{
		if (rows < 0)
		{
			throw rows;
		}
		if (cols < 0)
		{
			throw cols;
		}
	}
	catch (int invalidValue)
	{
		cout << "Wrong size " << invalidValue << endl;
		exit(810);
	}

	m_name = "Matrix " + to_string(m_count++);
	if (rows == 0 || cols == 0)
	{
		m_rows = 0;
		m_cols = 0;
		return;
	}
	m_rows = rows;
	m_cols = cols;

	vector <double> temp;
	m_matrix.resize(rows, temp);

	for (int i = 0; i < rows; ++i)
	{
		m_matrix[i].resize(cols, 0);
	}
}
Matrix::Matrix(Matrix& another_matrix)
{
	this->m_name = "Matrix " + to_string(m_count++);
	this->m_rows = another_matrix.m_rows;
	this->m_cols = another_matrix.m_cols;
	this->m_matrix = another_matrix.m_matrix;
}
Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
	{
		m_matrix[i].clear();
	}
	m_matrix.clear();
}

vector<double>& Matrix::operator[](int index)
{
	try
	{
		if (index < 0 || index >= m_rows)
		{
			throw index;
		}

		return m_matrix[index];
	}
	catch (int)
	{
		cerr << "Index: " << index << "is out of range!" << endl;
		exit(900);
	}
}

bool Matrix::is_compatible_width(const Matrix& another_matrix)
{
	return m_cols == another_matrix.m_rows;
}
Matrix Matrix::operator*(const Matrix& another_matrix)
{
	if (!is_compatible_width(another_matrix))
	{
		cerr << "Can't multiply these matrixes (wrong size)!" << endl;
		exit(809);
	}

	Matrix result(m_rows, another_matrix.m_cols);

	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < another_matrix.m_cols; ++j)
		{
			for (int k = 0; k < m_cols; ++k)
			{
				result.m_matrix[i][j] += m_matrix[i][k] * another_matrix.m_matrix[k][j];
			}
		}
	}

	return result;
}

void Matrix::fill_random()
{
	srand(time(NULL));
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_matrix[i][j] = rand() % 100;
		}
	}
}
void Matrix::fill_keyboard()
{
	for (int i = 0; i < m_rows; ++i)
	{
		cout << "Enter " << m_cols << " numbers of #" << i << " row: ";
		for (int j = 0; j < m_cols; ++j)
		{
			cin >> m_matrix[i][j];
		}
	}
	cout << endl;
}
void Matrix::fill_identity()
{
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			if (i == j)
			{
				m_matrix[i][j] = 1;
			}
			else
			{
				m_matrix[i][j] = 0;
			}
		}
	}
}

int Matrix::get_rows()
{
	return m_rows;
}
int Matrix::get_cols()
{
	return m_cols;
}
Matrix Matrix::get_transposed()
{
	Matrix result(m_cols, m_rows);
	for (int i = 0; i < m_cols; ++i)
	{
		for (int j = 0; j < m_rows; ++j)
		{
			result.m_matrix[i][j] = m_matrix[j][i];
		}
	}

	return result;
}
void Matrix::print()
{
	cout << *this;
}

ostream& operator<<(ostream& out, const Matrix& matrix_to_out)
{
	out << matrix_to_out.m_name << " (" << matrix_to_out.m_rows << "x" << matrix_to_out.m_cols << ")" << endl;

	if (matrix_to_out.m_rows == 0 && matrix_to_out.m_cols == 0)
	{
		out << "|| ||" << endl;

		return out;
	}
	else
	{
		for (int i = 0; i < matrix_to_out.m_rows; ++i)
		{
			out << "||";
			for (int j = 0; j < matrix_to_out.m_cols; ++j)
			{
				out << setw(SPACING) << setprecision(8) << ((abs(matrix_to_out.m_matrix[i][j]) < 0.0005) ? 0.0 : matrix_to_out.m_matrix[i][j]);
			}

			for (int k = 0; k < SPACING - 1; ++k)
			{
				out << " ";
			}
			out << "||" << endl;
		}

		return out;
	}
}
istream& operator>>(istream& in, Matrix& matrix_to_in)
{
	int rows;
	int cols;

	try
	{
		cout << endl << "Enter rows: ";
		cin >> rows;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Enter correct rows: ";
			cin >> rows;
		}
		cin.ignore();
		cout << "Enter cols: ";
		cin >> cols;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Enter correct cols: ";
			cin >> cols;
		}
		cin.ignore();
		if (rows < 0)
		{
			throw rows;
		}
		if (cols < 0)
		{
			throw cols;
		}	
	}
	catch (int)
	{
		cerr << "Wrong size " << rows << "x" << cols << endl;
		exit(800);
	}

	if (rows == 0 or cols == 0)
	{
		for (int i = 0; i < matrix_to_in.m_rows; ++i)
		{
			matrix_to_in.m_matrix[i].clear();
		}

		matrix_to_in.m_matrix.clear();
		matrix_to_in.m_rows = 0;
		matrix_to_in.m_cols = 0;

		return in;
	}
	else
	{
		vector <double> temp;

		matrix_to_in.m_rows = rows;
		matrix_to_in.m_cols = cols;
		matrix_to_in.m_matrix.resize(rows, temp);

		for (int i = 0; i < rows; ++i)
		{
			matrix_to_in.m_matrix[i].resize(cols, 0);
		}

		for (int i = 0; i < matrix_to_in.m_rows; ++i)
		{
			cout << "Please enter " << matrix_to_in.m_cols << " numbers of #" << i << " row: ";
			for (int j = 0; j < matrix_to_in.m_cols; ++j)
			{
				cin >> matrix_to_in.m_matrix[i][j];

				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Please, enter correct number: ";
					cin >> matrix_to_in.m_matrix[i][j];
				}
				cin.ignore();
			}
		}
	}

	cout << endl;

	return in;
}