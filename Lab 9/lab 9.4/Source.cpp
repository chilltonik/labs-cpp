#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct properties
{
    int m_amount = 0;//количество
    vector <int> m_lines;//строка
};

void scan_cpp(const char* file_name, map <string, properties>& identifiers);

vector <string> split(string& line);//раскол строки на ключевые слова
bool is_splitter(char c);
bool is_key_word(string& word);//определяет ключевое ли это слово

int main()
{
    map <string, properties> identifiers;//храними строку,количество повторений и номера строк

    scan_cpp("Source.cpp", identifiers);

    ofstream f("out.txt");
    for (auto p = identifiers.begin(); p != identifiers.end(); ++p)//запись в файл и в консоль
    {
        cout << "|" << p->first << "| met for " << p->second.m_amount << " times at: ";
        f << "|" << p->first << "| met for " << p->second.m_amount << " times at lines: ";

        for (int i = 0; i < p->second.m_lines.size(); ++i)
        {
            cout << p->second.m_lines[i];
            f << p->second.m_lines[i];
            if (i != p->second.m_lines.size() - 1)
            {
                cout << ", ";
                f << ", ";
            }
        }
        cout << endl;
        f << endl;
    }

    return 0;
}


vector <string> split(string& line)//выделяет идентификаторы
{
    vector <string> result;//вектор из слов
    string tmp;//буфферная строка
    int index = 0;
    int wordIndex = 0;

    while (index != line.size())//бежим по строке
    {
        if (is_splitter(line[index]))//если элемент строки splitter идем дальше
        {
            index++;
            continue;
        }
        else 
        {
            //Пропускаем комментарии
            if (line[index] == '/' && line[index + 1] == '/')
            {
                break;
            }
           
            while (index != line.size() && !is_splitter(line[index]))
            {
                tmp.push_back(line[index++]);
            }
            result.push_back(tmp);
            tmp.clear();
            wordIndex++;
        }
    }
    for (auto i = result.begin(); i != result.end();)
    {
        if (is_key_word(*i)) //если текущее слово == ключевому
        {
            i = result.erase(i);//то удаляем его
            continue;
        }
        ++i;
    }
    return result;
}
bool is_splitter(char c)
{
    switch (c)
    {
    case ' ':
    case '<':
    case '>':
    case ';':
    case '{':
    case '}':
    case '=':
    case '(':
    case ')':
    case '*':
    case ',':
    case '&':
    case '!':
    case '.':
    case '[':
    case ']':
    case '+':
    case '-':
    case ':':
        return true;
    default:
        return false;
    }
}
bool is_key_word(string& word)
{
    return  word == "using" || word == "namespace" || word == "int" || word == "void" || word == "const" ||
        word == "char" || word == "bool" || word == "while" || word == "if" || word == "and" || word == "continue" ||
        word == "else" || word == "return" || word == "switch" || word == "case" || word == "default" || word == "true" ||
        word == "false" || word == "for" || word == "struct" || word == "break" || word == "auto" || word == "or" || word == "std" ||
        word == "begin" || word == "cerr" || word == "clear" || word == "cout" || word == "empty" || word == "end" || word == "endl" ||
        word == "eof" || word == "erase" || word == "exit" || word == "first" || word == "string" || word == "ofstream" || word == "ifstream" ||
        word == "main" || word == "vector" || word == "map" || word == "second";
}
void scan_cpp(const char* file_Name, map <string, properties>& identifiers)
{
    ifstream f(file_Name);
    if (!f.is_open())
    {
        cerr << "CANT OPEN FILE" << endl;
        exit(9);
    }

    string bufferLine;
    vector <string> bufferWords;
    properties buffer;
    int lineCounter = 1;

    while (!f.eof())
    {
        getline(f, bufferLine);

        //Если строка пуста, идем на следующую
        if (bufferLine.empty()) {
            lineCounter++;
            continue;
        }
        //Если строка - директива препроцессора, идем на следующую
        if (bufferLine[0] == '#')
        {
            lineCounter++;
            continue;
        }
        //Если строка - комментарий, идем на следующую
        if (bufferLine[0] == '/')
        {
            lineCounter++;
            continue;
        }
        ////Если строка начинается с буквы
        //if (bufferLine[0] >= 'A' || bufferLine[0] <= 'Z' && bufferLine[0] >= 'a' || bufferLine[0] <= 'z')
        //{
        //    lineCounter++;
        //    continue;
        //}

        bufferWords = split(bufferLine); //Получаем из строки вектор идентификиторов
        for (int w = 0; w < bufferWords.size(); ++w)
        {
            if (identifiers.count(bufferWords[w]) == 0)
            {
                //Если не встречали, инициализируем по умолчанию
                buffer.m_amount = 1;
                buffer.m_lines.push_back(lineCounter);
                identifiers[bufferWords[w]] = buffer;
            }
            else
            {
                //В противном случае инкрементируем счетчик и, если нужно, добавляем в map
                identifiers[bufferWords[w]].m_amount++;
                if (find(identifiers[bufferWords[w]].m_lines.begin(), identifiers[bufferWords[w]].m_lines.end(),
                    lineCounter) == identifiers[bufferWords[w]].m_lines.end())
                {
                    identifiers[bufferWords[w]].m_lines.push_back(lineCounter);
                }
            }
            buffer.m_lines.clear();
        }
        lineCounter++;
    }
}