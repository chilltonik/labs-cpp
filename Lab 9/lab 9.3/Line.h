#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

static string twodigit = "<=>===!=&&";//строка наших операций

int string_to_int(string value);//переводим строку в инт
bool is_digit(char ch);//провера на циферку

class Line
{
private:
	vector<string> expression;//мое выражение
	stack<string> operation;//Храним операции в стеке
	stack<int> arguments;//Храним циферки в стеке

public:
	Line() {};
	Line(string line);//конструктор с параметром

	bool is_number(int i);//проверка на циферку
	bool is_logical(int i);//проверка на логический оператор
	bool is_brkt(int i);//проверка на скобочку

	void Convertation();//функция получения результата
	bool Operate(int& a, int& b, string& operat);//функция выполнения соответствующих операций
	bool Operate(int& a);//инвертирование переменной
	void COUT();//вывод
};