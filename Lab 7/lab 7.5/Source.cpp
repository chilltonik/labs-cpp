/*
	7.5. ЛИНЕЙНЫЕ СПИСКИ КАК МАССИВЫ ДАННЫХ
Выполнить задания 7.4, используя связанные динамические структуры данных в виде массивов. Оценить асимптотическую сложность алгоритма.

3. Описать функцию, которая формирует список символов L2, включив в него те символы из L1, которые входят в него ровно два раза.
*/
#include "functions.h"

int main() 
{
	cout << "Enter the number of L1 list's symbols:" << endl;
	cout << "N: ";
	int n = 0;
	enter(n);
	cout << endl;

	char* list1 = new char[n];
	int* p1 = new int[n];
	p1[0] = 0;

	char* list2 = new char[n];
	int* p2 = new int[n];
	p2[0] = 0;

	cout << "Enter symbols of L1 list:" << endl;

	input(list1, p1, n);
	cout << endl;
	createList(list1, list2, p1, p2);

	cout << "L2 list:" << endl;
	output(list2, p2);
	cout << endl;

	delete[] list1, p1;
	delete[] list2, p2;

	return 0;
}