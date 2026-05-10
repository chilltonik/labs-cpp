#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fill_str(vector<char>& str, int& size);
template<class T>
void show_str(vector<T>& str, int size)
{
	cout << "Your str:" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << str[i];
	}
	cout << endl;
}
void Getting_Array_Of_Words(vector<char>& str, vector<vector<char>>& Array_Of_Words, int& Number_Of_Word, int Count_Of_Words, int begin, int end);
bool& Comparing_arrays(vector<int>& Arr1, vector<int>& Arr2, bool& equal);
bool Comparison(vector<char>& s1, vector<char>& s2, bool& BooleanResult);
int Getting_Count_Of_Words(vector<char>& str, vector<char>& seporator);
int& Getting_token(vector<char>& str, vector<char>& seporator, int& begin, int& end, vector<vector<char>>& Array_Of_Words, int& Number_Of_Word, int Count_Of_Words);
void ShowArray(vector<vector<char>>& Array);
void Bool_Result(vector<vector<char>>& Array_Of_Words, vector<int>& Bool, int& NumberOfWord, int CountOfWords);
void Getting_Result(vector<char>& result, vector<char>& word, int& startpoz);