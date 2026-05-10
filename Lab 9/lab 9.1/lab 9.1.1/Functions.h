#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

#define max_for_int 10000
#define min_for_int 0

using namespace std;

void Recording_in_file(ofstream& fout, int size);
void Fill_array(ifstream& fin, vector<int>& arr, vector<bool>& bool_arr);
int calculate_size(ifstream& fin, vector<bool>& bool_arr);