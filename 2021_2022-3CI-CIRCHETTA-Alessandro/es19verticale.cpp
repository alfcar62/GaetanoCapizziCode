/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Screen Saver Verticale
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
	int riga = 0;
	system("cls");
	
	do
	{
	
	
	    do
	    {
	    	riga++;
	    	
			system("cls");
		    gotoxy (60,riga);
		    printf("CIAO");
		    
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
		while (riga < 24 && !kbhit());
	    
	    do
	    {
	    	riga--;
	    	
			system("cls");
		    gotoxy (60,riga);
		    printf("CIAO");
		    
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
		while (riga > 1 && !kbhit());
	    
	}
	while( !kbhit() );
	
	return 0;
} 

