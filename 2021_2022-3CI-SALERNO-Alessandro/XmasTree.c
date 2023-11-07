/************************************************
CONSEGNA:
Realizzare un programma che un albero di di
Natale, con le luci che si accendono e spengono
in modo casuale. Utilizzare la gotoXY e la
random.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    13 Gennaio 2022
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


#define STAR_CHAR 'X'

#ifdef _WIN32
    #include <windows.h>
    #define wait(ms) Sleep(ms)
    #define clrscr() system("cls")
    #define setupcolor() system("")
#else
    #ifndef _POSIX_SOURCE
        #define _POSIX_SOURCE
    #endif

    #include <unistd.h>
    #define wait(ms) usleep(ms * 1000)
    
    #define clrscr()                             \
        int __X__, __Y__;                        \
        for (__X__ = 0; __X__ < 80; __X__++)     \
        {                                        \
            for (__Y__ = 0; __Y__ < 40; __Y__++) \
            {                                    \
                gotoxy(__X__, __Y__);            \
                printf(" ");                     \
            }                                    \
        }                                        \
        gotoxy(0, 0);

    #define setupcolor()
#endif


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

void textcolor(color_t fgcolor)
{
    printf("\033[38;5;%dm", fgcolor);
}

void gotoxy(int x, int y)
{
    #if defined (_WIN32) && defined (LEGACY_WINDOWS)
        COORD pos     = { x + 1, y + 1 };
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, pos);
    #else
        printf("\033[%d;%dH", y + 1, x + 1);
    #endif
}



unsigned int GenerateRandom(unsigned int range)
{
    return rand() % range;
}

void TreeTriangle()
{
    int i, j;
    for (i = 1; i <= 8; i++)
    {
        for (j = 1; j <= 10 - i; j++)
            printf(" ");

        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }
}

void XmasTree()
{
    while (true)
    {
        int x = GenerateRandom(10);
        int y = GenerateRandom(35);

        clrscr();
        textcolor(Green);
        TreeTriangle();
        TreeTriangle();

        int i, j;
        for (i = 1; i <= 5; i++)
        {
            for (j = 1; j <= 7; j++)
                printf(" ");

            printf("*****\n");
        }

        textcolor(GenerateRandom(255));
        
        gotoxy(x, y);
        printf("%c", STAR_CHAR);

        gotoxy(x, y - 1);
        printf("%c", STAR_CHAR);

        gotoxy(x, y + 1);
        printf("%c", STAR_CHAR);

        gotoxy(x - 1, y);
        printf("%c", STAR_CHAR);

        gotoxy(x + 1, y);
        printf("%c", STAR_CHAR);

        fflush(stdout); 
        wait(400);
    }
}

int main()
{
    setupcolor();
    XmasTree();
    textcolor(White); 
    return 0;
}
