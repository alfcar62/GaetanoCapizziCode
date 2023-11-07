/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Screen Saver orrizzontale 
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
	int col = 0;
	system("cls");
	
	do
	{
	
	
	    do
	    {
	    	col++;
	    	
			system("cls");
		    gotoxy (col,12);
		    printf("CIAO");
		    
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
		while (col < 117 && !kbhit());
	    
	    do
	    {
	    	col--;
	    	
			system("cls");
		    gotoxy (col,12);
		    printf("CIAO");
		    
		    Sleep(40); //40 per i 25 frame e farlo risultare in movimento
	    }
		while (col > 1 && !kbhit());
	    
	}
	while( !kbhit() );
	
	return 0;
} 

