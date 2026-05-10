/*
Выполнить задание для заданной строки символов, используя C-строки для
представления данных.

Текст – непустая последовательность символов.

Слово – непустая последовательность любых символов, кроме символов-
разделителей.

Предложение – последовательность слов, разделенных одним или несколь-
кими символами-разделителями.

Символы-разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».

3. Записать в новую строку все несимметричные слова, которые имеют четную
длину.
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	const int SIZE = 300;

	char str[SIZE];
	char STR[SIZE];

	char delimetor[] = { " .,:;!?-()" };

	cin.getline(str, SIZE);

	char* word = strtok(str, delimetor);

	int Pos = 0;

	while (word)
	{
		bool noSimmetric = false; //Предположим что слово симметрично

		int length = strlen(word);

		if (length % 2 == 0) //проверка на четность
		{
			for (int i = 0, j = length - 1; i < j; ++i, --j)
			{
				if (word[i] != word[j])    //проверка на несимметрию
				{
					noSimmetric = true;
					break;
				}
			}
		}

		if (noSimmetric)   //Записываем слово в новую строку
		{
			for (int i = 0; i < length; ++i, ++Pos)
			{
				STR[Pos] = word[i];
			}

			STR[Pos++] = ' ';
		}

		word = strtok(nullptr, delimetor);   //Находим следующее слово
	}

	STR[Pos] = '\0';

	cout << STR;

	return 0;
}