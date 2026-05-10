/*
3. Ќаписать функцию вставки подстроки SS в строку S с позиции номер n.
»спользу€ эту функцию, вставить после каждой комбинации символов У, Ф текст
Унапример, Ф.
*/
#include <iostream>
#include <cstring>

using namespace std;

char* resize(const char* s, int size) // создание новой строки размером lenS + lenSub
{
    char* newStr = new char[size] {'\0'};

    for (int i = 0; s[i] != '\0'; ++i)
    {
        newStr[i] = s[i];
    }

    return newStr;
}

char* insert(char* s, char* sub, char* newStr, int startPoz) //функци€ копировани€ старой строки в новую
{
    int lenS = strlen(s);
    int lenSub = strlen(sub);
    int newLen = lenS + lenSub;

    if (newLen > strlen(newStr)) //проверка нужно ли выдел€ть новую пам€ть
    {
        newStr = resize(s, newLen);
    }

    for (int i = 0; i < startPoz; ++i) // копирование элементов до позиции вставки
    {
        newStr[i] = s[i];
    }

    for (int i = startPoz, j = 0; j < lenSub; ++i, ++j) // вставка подстроки
    {
        newStr[i] = sub[j];
    }

    for (int i = startPoz + lenSub, j = startPoz; j < lenS; ++j, ++i) //копирование элементов после позиции вставки
    {
        newStr[i] = s[j];
    }

    return newStr;
}

void find(char* str, int& start) // находим наши позиции дл€ вставки подстроки
{
    for (int i = start; i < strlen(str); ++i)
    {
        if (str[i] == ' ' && str[i - 1] == ',' || str[i] == ',' && str[i - 1] == ' ')
        {
            ++start;
            ++i;
            return;
        }
        ++start;
    }
}

int amount(char* str) //считаем количество позиций, после которых нужно вставить подстроку
{
    int result = 0;

    int len = strlen(str);

    for (int i = 1; i < len; ++i)
    {
        if (str[i] == ' ' && str[i - 1] == ',' || str[i] == ',' && str[i - 1] == ' ')
        {
            ++result;
            ++i;
        }
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter size of your string: ";
    cin >> n;

    char* s = new char[n] {'\0'};
    char* sub = new char[n] {'\0'};

    cout << "Enter s:" << endl;

    cin.clear();
    cin.ignore(32767, '\n');

    cin.getline(s, n);

    cout << "Enter sub:" << endl;
    cin.getline(sub, n);

    int lenS = strlen(s);
    int lenSub = strlen(sub);
    int newLen = lenS + lenSub;

    char* buffer = new char[newLen];
    char* result = new char[1]{ '\0' };

    int amountOfReplaces = amount(s);

    int start = 0;
    for (int i = 0; i < amountOfReplaces; ++i)
    {
        find(s, start);
        result = insert(s, sub, buffer, start);
        s = result;
    }
    int output = lenS + lenSub * amountOfReplaces;

    result[output] = '\0';
    result[n] = '\0';

    cout << result << endl;

    //delete[] s;
    //delete[] sub;
    //delete[] buffer;
    delete[] result;

    return 0;
}

