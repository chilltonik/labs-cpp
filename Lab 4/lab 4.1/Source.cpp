/*
3. Из заданного текста удалить те символы, которые встречаются в нем ровно один раз.
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[256] = { '\0' };
    int Int[256] = { 0 };

    //cin str
    cout << "Enter the str: " << endl;
    cin.getline(str, 256);

    int len = strlen(str);

    //cout str
    cout << "\nYour str:\n" << str << endl;
    cout << endl;

    int i = 0;

    //cin Int
    while (str[i] != '\0') 
    {
        Int[static_cast<int>(str[i])]++;
        i++;
    }

    //cout Int
    cout << "ASCII: " << endl;
    for (int i = 0; i < 256; i++)
    {
        cout << Int[i] << " ";
    }
    //cout << endl;

    int count = 0;

    char charSimbol[256];

    int j = 0;

    for (int i = 0; i < 256; ++i) 
    {
        if (Int[i] == 1) 
        {
            count++;
            char simbol = static_cast<char>(i);

            charSimbol[j] = simbol;
            j++;

            //cout << "\nSimbol: " << simbol;
        }
    }
    //cout << "\n\nCount: " << count << endl;

    /*{
        cout << endl;
        for (int i = 0; i < count; ++i)
        {
            cout << "charSimbol: " << charSimbol[i] << "   ";
        }
    }*/

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

    //cout str^
    cout << "str^:" << endl;
    for (int i = 0; i < len - count; ++i)
    {
        cout << str[i];
    }
    cout << endl;

    return 0;
}

