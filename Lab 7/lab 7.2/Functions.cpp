#include"Functions.h"

int** Inizialization(int colls, int rows)
{
	int** A = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		A[i] = new int[colls];
	}

	return A;
}
void Delete(int** A, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
	}
	delete[] A;
}
int Input(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter n: ";
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter n: ";
			cin >> test;
		}

		if (test >= 1 && test <= max)
		{
			flag = false;
		}
		else
		{
			flag = true;
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return test;
}
void Fill(int** A, int colls, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < colls; ++j)
		{
			A[i][j] = rand() % (max_for_generation - min_for_generation) + min_for_generation;
		}
	}
}
void Show(int** A, int colls, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < colls; ++j)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}
int** Multiplication(int** A, int** B, int A_rows, int A_colls, int B_rows, int B_colls)
{
	int** Result = Inizialization(B_colls, A_rows);

	for (int i = 0; i < A_rows; ++i)
	{
		for (int j = 0; j < B_colls; ++j)
		{
			Result[i][j] = 0;
			for (int k = 0; k < A_colls; ++k)
			{
				Result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return Result;
}
int** Transpose(int** A, int rows, int colls)
{
	int** A_T = Inizialization(rows, colls);

	for (int i = 0; i < colls; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			A_T[i][j] = A[j][i];
		}
	}

	return A_T;
}

int* Inizialization2(int colls, int rows)
{
	int* A = new int[rows * colls];

	return A;
}
void Fill2(int* A, int colls, int rows)
{
	for (int i = 0; i < colls * rows; ++i)
	{
		A[i] = rand() % (max_for_generation - min_for_generation) + min_for_generation;
	}
}
void Show2(int* A, int colls, int rows)
{
	for (int i = 0; i < colls * rows; ++i)
	{
		if (i > 0 && i % colls == 0)
		{
			cout << endl;
		}
		cout << A[i] << "\t";
	}
	cout << endl;
}
int* Transpose2(int* A, int rows, int colls)
{
	int* A_T = Inizialization2(rows, colls);

	for (int i = 0; i < colls; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			A_T[i * rows + j] = A[j * rows + i];
		}
	}

	return A_T;
}
int* Multiplication2(int* A, int* B, int A_rows, int A_colls, int B_rows, int B_colls)
{
	int* Result = Inizialization2(B_colls, A_rows);

	for (int i = 0; i < A_rows; ++i)
	{
		for (int j = 0; j < B_colls; ++j)
		{
			Result[i * B_colls + j] = 0;
			//Result[i][j] = 0;
			for (int k = 0; k < A_colls; ++k)
			{
				Result[i * B_colls + j] += A[i * B_colls + k] * B[k * B_colls + j];
				//Result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return Result;
}