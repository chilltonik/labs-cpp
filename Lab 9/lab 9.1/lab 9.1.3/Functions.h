#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>

#define max_for_n 30
#define min_for_generation 1
#define max_for_generation 10

using namespace std;

int Input(int max);
void Fill(vector<vector<int>>& A);
void Show(vector<vector<int>>& A);
vector<vector<int>> Multiplication(vector<vector<int>>& A, vector<vector<int>>& B);
vector<vector<int>> Transpose(vector<vector<int>>& A);
void Fill2(vector<int>& A);
void Show2(vector<int>& A);
vector<int> Multiplication2(vector<int>& A, vector<int>& B);
vector<int> Transpose2(vector<int>& A);