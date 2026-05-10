#include"Functions.h"

int input_value(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter count: ";
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
void fill_arr(int*& arr, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		int value = 0;
		bool isHere = true;

		while (isHere == true)
		{
			value = rand() % (100 - 0) + 0;
			isHere = false;

			for (int j = 0; j < i; ++j)
			{
				if (value == arr[j])
				{
					isHere = true;
					break;
				}
			}
		}

		arr[i] = value;
	}
}
void print_arr(int* arr, int size)
{
	cout << "Your arr:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

struct tree
{
	int data;
	tree* left;
	tree* right;
};

tree* search_position(tree* head, int d)
{
	tree* current_node = head;
	tree* previous_node = head;

	while (current_node)
	{
		previous_node = current_node;
		if (d < current_node->data)
		{
			current_node = current_node->left;
		}
		else
		{
			current_node = current_node->right;
		}
	}

	return previous_node;
}
tree* find_position(tree* head, int d)
{
	if (!head)
	{
		return NULL;
	}

	tree* position;
	if (d < head->data)
	{
		position = find_position(head->left, d);
	}
	else
	{
		position = find_position(head->right, d);
	}

	return position ? position : head;
}

void add(tree*& head, int d)
{
	tree* new_node = new tree;
	new_node->data = d;

	new_node->left = nullptr;
	new_node->right = nullptr;

	if (!head)
	{
		head = new_node;
	}
	else
	{
		tree* previous_node;
		previous_node = search_position(head, d);//поиск для нового узла
		//previous_node = find_position(head, d);//поиск для нового узла рекурсивно
		if (d < previous_node->data)
		{
			previous_node->left = new_node;//присоединение к левому поддереву предка
		}
		else
		{
			previous_node->right = new_node;//присоединение к правому поддереву предка
		}
	}

}
void fill_tree(tree*& head, int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		add(head, array[i]);
	}
}
void print_tree(tree* head)
{
	if (head)
	{
		print_tree(head->left);//обход левого поддерева
		cout << head->data << "  ";
		print_tree(head->right);//обход правого поддерева
	}
}
void print_tree_level(tree* head, int level)
{
	if (head)
	{
		print_tree_level(head->left, level + 1);
		for (int i = 0; i < level; ++i)
		{
			cout << "   ";
		}
		cout << head->data << endl;
		print_tree_level(head->right, level + 1);
	}
}
void del_tree(tree*& head)
{
	if (head)
	{
		del_tree(head->left);
		del_tree(head->right);
		delete head;
		head = nullptr;
	}
}

void find_and_delete_min(tree*& head)
{
	tree* current = head;
	tree* previous = head;

	while (current->left != nullptr)
	{
		previous = current;
		current = current->left;
	}
	previous->left = nullptr;
	delete current;
}