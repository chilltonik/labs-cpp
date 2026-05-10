/*
* Создать связанную структуру данных – список. 
Разработать функции для выполнения базовых операций над линейными связанными структурами,
содержащими записи со сведениями о студентах: ФИО, дата рождения, курс, успеваемость. 
При добавлении элемента данных в список обеспечить упорядоченность по алфавиту фамилий. 
Оценить асимптотическую сложность алгоритма.

3. По исходному списку определить всех студентов, ФИО которых начинается на заданную букву. 
Сформировать список из этих студентов, удалив их из исходного списка.
*/
#include <iostream>
#include <string>
#define max_members_count 30

using namespace std;

struct data_of_birth
{
	int day;
	int month;
	int year;
};
struct Data
{
	string surname = "";
	string name = "";
	string fathername = "";
	data_of_birth birthday;
	int course;
	float progress;
};
struct List
{
	Data data;
	List* next_node;
};

template<class Type>
Type Input_value(Type max)
{
	Type test = 0;
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
string Input_name()
{
	string test = "";
	bool flag = true;
	bool invite = false;
	//getline(cin, test);
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your string: " << endl;
			//getline(cin, test);
			cin >> test;
		}

		int length = test.length();

		for (int i = 0; i < length; ++i)
		{
			if (test[i] >= 'A' && test[i] <= 'Z' || test[i] >= 'a' && test[i] <= 'z')
			{
				flag = false;
			}
			else
			{
				flag = true;
				invite = true;
				cout << "Your enter is not correct. Please try again..." << endl;
				break;
			}
		}
	}

	return test;
}
char Input_simbol()
{
	char simbol;
	bool flag = true;
	bool invite = false;
	cout << "Enter your simbol: ";
	cin >> simbol;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter your simbol: ";
			cin >> simbol;
		}

		if (simbol >= 'A' && simbol <= 'Z' || simbol >= 'a' && simbol <= 'z')
		{
			flag = false;
		}
		else
		{
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return simbol;
}

void find_equal_for_key(List* lst, char key, List*& previous_node)
{
	List* current_node = lst;
	previous_node = lst;

	while (current_node && current_node->data.surname[0] != key)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}
}
void delete_node(List*& lst, char key)
{
	List* current_node;
	List* previous_node;

	find_equal_for_key(lst, key, previous_node);
	current_node = previous_node->next_node;

	if (current_node)
	{
		if (lst->data.surname[0] == key)
		{
			lst = lst->next_node;
		}
		else
		{
			previous_node->next_node = current_node->next_node;
		}
		previous_node->next_node = current_node->next_node;

		//delete current_node;
	}
}
void find_more_than_key(List* lst, char key, List*& previous_node)
{
	List* current_node = lst;
	previous_node = lst;

	while (current_node && current_node->data.surname[0] <= key)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}
}

void push(List*& lst, Data persone)
{
	List* previous_node = nullptr;
	List* new_node = new List;

	new_node->data = persone;
	new_node->next_node = nullptr;

	if (!lst)
	{
		lst = new_node;
	}
	else
	{
		if (lst->data.surname[0] >= persone.surname[0])
		{
			new_node->next_node = lst;
			lst = new_node;
		}
		else
		{
			find_more_than_key(lst, persone.surname[0], previous_node);
			new_node->next_node = previous_node->next_node;
			previous_node->next_node = new_node;
		}
	}
}

Data create_persone()
{
	Data persone;

	cout << "\nEnter surname: ";
	persone.surname = Input_name();
	cout << "Enter name: ";
	persone.name = Input_name();
	cout << "Enter fathername: ";
	persone.fathername = Input_name();

	cout << "Enter birthday day: ";
	persone.birthday.day = Input_value(30);
	cout << "Enter birthday month: ";
	persone.birthday.month = Input_value(12);
	cout << "Enter birthday year: ";
	persone.birthday.year = Input_value(2021);

	cout << "Enter course: ";
	persone.course = Input_value(5);
	cout << "Enter progress: ";
	persone.progress = Input_value(10.0);

	return persone;
}

void show_persone(Data persone)
{
	cout << "|Surname: " << persone.surname;
	cout << " | Name: " << persone.name;
	cout << " | Fathername: " << persone.fathername;
	cout << " | Birthday: " << persone.birthday.day;
	cout << "." << persone.birthday.month;
	cout << "." << persone.birthday.year;
	cout << " | Course: " << persone.course;
	cout << " | Progress: " << persone.progress << "|"<< endl;
}
void show_list(List* lst)
{
	cout << "Your list: " << endl;
	while (lst)
	{
		show_persone(lst->data);
		lst = lst->next_node;
	}
}

void create_result_list(List*& lst1, List*& lst2, char simbol)
{
	while (lst1)
	{
		if (lst1->data.surname[0] == simbol)
		{
			push(lst2, lst1->data);
			delete_node(lst1, simbol);
		}
		lst1 = lst1->next_node;
	}
}

int main()
{
	List* lst1 = nullptr;

	int members_count = 0;
	cout << "Enter members_count: ";
	members_count = Input_value(max_members_count);

	for (int i = 0; i < members_count; ++i)
	{
		Data persone = create_persone();
		push(lst1, persone);
	}
	show_list(lst1);
	
	char simbol = Input_simbol();

	List* lst2 = nullptr;
	create_result_list(lst1, lst2, simbol);
	show_list(lst2);

	show_list(lst1);

	return 0;
}