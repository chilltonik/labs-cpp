/*
* Выполнить задания 4.1, 4.2, 4.3, используя string-строки для представления данных. Задания выполнить через функции.
4.1:
- 3. Из заданного текста удалить те символы, которые встречаются в нем ровно
один раз.
4.2:
- 3. Написать программу перевода вещественных чисел из двоичной системы
счисления в десятичную.
4.3:
- 3. Записать в новую строку все несимметричные слова, которые имеют четную
длину.
*/

#include <iostream>
#include <string>
#define LINE 50
using namespace std;

void PrintLine()
{
	cout << endl;
	for (int i = 0; i < LINE; ++i)
	{
		cout << "_";
	}
    cout << endl;
}
void FillIntArr(int Int[256], string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        Int[static_cast<int>(str[i])]++;
        i++;
    }
}
void ShowArr(int arr[256])
{
    cout << "ASCII: " << endl;
    for (int i = 0; i < 256; i++)
    {
        cout << arr[i] << " ";
    }
    //cout << endl;
}
void CountOfSimbols(string& charSimbol, int Int[256], int& count)
{
    int j = 0;

    for (int i = 0; i < 256; ++i)
    {
        if (Int[i] == 1)
        {
            count++;
            char simbol = static_cast<char>(i);

            charSimbol[j] = simbol;
            j++;

           // cout << "\nSimbol: " << simbol;
        }
    }
   // cout << "\n\nCount: " << count << endl;
}
void DeleteSimbols(string charSimbol, string& str, int count, int len)
{
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (charSimbol[i] == str[j])
            {
                int Copyj = j;

                while (Copyj < len)
                {
                    str[Copyj] = str[Copyj + 1];
                    Copyj++;
                }
            }
        }
    }
}

void ONE1(char ONE, bool& flagZnakMinus, bool& flagZnakPlus, bool& flagNullOrOne)
{
	if (ONE == '-')
	{
		flagZnakMinus = true;
	}
	if (ONE == '+')
	{
		flagZnakPlus = true;
	}
	if (ONE == '0' || ONE == '1')
	{
		flagNullOrOne = true;
	}
}
void Correct(string str2, int len, bool flagZnakMinus, bool flagZnakPlus, bool flagNullOrOne, bool& correct)
{
	for (int i = 1; i < len; ++i)
	{
		if (!flagZnakMinus && !flagZnakPlus && !flagNullOrOne)
		{
			cout << "You have a mistake!" << endl;
			correct = false;
			//exit(0);
		}
		if (str2[i] != '0' && str2[i] != '1' && str2[i] != '.')
		{
			cout << "You have a mistake!" << endl;
			correct = false;
			//exit(0);
		}
	}
}
void Point(string str2, int len, int& countPoint, bool& flagPoint)
{
	for (int i = 0; i < len; ++i)
	{
		countPoint++;
		if (str2[i] == '.')
		{
			flagPoint = true;
			countPoint = i;
			break;
		}
	}
	/*cout << "flagPoint: " << flagPoint << endl;
	cout << "countPoint: " << countPoint << endl;*/
}
int WholePart(string str2, int countPoint, bool flagZnakMinus, bool flagZnakPlus)
{
	double wholePart = 0;
	double Degree2 = 1;

	if (flagZnakMinus == true || flagZnakPlus == true)
	{
		for (int i = countPoint - 1; i >= 1; --i)
		{
			int simbol = static_cast<int>(str2[i]) - static_cast <int>('0');
			wholePart += (simbol * Degree2);

			Degree2 *= 2;
		}

		//cout << "Whole Part: " << wholePart << endl;
	}
	else
	{
		for (int i = countPoint - 1; i >= 0; --i)
		{
			int simbol = static_cast<int>(str2[i]) - static_cast <int>('0');
			wholePart += (simbol * Degree2);

			Degree2 *= 2;
		}

		//cout << "Whole Part: " << wholePart << endl;
	}

	return wholePart;
}
double FractionalPart(string str2, bool flagPoint, int countPoint, int len)
{
	double fractionalPart = 0;
	double Degree_2 = 0.5;

	if (flagPoint)
	{
		for (int i = countPoint + 1; i < len; ++i)
		{
			int simbol = static_cast<int>(str2[i]) - static_cast <int>('0');
			fractionalPart += (simbol * Degree_2);

			Degree_2 /= 2;
		}

		//cout << "fractionalPart: " << fractionalPart << endl;
	}
	return fractionalPart;
}

