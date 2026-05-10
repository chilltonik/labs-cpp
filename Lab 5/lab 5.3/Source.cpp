/*
* Выполнить следующее задание для заданного текста.
Оформить задание в виде набора функций:

1. функция выделение слова (лексемы) + 
2. функция создания массива слов +
3. функция получения результирующей строки. +

Текст – непустая последовательность символов.
Слово – непустая последовательность любых символов, кроме символов-разделителей.
Предложение – последовательность слов, разделенных одним или несколькими символами-разделителями.
Символы-разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».

3. В заданном тексте найти все слова, которые имеют одинаковую длину и состо-
ят из одинаковых наборов символов (порядок символов может быть различ-
ный). Записать их в результирующую строку.
*/
#include <iostream>

using namespace std;

void Getting_Array_Of_Words(char* str, char Array_Of_Words[][20],int& Number_Of_Word, int Count_Of_Words, int begin, int end) // Заполнения массива словами
{
	for (int j = 0,k = begin; k < end; ++j, ++k)
	{
		Array_Of_Words[Number_Of_Word][j] = str[k];
	}
	
	if (Number_Of_Word <= Count_Of_Words)
	{
		Number_Of_Word++;
	}
}
bool& Comparing_arrays(int* Arr1, int* Arr2, bool& equal, const int MAXSIZE)
{
	for (int i = 0; i < MAXSIZE; ++i)
	{
		if (Arr1[i] == Arr2[i])
		{
			equal = true;
		}
		else
		{
			equal = false;
			break;
		}
	}

	//cout << "\nEqual: " << equal << endl;
	return equal;
}
bool Comparison(char* s1, char* s2, bool& BooleanResult) // Сравнение на нужное условие
{
	bool Length = false;

	int LenS1 = strlen(s1);
	int LenS2 = strlen(s2);

	if (LenS1 == LenS2)
	{
		Length = true;
	}
	else
	{
		//cout << "\nBooleanResult: " << BooleanResult << endl;
		//return BooleanResult;
	}

	const int MAXSIZE = 256;

	int IntS1[MAXSIZE] = { 0 };
	int IntS2[MAXSIZE] = { 0 };

	//Преобразуем символы строки s1 в инт и посчитаем их
	int i = 0;
	while (s1[i] != '\0')
	{
		IntS1[static_cast<int>(s1[i])]++;
		i++;
	}

	/*cout << "\nIntS1:" << endl;
	for (int i = 0; i < MAXSIZE; ++i)
	{
		cout << IntS1[i] << " ";
	}
	cout << endl;*/

	//Преобразуем символы строки s2 в инт и посчитаем их
	i = 0;
	while (s2[i] != '\0')
	{
		IntS2[static_cast<int>(s2[i])]++;
		i++;
	}

	/*cout << "\nIntS2:" << endl;
	for (int i = 0; i < MAXSIZE; ++i)
	{
		cout << IntS2[i] << " ";
	}*/

	bool equal = false;

	Comparing_arrays(IntS1, IntS2, equal, MAXSIZE);

	if (Length && equal)
	{
		BooleanResult = true;
	}

	//cout << "\nLength: " << Length << endl;
	//cout << "\nBooleanResult: " << BooleanResult << endl;

	return BooleanResult;
}
int Getting_Count_Of_Words(char* str, char* seporator,const short SEP) //Получение количества слов
{
	int lenS = strlen(str);

	int Count_Of_Words = 0;

	for (int i = 0; i < lenS; ++i)
	{
		bool flag = false;
		for (int j = 0; j < SEP; ++j)
		{
			if (str[i] == seporator[j] && i > 0)
			{
				if ((str[i - 1] != ' ') && (str[i - 1] != ',') && (str[i - 1] != '.') && (str[i - 1] != ':') && (str[i - 1] != '!') &&
					(str[i - 1] != '?') && (str[i - 1] != ';') && (str[i - 1] != ')') && (str[i - 1] != '(') && (str[i - 1] != '-'))
				{
					flag = true;
				}

			}
		}
		if (flag) Count_Of_Words++;
	}

	//cout << "Count of Words: " << Count_Of_Words << endl;
	return Count_Of_Words;
}
int& Getting_token(char* str, char* seporator, const short SEP, int& begin, int& end, char Array_Of_Words[][20], int& Number_Of_Word, int Count_Of_Words) // Получение одной лексемы
{
	unsigned lengthStr = strlen(str);

	bool BeginIsHere = false;
	bool EndIsHere = false;

	for (int i = begin; i < lengthStr; ++i) // Проход по строке
	{
		int SepCount = 0;
		for (int j = 0; j < SEP; ++j) // Является ли элемент строки хоть одним из разделителей
		{
			if (str[i] == seporator[j])
			{
				++SepCount;
			}
		}

		if (BeginIsHere == false && SepCount == 0) // Условие начала слова
		{
			begin = i;
			BeginIsHere = true;
		}

		if (BeginIsHere == true)
		{
			SepCount = 0;
			for (int j = 0; j < SEP; ++j) // Является ли элемент строки хоть одним из разделителей
			{
				if (str[i] == seporator[j])
				{
					++SepCount;
				}
			}

			if (EndIsHere == false && SepCount != 0) // Условие конца слова
			{
				end = i;
				EndIsHere = true;
			}
		}

	}

	//cout << "Begin: " << begin << endl;
	//cout << "End: " << end << endl;

	Getting_Array_Of_Words(str, Array_Of_Words, Number_Of_Word, Count_Of_Words, begin, end);

	//for (int i = begin; i < end; ++i) // Вывод лексемы
	//{
	//	cout << str[i];
	//}
	//cout << endl;

	begin = end + 1;
	return begin;
}
void ShowArray(char Array[20][20], const int N)// Вывод массива слов
{
	cout << "\tArray_Of_Words:" << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Array[i][j];
		}
		cout << endl;
	}
}
void Bool_Result(char Array_Of_Words[][20], bool* Bool, int& NumberOfWord, int CountOfWords)
{
	for (int i = NumberOfWord; i < CountOfWords - 1; ++i)
	{
		for (int j = NumberOfWord + 1; j < CountOfWords; ++j)
		{
			bool SameWords = false;
			Comparison(Array_Of_Words[i], Array_Of_Words[j], SameWords);

			//cout <<"SameWords? " << SameWords << endl;

			if (SameWords == true)
			{
				Bool[i] = true;
				Bool[j] = true;
			}

		}
		NumberOfWord++;
	}
}
void Getting_Result(char* result, char* word, int& startpoz) // Получение результирующей строки
{
	int k = startpoz;
	int lenWord = strlen(word);
	for (int i = 0; i < lenWord; ++k, ++i)
	{
		result[k] = word[i];
	}
	result[k] = ' ';
	startpoz = k + 1;
}

