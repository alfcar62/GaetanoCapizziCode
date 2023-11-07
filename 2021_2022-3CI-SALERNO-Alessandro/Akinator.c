/************************************************
CONSEGNA:
Scrivere un programma che pensa (random) un
numero da 1 a 10000 e l'utente deve indovinarlo
entro 10 tentativi.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    15 Dicembre 2021
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

unsigned int GenerateRandom(unsigned int range)
{
    return rand() % range;
}

void Akinator()
{
    clrscr();
    textcolor(Yellow);
    printf("Akinator Game");
    textcolor(White);

    int num = GenerateRandom(10000);
    int i;

    for (i = 0; i < 10; i++)
    {
        int input;

        textcolor(Blue);
        printf("\n\nInserire numero | Tentativo %d -> ", i + 1);
        textcolor(White);
        scanf("%d", &input);

        if (input < num)
        {
            textcolor(Magenta);
            printf("Input troppo piccolo    Alza un po'");
            textcolor(White);
        }

        else if (input > num)
        {
            textcolor(Cyan);
            printf("Input troppo grande    Abbassa un po'");
            textcolor(White);
        }

        else
        {
            textcolor(Green);
            printf("\nHai vinto! Il numero era %d\n", num);
            textcolor(White);

            return;
        }
    }

    textcolor(Red);
    printf("\nHai perso... Il numero era %d\n", num);
}

int main()
{
    setupcolor();
    srand(time(NULL));
    Akinator();
    textcolor(White); 
    return 0;
}