int Getting_Count_Of_Words(string str3, string delimetor, const short SEP) //Получение количества слов
{
	int lenS = size(str3);

	int Count_Of_Words = 0;

	for (int i = 0; i < lenS; ++i)
	{
		bool flag = false;
		for (int j = 0; j < SEP; ++j)
		{
			if (str3[i] == delimetor[j] && i > 0)
			{
				if ((str3[i - 1] != ' ') && (str3[i - 1] != ',') && (str3[i - 1] != '.') && (str3[i - 1] != ':') && (str3[i - 1] != '!') &&
					(str3[i - 1] != '?') && (str3[i - 1] != ';') && (str3[i - 1] != ')') && (str3[i - 1] != '(') && (str3[i - 1] != '-'))
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
int Getting_token(string str3, string delimetor, const short SEP, int& begin, int& end, int& length, int& CopyBegin) // Получение одной лексемы
{
	int lengthStr = size(str3);

	bool BeginIsHere = false;
	bool EndIsHere = false;

	for (int i = begin; i < lengthStr; ++i) // Проход по строке
	{
		int SepCount = 0;
		for (int j = 0; j < SEP; ++j) // Является ли элемент строки хоть одним из разделителей
		{
			if (str3[i] == delimetor[j])
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
				if (str3[i] == delimetor[j])
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

	/*cout << "Begin: " << begin << endl;
	cout << "End: " << end << endl;*/

	CopyBegin = begin;

	length = end - begin;

	//for (int i = begin; i < end; ++i) // Вывод лексемы
	//{
	//	cout << str3[i];
	//}
	//cout << endl;

	begin = end + 1;
	return begin;
}
bool NoSimmetricTest(string str3, int CopyBegin, int end, bool noSimmetric)
{
	for (int i = CopyBegin, j = end - 1; i < j; ++i, --j)
	{
		if (str3[i] != str3[j])    //проверка на несимметрию
		{
			noSimmetric = true;
			break;
		}
	}
	return noSimmetric;
}
void WriteWord(string str3, string& STR, int CopyBegin, int end, int& Pos)
{
	for (int i = CopyBegin; i < end; ++i, Pos++)
	{
		STR[Pos] = str3[i];
	}

	STR[Pos++] = ' ';
}

int main()
{
	cout << "4.1:" << endl;
    string str;
    int Int[256] = { 0 };

    cout << "Enter the str: " << endl;
    getline(cin, str);

    int len1 = size(str);

    FillIntArr(Int, str);
    ShowArr(Int);

    int count = 0;
	string charSimbol = "                   ";

    CountOfSimbols(charSimbol, Int, count);
    DeleteSimbols(charSimbol, str, count, len1);
    
    cout << "str^:" << endl;
    cout << str;
    PrintLine();

    cout << "4.2" << endl;
	string str2;
	const int SizeOfMySimbols = 6;
	char MySimbols[SizeOfMySimbols] = "01.-+";

	cout << "Bin: ";
	getline(cin, str2);

	int len2 = size(str2);

	char ONE = str2[0];

	bool flagZnakMinus = false;
	bool flagZnakPlus = false;
	bool flagNullOrOne = false;

	ONE1(ONE, flagZnakMinus, flagZnakPlus, flagNullOrOne);

	bool correct = true;

	Correct(str2, len2, flagZnakMinus, flagZnakPlus, flagNullOrOne, correct);

	if (correct == false)
	{
		cout << "Not Correct! I will can made something with this variable, but I`m tired sorry" << endl;
		exit(0);
	}

	bool flagPoint = false;
	int countPoint = 0;
	Point(str2, len2, countPoint, flagPoint);

	double Dec = 0;

	double wholePart = 0;
	wholePart = WholePart(str2, countPoint, flagZnakMinus, flagZnakPlus);

	double fractionalPart = 0;
	fractionalPart = FractionalPart(str2, flagPoint, countPoint, len2);

	Dec = static_cast<double>(wholePart) + fractionalPart;

	flagZnakMinus ? Dec *= -1 : Dec;
	cout << "Dec: " << Dec;
	PrintLine();

	cout << "4.3:" << endl;

	string str3 = "";
	string STR = "                                                           ";

	const short SEP = 11;
	string delimetor = " .,:;!?-()";
	cout << "Enter str:" << endl;
	getline(cin, str3);

	int CountOfWords = Getting_Count_Of_Words(str3, delimetor, SEP);
	
	int begin = 0;
	int CopyBegin = begin;
	int end = 0;

	int Pos = 0;

	for (int i = 0; i < CountOfWords; ++i)
	{
		int length = 0;
		Getting_token(str3, delimetor, SEP, begin, end, length, CopyBegin);
	
		bool noSimmetric = false; //Предположим что слово симметрично
		
		if (length % 2 == 0)
		{
			noSimmetric = NoSimmetricTest(str3, CopyBegin, end, noSimmetric);
			cout << "noSimmetric: " << noSimmetric << endl;
		}

		if (noSimmetric == true)
		{
			WriteWord(str3, STR, CopyBegin, end, Pos);
		}
	}

	STR[Pos] = '\0';
	cout << "Result: \n" << STR;

	return 0;
}