int main()
{
	const int SIZE = 300;
	const short SEP = 11;

	char str[SIZE] = { '\0' };
	char seporator[SEP] = { " ,.!?:;()-" };

	cout << "Enter str:" << endl;
	cin.getline(str, SIZE);
	cout << endl;

	int LenS = strlen(str);

	int Count_Of_Words = Getting_Count_Of_Words(str, seporator, SEP);

	int begin = 0;
	int end = 0;

	const int N = 20;
	char Array_Of_Words[N][N] = { '\0' };
	int Number_Of_Word = 0;

	for (int i = 0; i < Count_Of_Words; ++i)
	{
		Getting_token(str, seporator, SEP, begin, end, Array_Of_Words, Number_Of_Word, Count_Of_Words);
	}
	cout << endl;

	ShowArray(Array_Of_Words, N);

	int NumberOfWord = 0;

	bool* Bool = new bool[Count_Of_Words] {0};


	Bool_Result(Array_Of_Words, Bool, NumberOfWord, Count_Of_Words);

	char result[SIZE]{ '\0' };

	int startpoz = 0;

	for (int i = 0; i < Count_Of_Words; ++i)
	{
		if (Bool[i] == true)
		{
			//cout << Array_Of_Words[i] << endl;
			Getting_Result(result, Array_Of_Words[i], startpoz);
		}
	}

	cout << "Result: " << endl;
	cout << result << endl;

	delete[] Bool;
	return 0;
}
