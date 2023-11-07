/************************************************
CONSEGNA:
Programma in C che simula tre tipi di screen
saver (lo schermo è di 24 righe e 80 colonne)

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    17 Novembre 2021
*************************************************/


#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    // Librrie per Windows
    #include <Windows.h>
    #include <conio.h>

    // Macro per Windows
    #define Kbhit() kbhit()
    #define wait(ms) Sleep(ms)
#else
    // Librerie per macOS/Linux
    #define _POSIX_SOURCE
    #include <unistd.h>

    // Macro per macOS/Linux
    #define Kbhit() 0
    #define wait(ms) usleep(ms * 1000)
#endif

#define ROWS 24
#define COLUMNS 80
#define CIAO_LENGTH 4
#define MIDDLE COLUMNS / 2 - CIAO_LENGTH
#define FPS 25
#define WAIT_TIME 1000 / FPS
// #define LEGACY_WINDOWS <-- uncommentare in caso di problemi con gotoxy su Windows


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


int main()
{
    int n;
    system("");

    printf("Esercizio 19: Menu' per screen-saver\n");

    printf("1. Orizzontale\n");
    printf("2. Verticale\n");
    printf("3. Rombo\n");
    printf("4. Esci\n");

    do
    {
        printf("Sceglere opzione -> ");
        scanf("%d", &n);
    } while (n < 1 || n > 4);
    
    switch (n)
    {
        // orizzontale
        case 1: {
            while (!Kbhit())
            {
                int i_col = 0;

                do
                {
                    system("cls");
                    gotoxy(i_col, 12);
                    printf("ciao");
                    i_col++;

                    wait(WAIT_TIME);
                } while (i_col < COLUMNS && !Kbhit());
            }
        } break;

        // Vertical
        case 2: {
            while (!Kbhit())
            {
                int i_row = ROWS;

                do
                {
                    system("cls");
                    gotoxy(MIDDLE, i_row);
                    printf("ciao");
                    i_row--;

                    wait(WAIT_TIME);
                } while (i_row > 0 && !Kbhit());
            }
        } break;

        // Rombo
        case 3: {
            while (!Kbhit())
            {
                int i_row = 12,
                    i_col = 0;

                // Ovest -> Nord
                do
                {
                    system("cls");
                    gotoxy(i_col, i_row);
                    printf("ciao");
                    i_row--;
                    i_col += 4;

                    wait(WAIT_TIME);
                } while (i_row > 0 && i_col < MIDDLE && !Kbhit());

                // Nord -> Est
                do
                {
                    system("cls");
                    gotoxy(i_col, i_row);
                    printf("ciao");
                    i_row++;
                    i_col += 4;

                    wait(WAIT_TIME);
                } while (i_row < 12 && i_col < COLUMNS && !Kbhit());

                // Est -> Sud
                do
                {
                    system("cls");
                    gotoxy(i_col, i_row);
                    printf("ciao");
                    i_row++;
                    i_col -= 4;

                    wait(WAIT_TIME);
                } while (i_row < ROWS && i_col >= MIDDLE && !Kbhit());

                // Sud -> Ovest
                do
                {
                    system("cls");
                    gotoxy(i_col, i_row);
                    printf("ciao");
                    i_row--;
                    i_col -= 4;

                    wait(WAIT_TIME);
                } while (i_row > 12 && i_col > 0 && !Kbhit());
            }
        } break;

        case 4:
            break;
    }
    
    system("cls");
    return 0;
}
