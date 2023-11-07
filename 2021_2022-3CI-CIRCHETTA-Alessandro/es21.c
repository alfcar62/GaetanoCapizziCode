/**********************
ALUNNO: Alessandro C & Jacopo Bordoni
DATA:   17/11/2021
CLASSE: 3C INFORMATICA
TESTO:  Trasformare un numero da cifre a lettere
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void  gotoxy(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main()
{
    int m = 0,
        c = 0,
        d = 0,
        u = 0,
        t = 0,
        n = 0,
        v = 0;

    system("cls");

    gotoxy (35, 1);
        printf("Trasformare un numero da cifre a lettere");


    printf("\n1) Convertire\n");
    printf("2) Uscire\n");
    scanf ("%d", &t);

    switch (t)
    {
        case 1:
            system("cls");

            gotoxy (35, 1);
                printf("Trasformare un numero da cifre a lettere");

        printf("\nScrivere il numero che si vuole trasformare in testo compreso tra 0 e 10000: \n");

        do
        {
            scanf ("%d", &n);

            if (n < 0 || n > 10000)
                printf("  ATTENZIONE! \nINSERIRE UN NUMERO COMPRESO TRA 0 e 10000: \n");
        }
        while (n < 0 || n > 10000);



        m = n / 1000;
        c = n % 1000;

        switch  (m)
        {
            case 0:
                break;

            case 1:
            printf("Mille");
                break;

            case 2:
            printf("Duemila");
                break;

            case 3:
            printf("Tremila");
            break;

            case 4:
            printf("Quattromila");
                break;

            case 5:
            printf("Cinquemila");
                break;

            case 6:
            printf("Seimila");
                break;

            case 7:
            printf("Settemila");
                break;

            case 8:
            printf("Ottomila");
                break;

            case 9:
            printf("Novemila");
                break;

            case 10:
            printf("Diecimila");
                break;
        }

        d = c % 100;
        c = c / 100;

        switch (c)
        {
            case 0:
                break;

            case 1:
            printf("cento");
                break;

            case 2:
            printf("duecento");
                break;

            case 3:
            printf("trecento");
                break;

            case 4:
            printf("quattrocento");
                break;

            case void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}5:
            printf("cinquecento");
                break;

            case 6:
            printf("seicento");
                break;

            case 7:
            printf("settecento");
                break;

            case 8:
            printf("ottocento");
                break;

            case 9:
            printf("novecento");
                break;
        }

        u = d % 10;
        d = d / 10;

        switch (d)
        {
            case 0:

                switch (u)
                {
                    case 0:
                    if (u == n)
                    {
                    printf("zero");
                    }
                        break;

                    case 1:
                    printf("uno");
                        break;

                    case 2:
                    printf("due");
                        break;

                    case 3:
                    printf("tre");
                        break;

                    case 4:
                    printf("quatto");
                        break;

                    case 5:
                    printf("cinque");
                        break;

                    case 6:
                    printf("sei");
                        break;

                    case 7:
                    printf("sette");
                        break;

                    case 8:
                    printf("otto");
                        break;

                    case 9:
                    printf("nove");
                        break;
                }
                    break;

            case 1:

            switch (u)
            {
                case 0:
                printf("dieci");
                    break;

                case 1:
                printf("undici");
                    break;

                case 2:
                printf("dodici");
                    break;

                case 3:
                printf("tredici");
                    break;

                case 4:
                printf("quattordici");
                    break;

                case 5:
                printf("quindici");
                    break;

                case 6:
                printf("sedici");
                    break;

                case 7:
                printf("diciassette");
                    break;

                case 8:
                printf("diciotto");
                    break;

                case 9:
                printf("diciannove");
                    break;
            }
                break;

            case 2:
            printf("vent");

            switch (u)
            {
                case 0:
                printf("i");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("idue");
                    break;

                case 3:
                printf("itre");
                    break;

                case 4:
                printf("iquattro");
                    break;

                case 5:
                printf("icinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("inove");
                    break;
            }
            break;

            case 3:
            printf("trent");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 4:
            printf("quarant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 5:
            printf("cinquant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 6:
            printf("sessant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 7:
            printf("settant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 8:
            printf("ottant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
            break;

            case 9:
            printf("novant");

            switch (u)
            {
                case 0:
                printf("a");
                    break;

                case 1:
                printf("uno");
                    break;

                case 2:
                printf("adue");
                    break;

                case 3:
                printf("atre");
                    break;

                case 4:
                printf("aquattro");
                    break;

                case 5:
                printf("acinque");
                    break;

                case 6:
                printf("isei");
                    break;

                case 7:
                printf("isette");
                    break;

                case 8:
                printf("otto");
                    break;

                case 9:
                printf("anove");
                    break;
            }
                break;
        }
            break;

        case 2:
            break;
    }
    return 0;
}
