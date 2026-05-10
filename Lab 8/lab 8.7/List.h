#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
class Node_list
{
public:
	Node_list* pNext;
	T data;
	Node_list(T data = T(), Node_list* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class List
{
public:
	int Size;
	Node_list<T>* head;

	List();
	~List();

	void pop_front();
	void pop_back();

	void push_back(T data);
	void push_front(T data);

	void clear();
	int GetSize() { return Size; }
	T& operator[](const int index);

	void insert(T value, int index);
	void removeAt(int index);

	bool is_exist(T data);
	void remove(T data);
	void output();
};

template<typename T>
List<T> ::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T> :: ~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node_list<T>* temp = head;

	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node_list<T>(data);
	}
	else
	{
		Node_list<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node_list<T>(data);
	}
	Size++;
}
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node_list<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node_list<T>* previous = this->head;
		for (int i = 0; i < index - 1; ++i)
		{
			previous = previous->pNext;
		}

		Node_list<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
bool List<T>::is_exist(T data)
{
	Node_list<T>* current = head;
	while (current)
	{
		if (current->data == data)
		{
			return true;
		}
		current = current->pNext;
	}

	return false;
}
template<typename T>
void List<T>::remove(T data)
{
	if (!head)
	{
		return;
	}

	Node_list<T>* current = head;
	Node_list<T>* previous = head;
	while (current && current->data != data)
	{
		previous = current;
		current = current->pNext;
	}

	if (previous == head && head->data == data)
	{
		head = head->pNext;
		delete previous;
		Size--;
		return;
	}

	current = previous->pNext;
	if (!current)
	{
		return;
	}

	previous->pNext = current->pNext;
	delete current;
	Size--;
}

template<typename T>
void List<T>::output()
{
	Node_list<T>* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->pNext;
	}
	cout << endl;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node_list<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node_list<T>* previous = this->head;

		for (int i = 0; i < index - 1; ++i)
		{
			previous = previous->pNext;
		}

		Node_list<T>* newNode = new Node_list<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}