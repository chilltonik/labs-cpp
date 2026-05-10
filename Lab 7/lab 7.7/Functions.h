#pragma once
#include <iostream>
#include <ctime>
using namespace std;

int input_value(int max);
void fill_arr(int*& arr, int size);
void print_arr(int* arr, int size);

struct tree;

tree* search_position(tree* head, int d);
tree* find_position(tree* head, int d);

void add(tree*& head, int d);
void fill_tree(tree*& head, int array[], int size);
void print_tree(tree* head);
void print_tree_level(tree* head, int level);
void del_tree(tree*& head);

void find_and_delete_min(tree*& head);