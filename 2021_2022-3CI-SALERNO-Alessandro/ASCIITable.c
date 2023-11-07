/************************************************
CONSEGNA:
Scrivere un programma che stampa la tabella di
tutti i  caratteri ASCII

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


void ASCIITable()
{
    textcolor(Blue);
    printf("ID\tCarattere\n\n");
    int i;

    for (i = 32; i < 128; i++)
    {
        textcolor(Cyan);
        printf("%d\t", i);
        textcolor(Magenta);
        printf("%c\n", i);
    }
}

int main()
{
    setupcolor();
    ASCIITable();
    textcolor(White); 
    return 0;
}
