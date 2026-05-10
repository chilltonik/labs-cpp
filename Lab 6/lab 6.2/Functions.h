#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>

#define min_count_rand 10
#define max_count_rand 30
#define min_rand_generation 0
#define max_rand_generation 50

using namespace std;

int Rand_even_size();
int Generation_even_value();
int Generation_not_even_value();

void Showfile(ifstream& infile, string name);

void Recording_in_file(bool FLAG_BIN, int& count_even, int& count_not_even, int max_even, int max_not_even, ofstream& fout);
void Recording_not_even_values(bool FLAG_BIN, int difference, ofstream& fout);
void Recording_even_values(bool FLAG_BIN, int difference, ofstream& fout);

void Recording_in_fileG_even(ifstream& finF_even, string even, ofstream& foutG, int& count_even);
void Recording_in_fileG_not_even(ifstream& finF_not_even, string not_even, ofstream& foutG, int& count_not_even);

void Recording_in_fileBinG_even(ifstream& finBinF_even, int Bin_even, ofstream& foutBinG, int& Bin_count_even);
void Recording_in_fileBinG_not_even(ifstream& finBinF_not_even, int Bin_not_even, ofstream& foutBinG, int& Bin_count_not_even);
