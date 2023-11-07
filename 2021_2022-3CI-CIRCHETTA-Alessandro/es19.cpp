/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Screen Saver orrizzontale 
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy (int x, int y)
        {
            printf("\033[%d;%dH", y, x);
        }

int main()
{
int col;
system("cls");

do
{


    for (col = 0;col < 77; col++)
    {
system("cls");
    gotoxy (col,12);
    printf("ciao");
    Sleep(40);//40 per i 25 frame e farlo risultare in movimento
    //getchar();

        }
        for (col=76;col>1;col--)
    {
system("cls");
    gotoxy  (col,12);
    printf("ciao");
    Sleep(40);
    //getchar();

        }
}while( !kbhit() );

return 0;
} 

