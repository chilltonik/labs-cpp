/*
7.6. ДВУСВЯЗНЫЕ СПИСКИ КАК ДИНАМИЧЕСКИЕ СТРУКТУРЫ ДАННЫХ
Выполнить задания, используя двусвязные динамические структуры данных в
виде связных компонент. Оценить асимптотическую сложность алгоритма.

3. Даны натуральное число n, действительные числа x1, x2, ... xn. Разработать про-
грамму вычисления значения выражения следующего вида:
(x1 + x2 + nxn ) + (x2 + x3 + (n −1)xn−1 ) + ...+ (xn−1 + xn + 2x2 ) .
*/
#include<iostream>
#include<ctime>

#define max_value_for_generation 100
#define min_value_for_generation 0
#define max_for_values 100

using namespace std;

struct Node
{
	int data;
	Node* next_node;
	Node* previous_node;
};

int Input_value(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter value: ";
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
int generation_values()
{
	return rand() % (max_value_for_generation - min_value_for_generation) + min_value_for_generation;
}

void push_back(Node*& head, Node*& end, int key, int& size)
{
	Node* new_node = new Node;

	new_node->data = key;
	new_node->next_node = nullptr;
	new_node->previous_node = nullptr;

	if (head == nullptr)
	{
		head = new_node;
		end = new_node;
	}
	else
	{
		end->next_node = new_node;
		new_node->previous_node = end;
		end = new_node;
	}

	size++;
}

int calculate_result(Node*& head, Node*& end, int size)
{
	int result = 0;

	Node* copy_end = end;

	while (head != copy_end)
	{
		result += head->data + head->next_node->data + size * end->data;
		head = head->next_node;
		end = end->previous_node;

		size--;
	}

	return result;
}

void fill_list(Node*& head, Node*& end, int values_count, int& size)
{
	for (int i = 0; i < values_count; ++i)
	{
		int value = generation_values();
		push_back(head, end, value, size);
	}
}
void show(Node* head)
{
	cout << "Your list: " << endl;

	Node* current_node = head;
	while (current_node != nullptr)
	{
		cout << current_node->data << "  ";
		current_node = current_node->next_node;
	}
	cout << endl;
}
void show2(Node* end)
{
	cout << "Your list: " << endl;

	Node* current_node = end;
	while (current_node != nullptr)
	{
		cout << current_node->data << "  ";
		current_node = current_node->previous_node;
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	Node* head = nullptr;
	Node* end = nullptr;

	int size = 0;
	int values_count = 0;
	cout << "Enter count_values: ";
	values_count = Input_value(max_for_values);

	fill_list(head, end, values_count, size);
	show(head);
	show2(end);
	cout << "size: " << size << endl;

	int result = -1;
	result = calculate_result(head, end, size);
	cout << "Result: " << result << endl;
	
	return 0;
}