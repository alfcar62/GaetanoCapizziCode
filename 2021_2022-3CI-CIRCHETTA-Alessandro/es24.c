/********************************************
ALUNNO: Alessandro CIRCHETTA & Jacopo BORDONI
DATA:   17/11/2021
CLASSE: 3C INFORMATICA 
TESTO:  LUCI DI NATALE
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


typedef unsigned char color_t;

enum
    {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        LightGray,
        Gray,
        LightRed,
        LightGreen,
        LightYellow,
        LightBlue,
        LightMagenta,
        LightCyan,
        White
    };

void textcolor(color_t fgcolor, color_t bgcolor)
    {
        printf("\033[38;5;%dm\033[48;5;%dm",fgcolor, bgcolor);
    }

void  gotoxy(int x, int  y) 
    {
        COORD CursorPos = {x, y};
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsole, CursorPos);
    }


int main()
{
    srand (time(0));
    int x = 0,
        y = 0;
        
    system("cls");

    gotoxy(35, 1);
        printf("ES 24: ALBERO DI NATALE!\n");

        Sleep(2500);

    do
    {

        gotoxy(45, 19);
            printf("*");
        textcolor(Gray, Black);

        gotoxy(45, 18);
            printf("*");
        textcolor(Gray, Black);

        gotoxy(49, 19);
            printf("*");
        textcolor(Gray, Black);

        gotoxy(49, 18);
            printf("*");
        textcolor(Gray, Black);

        gotoxy(43, 18);
            printf("*");
        textcolor(Green, Black);

        gotoxy(41, 18);
            printf("*");
        textcolor(Green, Black);

        gotoxy(39, 18);
            printf("*");
        textcolor(Green, Black);
        
        gotoxy(40, 17);
            printf("*");
        textcolor(Green, Black);

        gotoxy(41, 16);
            printf("*");
        textcolor(Green, Black);

        gotoxy(42, 15);
            printf("*");
        textcolor(Green, Black);

        gotoxy(43, 14);
            printf("*");
        textcolor(Green, Black);

        gotoxy(44, 13);
            printf("*");
        textcolor(Green, Black);

        gotoxy(45, 12);
            printf("*");
        textcolor(Green, Black);

        gotoxy(46, 11);
            printf("*");
        textcolor(Green, Black);

        gotoxy(47, 10);
            printf("*");
        textcolor(Green, Black);

        gotoxy(51, 18);
            printf("*");
        textcolor(Green, Black);

        gotoxy(53, 18);
            printf("*");
        textcolor(Green, Black);

        gotoxy(55, 18);
            printf("*");
        textcolor(Green, Black);

        gotoxy(54, 17);
            printf("*");
        textcolor(Green, Black);

        gotoxy(53, 16);
            printf("*");
        textcolor(Green, Black);

        gotoxy(52, 15);
            printf("*");
        textcolor(Green, Black);

        gotoxy(51, 14);
            printf("*");
        textcolor(Green, Black);

        gotoxy(50, 13);
            printf("*");
        textcolor(Green, Black);

        gotoxy(49, 12);
            printf("*");
        textcolor(Green, Black);

        gotoxy(48, 11);
            printf("*");
        textcolor(Green, Black);



        
        Sleep(22500);

        /*if (x % 2 == 0)
        {
            x = rand()%240;
            y = rand()%60;

            gotoxy(x, y);
                printf("                       ");
        }
        */
        gotoxy(30, 3);
            printf(" Schiaccia un tasto per terminare ");
    } 
    while (!kbhit());

    return 0;
}