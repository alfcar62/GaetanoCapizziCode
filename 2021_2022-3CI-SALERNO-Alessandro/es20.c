/************************************************
CONSEGNA:
Scrivere un programma che effettui il
controllo formale di una data
(considerando anche gli anni bisestili)

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    17 Novembre 2021
*************************************************/


#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif


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


void clearline()
{
    gotoxy(0, 2);
    printf("                                           ");
}

int main()
{
    int dd, mm, yy;

    system(CLEAR);
    printf("Esercizio 20: Controllo formale della data\n");
    
    do
    {
        dd = 0;
        mm = 0;
        yy = 0;
        
        do
        {
            do
            {
                gotoxy(0, 1);
                printf("../../....");
                gotoxy(0, 1);

                scanf("%d", &dd);

                if (dd < 1 || dd > 31)
                {
                    gotoxy(0, 2);
                    printf("%d non e' un giorno valido.", dd);
                }
                else
                    clearline();
            } while (dd < 1 || dd > 31);
            
            do
            {
                gotoxy(2, 1);
                printf("/../....");
                gotoxy(3, 1);

                scanf("%d", &mm);

                if (mm < 1 || mm > 12)
                {
                    gotoxy(0, 2);
                    printf("%d non e' un mese valido.", mm);
                }
                else
                    clearline();
            } while (mm < 1 || mm > 12);

            if (dd == 31 && (mm == 11 || mm == 4 || mm == 6 || mm == 9) || dd > 29 && mm == 2)
            {
                gotoxy(0, 2);
                printf("Il giorno %d/%d non esiste.", dd, mm);
            }
            else
                clearline();
        } while (dd == 31 && (mm == 11 || mm == 4 || mm == 6 || mm == 9) || dd > 29 && mm == 2);

        do
        {
            gotoxy(5, 1);
            printf("/....");
            gotoxy(6, 1);

            scanf("%d", &yy);

            if (yy < 0 || yy > 9999)
            {
                gotoxy(0, 2);
                printf("L'anno %d e' fuori dal range supportato.", yy);
            }
            else
                clearline();
        } while (yy < 0 || yy > 9999);

        if (dd == 29 && mm == 2 && ((yy % 400 != 0 && yy % 100 == 0) || yy % 4 != 0))
        {
            gotoxy(0, 2);
            printf("L'anno %d non e' bisestile.", yy);
        }
        else
            clearline();
    } while (dd == 29 && mm == 2 && ((yy % 400 != 0 && yy % 100 == 0) || yy % 4 != 0));
    
    printf("\nLa data specificata e' valida.\n");
    return 0;
}
