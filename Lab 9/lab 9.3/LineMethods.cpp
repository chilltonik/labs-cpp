#include"Line.h"

//переводим строку в инт
int string_to_int(string value)
{
	if (value == "true")
	{
		return 1;
	}
	if (value == "false")
	{
		return 0;
	}

	int result = 0;
	for (int i = value.size() - 1; i >= 0; --i)
	{
		result += (value[i] - '0') * pow(10, value.size() - 1 - i);//перевод в десятичное.
	}

	return result;
}
//проверка является на цифоркой
bool is_digit(char ch)
{
	if (ch - '0' >= 0 && ch - '0' < 10)
	{
		return true;
	}

	return false;
}

//конструктор с параметром
Line::Line(string line)
{
	bool number = false;//цифра или не цифра
	int length = 0;//длина выражение
	int start;//позиция в выражении

	for (int i = 0; i < line.size(); ++i)//идем по всему выражению
	{
		if (is_digit(line[i]))//если цифра
		{
			length++;//увеличиваем длину

			if (!number)//находим стартовую позицию
			{
				start = i;
				number = true;
			}
		}
		else
		{
			if (number)
			{
				expression.push_back(line.substr(start, length));//добавляем в выражение циферки
				number = false;//обнуляем найденное 
				length = 0;
			}

			if (((line[i] == '>' || line[i] == '<' || line[i] == '!') && line[i + 1] != '=') || line[i] == '(' || line[i] == ')')
			{
				expression.push_back(line.substr(i, 1));//добавляем в выражение знак
			}

			else if (twodigit.find(line.substr(i, 2)) != string::npos)// npos -это беззнаковое интегральное значение, стандарт определяет его как -1 (знаковое представление), которое не обозначает никакой позиции.
			{
				expression.push_back(line.substr(i, 2));//добавляем в выражение следующие 
				i++;
			}

			else if (line[i] == 't')
			{
				expression.push_back("1");//добавляем в выражение true
				i += 3;
			}

			else if (line[i] == 'f')
			{
				expression.push_back("0");//добавляем в выражение false
				i += 4;
			}
		}
	}
}

//проверка на цифру
bool Line::is_number(int i)
{
	if ((expression[i][0] - '0' >= 0 && expression[i][0] - '0' < 10) || expression[i] == "true" || expression[i] == "false")
	{
		return true;
	}

	return false;
}
//проверка на логический оператор
bool Line::is_logical(int i)
{
	if (expression[i] == "&&" || expression[i] == "||")
	{
		return true;
	}

	return false;
}
//проверка на скобочки
bool Line::is_brkt(int i)
{
	if (expression[i] == "(" || expression[i] == ")")
	{
		return true;
	}

	return false;
}

void Line::Convertation()
{
	int i = 0;//счетчик для прохода по выражению
	bool Cbrkt = false;//скобочек нет
	expression.push_back(";");

	do
	{
		if (expression[i] == ")")
		{
			Cbrkt = true; //находим скобочку
		}

		if (this->is_number(i))//если циферка
		{
			arguments.push(string_to_int(expression[i]));//то добавляем ее в аргументы
		}

		else if (this->is_logical(i) || Cbrkt || expression[i] == ";")//если оператор или скобочка или ;
		{
			while (operation.size() > 0 && operation.top() != "(")//есть операторы и верхний элемент операторов не скобочка
			{
				int a = arguments.top();//забрасываем в а верхний аргумент

				if (operation.top() == "!")//если не
				{
					arguments.top() = Operate(a);//то интвертируем
				}
				else//иначе
				{
					arguments.pop();//удаляем верхний элемент стека аргументов
					int b = arguments.top();//запихиваем следующий в b
					arguments.top() = Operate(a, b, operation.top());//выполняем операцию с а и b
				}

				operation.pop();//удаляем эту операцию из стека оперций
			}
			if (operation.size() > 0 && Cbrkt && operation.top() == "(")//находим скобочку  (
			{
				operation.pop();// удаляем эту скобочку из стека операций
				Cbrkt = false;
			}

			if (!this->is_brkt(i) && expression[i] != ";")
			{
				operation.push(expression[i]);//добавляем операций в стрек
			}
		}
		else
		{
			operation.push(expression[i]);//добавляем операторы
		}

		i++;
	} while (i < expression.size());

	cout << "\nResult: " << arguments.top();
}
//выполнение соответствующих операторов
bool Line::Operate(int& a, int& b, string& operat)
{
	if (operat == "<=")
		return a >= b;
	else if (operat == ">=")
		return a <= b;
	else if (operat == ">")
		return a < b;
	else if (operat == "<")
		return a > b;
	else if (operat == "!=")
		return a != b;
	else if (operat == "==")
		return a == b;
	else if (operat == "&&")
		return a && b;
	else if (operat == "||")
		return a || b;
}
//выполняет инвертирование а
bool Line::Operate(int& a)
{
	return !a;
}
//вывод выражения
void Line::COUT()
{
	//cout << "Expression length: " << expression.size() << endl;
	for (int i = 0; i < expression.size(); i++)
	{
		cout << expression[i];
	}
}