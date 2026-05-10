/*
	односв€зный список. –еализаци€ через классы методов:
	- ”даление из начала списка.
	- ¬ставка в конец списка.
	- ”даление списка.
	- –азмер списка.
	- ¬ставка в начало списка.
	- ¬ставка в произвольную позицию списка.
	- ”даление произвольного узла списка.
	- ”далене последнего узла списка.

	ќбъ€вить шаблон класса ЂЋинейный списокї. ќпределить структуру класса и его методы.
	¬ классе должен быть конструктор по умолчанию, конструктор с формальными параметрами,
	конструктор копировани€ и деструктор.

ќпределить методы:
Х инициализаци€ первого элемента структуры; +
Х добавлени€ в структуру нового элемента; +
Х удаление элемента; +
Х поиск элемента по заданному ключу поиска (значению информационного пол€); +
Х вывод элементов списка на экран; +
Х удалени€ списка. +
»спользу€ объекты класса ЂЋинейный списокї, реализовать алгоритмы своих вариантов заданий 7.4.+

3. ќписать функцию, котора€ формирует список символов L2, включив в него те символы из L1, которые вход€т в него ровно два раза.+
*/
#include <iostream>
#include <string>
#include <ctime>
#define max_for_int 100
#define min_for_int 0
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
char generation_of_simbol()
{
	char simbol;
	bool selector = false;

	selector = rand() % 2;

	if (selector == false)
	{
		simbol = rand() % ('z' - 'a') + 'a';
	}
	else
	{
		simbol = rand() % ('Z' - 'A') + 'A';
	}

	return simbol;
}
int generation_of_values()
{
	return rand() % (max_for_int - min_for_int) + min_for_int;
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
		Node<Type>* next_node;
		int count;

		Node(Type data = Type(), Node* next_node = nullptr)
		{
			this->data = data;
			this->next_node = next_node;
			this->count = 1;
		}
	};

	int size;
	Node<Type>* head;

	void find_equal(Type key, Node<Type>*& previous_node);//+
	void find_more_than_key(Type key, Node<Type>*& previous_node);//+

public:
	List();//+
	~List();//+

	void push_back(Type data);//+
	void push_front(Type data);//+

	void pop_back();//+
	void pop_front();//+

	void insert(Type data, int index);
	void removeAt(int index);

	void push(Type key);//+
	void make_result(List<Type>* lst);//+

	void fill_list(int values_count);//+
	void clear();//+
	void show();//+
	int get_size() { return size; };//+
};

int main()
{
	srand(time(NULL));

	List<char> lst;

	cout << "Enter values_count: ";
	int values_count = input_value(max_for_values);
	lst.fill_list(values_count);

	lst.show();

	List<char> result;
	result.make_result(&lst);
	result.show();

	return 0;
}

template<class Type>
List<Type>::List()
{
	size = 0;
	head = nullptr;
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

	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Node<Type>* current_node = head;
		while (current_node->next_node != nullptr)
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = new_node;
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
	Node<Type>* current_node = head;
	Node<Type>* previous_node = head;

	while (current_node->next_node != nullptr)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}

	previous_node->next_node = nullptr;
	delete current_node;

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
void List<Type>::find_more_than_key(Type key, Node<Type>*& previous_node)
{
	Node<Type>* current_node = head;
	previous_node = head;

	while (current_node && current_node->data <= key)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}
}

template<class Type>
void List<Type>::push(Type key)
{
	Node<Type>* previous_node = nullptr;
	Node<Type>* new_node = new Node<Type>;

	new_node->data = key;
	new_node->count = 1;
	new_node->next_node = nullptr;

	if (!head)
	{
		head = new_node;
	}
	else
	{
		if (head->data >= key)
		{
			if (head->data > key)
			{
				new_node->next_node = head;
				head = new_node;
			}
			else
			{
				head->count++;
			}
		}
		else
		{
			find_equal(key, previous_node);

			if (previous_node->next_node != nullptr)
			{
				previous_node->next_node->count++;
			}

			else
			{
				find_more_than_key(key, previous_node);

				new_node->next_node = previous_node->next_node;
				previous_node->next_node = new_node;
			}
		}
	}
}

template<class Type>
void List<Type>::make_result(List<Type>* lst)
{
	Node<Type>* current_node = lst->head;
	while (current_node)
	{
		if (current_node->count == 2)
		{
			push_back(current_node->data);
		}
		current_node = current_node->next_node;
	}
}

template<class Type>
void List<Type>::fill_list(int values_count)
{
	for (int i = 0; i < values_count; ++i)
	{
		char simbol = generation_of_simbol();
		push(simbol);
	}
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
void List<Type>::show()
{
	cout << "Your list: " << endl;

	Node<Type>* current_node = head;
	while (current_node != nullptr)
	{
		cout << current_node->data << "-" << current_node->count << "  ";
		current_node = current_node->next_node;
	}
	cout << endl;
}
