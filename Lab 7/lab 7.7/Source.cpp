/*
По заданной последовательности различных целых чисел построить соответствующее бинарное дерево поиска T как динамическую структуру данных.
Выполнить следующие задания и вывести элементы дерева на экран.
Оценить асимптотическую сложность алгоритма.

3. Удалить вершину с минимальным значением элементов.
*/
#include"Functions.h"

int main()
{
	const int max_for_size = 100;
	int size = input_value(max_for_size);

	int* arr = new int[size];
	fill_arr(arr, size);

	cout << "\nYour arr:" << endl;
	print_arr(arr, size);

	tree* head = nullptr;
	fill_tree(head, arr, size);

	cout << "\nYour tree:" << endl;
	print_tree(head);

	cout << "\nYour tree:" << endl;
	print_tree_level(head, 0);

	find_and_delete_min(head);
	cout << "Your tree:" << endl;
	print_tree_level(head, 0);

	return 0;
}