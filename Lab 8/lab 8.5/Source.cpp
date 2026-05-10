/*
* Объявить шаблон класса «Двусвязный линейный список». Определить структуру класса и его методы.
В классе должен быть конструктор по умолчанию, конструктор с формальными параметрами, конструктор копирования и деструктор.

Определить методы:
• инициализация первого элемента структуры; +
• запись в структуру нового элемента; +
• удаление элемента; +
• поиск элемента по заданному ключу поиска (значению информационного поля); +
• вывод элементов списка на экран; +
• удаления всех элементов списка. +

Используя объекты класса «Двусвязный линейный список», реализовать алгоритм своего варианта задания 7.6.

3. Даны натуральное число n, действительные числа x1, x2, ... xn. Разработать про-
грамму вычисления значения выражения следующего вида:
(x1 + x2 + nxn ) + (x2 + x3 + (n −1)xn−1 ) + ...+ (xn−1 + xn + 2x2 ) .

*/

#include <iostream>
#include<ctime>

#define max_value_for_generation 100
#define min_value_for_generation 0
#define max_for_values 100

using namespace std;

int input_value(int max)
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

template<class Type>
class List 
{
private:
	template<class Type>
	class Node
	{
	public:
		Type data;
		Node* next_node;
		Node* previous_node;

		Node(Type data = Type(), Node* next_node = nullptr, Node* previous_node = nullptr)
		{
			this->data = data;
			this->next_node = next_node;
			this->previous_node = previous_node;
		}
	};

	int size;
	Node<Type>* head;
	Node<Type>* end;

public:
	List();
	~List();

	void push_back(Type data);
	void push_front(Type data);

	void pop_back();
	void pop_front();

	void fill_list(int values_count);
	void clear();
	
	void insert(Type data, int index);
	void removeAt(int index);

	void find_equal(Type key, Node<Type>*& previous_node);
	int calculate_result();

	void show();
	void show2();

	int get_size() { return size; };
};

int main()
{
	srand(time(NULL));

	List<int> lst;

	int values_count = 0;
	cout << "Enter count_values: ";
	values_count = input_value(max_for_values);

	lst.fill_list(values_count);
	lst.show();

	int result = lst.calculate_result();
	cout << "Result: " << result << endl;

	return 0;
}

template<class Type>
List<Type>::List()
{
	size = 0;
	head = nullptr;
	end = nullptr;
}

template<class Type>
List<Type>::~List()
{
	clear();
}

template<class Type>
void List<Type>::push_back(Type data)
{
	Node<Type>* new_node = new Node<Type>;

	new_node->data = data;
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

template<class Type>
void List<Type>::push_front(Type data)
{
	Node<Type>* new_node = new Node<Type>;
	new_node->data = data;
	new_node->next_node = nullptr;

	new_node->next_node = head;
	head = new_node;

	size++;
}

template<class Type>
void List<Type>::pop_back()
{
	Node<Type>* temp = end;
	end = end->previous_node;
	end->next_node = nullptr;
	delete temp;
	size--;
}

template<class Type>
void List<Type>::pop_front()
{
	Node<Type>* temp = head;
	head = head->next_node;

	delete temp;
	size--;
}

template<class Type>
void List<Type>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<class Type>
void List<Type>::insert(Type data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<Type>* previous_node = head;

		for (int i = 0; i < index - 1; ++i)
		{
			previous_node = previous_node->next_node;
		}

		Node<Type>* new_node = new Node<Type>(data, previous_node->next_node);
		previous_node->next_node = new_node;
		size++;
	}
}

template<class Type>
void List<Type>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<Type>* previous_node = head;

		for (int i = 0; i < index - 1; ++i)
		{
			previous_node = previous_node->next_node;
		}

		Node<Type>* toDelete = previous_node->next_node;
		previous_node->next_node = toDelete->next_node;
		delete toDelete;

		size--;
	}
}

template<class Type>
void List<Type>::fill_list(int values_count)
{
	for (int i = 0; i < values_count; ++i)
	{
		int value = generation_values();
		push_back(value);
	}
}

template<class Type>
void List<Type>::find_equal(Type key, Node<Type>*& previous_node)
{
	Node<Type>* current_node = head;
	previous_node = head;

	while (current_node && current_node->data != key)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}
}

template<class Type>
int List<Type>::calculate_result()
{
	int result = 0;

	Node<Type>* copy_end = end;

	while (head != copy_end)
	{
		result += head->data + head->next_node->data + size * end->data;
		head = head->next_node;
		end = end->previous_node;

		size--;
	}

	return result;
}

template<class Type>
void List<Type>::show()
{
	cout << "Your list: " << endl;

	Node<Type>* current_node = head;
	while (current_node != nullptr)
	{
		cout << current_node->data << "  ";
		current_node = current_node->next_node;
	}
	cout << endl;
}

template<class Type>
void List<Type>::show2()
{
	cout << "Your list: " << endl;

	Node<Type>* current_node = end;
	while (current_node != nullptr)
	{
		cout << current_node->data << "  ";
		current_node = current_node->previous_node;
	}
	cout << endl;
}
