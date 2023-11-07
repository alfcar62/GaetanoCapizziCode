/**********************
ALUNNO: Alessandro CIRCHETTA
DATA:   17/11/2021   
CLASSE: 3C INFORMATICA 
TESTO:  Menù screen saver 
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void gotoxy (int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

int main()
{
    int n = 0,
      col = 0,
      rig = 0,
      dia = 0; 

    do
    {
        printf("\n1) Screen-Saver Verticale\n");
        printf("2) Screen-Saver Orizzontale\n");
        printf("3) Screen-Saver Diagonale\n");
        printf("4) ESCI\n");
        printf("\nSCEGLI: ");
        scanf ("%d", &n);

        system("cls");

        switch (n)
        {
        case 1:

        do
        {

            do
            {
                rig++;

                system("cls");
                gotoxy (60, rig);
                printf("CIAO");

                Sleep(40); 
            }
            while (rig < 24 && !kbhit());

            do
            {
                rig--;

                system("cls");
                gotoxy (60, rig);
                printf("CIAO");

                Sleep(40); 
            }
            while (rig > 1 && !kbhit());

        }
        while( !kbhit() );

            break;
            
        case 2:

        do
        {
            do
            {
                col++;

                system("cls");
                gotoxy (col,12);
                printf("CIAO");

                Sleep(40); 
            }
            while (col < 117 && !kbhit());

            do
            {
                col--;

                system("cls");
                gotoxy (col,12);
                printf("CIAO");

                Sleep(40); 
            }
            while (col > 1 && !kbhit());

        }
        while(!kbhit());

            break;

        case 3: 

        do
        {
            int
            col = 0,
            rig = 12;

            do // ovest -> nord
            {
                system("cls");
                gotoxy (col, rig);
                printf("CIAO");
                rig--;
                col += 4;
                Sleep(40); 
            }
            while (rig > 1 && col < 56 && !kbhit());

            do // nord -> est
            {
                system("cls");
                gotoxy (col, rig);
                printf("CIAO");
                rig++;
                col += 4;
                Sleep(40); 
            }
            while (rig < 12 && col < 120 && !kbhit());

            do // est -> sud
            {
                system("cls");
                gotoxy (col, rig);
                printf("CIAO");
                rig++;
                col -= 4;
                Sleep(40); 
            }
            while (rig < 24 && col < 120 && !kbhit());

            do // sud -> ovest
            {
                system("cls");
                gotoxy (col,rig);
                printf("CIAO");
                rig--;
                col -= 4;
                Sleep(40); 
            }
            while (rig > 12 && col > 0 && !kbhit());

        } 
        while (!kbhit());

            break;
        }
    }
    while (n < 1 || n < 4);

    return 0;
}