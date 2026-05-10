/*
* Выполнить задание, используя динамическое выделение памяти для двумерного массива, двумя способами:
• описывая двумерный массив как одномерный, с расчетом смещения элемента массива по линейной формуле;
• описывая двумерный массив как указатель на массив указателей.+

3. Дана вещественная квадратная матрица А порядка n, вектор b с n элементами.
Составить функцию, которая позволяет получить вектор c = А^2 * b .
*/
#include"Functions.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
	srand(time(NULL));

	int n = 0;
	n = Input(max_for_n);

	int** A = Inizialization(n, n);
	Fill(A, n, n);
	cout << "A: " << endl;
	Show(A, n, n);

	int** b = Inizialization(n);
	Fill(b, n);
	cout << "\nVector b:" << endl;
	Show(b, n);

	int** A_2 = Inizialization(n, n);
	A_2 = Multiplication(A, A, n, n, n, n);
	cout << "\nA^2: " << endl;
	Show(A_2, n, n);

	int** b_T = Inizialization(1, n);
	b_T = Transpose(b, 1, n);
	//cout << "\nVector b^T:" << endl;
	//Show(b_T, 1, n);

	int** c = Inizialization(1, n);
	c = Multiplication(A_2, b_T, n, n, n, 1);
	//cout << "\nVector c:" << endl;
	//Show(c, 1, n);

	int** с_T = Inizialization(n, 1);
	с_T = Transpose(c, n, 1);
	cout << "\nVector c:" << endl;
	Show(с_T, n, 1);

	Delete(A, n);
	Delete(b, 1);
	Delete(A_2, n);
	Delete(b_T, n);
	Delete(c, n);
	Delete(с_T, 1);
	//_______________________________________________________

	int* A2 = Inizialization2(n, n);
	Fill2(A2, n, n);
	cout << "\nA2: " << endl;
	Show2(A2, n, n);

	int* b2 = Inizialization2(n);
	Fill2(b2, n);
	cout << "\nVector b2:" << endl;
	Show2(b2, n);

	int* A2_2 = Inizialization2(n, n);
	A2_2 = Multiplication2(A2, A2, n, n, n, n);
	cout << "\nA2^2: " << endl;
	Show2(A2_2, n, n);

	int* b2_T = Inizialization2(1, n);
	b2_T = Transpose2(b2, 1, n);
	//cout << "\nVector b2^T:" << endl;
	//Show2(b2_T, 1, n);

	int* c2 = Inizialization2(1, n);
	c2 = Multiplication2(A2_2, b2_T, n, n, n, 1);
	//cout << "\nVector c2:" << endl;
	//Show2(c2, 1, n);

	int* c2_T = Inizialization2(n);
	c2_T = Transpose2(c2, 1, n);
	cout << "\nVector c2:" << endl;
	Show2(c2_T, n, 1);

	delete[] A2;
	delete[] b2;
	delete[] A2_2;
	delete[] b2_T;
	delete[] c2;

	return 0;
}
