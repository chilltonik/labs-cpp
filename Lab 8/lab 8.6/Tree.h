#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

template <class T>
void enter(istream& in, T& data)
{
	while (true)
	{
		in >> data;

		if (in.fail())
		{
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else
		{
			break;
		}
	}
}

int input_value(int max);
void fill_arr(int*& arr, int size);
void print_arr(int* arr, int size);

template <class T>
class Tree
{
private:
	template <class T>
	class Node
	{
	public:
		T data;
		Node<T>* left;
		Node<T>* right;

		//Конструктор узла
		Node(T data = T(), Node<T>* left = nullptr, Node<T>* right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

	int size;
	Node<T>* head;

	Node<T>* find_push(Node<T>* top, T data);//Найти узел для вставки
	Node<T>* search_key(Node<T>* top, T data);//Найти узел по ключу
	void copy_tree(const Node<T>* top);//Копировать узел
	void deleteTree(Node<T>* top);//Удалить узлы дерева
	void outL(Node<T>* top);//Вывести левые узлы (меньшие, потом большие)
	void outR(Node<T>* top);//Вывести правые узлы (большие, потом меньшие)

	void find_and_delete_min(Node<T>* top);//Найти у удалить узел с минимальным значением элементов.

public:
	Tree();//Конструктор без параметров
	Tree(int size, T data);//Конструктор с параметрами
	Tree(const Tree<T>& tree);//Конструктор копирования

	~Tree();//Деструктор

	//Оператор для копирования
	Tree& operator =(const Tree& tree)
	{
		if (&tree != this)
		{
			clear();
			copy_tree(tree.head);
		}
		return *this;
	}

	void input(T arr[], int n);//Заполнение дерева
	void push(T data);//Вставка
	Node<T>* search_data(T data);//Найти данные по ключу
	void clear();//Очистить
	void output_left();//Вывести от меньшего к большему
	void output_right();//Вывести от большего к меньшему
	int get_size() const;

	void find_and_delete();//Удалить вершину с минимальным значением элементов.
};

template<class T>
Tree<T>::Tree()
{
	this->size = 0;
	this->head = nullptr;
}

template<class T>
Tree<T>::Tree(int size, T data)
{
	this->size = size;
	this->head = nullptr;

	for (int i = 0; i < size; ++i)
	{
		push(data);
	}
}

template<class T>
Tree<T>::Tree(const Tree<T>& tree)
{
	size = 0;
	head = nullptr;
	copy_tree(tree.head);
}

template<class T>
Tree<T>::~Tree()
{
	clear();
}

template<class T>
void Tree<T>::input(T arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		T data = arr[i];
		push(data);
	}
}

template<class T>
Tree<T>::Node<T>* Tree<T>::find_push(Tree<T>::Node<T>* top, T data)
{
	if (!top)
	{
		return nullptr;
	}

	Node<T>* element = nullptr;
	if (data < top->data)
	{
		element = find_push(top->left, data);
	}
	else
	{
		element = find_push(top->right, data);
	}

	return element ? element : top;
}

template<class T>
void Tree<T>::push(T data)
{
	if (!size)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* element = find_push(head, data);

		if (data < element->data)
		{
			element->left = new Node<T>(data);
		}
		else
		{
			element->right = new Node<T>(data);
		}
	}

	size++;
}

template<class T>
void Tree<T>::copy_tree(const Node<T>* top)
{
	if (top)
	{
		push(top->data);
		copy_tree(top->left);
		copy_tree(top->right);
	}
}

template<class T>
Tree<T>::Node<T>* Tree<T>::search_key(Node<T>* top, T data)
{
	if (top)
	{
		if (top->data == data)
		{
			return top;
		}
		if (top->data > data)
		{
			return search_key(top->left, data);
		}
		else
		{
			return search_key(top->right, data);
		}
	}
	else
	{
		return nullptr;
	}
}

template <class T>
Tree<T>::Node<T>* Tree<T>::search_data(T data)
{
	if (head)
	{
		if (head->data == data) 
		{
			return head;
		}
		if (head->data > data) 
		{
			return search_key(head->left, data);
		}
		else 
		{
			return search_key(head->right, data);
		}
	}
	else 
	{
		return nullptr;
	}
}

template<class T>
void Tree<T>::deleteTree(Node<T>* top)
{
	if (top)
	{
		deleteTree(top->left);
		deleteTree(top->right);
		delete top;
		top = nullptr;
	}
}

template<class T>
void Tree<T>::clear()
{
	if (head)
	{
		deleteTree(head->left);
		deleteTree(head->right);
		delete head;
		head = nullptr;
		size = 0;
	}
}

template<class T>
void Tree<T>::outL(Node<T>* top)
{
	if (top)
	{
		outL(top->left);
		cout << top->data << " ";
		outL(top->right);
	}
}

template<class T>
void Tree<T>::output_left()
{
	cout << "Your tree: " << endl;
	if (head)
	{
		outL(head->left);
		cout << head->data << " ";
		outL(head->right);
	}
	cout << endl;
}

template <class T>
void Tree<T>::outR(Node<T>* top)
{
	if (top)
	{
		outR(top->right);
		cout << top->data << " ";
		outR(top->left);
	}
}

template <class T>
void Tree<T>::output_right()
{
	cout << "Your tree: " << endl;
	if (head)
	{
		outR(head->right);
		cout << head->data << " ";
		outR(head->left);
	}
	cout << endl;
}

template <class T>
int Tree<T>::get_size() const
{
	return this->size;
}

template<class T>
void Tree<T>::find_and_delete_min(Node<T>* top)
{
	Node<T>* current = top;
	Node<T>* previous = top;

	while (current->left != nullptr)
	{
		previous = current;
		current = current->left;
	}
	previous->left = nullptr;
	delete current;
}

template<class T>
void Tree<T>::find_and_delete()
{
	find_and_delete_min(head);
}