/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Screen Saver Diagonale.
*****************************************/
// 120 colonne e 24 righe

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
    
	
	do
    {
        int  
            col  = 0,
            riga = 12;
        
	    do // ovest -> nord
	    {
			system("cls");
		    gotoxy (col,riga);
            printf("CIAO");
            riga--;
            col += 4;
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
        while (riga > 1 && col < 56 && !kbhit());
	    
        do // nord -> est
	    {
			system("cls");
		    gotoxy (col,riga);
            printf("CIAO");
            riga++;
            col += 4;
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
        while (riga < 12 && col < 120 && !kbhit());

        do // est -> sud
	    {
			system("cls");
		    gotoxy (col,riga);
            printf("CIAO");
            riga++;
            col -= 4;
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
        while (riga < 24 && col < 120 && !kbhit());

        do // sud -> ovest
	    {
			system("cls");
		    gotoxy (col,riga);
            printf("CIAO");
            riga--;
            col -= 4;
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
        while (riga > 12 && col > 0 && !kbhit());

    } while (!kbhit());
    return 0;
}
