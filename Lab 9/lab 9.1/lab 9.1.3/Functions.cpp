#include"Functions.h"

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
void Fill(vector<vector<int>>& A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			A[i][j] = rand() % (max_for_generation - min_for_generation) + min_for_generation;
		}
	}
}
void Show(vector<vector<int>>& A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A[i].size(); ++j)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}
vector<vector<int>> Multiplication(vector<vector<int>>& A, vector<vector<int>>& B)
{
	vector<vector<int>> Result;
	Result.assign(A.size(), vector<int>(B[0].size()));

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B[i].size(); ++j)
		{
			Result[i][j] = 0;
			for (int k = 0; k < A[j].size(); ++k)
			{
				Result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return Result;
}
vector<vector<int>> Transpose(vector<vector<int>>& A)
{
	vector<vector<int>> A_T;
	A_T.assign(A[0].size(), vector<int>(A.size()));

	for (int i = 0; i < A[0].size(); ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			A_T[i][j] = A[j][i];
		}
	}

	return A_T;
}
void Fill2(vector<int>& A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		A[i] = rand() % (max_for_generation - min_for_generation) + min_for_generation;
	}
}
void Show2(vector<int>& A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		if (i > 0 && i % static_cast<int>(sqrt(A.size())) == 0)
		{
			cout << endl;
		}
		cout << A[i] << "\t";
	}
	cout << endl;
}
vector<int> Transpose2(vector<int>& A)
{
	vector<int> A_T(A.size());

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < 1; ++j)
		{
			A_T[i + j] = A[j + i];
		}
	}

	return A_T;
}
vector<int> Multiplication2(vector<int>& A, vector<int>& B)
{
	vector<int> Result(A.size());

	for (int i = 0; i < static_cast<int>(sqrt(A.size())); ++i)
	{
		for (int j = 0; j < static_cast<int>(sqrt(B.size())); ++j)
		{
			Result[i * static_cast<int>(sqrt(B.size())) + j] = 0;
			//Result[i][j] = 0;
			for (int k = 0; k < static_cast<int>(sqrt(A.size())); ++k)
			{
				Result[i * static_cast<int>(sqrt(B.size())) + j] += A[i * static_cast<int>(sqrt(B.size())) + k] * B[k * static_cast<int>(sqrt(B.size())) + j];
				//Result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return Result;
}