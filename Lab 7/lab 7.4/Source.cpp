#include<iostream>
#define max_for_count_of_simbols 1000

using namespace std;

template<class Type>
struct Node
{
	Type data;
	int count;
	Node* next_node;
};

template<class Type>
void find_equal_for_key(Node<Type>* head, Type key, Node<Type>*& previous_node)
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
void find_more_than_key(Node<Type>* head, Type key, Node<Type>*& previous_node)
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
void push(Node<Type>*& head, Type key)
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
			find_equal_for_key(head, key, previous_node);

			if (previous_node->next_node != nullptr)
			{
				previous_node->next_node->count++;
			}

			else
			{
				find_more_than_key(head, key, previous_node);

				new_node->next_node = previous_node->next_node;
				previous_node->next_node = new_node;
			}
		}
	}
}

template<class Type>
void show(Node<Type>* head)
{
	cout << "Your list: " << endl;
	while (head)
	{
		cout << head->data << "-" << head->count << "  ";
		head = head->next_node;
	}
	cout << endl;
}

template<class Type>
void delete_node(Node<Type>*& head, Type key)
{
	Node<Type>* current_node;
	Node<Type>* previous_node;

	find_equal_for_key(head, key, previous_node);
	current_node = previous_node->next_node;

	if (current_node)
	{
		if (head->data == key)
		{
			head = head->next_node;
		}
		else
		{
			previous_node->next_node = current_node->next_node;
		}

		delete current_node;
	}
}

template<class Type>
void Result(Node<Type>* head, Node<Type>*& result)
{
	while (head)
	{
		if (head->count == 2)
		{
			push(result, head->data);
		}
		head = head->next_node;
	}
}

int Input(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter n: ";
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter n: ";
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
char Generation_of_simbol()
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

int main()
{
	Node<char>* head = nullptr;
	Node<char>* result = nullptr;

	int count_of_simbols = 0;
	count_of_simbols = Input(max_for_count_of_simbols);

	for (int i = 0; i < count_of_simbols; ++i)
	{
		char simbol = Generation_of_simbol();
		push(head, simbol);
	}
	show(head);

	Result(head, result);
	show(result);

	return 0;
}