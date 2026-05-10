#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#define max_for_array 250000
#define max_value_for_genertion 20
#define min_value_for_genertion 1

using namespace std;

int Integer();
void Show_array(int* arr, int size);
void Fill_array(ifstream& fin, int* arr, int size, bool* bool_arr, int bool_size);
void Recording_in_file(ofstream& fout, int size);