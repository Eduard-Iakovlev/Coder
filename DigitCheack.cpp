#include"DigitCheack.h"
#include <Windows.h>
#include <iostream>
#


int checkDigit() // �������� �� ���� ��������� �������� ���������� �������. 
{
    bool inter = true;
    int x;

    while (inter)
    {
        char str[256]{}, * p = str;
        bool isd = true;
        std::cin >> str;
        while (*p)
        {
            if (!isdigit(*p++))
            {
                isd = false;
                break;
            }
        }
        if (isd)
        {
            x = atoi(str);
            inter = false;
        }
        else
        {
            std::cout << " �������� �� ��������!!!\n �������� ����:\n ";
            Beep(1000, 250);
        }
    }
    return x;
}
