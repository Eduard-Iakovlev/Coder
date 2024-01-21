#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "DigitCheack.h"

using std::cout;
using std::cin;


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char cod;
    char globalWork = 1;
    int x;
    int counter = 0;

    int KeyCodeCheck;


        cout << " Как пользоваться шифровальщиком.\n Выберите режим согласно запроса (раскладка клавиатуры не важна) \n Введите текст (на кирилице, латинице или смешанный). По окончанию ввода нажмите 'Enter'.\n Допустимые знаки препинания: '.' ',' 'пробел' '!' '?' \n При вводе не корректных символов воспользуйтесь клавишей 'Backspace'.";
        cout << "\n Для продолжения работы нажмите клавишу 'пробел':";


    while (globalWork != 32)
    {
        globalWork = _getch();
    }

    system("cls");

    while (globalWork == 32) // цикл работы шифровальщика.
    {
        cout << " Задайте ключ шифрования (целое цисло): ";
      
        x = checkDigit(); // проверка на ввод чмлового значения

        cout << " Принят ключ: " << x << "\n\n";
       
        cout << "\n Будем шифровать - нажмите \"C\" или расшифровывать - нажмите \"D\", завершить \"Esc\": ";

        do // выбор действия (шифровка / дешифровка)
        {
            cod = _getch();
            if (cod == 'C' || cod == 'c' || cod == 'С' || cod == 'с')
            {
                cod = 'c';
                break;
            }
            else if (cod == 'D' || cod == 'd' || cod == 'В' || cod == 'в')
            {
                cod = 'd';
                x *= -1;
                break;
            }
            else if (cod == 27)
            {
                globalWork = cod;
                break;
            }
            else Beep(1500, 100);;
        } while (cod);
        if (globalWork == 27) break;

            while (cod == 'c' || cod == 'd') // цикл шифровки
            {
             char* textcod = new char[10'000]{};

             if (cod == 'c') cout << "\n Введите текст для шифровки:\n\n ";
             else cout << "\n\n Введите текст для расшифровки:\n\n ";
                             
                for (int i = 0; i < 10'000; i++)
                {
                    if (i < 10'000)
                    {
                        KeyCodeCheck = _getch();
                    }
                    else
                    {
                        cout << "\n Память шифровальшика заполнена! \n";
                        KeyCodeCheck = 13;
                    }
                    
                    if (KeyCodeCheck == 224 && _kbhit())
                    {
                        KeyCodeCheck = _getch();
                        Beep(1500, 250);
                        continue;
                    }
                    if (KeyCodeCheck == 9)
                    {
                        KeyCodeCheck = 0;
                        Beep(1500, 250);
                        continue;
                    }
                    textcod[i] = KeyCodeCheck;
                       cout << textcod[i];

                    if (textcod[i] == 13)
                    {
                        textcod[i] = '\0';
                        counter = i;
                        break;
                    }
                    if (textcod[i] >= 'A' && textcod[i] <= 'Z')
                    {
                        textcod[i] += x;
                        if (textcod[i] > 'Z') textcod[i] = 'A' + (textcod[i] - 'Z' - 1);
                        if (textcod[i] < 'A') textcod[i] = 'Z' - ('A' - textcod[i] - 1);
                    }
                    else if (textcod[i] >= 'a' && textcod[i] <= 'z')
                    {
                        textcod[i] += x;
                        if (textcod[i] > 'z')  textcod[i] = 'a' + (textcod[i] - 'z' - 1);
                        if (textcod[i] < 'a')  textcod[i] = 'z' - ('a' - textcod[i] - 1);
                    }
                    else if (textcod[i] >= 'А' && textcod[i] <= 'Я')
                    {
                        textcod[i] += x;
                        if (textcod[i] > 'Я') textcod[i] = 'А' + (textcod[i] - 'Я' - 1);
                        if (textcod[i] < 'А') textcod[i] = 'Я' - ('А' - textcod[i] - 1);
                    }
                    else if (textcod[i] >= 'а' && textcod[i] <= 'я')
                    {
                        textcod[i] += x;
                        if (textcod[i] > 'я')  textcod[i] = 'а' + (textcod[i] - 'я' - 1);
                        if (textcod[i] < 'а')  textcod[i] = 'я' - ('а' - textcod[i] - 1);
                    }

                    else if (textcod[i] == 8) // удаление не корректно введённых символов
                    {
                        cout << " " << "\b";
                        i -= 2;
                        if (i < 0) i = -1;  // защита от ошибки при нажатии избыточного кол-а backspace
                    }
                    else if (textcod[i] == ' ' || textcod[i] == ',' || textcod[i] == '.' || textcod[i] == '!' || textcod[i] == '?') textcod[i];
                    else // защита от нажатия не обрабатываемых клавиш
                     {
                       --i;
                       cout << "\b" << " " << "\b";
                       Beep(1500, 250);
                     }
                }

                if (cod == 'c')  cout << "\n\n Зашифровано: \n\n ";
                else cout << "\n\n Расшифровано: \n\n ";
               
                for (int i = 0; i < counter; i++)
                {
                    cout << textcod[i];
                }
                cout << "\n\n";
                delete[] textcod;
                break;
            }
                  
            cout << "\n Продолжим? Да - \"пробел\", Нет - \"Esc\"";
        do // выбор продолжать или закончить
        {
            globalWork = _getch();
            if (globalWork == 32)
            {
                system("cls");
                break;
            }
            else if(globalWork != 27)
            {
                Beep(1500, 250);
                cout << "\n Не понял? Повторите. \n";
                globalWork = 32;
            }
        } while (globalWork == 32);
    }
    

                system("cls");
                cout << "\n\n\n                           Всего хорошего!\n\n\n";
}
