/**********************
ALUNNO: Alessandro CIRCHETTA & Jacopo BORDONI
DATA:   17/11/2021   
CLASSE: 3C INFORMATICA 
TESTO:  LUCI DI NATALE
**********************/

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
printf(
// \003 indica una sequenza
// 38 � colore testo
// 48 � colore sfondo
// 5 indica modalit� a 256 colori (Profondit� 8 bit)
// %d � il colore
"\033[38;5;%dm\033[48;5;%dm",
fgcolor, bgcolor
);
}

void  gotoxy(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}


int main()
{
    srand (time(0));
    int x = 0,
        y = 0;

    gotoxy(35, 1);
        printf("ES 23: LUCI DI NATALE\n");

        system("cls");

    do
    {
        x = rand()%240;
        y = rand()%60;
        textcolor(rand()%255, Black);

        gotoxy(x, y);
            printf("*");

        Sleep(10);

        if (x % 2 == 0)
        {
            x = rand()%240;
            y = rand()%60;

            gotoxy(x, y);
                printf("                               ");
            gotoxy(x, y);
                printf("                               ");
            gotoxy(x, y);
                printf("                               ");
        }

    } 
    while (!kbhit());

    return 0;
}
