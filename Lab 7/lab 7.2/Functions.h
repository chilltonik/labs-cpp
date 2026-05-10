#include <iostream>
#include <ctime>
#define max_for_n 30
#define min_for_generation 1
#define max_for_generation 10

using namespace std;

int** Inizialization(int colls, int rows = 1);
void Delete(int** A, int n);
int Input(int max);
void Fill(int** A, int colls, int rows = 1);
void Show(int** A, int colls, int rows = 1);
int** Multiplication(int** A, int** B, int A_rows, int A_colls, int B_rows, int B_colls);
int** Transpose(int** A, int rows, int colls);

int* Inizialization2(int colls, int rows = 1);
void Fill2(int* A, int colls, int rows = 1);
void Show2(int* A, int colls, int rows = 1);
int* Transpose2(int* A, int rows, int colls);
int* Multiplication2(int* A, int* B, int A_rows, int A_colls, int B_rows, int B_colls);