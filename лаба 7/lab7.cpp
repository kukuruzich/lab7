#include <iostream>
#include "windows.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
void RAZBIVKA(char* word, ifstream& text)
{
    char *token = NULL, *next_token = NULL; //инициализация пустых токенов (служебные для strtok_s)
    string buffer; bool flag = 0;
    const char* SEPARATORS = " ,";
    while (!text.eof())  //пока не конец файла 
    {
        //прогоняем по строкам 
        getline(text, buffer, '.');
        const char* cstr = buffer.c_str(); //преобразовываем string в const char
        char buffer_c[255];
        strcpy_s(buffer_c, buffer.c_str()); //преобразовываем const char в char
        //Разбиваем строку на слова
        token = strtok_s(buffer_c, SEPARATORS, &next_token);
        while (token != NULL)
        {

            if (strcmp(token, word) == 0) {
                cout << buffer << endl;
                flag = 1;
                break;
            }
            if (token != NULL)
                token = strtok_s(NULL, SEPARATORS, &next_token);

        }
    }
    if (flag == 0) {
        cout << "String doesn't exist" << endl;
    }
}

int main()
{
    char word[30]; //Вводимое с клавиатуры слово
    char* token = NULL, * next_token = NULL;
    const char* SEPARATORS = " ,";
    string buffer;
    bool flag = 0;
    ifstream text("text.txt");
    cout << "Enter the word: ";
    cin >> word;
    if (!text.is_open()) // если файл не открыт
        cout << "File doesnt open\n"; // сообщить об этом
    else
    {
        RAZBIVKA(word, text);

        return 0;
    }
}