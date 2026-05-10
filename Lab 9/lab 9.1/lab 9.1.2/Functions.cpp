#include"Functions.h"

void fill_str(vector<char>& str, int& size)
{
	string buffer = "";
	getline(cin, buffer);

	size = buffer.size();

	for (int i = 0; i < size; ++i)
	{
		str[i] = buffer[i];
	}
}
void Getting_Array_Of_Words(vector<char>& str, vector<vector<char>>& Array_Of_Words, int& Number_Of_Word, int Count_Of_Words, int begin, int end) // Заполнения массива словами
{
	for (int j = 0, k = begin; k < end; ++j, ++k)
	{
		Array_Of_Words[Number_Of_Word][j] = str[k];
	}

	if (Number_Of_Word <= Count_Of_Words)
	{
		Number_Of_Word++;
	}
}
bool& Comparing_arrays(vector<int>& Arr1, vector<int>& Arr2, bool& equal)
{
	int MAXSIZE = Arr1.size();

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
bool Comparison(vector<char>& s1, vector<char>& s2, bool& BooleanResult) // Сравнение на нужное условие
{
	bool Length = false;

	int LenS1 = s1.size();
	int LenS2 = s2.size();

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

	vector<int> IntS1(MAXSIZE, 0);
	vector<int> IntS2(MAXSIZE, 0);

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

	Comparing_arrays(IntS1, IntS2, equal);

	if (Length && equal)
	{
		BooleanResult = true;
	}

	//cout << "\nLength: " << Length << endl;
	//cout << "\nBooleanResult: " << BooleanResult << endl;

	return BooleanResult;
}
int Getting_Count_Of_Words(vector<char>& str, vector<char>& seporator) //Получение количества слов
{
	int lenS = str.size();

	int Count_Of_Words = 0;

	for (int i = 0; i < lenS; ++i)
	{
		bool flag = false;
		for (int j = 0; j < seporator.size(); ++j)
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
int& Getting_token(vector<char>& str, vector<char>& seporator, int& begin, int& end, vector<vector<char>>& Array_Of_Words, int& Number_Of_Word, int Count_Of_Words) // Получение одной лексемы
{
	unsigned lengthStr = str.size();
	int SEP = seporator.size();

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
void ShowArray(vector<vector<char>>& Array)// Вывод массива слов
{
	cout << "\tArray_Of_Words:" << endl;
	for (int i = 0; i < Array.size(); ++i)
	{
		for (int j = 0; j < Array.size(); ++j)
		{
			cout << Array[i][j];
		}
		cout << endl;
	}
}
void Bool_Result(vector<vector<char>>& Array_Of_Words, vector<int>& Bool, int& NumberOfWord, int CountOfWords)
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
void Getting_Result(vector<char>& result, vector<char>& word, int& startpoz) // Получение результирующей строки
{
	int k = startpoz;
	int lenWord = word.size();

	for (int i = 0; i < lenWord; ++k, ++i)
	{
		result[k] = word[i];
	}
	result[k] = ' ';
	startpoz = k + 1;
}