/*
*Дан массив чисел произвольной длины. Отсортировать массив заданными методами:
- сортировкой выбором и обменом; + 
*Для тестирования программы заполнять массив значениями тремя способами:
- по возрастанию,+
- по убыванию,+
- случайным образом.+
*Каждый метод сортировки, каждый способ заполнения массивов оформить отдельными функциями. Функции оформить в виде отдельного файла. +
*Для каждого метода сортировки определить число сравнений и перемещений (перестановок с одного места на другое) элементов в процессе выполнения программы.+
*Сравнить экспериментальные результаты с известными теоретическими оценками этих показателей для заданных методов сортировки.+
*Обеспечить перегрузку и шаблоны необходимых функций для выполнения задания с типами элементов массивов char, int, float, double.+

														 Пастушенко Антон
*/
#include <iostream>
#include <ctime>
#include "Header.h"
//#include "Source1.cpp"
//#define TAB 8
//#define Rand 1.3

//using namespace std;

//void FillArray(int* arr, const int size);
//void FillArray(char* arr, const int size);
//void FillArray(double* arr, const int size);
//
//template<class TT>
//void ShowArray(TT* arr, const int size);
//
//template <class T1>
//void ChoiceIncrease(T1* arr, const int size, int& comparison, int& moving);
//template <class T2>
//void ChoiceWaning(T2* arr, const int size, int& comparison, int& moving);
//
//template <class T3>
//void BubbleIncrease(T3* arr, const int size, int& comparison, int& moving);
//template <class T4>
//void BubbleWaning(T4* arr, const int size, int& comparison, int& moving);

int main()
{
	srand(time(NULL));

	int size = 0;

	cout << "Enter size: ";
	cin >> size;

	int* ArrInt = new int[size];

	FillArray(ArrInt, size);
	ShowArray(ArrInt, size);

	int comparison = 0;
	int moving = 0;

	ChoiceIncrease(ArrInt, size, comparison, moving); 
	cout << "Comparisons: " << comparison << endl;
	cout << "Movings: " << moving << endl;
	ShowArray(ArrInt, size);

	int comparison1 = 0;
	int moving1 = 0;

	/*ChoiceWaning(ArrInt, size, comparison1, moving1);
	cout << "Comparisons: " << comparison1 << endl;
	cout << "Movings: " << moving1 << endl;
	ShowArray(ArrInt, size);*/

	int comparison2 = 0;
	int moving2 = 0;

	/*BubbleIncrease(ArrInt, size, comparison2, moving2);
	cout << "Comparisons: " << comparison2 << endl;
	cout << "Movings: " << moving2 << endl;
	ShowArray(ArrInt, size);*/

	int comparison3 = 0;
	int moving3 = 0;

	/*BubbleWaning(ArrInt, size, comparison3, moving3);
	cout << "Comparisons: " << comparison3 << endl;
	cout << "Movings: " << moving3 << endl;
	ShowArray(ArrInt, size);*/

	double* ArrDoub = new double[size];

	FillArray(ArrDoub, size);
	ShowArray(ArrDoub, size);

	int comparison4 = 0;
	int moving4 = 0;

	/*ChoiceIncrease(ArrDoub, size, comparison4, moving4);
	cout << "Comparisons: " << comparison4 << endl;
	cout << "Movings: " << moving4 << endl;
	ShowArray(ArrDoub, size);*/

	int comparison5 = 0;
	int moving5 = 0;

	/*ChoiceWaning(ArrDoub, size, comparison5, moving5);
	cout << "Comparisons: " << comparison5 << endl;
	cout << "Movings: " << moving5 << endl;
	ShowArray(ArrDoub, size);*/

	int comparison6 = 0;
	int moving6 = 0;

	/*BubbleIncrease(ArrDoub, size, comparison6, moving6);
	cout << "Comparisons: " << comparison6 << endl;
	cout << "Movings: " << moving6 << endl;
	ShowArray(ArrDoub, size);*/

	int comparison7 = 0;
	int moving7 = 0;

	/*BubbleWaning(ArrDoub, size, comparison7, moving7);
	cout << "Comparisons: " << comparison7 << endl;
	cout << "Movings: " << moving7 << endl;
	ShowArray(ArrDoub, size);*/

	char* ArrChar = new char[size];

	FillArray(ArrChar, size);
	ShowArray(ArrChar, size);

	int comparison8 = 0;
	int moving8 = 0;

	/*ChoiceIncrease(ArrChar, size, comparison8, moving8);
	cout << "Comparisons: " << comparison8 << endl;
	cout << "Movings: " << moving8 << endl;
	ShowArray(ArrChar, size);*/

	int comparison9 = 0;
	int moving9 = 0;

	/*ChoiceWaning(ArrChar, size, comparison9, moving9);
	cout << "Comparisons: " << comparison9 << endl;
	cout << "Movings: " << moving9 << endl;
	ShowArray(ArrChar, size);*/

	int comparison10 = 0;
	int moving10 = 0;

	/*BubbleIncrease(ArrChar, size, comparison10, moving10);
	cout << "Comparisons: " << comparison10 << endl;
	cout << "Movings: " << moving10 << endl;
	ShowArray(ArrChar, size);*/

	int comparison11 = 0;
	int moving11 = 0;

	/*BubbleWaning(ArrChar, size, comparison11, moving11);
	cout << "Comparisons: " << comparison11 << endl;
	cout << "Movings: " << moving11 << endl;
	ShowArray(ArrChar, size);*/

	delete[] ArrChar;
	delete[] ArrDoub;
	delete[] ArrInt;
	return 0;
}