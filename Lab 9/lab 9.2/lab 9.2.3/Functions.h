#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <ctime>

#define max_value_for_generation 100
#define min_value_for_generation 0
#define max_for_values 100

using namespace std;

int Input_value(int max);

void fill_vector(vector<int>& arr);
void print_vector(vector<int>& arr);
int calculate_result_vector(vector<int>& arr);

void fill_list(list<int>& lst);
void print_list(list<int>& lst);
int calculate_result_list(list<int>& lst);
